import processing.serial.*;
Serial myPort;
int red = 0;
int green = 0;
int blue = 0;

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
  println(s);
  myPort.write(s);
  red = round(map(mouseX, 0, width, 0, 255));
  blue = round(map(mouseY, 0, height, 0, 255));
}
