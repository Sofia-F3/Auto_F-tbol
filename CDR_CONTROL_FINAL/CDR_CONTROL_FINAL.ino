#include <SoftwareSerial.h>

#define BOT1 12
#define BOT2 9
#define BOT3 8
#define BOT4 7
#define LED1 3
#define LED2 4
#define LED3 6
#define LED4 5
#define JS_BOT 2
#define VRY A0
#define VRX A1
#define TXD 10
#define RXD 11

SoftwareSerial BT(TXD, RXD);

int x;
int y;
int movActual = 5;
int movUlt = 10;

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

  movUlt = movActual;

  if (x < 562 && x > 462 && y < 576 && y > 476) {
    movActual = 5;
  } else {
    if (x > 562) {
      movActual = 1;
    } else if (x < 462) {
      movActual = 2;
    } else if (y > 576) {
      movActual = 3;
    } else if (y < 476) {
      movActual = 4;
    }
  }

  if (movActual != movUlt) {
    switch (movActual) {
      case 1:
        BT.write('R');
        Serial.println("derecha");
        break;
      case 2:
        BT.write('L');
        Serial.println("izquierda");
        break;
      case 3:
        BT.write('B');
        Serial.println("atras");
        break;
      case 4:
        BT.write('F');
        Serial.println("adelante");
        break;
      case 5:
        BT.write('S');
        Serial.println("quieto");
        break;
    }
  }

  /*if (digitalRead(BOT1) == LOW) {
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
    }*/
}
