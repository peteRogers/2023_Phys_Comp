#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <movingAvg.h> 

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
movingAvg avgX(50);  
movingAvg avgY(50);  

void setup() {
  Serial.begin(115200);
  /* Initialise the sensor */
  if(!accel.begin()){
    
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }

  /* Set the range to whatever is appropriate for your project */
  //accel.setRange(ADXL345_RANGE_16_G);
  //accel.setRange(ADXL345_RANGE_8_G);
  //accel.setRange(ADXL345_RANGE_4_G);
  accel.setRange(ADXL345_RANGE_2_G);
  avgX.begin();
  avgY.begin();
  
  
}

void loop() {
  sensors_event_t event; 
  accel.getEvent(&event);
  
 
  int x = avgX.reading(event.acceleration.x * 10);
  int y = avgY.reading(event.acceleration.y * 10);
 
  Serial.print(x);
  Serial.print(">");
  Serial.print(y);
  Serial.println(">");
  delay(5);
}
