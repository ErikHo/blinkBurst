#include <blinkBurst.h

blinkBurst::begin(int ledPin, int numBlinks, unsigned long blinkTime, 
                  unsigned long blinkInterval, unsigned long burstInterval){
  _ledPin = ledPin;                   // initialize the LED
  pinMode(_ledPin, OUTPUT);
  digitalWrite(_ledPin, LOW);
  _numBlinks = numBlinks;             // initialize private variables
  _blinkPhase = (2 * numBlinks) - 1;
  _blinkTime = blinkTime;
  _blinkInterval = blinkInterval;
  _interval = _blinkTime;
  _burstInterval = burstInterval;
}


void blinkBurst::doBurst(){

  unsigned long currentMillis = millis();               // get current time
  if (currentMillis - _previousMillis >= _interval) {   // has _interval elapsed?
    _previousMillis = currentMillis;

    if(_blinkPhase >= (_numBlinks * 2) - 1){            // test phase
      _blinkPhase = 0;                                  // if final, reset phase
      _interval = _burstInterval;                       // initiate interval between bursts
      digitalWrite(_ledPin, LOW);                       // LED off
    }
    else if ((_blinkPhase % 2) == 0){                   // if even phase (0,2,4...)
      _blinkPhase++;                                    // increment phase
      _interval = _blinkTime;                           // initiate LED blink
      digitalWrite(_ledPin, HIGH);                      // LED on
    }
    else{
      _blinkPhase++;                                    // phase is odd, increment phase
      _interval = _blinkInterval;                       // initiate LED pause 
      digitalWrite(_ledPin, LOW);                       // LED off
    }
  }
}

