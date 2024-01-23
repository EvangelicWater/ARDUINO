int pinpuls = 4, pinpuls2 =5; // VARIABLE DE LOS PULSADORES 
int led3 = 3; // PINS DE CONEXIÓN DEL LED
int led6 =6;
int led7 =7;
int led8 =8;
int led9 =9;
int potVal;
int dt =200;
int light;//VARIABLE PARA EL POTENCIOMETRO

void setup() {
  
  //CONFIGURACIÓN DE LOS LEDS
  
pinMode (led3, OUTPUT);
pinMode (led6, OUTPUT);
pinMode (led7, OUTPUT);
pinMode (led8, OUTPUT);
pinMode (led9, OUTPUT);
//CONFIGURACION DEL POTENCIOMETRO
pinMode (A0, INPUT);
Serial.begin(9600);

  //CONFIGURACIÓN DE LOS PULSADORES
  pinMode (pinpuls, INPUT);
  pinMode (pinpuls2, INPUT);
}

void loop() {

potVal=analogRead(A0);
Serial.println(potVal);
light=map(potVal,0,1023,0,255); 
if(digitalRead(pinpuls)==LOW&&digitalRead(pinpuls2)==LOW){
    digitalWrite (led3, LOW); 
    digitalWrite (led6, LOW); //SERIE 1
    digitalWrite (led7, LOW); 
    digitalWrite (led8, LOW); 
    digitalWrite (led9, LOW); 
}
if(digitalRead(pinpuls)==LOW&&digitalRead(pinpuls2)==HIGH){
    analogWrite(led3,light);
    analogWrite(led3,light);
                             //SERIE 2
    digitalWrite (led7, LOW); 
    digitalWrite (led8, LOW); 
    digitalWrite (led9, LOW); 
}
if(digitalRead(pinpuls)==HIGH&&digitalRead(pinpuls2)==LOW){
    digitalWrite (led3, LOW); 
    digitalWrite (led6, LOW); 
    analogWrite(led7,light);      //SERIE 3
    analogWrite(led8,light);
    analogWrite(led9,light);
    
}
if(digitalRead(pinpuls)==HIGH&&digitalRead(pinpuls2)==HIGH){
    analogWrite(led3,light);
    analogWrite(led6,light);
    analogWrite(led7,light);       //SERIE 4
    analogWrite(led8,light);
    analogWrite(led9,light);
    
   

}

  

 

}
