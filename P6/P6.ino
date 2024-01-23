#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char password[5];
char realpassword[7]= "1234";
byte index=0;
byte bandera=0;

void setup(){
  Serial.begin(9600);
  pinMode(12,OUTPUT);//VERDE
  pinMode(13,OUTPUT);//ROJO
  pinMode(11,OUTPUT);//AMARILLO
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.println(key);
    password[index]= key;
    index++;
  }
  if (index==4){
    byte check =0;
      for(int i=0;i<4;i++){
        Serial.print(password[i]);
        if (password[i]==realpassword[i]){
          check++;
        }
      }   
    
      if(bandera>=3){
        digitalWrite(11,HIGH);
        digitalWrite(13,LOW);
        digitalWrite(11,LOW);
        if (check== 4) {
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        Serial.println("CORRECTO");
        delay(500);
        digitalWrite(12,LOW);
        bandera=0;
        
      }else{
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("INCORRECTO");
        delay(500);
        digitalWrite(13,LOW);
        bandera++;
      }
      index=0;
    if(bandera>=3){
        digitalWrite(11,HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("ALARMA");
        delay(500);
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        Serial.println("ALARMA");
        delay(500);
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("ALARMA");
        delay(500);
        digitalWrite(13,LOW);
    
       
       
    }
      }

      else{
        digitalWrite(11,LOW);
        digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        if (check== 4) {
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        Serial.println("CORRECTO");
        delay(500);
        digitalWrite(12,LOW);
        bandera=0;
        
      }else{
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("INCORRECTO");
        delay(500);
        digitalWrite(13,LOW);
        bandera++;
      }
      index=0;
    if(bandera>=3){
       digitalWrite(11,HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("ALARMA");
        delay(500);
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        Serial.println("ALARMA");
        delay(500);
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Serial.println("ALARMA");
        delay(500);
        digitalWrite(13,LOW);
      
    }
      }
  }
}
