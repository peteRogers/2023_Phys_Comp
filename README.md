# Y2_Phys_Comp

## Code To use Haptic Controller
The DRV2605 from TI is a fancy little motor driver. Rather than controlling a stepper motor or DC motor, its designed specifically for controlling haptic motors

### Control Haptic motor by creating a series 'events'
```java
#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG); 
}

void loop() {
  drv.setWaveform(0, 71);  // start composition
  drv.setWaveform(1,82);
  drv.setWaveform(3,0); //end wave form
  drv.go();
}
```


