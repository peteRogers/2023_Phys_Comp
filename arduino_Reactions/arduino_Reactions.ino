const byte interruptPin = 2;
volatile bool timing = false;
volatile long mill = 0;
volatile long result = 0;

void setup() {
  pinMode(interruptPin, INPUT);
  pinMode(13, OUTPUT);
 // attachInterrupt(digitalPinToInterrupt(interruptPin), interrupt, CHANGE);
  Serial.begin(9600);
}

void loop() {
  delay(random(100, 5000));
  mill = millis();
  digitalWrite(13, HIGH);
  while(digitalRead(2) == LOW){
      
    }
    Serial.println(millis() - mill);
    digitalWrite(13, LOW);
 }


//this one is for working out how close you can count in seconds
//void interrupt() {
//  if (timing == false){
//    timing = true;
//    mill = millis();
//  }else{
//    timing = false;
//    result = millis() - mill;
//    Serial.println(result);
//  }
//}
