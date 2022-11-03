const byte interruptPin = 2;

long mill = 0;


void setup() {
  pinMode(interruptPin, INPUT);
  pinMode(13, OUTPUT);
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
