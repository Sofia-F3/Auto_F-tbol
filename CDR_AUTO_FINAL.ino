#include <SoftwareSerial.h>
#include <TimerOne.h>

#define IN1 7
#define IN2 8
#define IN3 4
#define IN4 5
#define EN 6
#define EN2 3
#define TXD 11
#define RXD 10

SoftwareSerial BT(TXD, RXD);

#define INIT 0
#define MANUAL 1
#define AUTO 2
int estadoAuto = 0;
int mSeg = 0;
char data;

void TIMER() {
  mSeg++;
}

void setup() {
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(EN2, OUTPUT);
  digitalWrite(EN, HIGH);
  digitalWrite(EN2, HIGH);
  Serial.begin(9600);
  BT.begin(9600);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(TIMER);
}

void loop() {
  if (BT.available()) {
    data = BT.read();
    Serial.println(data);
  }
  maquinaAuto();
}

void maquinaAuto() {
  switch (estadoAuto) {
    case INIT:
      Stop();
      if (mSeg >= 3000) {
        estadoAuto = MANUAL;
      }
      break;

    case MANUAL:
      if (data == 'S') {
        Stop();
      }
      if (data == 'R') {
        Right();
      }
      if (data == 'L') {
        Left();
      }
      if (data == 'F') {
        Forward();
      }
      if (data == 'B') {
        Back();
      }
      break;
  }
}

void Right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Forward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Back(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}