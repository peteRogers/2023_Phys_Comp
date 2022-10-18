/*
 * Unistep2 example: move
 *
 * Simple example of stepper enumeration and movement via move(steps).
 * If steps > 0 clockwise, else counter clockwise. Non-blocking.
 *
 * 30Jan18
 * R Sanchez
 *
 * This code is released to the public domain
 *
 */

// include the library
#include <Unistep2.h>

// Define some steppers and the pins they will use
//Unistep2 stepperX(2, 3, 4, 5, 4096, 1000); // pins for IN1, IN2, IN3, IN4, steps per rev, step delay(in micros)
Unistep2 stepper(7, 8, 9,10, 4096, 800);
int incer = 4096;

void setup()
{
  // Your setup code here
  // The library initializes the pins for you
}

void loop(){
  stepper.run();
  if(stepper.stepsToGo() == 0){
    incer = incer * -1;
    stepper.stop();
    delay(2000);
    stepper.move(incer);
  }
}
