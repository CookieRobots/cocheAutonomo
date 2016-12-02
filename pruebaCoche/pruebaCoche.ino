/* 
 *  Coche con movimientos preprogramados
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

Servo direccion;  // crea el objeto direccion de la clase Servo
int pos = CENTRO;    // variable para almacenar la posicion del servo

void setup() {
  direccion.attach(3);  // El servo está conectado al pin 3
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


