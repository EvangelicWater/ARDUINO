 int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

float valor=0;
float mv=0;

  // Arduino pins used for the switches
  // S1 7
  // S2 6
  // S3 5
  // S4 4
 

  // State of each switch (0 or 1)
  int state[4];

  // Random values for LED state and delay
  long onoroff;
  long millisecs;

  // loop counters
  int i, j;



   void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

  

  void setup() {
    //
    //declarar pines de leds
    //

    pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

    
    // pins for switches are inputs
    // switches 1-4 on pins 7-4
    for (i = 7; i >= 4; i--) {
      pinMode(i, INPUT);
    }

    Serial.begin(9600);
  }

  void loop() {
  
    state[0]=digitalRead(0);
    state[1]=digitalRead(7);
    state[2]=digitalRead(6);
    state[3]=digitalRead(5);
   if(state[0]){

    digitalWrite(8,HIGH);
   // LEDS OND AND OFF
   //Pegar los leds declarados en on & off

    } else if (state[1]) {

      digitalWrite(9,HIGH);
    //LED RGB
       


   } else if (state[2]) {

        digitalWrite(10,HIGH);
      //motor a pasos

    }
    else if (state[3]) {

      digitalWrite(11,HIGH);
    //temperatura
    
   

  }
  }
