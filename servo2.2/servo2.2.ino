/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servoD;
Servo servoI;// create servo object to control a servo
boolean empezar = false;
boolean obstaculo = false;
int boton = 3;
int pin_in = 6;
int pin_out = 7;

int trigger = 11;
int echo = 10;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
long distancia;

void setup() {
  //attachInterrupt(digitalPinToInterrupt(boton), danger, FALLING);//interrupcion para bumpers
  servoD.attach(9);  // attaches the servo on pin 9 to the servo object
  servoI.attach(8);
  Serial.begin(9600);
  pinMode(pin_in,OUTPUT);
  pinMode(pin_out,INPUT);
  
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(3,INPUT_PULLUP);
}

void loop() {
   if(digitalRead(3)==0){
      delay(2000);
      empezar = true;
   }
   if(empezar){
      avanzar(120);
   }
   Serial.println(distanciaF());
   if(distanciaF()<40){
      obstaculo = true;
   }
   if(obstaculo && empezar){
      detener(1000);
      vueltaIzquierda(1000);
      obstaculo=false;
   }
}
void vueltaDerecha(int tiempo){
   servoD.write(90);
   servoI.write(140);
   delay(tiempo);
}
void vueltaIzquierda(int tiempo){
    servoD.write(140);
    servoI.write(90);
    delay(tiempo);
}
long distanciaF(){
  digitalWrite(pin_in, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_in, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_in, LOW);
  distancia = pulseIn(pin_out,HIGH);
  distancia = distancia/58;
  //delay(20);
  return distancia;
}
long distanciaL(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  distancia = pulseIn(echo,HIGH);
  distancia = distancia/58;
  //delay(20);
  return distancia;
}
void reversaD(int tiempo){
  servoD.write(90);           
  servoI.write(65);
  delay(tiempo);
}
void reversaI(int tiempo){
  servoD.write(65);           
  servoI.write(90);
  delay(tiempo);
}
void detener(int time){
    servoD.write(90);           
    servoI.write(90);
    delay(time);
}
void avanzar(int vel){
    servoD.write(vel);           
    servoI.write(vel);
}
