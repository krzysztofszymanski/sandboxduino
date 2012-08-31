// SainSmart L293D Motor Drive Shield
// this is a clone of adafruit motor shield
// using adafruit library - that is fully compatible(as far as I tested)
// 
// Application runs two motor traked chasis back and forward
// motors connected to slots 3 and 4

#include <AFMotor.h>

AF_DCMotor motor(4);
AF_DCMotor motor2(3);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(400);
  motor2.setSpeed(400);
  motor.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  motor.run(FORWARD);
  motor2.run(FORWARD);
  for (i=100; i<255; i++) {
    motor.setSpeed(i);  
    motor2.setSpeed(i);  
    delay(10);
 }
  for (i=255; i!=100; i--) {
    motor.setSpeed(i);  
    motor2.setSpeed(i);  
    delay(10);
 }
  delay(500);
  Serial.print("tock");

  motor.run(BACKWARD);
    motor2.run(BACKWARD);
  for (i=100; i<255; i++) {
    motor.setSpeed(i);  
    motor2.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=100; i--) {
    motor.setSpeed(i);
    motor2.setSpeed(i);    
    delay(10);
 }
 motor.run(RELEASE);
 motor2.run(RELEASE);
 delay(500);
}
