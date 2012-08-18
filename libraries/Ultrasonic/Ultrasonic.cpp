/*####################################################################
 FILE: Ultrasonic.h - Library for the Virtuabotix Ultrasonic Sensor.
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

 * Centimeters Divisor
  * =========== =======
  *  15.875     26.9029
  *  46.355     27.6233
  *  92.075     28.1949
  * 137.795     28.4717
  * 183.515     28.5584
  * 229.235     28.5936
  * 274.955     28.7194
  *
  * Inches      Divisor
  * ======      =======
  *   6.25      68.3333
  *  18.25      70.1633
  *  36.25      71.6152
  *  54.25      72.3182
  *  72.25      72.5384
  *  90.25      72.6277
  * 108.25      72.9473
#######################################################################*/

#include <string.h>

#ifndef ULTRASONIC_H

#include "Ultrasonic.h"

//############ Timing Functions #############

long Ultrasonic::timing()
    {
	return (timing(_defaultTimeout));
    }

long Ultrasonic::timing(float myTimeout, bool metric)
    {

	if(metric) return (timing((unsigned long)(myTimeout * _cmDivisor * 2.0)));
    else return (timing((unsigned long)(myTimeout * _inDivisor * 2.0)));

    }

long Ultrasonic::timing(unsigned long myTimeout)
    {
	int myTrigger;
	int myEcho;

	if(_BUSenabled)
	{
		myTrigger=_myBUS.PINS[_trigPin];
		myEcho=_myBUS.PINS[_echoPin];
		//Serial.println("Bus Enabled");
	}
	else //compatibility mode
	{
		//Serial.println("Compatability mode");
		myTrigger=_trigPin;
		myEcho=_echoPin;
	}

	/*Serial.print("\ntrigger: ");
	Serial.print(myTrigger);
	Serial.print("echo: ");
	Serial.println(myEcho);
*/
	/*pinMode(_trigPin, OUTPUT);
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    pinMode(_echoPin, INPUT);
    long myTiming=pulseIn(_echoPin, HIGH);
    Serial.print("Timing ");
    Serial.println(myTiming);
    return myTiming;
*/
	pinMode(myTrigger, OUTPUT);
    digitalWrite(myTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(myTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(myTrigger, LOW);
	pinMode(myEcho, INPUT);
    return pulseIn(myEcho, HIGH, 1000, myTimeout);

 }
//###############################################################

//########################UNIT CONVERSIONS#######################
float Ultrasonic::convert(long microsec, bool metric)
    {
    // microsec / 29 / 2;
    if(metric) return microsec / _cmDivisor / 2.0;  // CM
    // microsec / 74 / 2;
    else return microsec / _inDivisor / 2.0;  // IN
    }

void Ultrasonic::setDivisor(float value, bool metric)
    {
    if(metric) _cmDivisor = value;
    else _inDivisor = value;
    }

//###############################################################


//######### Initialization and Pin Structures ###################
	Ultrasonic::Ultrasonic(int myTrigger, int myEcho)
    {
		begin(myTrigger, myEcho);
    }

	//this will allow the bus of an instance of this library to be changed
	Ultrasonic::Ultrasonic(int myTrigger, int myEcho, VersalinoBUS myBUS)
	{
		begin(myTrigger, myEcho, myBUS);
	}

	void Ultrasonic::begin(int myTrigger, int myEcho)
    {
		_cmDivisor = 27.6233;
		_inDivisor = 70.1633;
		_trigPin = myTrigger;
		_echoPin = myEcho;
		_BUSenabled = false;
    }

	//this will allow the bus of an instance of this library to be changed
	void Ultrasonic::begin(int myTrigger, int myEcho, VersalinoBUS myBUS)
	{

		_cmDivisor = 27.6233;
		_inDivisor = 70.1633;
		_trigPin = myTrigger;
		_echoPin = myEcho;
		_myBUS = myBUS;
		_BUSenabled = true;
	}


	//This will return the VersalinoBUS currently assigned to the instance of this library
	VersalinoBUS Ultrasonic::getBUS()
	{
		return _myBUS;
	}

	void Ultrasonic::removeBUS()
	{
		_BUSenabled=false;
	}

	void Ultrasonic::setBUS(VersalinoBUS myBUS)
	{
		_myBUS = myBUS;
		_BUSenabled=true;
	}


//##################################################################

#endif // ULRTASONIC_H
