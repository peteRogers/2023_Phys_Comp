#include <Adafruit_NeoPixel.h>


#define PIN 6
int d = 20;



Adafruit_NeoPixel jewel = Adafruit_NeoPixel(7, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
 
  jewel.begin();
  
}

void loop() {
  for(int i = 1; i < jewel.numPixels(); i++) {
    jewel.setPixelColor(i, 0, 0, 0, 255);
    jewel.show();
    delay(d);
    jewel.clear();
  }
}
