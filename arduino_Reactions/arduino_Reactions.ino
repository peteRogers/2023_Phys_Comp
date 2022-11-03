long mill = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(random(100, 5000));
  mill = millis();
  digitalWrite(13, HIGH);
  while(digitalRead(2) == LOW){
      //waiting for button press
  }
  Serial.println(millis() - mill);
  digitalWrite(13, LOW);
}
