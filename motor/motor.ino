#include <Stepper.h>
#define STEPS 100 

Stepper motor(STEPS, 8, 10, 9, 11); 

int pasos;
char val;
void setup() { 
Serial.begin(9600);
}

void loop() { 
  digitalWrite(4,HIGH);
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
