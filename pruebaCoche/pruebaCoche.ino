/* 
 *  Coche
 *  
 *  
*/
#include <Servo.h>




//constantes del SERVO
#define DERECHA 53
#define CENTRO 75
#define IZQUIERDA 100

#define TIEMPO 900
#define POTENCIA 200

//contsantes del MOTOR
int IN3 = 12;    // Input3 conectada al pin 12
int IN4 = 10;    // Input4 conectada al pin 10
int ENB = 11;    // ENB conectada al pin 11 de Arduino para PWM

Servo direccion;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = CENTRO;    // variable to store the servo position

void setup() {
  direccion.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode (ENB, OUTPUT); 
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  delay(20000);
}

void loop() {

  atras(POTENCIA);
  delay(250);
  adelante(POTENCIA);
  delay(TIEMPO);
   atras(POTENCIA);
  delay(TIEMPO+100);

  gira(DERECHA);

  adelante(POTENCIA);
  delay(TIEMPO);
   atras(POTENCIA);
  delay(TIEMPO+100);

  gira(IZQUIERDA);

  adelante(POTENCIA);
  delay(TIEMPO);
   atras(POTENCIA);
   delay(TIEMPO+100);

   
   freno();
  delay(TIEMPO*200);
  

  /*
  for (pos = MIN; pos <= MAX; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    direccion.write(pos);              // tell servo to go to position in variable 'pos'
    delay(tiempo);                       // waits 15ms for the servo to reach the position
  }
    delay(500);

  for (pos = MAX; pos >= MIN; pos -= 1) { // goes from 180 degrees to 0 degrees
    direccion.write(pos);              // tell servo to go to position in variable 'pos'
    delay(tiempo);                       // waits 15ms for the servo to reach the position
  }
      delay(500);
*/
}


void atras(int velocidad)
{
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(ENB,velocidad);
}
void adelante(int velocidad)
{
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(ENB,velocidad);
}
void freno()
{
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}

void gira(int pos)
{
   direccion.write(pos); 
}


