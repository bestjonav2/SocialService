#include <SoftwareSerial.h>


String option;
int option2;
String Roption;
int Roption2;
int led = 13;
char letras[64];
void setup(){
  //iniciamos el puerto serie
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(100);
  pinMode(led, OUTPUT);
}
 
void loop(){
  if(Serial.available()){
    Roption2 = Serial.read();
    //Serial.println(Roption2);
    if(Roption2 == 49){
      Serial1.write(1);
      Serial.println(Roption2);
    }
    if(Roption2 == 50){
      Serial1.write(2);
      Serial.println(Roption2);
    }
    if(Roption2 == 51){
      Serial1.write(3);
      Serial.println(Roption2);
    }
    if(Roption2 == 52){
      Serial1.write(4);
      Serial.println(Roption2);
    }
    Serial.flush();
    Serial1.flush();
    //while (Serial.available()>0)  Serial.read();
  }
}
