#include <OneButton.h>

// This function is called from the interrupt when the signal on the PIN_INPUT has changed.
// do not use Serial in here.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO_EVERY)
#define D1 2
#define D2 0

#define TX_PIN 22
#define RX_PIN 8

const int l_pin = 13;
const int r_pin = 12;

OneButton LEFT = OneButton(l_pin, true);
OneButton RIGHT = OneButton(r_pin, true);

void checkTicks()
{
  // include all buttons here to be checked
  LEFT.tick();
  RIGHT.tick(); // just call tick() to check the state.
}

#elif defined(ESP8266)
#define D1 2
#define D2 0

#define TX_PIN 22
#define RX_PIN 8

const int l_pin = 13;
const int r_pin = 12;

OneButton LEFT = OneButton(l_pin, true);
OneButton RIGHT = OneButton(r_pin, true);

ICACHE_RAM_ATTR void checkTicks()
{
  // include all buttons here to be checked
  LEFT.tick();
  RIGHT.tick(); // just call tick() to check the state.
}

#elif defined(ARDUINO_AVR_MICRO)
#define D1 2
#define D2 3

#define TX_PIN 21 //22   // D5
#define RX_PIN 8  // B0

const int l_pin = D1;
const int r_pin = D2;

OneButton LEFT = OneButton(l_pin);
OneButton RIGHT = OneButton(r_pin);

void checkTicks()
{
  // include all buttons here to be checked
  //   Serial.println("Checking...");
  LEFT.tick();
  RIGHT.tick(); // just call tick() to check the state.
}
#else
#define D1 2
#define D2 0

#define TX_PIN 22
#define RX_PIN 8

const int l_pin = 13;
const int r_pin = 12;

OneButton LEFT = OneButton(l_pin, true);
OneButton RIGHT = OneButton(r_pin, true);

void checkTicks()
{
  LEFT.tick();
  RIGHT.tick();
}
#endif

class Light
{
private:
  int led_pin;
  bool is_on = false;

public:
  Light(int _pin, bool _is_on) : led_pin(_pin), is_on(_is_on)
  {
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, !is_on ? HIGH : LOW);
  }
  bool on()
  {
    digitalWrite(led_pin, HIGH);
    is_on = true;
    return is_on;
  }
  bool off()
  {
    digitalWrite(led_pin, LOW);
    is_on = true;
    return is_on;
  }
  // blocking
  void on_off(int _delay = 80)
  {
    digitalWrite(led_pin, HIGH);
    delay(_delay);
    digitalWrite(led_pin, LOW);
  }
  bool toggle()
  {
    digitalWrite(led_pin, !digitalRead(led_pin) ? HIGH : LOW);
    is_on = digitalRead(led_pin);
    return is_on;
  }
};

int debounce = 160;

Light rx_led = Light(RX_PIN, true);
Light tx_led = Light(TX_PIN, true);

int hold_start_L;
int hold_start_R;

// this function will be called when the button was pressed 1 time only.
void singleClick_L()
{
  Serial.println("singleClick_L() detected.");
  tx_led.toggle();
} // singleClick

void singleClick_R()
{
  Serial.println("singleClick_R() detected.");
  rx_led.toggle();
} // singleClick

// this function will be called when the button was pressed 2 times in a short timeframe.
void doubleClick_L()
{
  Serial.println("doubleClick_L() detected.");
  tx_led.on_off(800);
} // doubleClick

// this function will be called when the button was pressed 2 times in a short timeframe.
void doubleClick_R()
{
  Serial.println("doubleClick_R() detected.");
  rx_led.on_off(800);
} // doubleClick

// this function will be called when the button was pressed multiple times in a short timeframe.
void multiClick_L()
{
  Serial.print("multiClick_L(");
  Serial.print(LEFT.getNumberClicks());
  Serial.println(") detected.");
} // multiClick

// this function will be called when the button was pressed multiple times in a short timeframe.
void multiClick_R()
{
  Serial.print("multiClick_R(");
  Serial.print(LEFT.getNumberClicks());
  Serial.println(") detected.");
} // multiClick

// this function will be called when the button was held down for 1 second or more.
void pressStart_L()
{
  Serial.println("pressStart_L()");
  hold_start_L = millis() - 1000; // as set in setPressTicks()
  tx_led.on();
} // pressStart()

// this function will be called when the button was held down for 1 second or more.
void pressStart_R()
{
  Serial.println("pressStart_R()");
  hold_start_L = millis() - 1000; // as set in setPressTicks()
  rx_led.on();
} // pressStart()

// this function will be called when the button was released after a long hold.
void pressStop_L()
{
  tx_led.off();
  Serial.print("pressStop_L(");
  Serial.print(millis() - hold_start_L);
  Serial.println(") detected.");
} // pressStop()

// this function will be called when the button was released after a long hold.
void pressStop_R()
{
  rx_led.off();
  Serial.print("pressStop_R(");
  Serial.print(millis() - hold_start_L);
  Serial.println(") detected.");
} // pressStop()

namespace Lights
{
  void setup(int _debounce = -1)
  {
    if (_debounce > -1)
    {
      debounce = _debounce;
    }

    LEFT.attachClick(singleClick_L);
    RIGHT.attachClick(singleClick_R);
    LEFT.setClickTicks(debounce);
    RIGHT.setClickTicks(debounce);

    LEFT.attachDoubleClick(doubleClick_L);
    RIGHT.attachDoubleClick(doubleClick_R);
    // button.attachMultiClick(multiClick);

    LEFT.attachLongPressStart(pressStart_L);
    RIGHT.attachLongPressStart(pressStart_R);
    LEFT.attachLongPressStop(pressStop_L);
    RIGHT.attachLongPressStop(pressStop_R);
    LEFT.setPressTicks(debounce * 2);  // that is the time when LongPressStart is called
    RIGHT.setPressTicks(debounce * 2); // that is the time when LongPressStart is called
  }
} // namespace Lights
