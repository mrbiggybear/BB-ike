#include <Arduino.h>
#include "lights.h"
#include "gps.h"

using namespace GPS;

int timer = 0;

void setup()
{
    // set serial baud
    Serial.begin(9600);
    Serial1.begin(9600);

    // gps is setup in 'gps.h'
    Lights::setup();
    // set timer
    timer = millis();
}

void loop()
{
    // trigger every 15 seconds
    if ((millis() - timer) > 15000)
    {
        // reset timer
        timer = millis();
        // read gps
        read();
    }

    delay(80);
    // check buttons
    checkTicks();
}