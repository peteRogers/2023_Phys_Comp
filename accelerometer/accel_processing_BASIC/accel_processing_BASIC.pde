import processing.serial.*;
int accelX = 0;


void setup() {
  size(1024, 1024);
  printArray(Serial.list());
  new Serial(this, Serial.list()[3], 115200);
}



void draw() {
  background(0);
  rectMode(CENTER);
  rect(width/2+(accelX*5), height/2, 50, 50);
}


void serialEvent (Serial p) {
  String inString = p.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    // println(inString);
    accelX = int(inString);
  }
}
