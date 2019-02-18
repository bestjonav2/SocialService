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
boolean distanciaState = true;
boolean buttonState = true;
int boton = 3;
int pin_in = 6;
int pin_out = 7;

int trigger = 11;
int echo = 10;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
long duration;

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
  while(true){
    if(digitalRead(3)==0){
      delay(2000);
      break;
    }
  }
  while(distanciaState){
    servoD.write(140);        //movimiento hacia delente en ambos servos
    servoI.write(140);
    distancia();              //leemos la lectura del sensor ultrasonido
    //distancia2();
     Serial.print("RECTO:");
    Serial.println(duration);
    if(duration<30)        //si la duracion que recibimos del sensor ultrasonido es menor de 1500(obstaculo)
      distanciaState = false; //salimos del ciclo que mueve hacia delante
  }
  servoD.write(90);           //detenemos los servos
  servoI.write(90);
  distancia();                //leemos la lectura del sensor ultrasonido
  if(duration>1500)           //si la duracion que recibimos del sensor ultrasonido es mayor de 1500(obstaculo)
  {
      distanciaState = true;  //regresamos al cilclo recto
      duration = 1800;
  }
  //servoD.write(80);           //reversa
 // servoI.write(80);
  delay(800);                 //durante 800 milisegundos
  //reversaD(1000);             //reversa para la derecha
  reversaI(1150);
  while(true){
    servoD.write(120);
    servoI.write(120);
    delay(100);
    distancia2();                //volvemos
    Serial.print("IZ:");
    Serial.println(duration);
    if(duration>40){
      Serial.println("YA ENTRE");
      delay(200);
      servoD.write(140);
      servoI.write(90);
      delay(1000);
      //reversaD(1150);
      //servoD.write(90);
      //servoI.write(90);
      //delay(1000);
      distanciaState = true;
      break;
    }
  }
  
}
void vueltaDerecha(int tiempo){
  for(int i= 0;i<=tiempo;i++){
    servoD.write(100);
    servoI.write(110);
    delay(15);
  }
}
void vueltaIzquierda(int tiempo){
  for(int i= 0;i<=tiempo;i++){
    servoD.write(110);
    servoI.write(100);
    delay(15);
  }
}
void distancia(){
  digitalWrite(pin_in, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_in, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_in, LOW);
  duration = pulseIn(pin_out,HIGH);
  duration = duration/58;
  delay(20);
}
void distancia2(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo,HIGH);
  duration = duration/58;
  delay(20);
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
void danger(){
 while(true){
    servoD.write(90);           
    servoI.write(90);
  }
}
