/*  
 Iraduino-Ejemplo #6 DipSwitch
 Más información: http://tecdigitaldelbajio.com/productos1/arduino/iraduino.html
 Síguenos: https://www.facebook.com/TecnologiaDigitaldelBajio
 Tienda Virtual: http://tiendavirtual-tdb.com/
 Irapuato, Gto. 21 de febrero de 2016,  Tecnología Digital del Bajío
 */

/** Define las variables para los 4 interruptores, se conectan a los pueros análogicos **/  
#define SW1 A0
#define SW2 A1
#define SW3 A2
#define SW4 A3


// the setup function runs once when you press reset or power the board
int i,j;                  
  // Arreglo bidimensional para el display, orden de los segmentos: a, b, c, d, e, f, g, x, el display es ánodo común, para que encienda un led se envía un "0"

void setup() {
   
  for(i=8;i<11;i++){ //Ciclo para configurar cada uno de los PINES como de Salida.
     pinMode(i,OUTPUT);
  }
  pinMode(SW1, INPUT); pinMode(SW2, INPUT), pinMode(SW3, INPUT); pinMode(SW4, INPUT); /** Declara las variables para los switch como entradas **/
}
/** Función que recibe un digito del 0 al 9 y envía los códigos necesarios para mostarlo en un display **/
    
// the loop function runs over and over again forever
void loop() {
  int x, valor1, valor2, valor3, valor4, valorHEX;
  valor1 = digitalRead(SW1); valor2 = digitalRead(SW2); /** Instrucción para leer el estado de cada interruptor y lo almacena en 4 variables **/
  valor3 = digitalRead(SW3); valor4 = digitalRead(SW4);
  valorHEX = 0x0F & ((valor4 << 3) | (valor3 << 2) | (valor2 << 1) | valor1);  /*** Operaciones lógicas para "juntar" el estado de los 4 interruptores en una sola variable ****/
  switch(valorHEX) {  /** Switch para decodificar el valor de los interruptores ***/
    case 0x00:digitalWrite(8,HIGH); break;
    case 0x01:digitalWrite(9,HIGH); break;
    case 0x02:digitalWrite(10,HIGH); break;
    case 0x03:digitalWrite(11,HIGH); break;
    
  }      
}
