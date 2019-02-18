/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
//Servo myservo2;
// twelve servo objects can be created on most boards
/*void vueltaDerecha(int tiempo){
  myservo.write(180);
  myservo2.write(120);
  delay(tiempo);
}
void recto(int tiempo){
  myservo.write(180);
  myservo2.write(0);
  delay(tiempo);
}
void reversa(int tiempo){
  myservo.write(0);
  myservo2.write(180);
  delay(tiempo);
}
void vueltaIzquierda(int tiempo){
  myservo.write(120);
  myservo2.write(180);
  delay(tiempo);
}
void detener(int tiempo){
  myservo.write(90);
  myservo2.write(90);
  delay(tiempo);
}*/
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  //myservo2.attach(8);
}

void loop() {
  //recto(5000);
  //detener(2000);
  for (pos = 0; pos <= 10; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(180); // tell servo to go to position in variable 'pos'
    //myservo2.write(0);
    delay(300);                       // waits 15ms for the servo to reach the position
  }
  myservo.write(90);
  //myservo2.write(90);
  delay(350);
 /*for (pos = 0; pos <= 10; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(60); // tell servo to go to position in variable 'pos'
    myservo2.write(120);
    delay(300);                       // waits 15ms for the servo to reach the position
  }
  myservo.write(90);
  myservo2.write(90);
  delay(350);*/
}
