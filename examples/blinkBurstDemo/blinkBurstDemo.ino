#include <blinkBurst.h>

blinkBurst myBurst;        // create myBurst instance of the blinkBurst class

void setup() {
  // 4 times a flash of 50 ms separated by 100 ms, all of this separated by 1300 ms
  // total cycle time 2000 ms
  myBurst.begin(LED_BUILTIN, 4, 50, 100, 1300);
}

void loop() {              // execute main loop
  myBurst.doBurst();
}

