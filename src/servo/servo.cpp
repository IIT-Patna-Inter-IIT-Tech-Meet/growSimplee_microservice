#include "servo.h"

Servo myservo;

int value = 20;

void setup_servo(){
    myservo.attach(SERVO_MOTOR); 
}


void servo_block(){
    for (int i = 0 ; i <=90; i++){
        myservo.write(i);
        delay(15);
    }     
}


void servo_release(){
    for (int i = 90; i >= 0; i--){
        myservo.write(i); 
        delay(15)  ;
    }
}