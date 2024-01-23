#include <SoftwareSerial.h>
#include <Stepper.h>
#define STEPS 100 

#include <Stepper.h>
#define STEPS 100 

Stepper motor(STEPS, 8, 10, 9, 11);

int pasos;
char val;

SoftwareSerial mySerial(5, 6); // RX, TX  


//     Pin 1/TXD          Pin 5

//     Pin 2/RXD          Pin 6

char myChar ; float valor=0;
float mv=0;

//todos las salidas LED se cambiaron a el puerto 13 debido a que con cada parte de la multipractica necesitaba reutiliizar puertos ya en uso

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);

  mySerial.println("mySerial OPEN");
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
  
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 pinMode(4,OUTPUT);
 pinMode(5,INPUT);

 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);  //Cambiar pin de leds para secuencia conforme este disponible
 pinMode(7,OUTPUT);
 pinMode(11,OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==LOW&&digitalRead(3)==LOW){   
   if(mySerial.available()){
  myChar = mySerial.read();
   switch(myChar){
    case 'a':
    
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
     digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
     digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    break;
    case 'b':
     digitalWrite(13,LOW);
    digitalWrite(13,LOW);
    digitalWrite(13,LOW);
    digitalWrite(13,LOW);
    break;
   }
   }
  }
  
   if(digitalRead(2)==LOW&&digitalRead(3)==HIGH){
    
    if(mySerial.available()){
      myChar = mySerial.read();
   switch(myChar){
    case 'r':   //rojo
    
    digitalWrite(13,255);
    digitalWrite(13,0);
     digitalWrite(10,0);
      
      break;
      case 'v': //verde
      digitalWrite(13,0);
      digitalWrite(13,255);
      digitalWrite(13,0);
      
      break;
      case 'a':  //azul
     digitalWrite(13,0);
     digitalWrite(13,0);
     digitalWrite(13,255);
     
     break;
     case 'b':  //blanco
     digitalWrite(13,255);
     digitalWrite(13,255);
     digitalWrite(13,255);
     
     break;
     case 'm':  //amarillo
     digitalWrite(13,255);
     digitalWrite(13,255);
     digitalWrite(13,0);
     
     break;
     case 'g':  //magenta
     digitalWrite(13,255);
     digitalWrite(13,0);
     digitalWrite(13,255);
     
     break;
   }
    }
  }

   if(digitalRead(2)==HIGH&&digitalRead(3)==LOW)  //en este caso que es el 01 el primer led 11 indica que se esta ejecutando bien el dipswitch, el segundo indica que se esta ejecutando la opcion por medio de la aplicacion y el tercero indica que se esta leyendo la temperatura
  {
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(13,HIGH);
   if(mySerial.available()){
      myChar = mySerial.read();
   switch(myChar){
    
   case 'a':
   {
    digitalWrite(13,LOW);
   }
   break;

   case 'b':
   {
    digitalWrite (13,LOW);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(13,HIGH);
   valor=analogRead(1);
  float mv=(valor/1024.0)*5000;
  float c= mv/10;
  Serial.print("Temperatura: ");
  Serial.println(c);
  delay(100);

  if(c>150){

    
    digitalWrite(13,HIGH);
      
  }else {
   
    digitalWrite(13,LOW);
     
  }
   

    
   }
    
    
  }
   }
  }

  if(digitalRead(2)==HIGH&&digitalRead(3)==HIGH){
    digitalWrite(4,HIGH);//bandera
    delay(500);
    digitalWrite(4,LOW);
    delay(500);
    digitalWrite(4,HIGH);
    if( Serial.available() ) {
val = Serial.read();
Serial.print(val);
if( val == '1' )
{
motor.setSpeed(200);
motor.step(5);
}
if( val == '2' )
{
motor.setSpeed(200);
motor.step(-5);
}
if( val == '3' )
{
motor.setSpeed(200);
motor.step(10);
}
if( val == '4' )
{
motor.setSpeed(200);
motor.step(-10);
}
if( val == '5' )
{
motor.setSpeed(200);
motor.step(15);
}
if( val == '6' )
{
motor.setSpeed(200);
motor.step(-15);
}
if( val == '7' )
{
motor.setSpeed(200);
motor.step(20);
}
if( val == '8' )
{
motor.setSpeed(200);
motor.step(-20);
}
if( val == 'A' )
{
motor.setSpeed(200);
motor.step(10);
}
if( val == 'B' )
{
motor.setSpeed(200);
motor.step(-10);
}

}


    
  }
  else {
   //apagar leds de serie o leds de prueba
  }

}
