/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>  //LIBRERIA PARA CONTROLAR SERVOS

Servo servoD; //SERVO DE LA DERECHA
Servo servoI; //SERVO DE LA IZQUIERDA
boolean obstaculo = false;    //BANDERA PARA OBSTACULO
boolean buttonState = false;  //BANDERA PARA BOTON
int pin_in = 6;   //PIN DE ENTRADA PARA EL ULTRASONIDO
int pin_out = 7;  //PIN DE SALIDA PARA EL ULTRASONIDO
long distancia;   //VARIABLE PARA GUARDA LA DISTANCIA LEIDA DEL ULTRASONIDO

void setup() {
  servoD.attach(9);  //ASIGNAMOS PIN PARA EL SERVO DERECHO E IZQUIERDO
  servoI.attach(8);
  pinMode(3,INPUT_PULLUP);  //ASIGNAMOS PINES AL BOTON Y AL ULTRASONIDO
  pinMode(pin_in,OUTPUT);
  pinMode(pin_out,INPUT);
}

void loop() {
  if(digitalRead(3)==0){//ESCUCHAMOS EL BOTON E INICIAMOS LOS SERVOS CON 120
    servoD.write(120);
    servoI.write(120);
    delay(2000);
    buttonState = true;
  }
  distancia = distanciaF(); //ESCUCHAMOS Y GUARDAMOS LA DISTANCIA DESDE EL ULTRASONIDO
  if(buttonState && distancia>30 && distancia<70){//SI EL BOTON FUE PRESIONADO Y LA DISTANCIA ESTA ENTRE 30 Y 70CM DETENEMOS LOS SERVOS Y LEVANTAMOS LA BANDERA DE OBSTACULO
    obstaculo = true;
    servoD.write(90);
    servoI.write(90);
  }
  else{                           //SI NO ESTA ENTRE ESA DISTANCIA MOVEMOS LOS SERVOS HACIA ADELANTE O HACIA ATRAS
    if(buttonState && obstaculo){ //SI EL BOTON FUE PRECIONADO(SI YA INICIARON LOS SERVOS) Y HAY UN OBSTACULO
      if(distancia<40){           // Y SI LA DISTANCIA ES MENOR A 40CM ESCRIBIMOS LOS SERVOS HACIA ATRAS
        servoD.write(70);
        servoI.write(70);
      }else{
        if(distancia < 300)       //SI NO, CHECAMOS QUE NO ESCUCHE UNA LECTURA MAYOR A 300CM (POR POSIBLES PICOS DE ERROR)
          obstaculo = false;      //BAJAMOS BANDERA DE OBSTACULO PARA QUE SIGA HACIA ADELANTE
      }
    }
  }
  if(buttonState && !obstaculo){  //SI LA BANDERA DE OBSTACULO ESTA ABAJO ESBRIBIMOS EN LOS SERVOS 120(O SEA HACIA DELANTE  A VELOCIDAD MEDIA)
    servoD.write(120);
    servoI.write(120);
  }
  if(digitalRead(3)==0 && buttonState ){ //SI SE VUELVE A PRESIONAR EL BOTON DESPUES DE AVER INICIADO PARAMOS LOS SERVOS
    servoD.write(90);
    servoI.write(90);
    delay(2000);
    buttonState = false;
  }
}


long distanciaF(){            //METODO PARA CALCULAR DISTANCIA DEL SENSOR ULTRASONIDO
  digitalWrite(pin_in, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_in, HIGH);         //MANDAMOS SE;ALES A LOS PINES DEL SENOR ULTRASONICO PARA INICIAR LA TRANSFERENCIA
  delayMicroseconds(10);
  digitalWrite(pin_in, LOW);
  distancia = pulseIn(pin_out,HIGH); // LEEMOS EL TIEMPO DE VUELO
  distancia = distancia/58;          // CONVERTIMOS A DISTANCIA (CM)
  delay(100);
  return distancia;
}
