#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11
#define IN1 7
#define IN2 8
#define IN3 4
#define IN4 5
#define EN1 6
#define EN2 3

SoftwareSerial modu(TXD, RXD);
char accion = 's';

void setup() {
  modu.begin(9600);
  Serial.begin(9600);

  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
}

void loop() {
  //IMPORTANTE: SERIAL Y MODU A 9600
  if (modu.available()) {
    accion = modu.read();
  }
  Serial.println(accion);
  switch (accion) {
    case 'f':
      adelante();
      break;
    case 'b':
      atras();
      break;
    case 'l':
      izquierda();
      break;
    case 'r':
      derecha();
      break;
    case 's':
      freno();
      break;
  }
}

void derecha() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void izquierda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void adelante() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void atras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void freno() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
