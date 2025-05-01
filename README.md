Arduino Traffic Light Countdown
Yo, this is my Arduino project! It’s a traffic light countdown using a TM1637 display and two ultrasonic sensors. Basically, it counts down from 30 secs when both sensors detect something close, speeds up the countdown if both are triggered, and switches lights (red, yellow, green) based on time. Made it for fun—could be cool for a mini traffic setup or just to mess around!
What You Need

Arduino Uno (or any compatible board)
TM1637 4-Digit Display
2 Ultrasonic Sensors (HC-SR04)
LEDs: Red, Yellow, Green (with resistors, like 220Ω)
Jumper wires and a breadboard
USB cable to power it

Libraries

TM1637Display: Grab it from Arduino IDE (Sketch > Include Library > Manage Libraries)

Wiring



Arduino Pin
Component



A0
TM1637 CLK


A1
TM1637 DIO


6
Sensor 1 TRIG


7
Sensor 1 ECHO


8
Sensor 2 TRIG


9
Sensor 2 ECHO


3
Red LED


4
Yellow LED


5
Green LED


GND
LEDs & Sensors GND


5V
Sensors VCC


Note: Stick the LEDs with resistors to avoid frying them. Sensors need 5V, so double-check your power setup.
How to Set It Up

Clone this repo
Open the .ino file in Arduino IDE.
Pick your Arduino board (Tools > Board > Arduino Uno).
Install the TM1637Display library if you haven’t.
Upload the code—hit that upload button!

How It Works

Starts with a 30-sec countdown on the display.
Sensors check distance (under 10cm = blocked).
If both sensors are blocked, countdown drops 2 secs per cycle.
If just one or none, it’s 1 sec per cycle.


Red light stays on above 5 secs, then switches to green.
After countdown hits 0, yellow lights up for 20 secs, then back to red.
Display shows the countdown flipped (cool effect I added!).
License
MIT License—do whatever with it, just give me a nod! Check LICENSE.
Tips

If the display looks funky, tweak the brightness (it’s set to 7 now).
Sensors acting up? Make sure they’re not too close to each other.
Hit me up on GitHub if it’s glitchy—I’m still figuring stuff out!

Peace out, have fun coding! 🚦
