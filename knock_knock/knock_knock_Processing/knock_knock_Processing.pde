import processing.sound.*;
import processing.serial.*;
Serial myPort; 
int sensor = 0;
SoundFile sf;

void setup(){
  size(1024, 1024);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  sf = new SoundFile( this, "knock.mp3");
}



void draw(){
  //background(0);
  //fill(255,255,255, 50);
  //if(sf.isPlaying()){
  //    ellipse(width/2, height/2, 200, 200);
  //}
}

//function controls receiving data from arduino
void serialEvent (Serial p){
   String inString = p.readStringUntil('\n');
   if (inString != null) {
      inString = trim(inString);
      sensor = int(inString);
      sf.play();
   }
}
