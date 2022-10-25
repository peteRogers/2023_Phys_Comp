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
![Screenshot](hapticControls.png)
### Read Serial data from the computer into arduino
This code will read one piece of data sent from the computer. 
```java
//receiving serial messages
void serialEvent() {
  if(Serial.available()){
      String input = Serial.readStringUntil('\n');
      //you need a global variable to use data elsewhere in your code
      myData = input.toInt();
  }
}
```
### Split Strings in arduino with a certain character
This code allows you to split a string, so you can send receive multiple pieces of data in one go
```java

String getValue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
```
You use it like this to get a number, the parameters are the input, the character to split with and which item you want to get when you split
```java
int button = getValue(input, '>', 0).toInt();
```
or like this to get a string
```java
String s = getValue(input, '>', 0);
```

