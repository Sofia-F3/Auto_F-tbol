#include <SoftwareSerial.h>

#define IN1 7
#define IN2 8
#define IN3 4
#define IN4 5
#define EN 6
#define EN2 3
#define TXD 11
#define RXD 10

SoftwareSerial BT(TXD, RXD);

char data;

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
}

void loop() {
  if (BT.available()) {
    data = BT.read();
    
  }
  maquinaAuto();
}

void maquinaAuto() {
  if (data == 'S') {
    Serial.println(data);
    Stop();
  }
  if (data == 'R') {
    Serial.println(data);
    Right();
  }
  if (data == 'L') {
    Serial.println(data);
    Left();
  }
  if (data == 'F') {
    Serial.println(data);
    Forward();
  }
  if (data == 'B') {
    Serial.println(data);
    Back();
  }
}

void Right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Forward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Back() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
