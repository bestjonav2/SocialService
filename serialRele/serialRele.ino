

int Roption2;
boolean LED1 = false;
boolean LED2 = false;
int led = 8;
int led2 = 7;
void setup(){
  //iniciamos el puerto serie
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(100);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}
 
void loop(){
  /*digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
  delay(1000);*/
  if(Serial1.available()){
    Roption2 = Serial1.read();
    
    if(Roption2==1){
      if(LED1){
        digitalWrite(led,LOW);
        LED1 = false;
      }
      else{
        digitalWrite(led,HIGH);
        LED1 = true;
      }
    }   
    if(Roption2==2){
      if(LED2){
        digitalWrite(led2,LOW);
        LED2 = false;
      }
      else{
        digitalWrite(led2,HIGH);
        LED2 = true;
      }
    }   
    //while (Serial.available()>0)  Serial.read();
  }
  //delay(100);
}
