//initialize libraries, global vars

#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

#include <Servo.h>
Servo topServo;
Servo bottomServo;
int topButton;
int bottomButton;
const int topOn = 0;
const int topOff = 30;   //These should be changed depending on how your servos are mounted
const int botOn = 90;    //For both the top servo and the bottom there is an on and and off value
const int botOff = 60;   //Those are the angles for the servo to be pressing the switch and not pressing the switch
int counter = 0;
boolean done = true;

void setup() {
  //more setup, moves both servos to the off (not pressed) position 
  topServo.attach(9);
  bottomServo.attach(10);
  Serial.begin(9600);
  topServo.write(topOff);
  bottomServo.write(botOff);
  delay(500);
  topServo.detach();
  bottomServo.detach();
  irrecv.enableIRIn();
  pinMode(4, OUTPUT);
}

void loop() {

  if (irrecv.decode(&results)){
     Serial.println(results.value);
     irrecv.resume(); 
    }
  int irVal = results.value;
  //reads the IR value from the remote


  //a real hacky way of not reading the next value from the IR until some time has passed for the servos to move
  //this allows the loop to keep running
  if(!done){
    counter ++;
  }
  if (counter > 1000){
    done = true;
  }
  
  if(results.value == 2368359343 && done){
    //press the top servo and then release it to press the top of the light switch (turning on the lights)
    //I attach and detach the servo to prevent them from running and wasting power in between remote commands
    done = false;
    counter = 0;
    topServo.attach(9);
    topServo.write(topOn);
    delay(500);
    topServo.write(topOff);
    delay(500);
    topServo.detach();
  }
  if (results.value == 472047109 && done){
    //the same but for pressing the bottom of the switch
    done = false;
    counter = 0;
    bottomServo.attach(10);
    bottomServo.write(botOn);
    delay(500);
    bottomServo.write(botOff);
    delay(500);
    bottomServo.detach();
  }
  results.value = 0; 
}
