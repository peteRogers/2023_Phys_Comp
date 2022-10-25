#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG); 
}


void loop() {


 // delay(1000);
  
  drv.setWaveform(0, 71);  // play effect 
  drv.setWaveform(1,82);
  drv.setWaveform(3,0);
 // end waveform
  drv.go();
  
 // delay(1000);
  
}
