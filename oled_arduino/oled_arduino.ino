//#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  //display.invertDisplay(true);
  display.setTextWrap(false);
  display.setTextColor(SSD1306_WHITE, 0x0000);
  display.setTextSize(2);
}
void loop() {
 
  display.clearDisplay();
  display.fillRect(i,0, 20, 5, SSD1306_WHITE);
  display.setCursor(20, 20);
  display.print("hello");
  display.display();
}
