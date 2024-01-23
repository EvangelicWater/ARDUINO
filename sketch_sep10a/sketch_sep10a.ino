int pinpuls = 4, pinpuls2 =5; // VARIABLE Y PIN DEL PULSADOR 
int led3 = 3; // PINS DE CONEXIÓN DEL LED
int led6 =6;
int led7 =7;
int led8 =8;
int led9 =9;
int potVal;
int dt =200;
int light;

void setup() {
  
  //CONFIGURACIÓN DE LOS LEDS
  
pinMode (led3, OUTPUT);
pinMode (led6, OUTPUT);
pinMode (led7, OUTPUT);
pinMode (led8, OUTPUT);
pinMode (led9, OUTPUT);



  //CONFIGURACIÓN DEL PULSADOR
  pinMode (pinpuls, INPUT);
  pinMode (pinpuls2, INPUT);
}

void loop() {


if(digitalRead(pinpuls)==LOW&&digitalRead(pinpuls2)==LOW){
    digitalWrite (led3, LOW); // LED3 = OFF
    digitalWrite (led6, LOW); // LED3 = OFF
    digitalWrite (led7, LOW); // LED3 = OFF
    digitalWrite (led8, LOW); // LED3 = OFF
    digitalWrite (led9, LOW); // LED3 = OFF
}
else if(digitalRead(pinpuls)==LOW&&digitalRead(pinpuls2)==HIGH){
    
   digitalWrite (led3,HIGH);
   digitalWrite (led6,HIGH);
    digitalWrite (led7, LOW); // LED3 = OFF
    digitalWrite (led8, LOW); // LED3 = OFF
    digitalWrite (led9, LOW); // LED3 = OFF
}
else if(digitalRead(pinpuls)==HIGH&&digitalRead(pinpuls2)==LOW){
    digitalWrite (led3, LOW); // LED3 = OFF
    digitalWrite (led6, LOW); // LED3 = OFF
    digitalWrite (led7,HIGH);
    digitalWrite (led8,HIGH);
    digitalWrite (led9,HIGH);
    
    
}
else if(digitalRead(pinpuls)==HIGH&&digitalRead(pinpuls2)==HIGH){
   digitalWrite(led3,HIGH);
   digitalWrite(led6,HIGH);
   digitalWrite(led7,HIGH);
   digitalWrite(led8,HIGH);
   digitalWrite(led9,HIGH);
 
    
   

}



  

 

}
