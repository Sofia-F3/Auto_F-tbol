#include <SoftwareSerial.h>

#define BOT1 2
#define BOT2 3
#define BOT3 9
#define BOT4 6
#define LED1 7
#define LED2 4
#define LED3 13
#define LED4 5
#define JS_BOT 12
#define VRY A0
#define VRX A1
#define TXD 11
#define RXD 10

SoftwareSerial BT(TXD, RXD);

int x;
int y;

void setup() {
  pinMode(BOT1, INPUT_PULLUP);
  pinMode(BOT2, INPUT_PULLUP);
  pinMode(BOT3, INPUT_PULLUP);
  pinMode(BOT4, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(JS_BOT, INPUT_PULLUP);
  pinMode(VRY, INPUT);
  pinMode(VRX, INPUT);
  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  enviarBT();
}

void enviarBT() {
  x = analogRead(VRX);
  y = analogRead(VRY);

  if (x < 562 && x > 462 && y < 576 && y > 476) {
    Serial.println("quieto");
    BT.write('S'); //stop
  } else {
    if (x > 562) {
      Serial.println("derecha");
      BT.write('R'); //right
    } else if (x < 462) {
      Serial.println("izquierda");
      BT.write('L'); //left
    } else if (y > 576) {
      Serial.println("atras");
      BT.write('B'); //back
    } else if (y < 476) {
      Serial.println("adelante");
      BT.write('F'); //forward
    }
  }

  if (digitalRead(BOT1) == LOW) {
    Serial.println("uno");
    BT.write('U'); //uno
  }
  if (digitalRead(BOT2) == LOW) {
    Serial.println("dos");
    BT.write('D'); //dos
  }
  if (digitalRead(BOT3) == LOW) {
    Serial.println("tres");
    BT.write('T'); //tres
  }
  if (digitalRead(BOT4) == LOW) {
    Serial.println("cuatro");
    BT.write('C'); //tres
  }
}
