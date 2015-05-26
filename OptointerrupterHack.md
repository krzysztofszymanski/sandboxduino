# Optointerrupter made into optocoupler.

# Introduction #

I found several optointerrupters in old printers and I needed optocoupler. I decided to hack a optointerrupter and make it into optocoupler.

## IF YOU DON'T HAVE INTERRUPTERS - DON'T BUY ONE JUST TO HACK IT, IT'S NOT WORTH IT(it's around 10$ on ebay), BUY OPTOCOUPLER. ##


## Setup: ##

  * Optointerrupter from old printer
  * 220OHM resistors
  * jumper connectors
  * two 3V VCC sources
  * LED
  * dremmel

# Details #

Optointerrupter:

![http://sandboxduino.googlecode.com/svn/trunk/OptoInterrupterHack/optointerrupter.png](http://sandboxduino.googlecode.com/svn/trunk/OptoInterrupterHack/optointerrupter.png)


Those two parts are basically made out of two components:
- LED
- photoresistor

Optocoupler completely separates two circuits, helps you to protect expensive parts from the rest of the circuit. I needed one to separate my camera from Arduino.

There's one small difference between optointerrupters and optocoupler: optointerrupter uses the same VCC for both LED and photoresistor and this is what needs to be hacked:

## Your goal: ##
![http://sandboxduino.googlecode.com/svn/trunk/OptoInterrupterHack/circuit.png](http://sandboxduino.googlecode.com/svn/trunk/OptoInterrupterHack/circuit.png)

## Hack: ##
![http://sandboxduino.googlecode.com/svn/trunk/OptoInterrupterHack/hacked-opto-interrupter.png](http://sandboxduino.googlecode.com/svn/trunk/OptoInterrupterHack/hacked-opto-interrupter.png)

## Optocoupler in action: ##

<a href='http://www.youtube.com/watch?feature=player_embedded&v=fFl5DkLFVr0' target='_blank'><img src='http://img.youtube.com/vi/fFl5DkLFVr0/0.jpg' width='425' height=344 /></a>

## Notes ##
Make sure to use 220 OHM resistors for infrared LED - otherwise it will be damaged.