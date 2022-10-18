import processing.serial.*;
Serial myPort;

int accelX = 0;
int accelY = 0;

void setup() {
  size(1024, 1024);
  printArray(Serial.list());
  try {
    myPort = new Serial(this, Serial.list()[3], 115200);
  }
  catch(Exception e) {
    println(e);
  }
}



void draw() {
  //background(0);
  rectMode(CENTER);
  rect(width/2+(accelX*5), height/2 + (accelY*5), 50, 50);
}


void serialEvent (Serial p) {
  String inString = p.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    println(inString);
    String[] s = split(inString, '>');
    try {
      accelX = int(s[0]);
      accelY = int(s[1]);
    }
    catch(Exception e) {
      println("foofoo");
    }
  }
}
