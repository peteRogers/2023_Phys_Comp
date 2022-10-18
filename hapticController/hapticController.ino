#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);
  Serial.println("DRV test");
  drv.begin();
    
  // Set Real-Time Playback mode
  drv.setMode(DRV2605_MODE_REALTIME);
}
uint8_t effect = 30;

void loop() {
   
  drv.setRealtimeValue(effect);
  delay(100);
  drv.setRealtimeValue(0x00);
 // delay(200);
  effect = effect + 1;
  Serial.println(effect);
  if (effect > 51){
    effect = 30;
  }
  
}
