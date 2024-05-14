#define vrx A1
#define vry A0
#define sw 12

int x;
int y;
int p; 

void setup() {
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  x = analogRead(vrx);
  y = analogRead(vry);

  if (x < 562 && x > 462 && y < 576 && y > 476){
    Serial.println("quieto");
  } else {
    if (x > 562){
    Serial.println("derecha");
    } else if (x < 462){
    Serial.println("izquierda");
    } else if (y > 576){
    Serial.println("atras");
    } else if (y < 476){
    Serial.println("adelante");
    }
  }

  if (digitalRead(sw) == LOW){
    Serial.println("Pulsado");
  }
}
