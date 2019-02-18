
const int datosPIN = 9;
const int datosPIN2 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);    //iniciar puerto serie
  pinMode(datosPIN , OUTPUT);  //definir pin como salida
  pinMode(8 , OUTPUT);  //definir pin como salida
}
void detener(){
    digitalWrite(9 , HIGH);   // poner el Pin en HIGH
    digitalWrite(8 , HIGH);   // poner el Pin en HIGH
    delayMicroseconds(1495);
    digitalWrite(9 , LOW);    // poner el Pin en LOW
    delayMicroseconds(5);
    digitalWrite(8 , LOW);   // poner el Pin en HIGH 
    delayMicroseconds(18500);
}
void vel(int puerto ,int velocidad1, int velocidad2, boolean ford){
  int tiempo;
  if(ford){
    switch(velocidad1){
      case 1:
        tiempo = 1555;
      break;
      case 2:
        tiempo = 1611;
      break;
      case 3:
        tiempo = 1666;
      break;
      case 4:
        tiempo = 1722;
      break;
      case 5:
        tiempo = 1777;
      break;
      case 6:
        tiempo = 1833;
      break;
      case 7:
        tiempo = 1888;
      break;
      case 8:
        tiempo = 1944;
      break;
      case 9:
        tiempo = 2000;
      break;
      default:
       tiempo = 1500;
       break;
    }
  }
  else
  {
    switch(velocidad1){
      case 1:
        tiempo = 1444;
      break;
      case 2:
        tiempo = 1388;
      break;
      case 3:
        tiempo = 1333;
      break;
      case 4:
        tiempo = 1277;
      break;
      case 5:
        tiempo = 1222;
      break;
      case 6:
        tiempo = 1166;
      break;
      case 7:
        tiempo = 1111;
      break;
      case 8:
        tiempo = 1055;
      break;
      case 9:
        tiempo = 1000;
      break;
      default:
       tiempo = 1500;
       break;
    }
  }
  if(velocidad1==velocidad2&&ford){
    int tiempo2 = 3000-tiempo;
    digitalWrite(puerto , HIGH);   // poner el Pin en HIGH
    digitalWrite(8 , HIGH);   // poner el Pin en HIGH
    delayMicroseconds(tiempo2);
    digitalWrite(8 , LOW);   // poner el Pin en HIGH
    delayMicroseconds(tiempo - tiempo2);
    digitalWrite(puerto , LOW);    // poner el Pin en LOW
    delayMicroseconds(20000-tiempo);
  }
  if(velocidad1==velocidad2&&!ford){
    int tiempo2 = 3000-tiempo;
    digitalWrite(puerto , HIGH);   // poner el Pin en HIGH
    digitalWrite(8 , HIGH);   // poner el Pin en HIGH
    delayMicroseconds(tiempo);
    digitalWrite(puerto , LOW);   // poner el Pin en HIGH
    delayMicroseconds(tiempo2-tiempo);
    digitalWrite(8 , LOW);    // poner el Pin en LOW
    delayMicroseconds(20000-tiempo2);
  }
  /*digitalWrite(puerto , HIGH);   // poner el Pin en HIGH
  digitalWrite(8 , HIGH);   // poner el Pin en HIGH
  delayMicroseconds(1000);
  digitalWrite(8 , LOW);   // poner el Pin en HIGH
  delayMicroseconds(1000);
  digitalWrite(puerto , LOW);    // poner el Pin en LOW
  delayMicroseconds(20000-tiempo);*/
}
void loop() {
  for(int i = 0;i<150;i++)
  {
    detener();
  }
  for(int i = 0;i<300;i++)
  {
    vel(datosPIN,9,9,true);
  }
  //vel(datosPIN2,9,false);
  /*digitalWrite(datosPIN , HIGH);   // poner el Pin en HIGH
  delayMicroseconds(2000); 
  digitalWrite(datosPIN , LOW);    // poner el Pin en LOW
  delayMicroseconds(18000);*/
  
}
