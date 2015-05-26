# self driving robot built based on toy saved from garage sale.

# Setup #
  * Arduino Uno [R3](https://code.google.com/p/sandboxduino/source/detail?r=3)
  * Parents Go Bot (available on amazon)
  * 9V battery to power arduino
  * HC-SR04 ultrasonic module
  * jumper wires(male/female + female/female)

# Goal #
I got this toy from my friend. He found it on a garage sale, so it was like 2$. Original toy comes with IR remote, but this one was missing it. Since it didn't do anything without a pilot I decided to rebuild it and give it some personality.

Original toy:

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/000.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/000.png)

I think this toy is worth buying new just to make it into self driving robot. It's 13$ on amazon, so fairly cheap and this is what you get in package:
  * two motors with gears(you would normally probably paid 10$ for it)
  * even more motors, one that turns the head, one that turns eyes, one that opens/closes eyes.
  * H bridges - yup, at least 4 full blown H bridges - equivalent of 20$ arduino motor shield.
  * plenty of LEDS,
  * few switches
  * IR pilot, receiver, processor that can be reused for other projects.
  * speaker

For this price it's really nice deal.

I need to mention that this toy is creepy. My 2 year old son is terrified of it. You don't want to buy it for your kids...

This is what you will see when you open the robot:

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/001.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/001.png)

Front:

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/002.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/002.png)

I have taken all the plastic off, disconnected LEDs and IR receiver.
It turned out that the black cable going from body to head, contains 5V, 9V, ground wires, and more wires that are connected to switches. Switches are used as sensors detecting tower rotation. FE when the tower(head) turns right it reaches switch that disconnects the motor etc.

Red cable is used to supply power to motors.

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/003.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/003.png)

All you need from black cable is those three wires:
BLACK: GND
ORANGE: 5V
RED : 9V

I cut away the rest of the wires from the black cable. You could potentially try to use switches to determine tower position, but I decided not to to it, just to simplify things a bit.

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/004.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/004.png)

Then, I removed processor and sound processor from the board:
![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/005.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/005.png)

This is how I connected arduino to H bridges
![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/005a.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/005a.png)

WIres have been soldered to a board and they will be connected to arduino output pins. High signal enables forward or backward for each motor.
I've checked that you can actually use 5V arduino output to turn on motors by connecting 5V wire to each of those points. Just by checking every point I figured out what is what.

Motor 1 and motor 2 are responsible for moving the toy. Motor 3 is responsible for turning the head.

I have decided to remove two motors. I have removed the one that was responsible for turning the head, and the one that was responsible for moving eyes left and right. I didn't want to turn the head to make things simpler. And I think the eyes motor's h bridge was broken. I was unable to figure out what was wrong there, so I just skipped it.

The next thing was to attach ultra sound sensor:

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/006.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/006.png)

I also sanded a piece of plastic that moved the head up and down, I didn't like it. It still opens and closes the eyes.

Attaching all the wires to arduino:

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/007.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/007.png)
![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/008.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/008.png)
![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/009.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/009.png)

This is how it looks like:

![http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/010.png](http://sandboxduino.googlecode.com/svn/trunk/ToyRobot/toy-robot/010.png)

Robot works fine, doesn't consume too much power, doesn't overheat. Arduino seems to be safe, nothing has happened to it so far, I did try it several times, everything works as expected.

Few notes:
  * MAKE SURE TO CONNECT ARDUINO GND WITH ROBOT GND. That's really important.
  * make sure to provide separate 9V power supply to Arduino. You could try to use toy batteries, but it might result in strange behaviors. As motor starts and consumes energy it lowers the battery voltage, and may even reset Arduino. It'a a good idea to have two power supplies.
  * you might remove processor and play with other processor output(put 5v on them to identify all the transistor switches. This is one thing I would do if I was about to do it again. If you manage to get some more information, please let me know. I will gladly post it.


<a href='http://www.youtube.com/watch?feature=player_embedded&v=1tBEmbXnFmM' target='_blank'><img src='http://img.youtube.com/vi/1tBEmbXnFmM/0.jpg' width='425' height=344 /></a>