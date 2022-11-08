import processing.serial.*;
Serial myPort;


void setup(){
  size(1024, 1024);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  colorMode(HSB, 255);
}

void draw(){
  color c = color(mouseX/4,1023,mouseY/4);
  String s = ""+red(c)+">"+green(c)+">"+blue(c)+">"+"\n";
  background(c);
  myPort.write(s);
}
