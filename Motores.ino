#define A1 7
#define A2 4
#define B1 2
#define B2 3

void setup() {
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(B1, OUTPUT);
}

void loop() {
  adelante();
  delay(2000);
  atras();
  delay(2000);
  izquierda();
  delay(2000);
  derecha();
  delay(2000);
}

void adelante(){
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
}

void atras(){
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
}

void izquierda(){
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
}

void derecha(){
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, HIGH);
}

void freno(){
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}
