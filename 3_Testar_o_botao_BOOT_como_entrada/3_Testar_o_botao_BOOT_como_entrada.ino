// Você pode usar o botão BOOT da própria placa como um "sensor" de entrada:
// O botão BOOT geralmente está ligado no GPIO0 e funciona como entrada digital com INPUT_PULLUP.

#define BOTAO 0  // GPIO0 é o botão BOOT

void setup() {
  pinMode(BOTAO, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(BOTAO) == LOW) {
    Serial.println("Botão BOOT pressionado!");
  } else {
    Serial.println("Botão solto.");
  }
  delay(300);
}
