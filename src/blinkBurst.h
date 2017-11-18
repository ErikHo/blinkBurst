/*
BlinkBurst

Turns on and off a LED with a specified 'on' time and a specified 'off' time. After 
a defined number of on's the LED is off for a certain interval. 
The light emitting diode (LED) connected to a digital pin.
The timing mechanism used is as in ""BlinkWithoutDelay" from the Arduino Digital library.
This means that other code can run at the  same time without being interrupted by this 
LED code.

The circuit:
- Use the onboard LED.
- Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
  and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
  is set to the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your
  Arduino model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products


(C) Erik Homburg 2017

This work is licensed under the Creative Commons Attribution 4.0 International License.
To view a copy of this license, visit http://creativecommons.org/licenses/by/4.0/ or 
send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/

#ifndef blinkBurst_h
#define blinkBurst_h

#include <Arduino.h>

class blinkBurst{
public:
  begin(int ledPin = LED_BUILTIN, int numBlinks = 2, unsigned long blinkTime = 100, 
        unsigned long blinkInterval = 100, unsigned long burstInterval = 700);
  void doBurst();
private:
  unsigned long _previousMillis = 0;        // stores last time LED was updated
  unsigned long _blinkInterval;             // interval for the LED to blink (milliseconds)
  unsigned long _blinkTime;                 // pause between blinks (milliseconds)
  unsigned long _burstInterval;             // pause between bursts (milliseconds) 
  unsigned long _interval;

  unsigned int _ledPin;                     // pin to connnect ther LED
  unsigned int _numBlinks;                  // number of blinks in burst
  // _blinkPhase counts the phase in a cycle, initialized to the highest possible value
  // so that at the first trigger of doburst phase 0 is started.
  unsigned int _blinkPhase = (2 * _numBlinks) - 1;
};

#endif

