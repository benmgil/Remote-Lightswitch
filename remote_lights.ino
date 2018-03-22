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
const int topOff = 30;
const int botOn = 90;
const int botOff = 60;
int counter = 0;
boolean done = true;

void setup() {
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
  topButton = digitalRead(2);
  bottomButton = digitalRead(3);

  if (irrecv.decode(&results)){
     Serial.println(results.value);
     irrecv.resume(); 
    }
  int irVal = results.value;
  if(!done){
    counter ++;
  }
  if (counter > 1000){
    done = true;
  }
  
  if(results.value == 2368359343 && done){
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
