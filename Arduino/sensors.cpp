#include "sensors.h"
void scan(){
  String data = "";
  int d;
  d = distance(FRONT);
  Serial.write(d);

  d = distance(RIGHT);
  Serial.write(d);

  d = distance(LEFT);
  Serial.write(d);
}

void sensorsSetup(){
  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(LEFT_TRIG, OUTPUT);
  
  pinMode(FRONT_ECHO, INPUT);
  pinMode(RIGHT_ECHO, INPUT);
  pinMode(LEFT_ECHO, INPUT);
}

float distance(int dir){
  float duration_us, distance_cm;

  switch(dir){
    case FRONT:
      trig(FRONT_TRIG);
      duration_us = pulseIn(FRONT_ECHO, HIGH); 
      break;
   case RIGHT:
      trig(RIGHT_TRIG);
      duration_us = pulseIn(RIGHT_ECHO, HIGH); 
      break;
   case LEFT:
      trig(LEFT_TRIG);
      duration_us = pulseIn(LEFT_ECHO, HIGH); 
      break;
  }

  //Calculate distance
  distance_cm = 0.017 * duration_us;
  return (distance_cm);
}

void trig(int pinNumber){
  digitalWrite(pinNumber, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinNumber, LOW);
}
