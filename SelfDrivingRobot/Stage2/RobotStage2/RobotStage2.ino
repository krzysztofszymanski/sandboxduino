#include <AFMotor.h>
#include <Servo.h>
#include <Ultrasonic.h>

// setup pins for ultrasonic
#define ECHO_PIN     A0
#define TRIGGER_PIN  A1
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

// servo head calibration
int LEFT_DIRECTION = 0;
int STRAIGHT_DIRECTION = 80;
int RIGHT_DIRECTION = 185;
Servo headServo;

// motors 
// max motor speed, this one is with 9,6V battery pack, shield gets hot, really hot, need to rethink that
uint8_t MAX_SPEED = 200;
int TURN_DELAY = 200;
AF_DCMotor motorRight(3);
AF_DCMotor motorLeft(2);

void setup() {
  // set up a serial
  Serial.begin(9600);
  Serial.println("Hi, I'm a autonomous robot!\n");
  //turn servo on
  headServo.attach(9);
  turnHead(STRAIGHT_DIRECTION);
}

void turnHead(int direction){
  headServo.write(direction);
}

void runForward() {
  Serial.print("forward\n");
  motorLeft.setSpeed(MAX_SPEED);
  motorRight.setSpeed(MAX_SPEED);
  // yeah, I need to change cables polarization in order to make it match directions
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
}

void turnRight() {
  Serial.print("\nturnRight\n");
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
  motorLeft.setSpeed(MAX_SPEED);
  motorLeft.run(BACKWARD);
  delay(TURN_DELAY);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void turnLeft() {
  Serial.print("turnLeft\n");
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
  motorRight.setSpeed(MAX_SPEED);
  motorRight.run(BACKWARD);
  delay(TURN_DELAY);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}


float distance() {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("\n insideDIst: ");
  Serial.print(cmMsec);
  return cmMsec;
  
}
//check distance and turn if needed, only turns right at this point
void checkAndTurn() {
  if (distance()<65) {
    for(int i=0;i<10;i++) {
      if (distance()<100) {
          turnRight();
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

