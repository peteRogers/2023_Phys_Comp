import processing.serial.*;
Serial myPort; 
float x1 = 0;
float x2 = 1024;
float inc1 = 10; 

void setup(){
  size(1024, 1024);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
}



void draw(){
  background(0);
  ellipse(x1, width/2, 50,50);
  ellipse(x2, width/2, 50,50);
  x1 += inc1;
  x2 -= inc1;
  if(abs(x1-x2) < 50){ 
     myPort.write("27");
     myPort.write('\n');
     
     inc1 = inc1*-1;
     
  }
  
  if(x1 > width || x2 > width){
     myPort.write("1");
     myPort.write('\n');
     inc1 = inc1*-1;
  }
}
