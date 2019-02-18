/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;
Servo myservo2;// create servo object to control a servo
boolean distanciaState = true;
boolean buttonState = true;
int pin_in = 6;
int pin_out = 7;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
long duration;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(8);
  Serial.begin(9600);
  pinMode(10,INPUT_PULLUP);
  pinMode(pin_in,OUTPUT);
  pinMode(pin_out,INPUT);
}

void loop() {

  while(buttonState){
    while(distanciaState){
      for (pos = 0; pos <= 1; pos += 1) { // goes from 180 degrees to 0 degrees
        myservo.write(140);
        myservo2.write(140);// tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      //vueltaIzquierda(50);
      if(digitalRead(10)==0){
        buttonState = false;
        break;
      }
      distancia();
      if(duration<1500){
        distanciaState = false;
      }
    }
    myservo.write(90);
    myservo2.write(90);
    distancia();
    if(duration>1500)
    {
        distanciaState = true;
        duration = 1800;
    }
    if(duration<1500)
    {
      while(true){
        myservo.write(80);
        myservo2.write(80);
        delay(800);
        myservo.write(90);
        myservo2.write(65);
        delay(1000);
        distancia();
        if(duration>1500){
          myservo.write(90);
          myservo2.write(90);
          delay(1000);
          distanciaState = true;
          break;
        }
        if(digitalRead(10)==0){
        break;
        }
      }
    }
    if(digitalRead(10)==0){
        break;
    }
  }
}
void vueltaDerecha(int tiempo){
  for(int i= 0;i<=tiempo;i++){
    myservo.write(100);
    myservo2.write(110);
    delay(15);
  }
}
void vueltaIzquierda(int tiempo){
  for(int i= 0;i<=tiempo;i++){
    myservo.write(110);
    myservo2.write(100);
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
}
