int contador{ 0 };
#define InputNum 2

void setup() {
  for (int i{ 4 }; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(13, OUTPUT);
  Serial.begin(9700);
}

void loop() {
  if (digitalRead(InputNum) == 1) {
    contador++;
    digitalWrite(13, 1);
    delay(10);
    digitalWrite(13, 0);
  }

  Serial.println(contador);

  for (int i{ 0 }; i < 6; i++) {
    digitalWrite(4 + i, (contador >> (5 - i)) & 1);
  }

  delay(180);
}
