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
#######################################################################*/


#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stddef.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif


#include <Versalino.h>
#include <inttypes.h>


class Ultrasonic
{

	public:
	//-------Versalino Functions
	VersalinoBUS getBUS(); //This will return the VersalinoBUS currently assigned to the instance of this library
	void setBUS(VersalinoBUS myBUS);
	void removeBUS();

	//-------Ultrasonic Functions
    Ultrasonic(int myTrigger, int myEcho);
    Ultrasonic(int myTrigger, int myEcho, VersalinoBUS myBUS);

    void begin(int myTrigger, int myEcho);
    void begin(int myTrigger, int myEcho, VersalinoBUS myBUS);

    long timing();
    long timing(unsigned long myTimeout);
    long timing(float myTimeout, bool metric);

    float convert(long microsec, bool metric);
    void setDivisor(float value, bool metric);
    static const bool IN = 0;
    static const bool CM = 1;

	private:
	VersalinoBUS _myBUS;
	bool _BUSenabled;
	int _trigPin;
	int _echoPin;
	float _cmDivisor;
	float _inDivisor;
	const static unsigned long _defaultTimeout = 30000; //30000 microseconds, 30 milliseconds
														//slightly greater than the time required for sound to make the 10 meter round trip

};

	//---------begin constants

/* Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse. */

inline unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout, unsigned long width_timeout)
{
        // cache the port and bit of the pin in order to speed up the
        // pulse width measuring loop and achieve finer resolution.  calling
        // digitalRead() instead yields much coarser resolution.
        uint8_t bit = digitalPinToBitMask(pin);
        uint8_t port = digitalPinToPort(pin);
        uint8_t stateMask = (state ? bit : 0);
        unsigned long width = 0; // keep initialization out of time critical area

        // convert the timeout from microseconds to a number of times through
        // the initial loop; it takes 16 clock cycles per iteration.
        unsigned long numloops = 0;
        unsigned long numwidth = 0;
        unsigned long maxloops = microsecondsToClockCycles(timeout) / 16;
        unsigned long maxwidth = microsecondsToClockCycles(width_timeout) / 16;

        // wait for any previous pulse to end
        while ((*portInputRegister(port) & bit) == stateMask)
                if (numloops++ == maxloops)
                        return 0;

        // wait for the pulse to start
        while ((*portInputRegister(port) & bit) != stateMask)
                if (numloops++ == maxloops)
                        return 0;

        // wait for the pulse to stop
        while ((*portInputRegister(port) & bit) == stateMask)
        {
			if (numwidth++ == maxwidth)
                break;
            width++;
		}

        // convert the reading to microseconds. The loop has been determined
        // to be 10 clock cycles long and have about 16 clocks between the edge
        // and the start of the loop. There will be some error introduced by
        // the interrupt handlers.
        return clockCyclesToMicroseconds(width * 16 + 16);
};



#endif // ULTRASONIC_H
