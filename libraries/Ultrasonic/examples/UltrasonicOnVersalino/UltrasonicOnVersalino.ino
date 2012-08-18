/*####################################################################
 FILE: UltrasonicDemo.pde - Basic example of the Library for the Virtuabotix Ultrasonic Sensor.
 VERSION: 2S0A

 PURPOSE: Distance measurement using the HC-SRO4, HY-SRF05 and other
 pulse based distance sensing modules in single or double wire modes.

 LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)

 GET UPDATES: https://www.virtuabotix.com/

  HISTORY:
  Joseph Dattilo (Virtuabotix LLC) - Version 2S0A (05/06/2012)
  	-Complete library re-write adding Versalino support
  	-Improved one wire
  	-added three timing overloads to help to eliminate timeout problems
  	-Removed standard deviation, statistical operations being moved to
  	-a dedicated analysis library
  Joseph Dattilo (Virtuabotix LLC) - Version 1S1A (04/21/2012)
 	-Added one wire support
  Joseph Dattilo (Virtuabotix LLC) - Version 1S0A (02/28/2012)
 	-Added Arduino 1.0 Compatability
  cnobile 						  - HCSR04 Library (08/10/2011)
 ITead studio.                    - Concepts (01/20/2010)
#######################################################################*/

#include <Ultrasonic.h>

#define TRIGGER_PIN  AN1
#define ECHO_PIN     AN0
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN, BUSA);

void setup()
  {
  Serial.begin(9600);
  }

void loop()
  {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing(15, Ultrasonic::IN);

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.println(inMsec);
  delay(1000);
  }
