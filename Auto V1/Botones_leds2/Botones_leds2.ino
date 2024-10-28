#define BOT1 2
#define BOT2 3
#define BOT3 9
#define BOT4 6
#define LED1 7
#define LED2 4
#define LED3 13
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
  if (digitalRead(BOT1) == LOW) {
    Serial.println("bot1");
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  if (digitalRead(BOT2) == LOW) {
    Serial.println("bot2");
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  if (digitalRead(BOT3) == LOW) {
    Serial.println("bot3");
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  if (digitalRead(BOT4) == LOW) {
    Serial.println("bot4");
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }
}
