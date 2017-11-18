# blinkBurst
Generate bursts of LED flashes separated by a waiting time on an Arduino.

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
