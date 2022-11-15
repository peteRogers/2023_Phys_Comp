
bool pressed = false;
bool on = false;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  int b  = digitalRead(5);
  if (b == HIGH && pressed == false) {
    pressed = true;
    on = !on;
    Serial.println(on);
  }
  
  if(b == LOW && pressed == true){
    pressed = false;
  }
  
  digitalWrite(13, on);
}
