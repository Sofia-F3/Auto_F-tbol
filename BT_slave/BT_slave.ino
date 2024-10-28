#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial modu(TXD, RXD);

void setup() {
  modu.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //IMPORTANTE: SERIAL A 9600 Y MODU A 38400 || SERIAL A 9600 Y MODU A 9600 --> depende de cómo venga configurado
  if (modu.available()) {
    Serial.write(modu.read());
  }
  if (Serial.available()) {
    modu.write(Serial.read());
  }
}
