 
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

void setup () {
    Serial.begin(9600);
    Wire1.begin();
    RTC.begin();
 
}
void loop () {
    DateTime now = RTC.now(); 
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println(); 
    delay(1000);
}
