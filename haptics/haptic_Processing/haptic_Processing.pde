import processing.serial.*;
Serial myPort; 

void setup(){
  size(1024, 1024);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
}



void draw(){
  background(0);
  text("press screen", width/2, height/2);
}

void mouseReleased(){
  myPort.write("64");
  myPort.write('\n');
}

void mousePressed(){
  myPort.write("41");
  myPort.write('\n');
}
