#include "Wire.h"


void setup() {
  Serial.begin(9600);
 // set dig pin
 Wire.beginTransmission(8);
 Wire.write(13);
 Wire.write(1); // led on  or 0 for led off
 Wire.endTransmission();


 // get dig pin nr 11 value high:1 or low: 0
 Wire.beginTransmission(8);
 Wire.write(11);
 Wire.endTransmission();
}
void loop() {

 // and now pull result home

 Wire.requestFrom(8, 1);    // request 1 byte from slave device #8
 while (Wire.available()) { // slave may send less than requested
   char c = Wire.read(); // receive a byte as character
   if (c == 1)
     Serial.println("pin is high");
   else
     Serial.println("pin is low");
 }
}
