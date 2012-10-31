#include <AFMotor.h>
#include <Servo.h>
#include <Ultrasonic.h>

// setup pins for ultrasonic
#define ECHO_PIN       A0
#define TRIGGER_PIN    A1
//setup pins for motors
#define LEFT_FORWARD   A2
#define LEFT_BACKWARD  A3
#define RIGHT_BACKWARD A4
#define RIGHT_FORWARD  A5


Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
int TURN_DELAY = 200;

void setup() {
  // set up a serial for testing pur
  Serial.begin(9600);
  Serial.println("Hi, I'm a autonomous toy-robot!\n");
  //set all motor outputs, set them to LOW
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);  
}


void runForward() {
  // backward pins to LOW, forward to HIGH
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);  

}


void turn(boolean turnDirection) {
  Serial.print("\nturnRight\n");
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);  
  // decide if this should be left or right
  digitalWrite(LEFT_FORWARD, turnDirection);
  digitalWrite(RIGHT_FORWARD, !turnDirection);  
  delay(TURN_DELAY);
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

