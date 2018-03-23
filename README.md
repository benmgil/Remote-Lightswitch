# Arduino-Mac-Script-Runner


## About
I thought those smart-home-ish type automatic light switch things were pretty cool and convenient, so I decided to build an imitation of that. It developed into a box that can clip onto the front of a light switch, and it is powered by an Arduino and two servo motors. Rather than voice control, I used an infrared remote. It was easier to implement.


## Build the Arduino circuit
The circuit looks as follows:

![Circuit](https://github.com/benmgil/Remote-Lightswitch/blob/master/circuit.png)

## Upload the code
You will need to replace the values of the infrared signals in the code to the ones that your remote sends. Every remote is different. To find out what values your remote is sending, open the Serial Monitor in the Arduino IDE. I had the code print the values that it was receiving.

## Mount the circuit
You will need to mount this to your light switch in order for the motors to be able to press it. I found an old aluminum box and put the entire circuit inside that, and cut holes for the servod to poke through. You can see it below:

![Mount](https://github.com/benmgil/Remote-Lightswitch/blob/master/lightswitch.jpg)
I had to take the circuit out of the breadboard in order for it to fit inside the box, but that's just because I wanted it to be smaller. You can put it together yourself however you want.
