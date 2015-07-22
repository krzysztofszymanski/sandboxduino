#include <Ultrasonic.h>
#include <AFMotor.h>

// setup pins for ultrasonic
#define ECHO_PIN       A0
#define TRIGGER_PIN    A1
//setup pins for motors
uint8_t MAX_SPEED = 255;
AF_DCMotor motorRight(4);
AF_DCMotor motorLeft(2);


Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
int TURN_DELAY = 200;

void setup() {
  // set up a serial for testing pur
  Serial.begin(9600);
  Serial.println("Hi, I'm a autonomous toy-robot!\n");
  //set all motor outputs, set them to LOW
}


void runForward() {
  // backward pins to LOW, forward to HIGH
  Serial.println("Going FORWARD!\n");
  motorLeft.setSpeed(MAX_SPEED);
  motorRight.setSpeed(MAX_SPEED);
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
  delay(TURN_DELAY);
}


void turn(boolean turnDirection) {

  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);  // decide if this should be left or right
  
  if (turnDirection) {
    Serial.println("Going LEFT!\n");
    motorLeft.setSpeed(MAX_SPEED);    
    motorLeft.run(FORWARD);
    motorRight.setSpeed(MAX_SPEED);    
    motorRight.run(BACKWARD);

  } else{
    Serial.println("Going RIGHT!\n");
    motorRight.setSpeed(MAX_SPEED);    
    motorRight.run(FORWARD);
    motorLeft.setSpeed(MAX_SPEED);
    motorLeft.run(BACKWARD);
  }
  delay(TURN_DELAY);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

float distance() {
  // get distance from ultrasonic
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  return cmMsec;
  
}

//check distance and turn if needed, choose turn direction randomly
void checkAndTurn() {
  if (distance() < 65) {
    int rand = random(100);
    boolean turnDirection = rand<50;
    for(int i=0; i < 10; i++) {
      if (distance() < 100) {
          turn(turnDirection);
      } else {
        break;
      }
    }
  }
}

void loop() {
  checkAndTurn();
  runForward();
}
