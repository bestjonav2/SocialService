#include <SoftwareSerial.h>

int option;
int optio2;
int led = 13;
SoftwareSerial Serie2(10,11); 

void setup(){
  //iniciamos el puerto serie
  Serial.begin(9600);
  Serie2.begin(9600); 
  pinMode(led, OUTPUT);
}
 
void loop(){
  if (Serial.available()>0){
    //leemos la opcion enviada
    option=Serial.read();
    if(option=='a') {
      digitalWrite(led, LOW);
      Serial.println("OFF");
    }
    if(option=='b') {
      digitalWrite(led, HIGH);
      Serial.println("ON");
    }
    if(option=='c') {
      Serie2.write("b");
    }
    if(option=='d') {
      Serie2.write("a");
    }
  }
if(Serie2.available()>0){
  option=Serie2.read();
    if(option=='a') {
      digitalWrite(led, LOW);
      Serie2.println("Otro : OFF");
    }
    if(option=='b') {
      digitalWrite(led, HIGH);
      Serie2.println("Otro : ON");
    }
  }
}
