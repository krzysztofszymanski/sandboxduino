  * added ultrasound sensor and servo (not connected yet)

![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/servo.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/servo.png)

![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/robot2.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/robot2.png)

  * I had to solder some new pins to motor shield in order to be able to connect ultrasound sensor

![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/01%20pins.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/01%20pins.png)

  * first row of pins:
![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/02%20pins.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/02%20pins.png)

  * all pins:
![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/03%20pins.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/03%20pins.png)

  * I had no female/female jumper cable and I was unable to connect ultrasound sensor directly to shield. That's why I took old 40 pins computer cable, dismounted it, and created smallest breadboard in the world:

![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/04%20breadboard.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/04%20breadboard.png)

I had to solder every two pins(they used to be connected to the cable). Here's the breadboard in action:

![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/05%20breadboard.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/05%20breadboard.png)

  * Robot with the breadboard and sensor connected:
![http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/06%20robot.png](http://sandboxduino.googlecode.com/svn/trunk/SelfDrivingRobot/Stage2/06%20robot.png)

  * Unfortunately standard 9v cell is not enough for two motors and servo, so I had to use 9.6V battery pack to drive a robot. Arduino has it's own 9v battery.