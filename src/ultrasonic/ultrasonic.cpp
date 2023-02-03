#include "ultrasonic.h"

void setupUltrasonic(){
    pinMode(TRIG_PIN_1, OUTPUT);
    pinMode(ECHO_PIN_1, INPUT);
    pinMode(TRIG_PIN_2, OUTPUT);
    pinMode(ECHO_PIN_2, INPUT);
    pinMode(TRIG_PIN_3, OUTPUT);
    pinMode(ECHO_PIN_3, INPUT);
    Serial.println(": LOG : Ultrasonic setup complete");
}

float capturedistance(int trig_pin, int echo_pin){
    long duration;
    float distanceCm;

    // Send pulse
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);

    // Read the echo pin
    duration = pulseIn(echo_pin, HIGH);
    distanceCm = duration * SOUND_SPEED/2;
    return distanceCm;
}