// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 

    myservo.write(0);              // tell servo to go to position in variable 'pos' 
    delay(300);
    myservo.write(90);              // tell servo to go to position in variable 'pos' 
    delay(300);
    myservo.write(180);              // tell servo to go to position in variable 'pos' 
    delay(300);
} 
