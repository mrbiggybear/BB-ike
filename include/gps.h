#include "TinyGPS++.h"
TinyGPSPlus gps;

namespace GPS
{
    void read()
    {
        if (Serial1.available() > 0)
        {
            gps.encode(Serial1.read());
            Serial.println(gps.location.isUpdated());
            if (gps.location.isUpdated())
            {
                Serial.println("Reading gps...");
                Serial.print(gps.date.month());  
                Serial.print(' ');  
                Serial.print(gps.date.day());  
                Serial.print(',');  
                Serial.println(gps.date.year());  
                
                Serial.print(gps.time.hour());  
                Serial.print(':');  
                Serial.print(gps.time.minute());  
                Serial.print('.');  
                Serial.println(gps.time.second());  
                                
                Serial.print("Speed: ");  
                Serial.println(gps.speed.value());  
                
                Serial.print("Sat. Count: ");  
                Serial.println(gps.satellites.value());

                Serial.println();  
                // delay(2000);
            }
        }
    };
}