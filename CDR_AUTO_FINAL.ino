#include <SoftwareSerial.h>
#include <TimerOne.h>

#define A1 7
#define A2 4
#define B1 2
#define B2 3
#define TXD 10
#define RXD 11

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
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
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

void Forward() {
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
}

void Back() {
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
}

void Left() {
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
}

void Right() {
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
}

void Stop() {
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}
