#define BOT1 12
#define BOT2 9
#define BOT3 8
#define BOT4 7
#define LED1 3
#define LED2 4
#define LED3 6
#define LED4 5

void setup() {
  Serial.begin(9600);
  pinMode(BOT1, INPUT_PULLUP);
  pinMode(BOT2, INPUT_PULLUP);
  pinMode(BOT3, INPUT_PULLUP);
  pinMode(BOT4, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  if (digitalRead(BOT1) == LOW){
    digitalWrite(LED1, HIGH);
    Serial.println("bot1");
  } else {
    digitalWrite(LED1, LOW);
  }
  if (digitalRead(BOT2) == LOW){
    digitalWrite(LED2, HIGH);
    Serial.println("bot2");
  } else {
    digitalWrite(LED2, LOW);
  }
  if (digitalRead(BOT3) == LOW){
    digitalWrite(LED3, HIGH);
    Serial.println("bot3");
  } else {
    digitalWrite(LED3, LOW);
  }
  if (digitalRead(BOT4) == LOW){
    digitalWrite(LED4, HIGH);
    Serial.println("bot4");
  } else {
    digitalWrite(LED4, LOW);
  }
  digitalWrite(LED1, HIGH);
}
