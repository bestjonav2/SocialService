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
    Serial.readBytesUntil(' ',letras, 64);
    Serial.print("Jona: ");
    Serial.println(letras);
    Serial1.write(letras);
    Serial.flush();
    Serial1.flush();
    //while (Serial.available()>0)  Serial.read();
    delay(100);
  }
  if(Serial1.available()){
    Serial1.readBytesUntil(' ',letras, 64);
    Serial.print("Uziel: ");
    Serial.println(letras);
    //while (Serial1.available()>0)  Serial1.read();
    /*Roption=Serial1.readString();
    Serial.print("Jona: ");
    Serial.println(Roption);
    Serial1.flush();*/
  }
  //delay(100);
}
