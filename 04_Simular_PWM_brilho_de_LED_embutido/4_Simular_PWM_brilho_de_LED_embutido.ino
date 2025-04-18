// Você pode usar analogWrite() com ledcWrite() no ESP32 (já que analogWrite() não é padrão nele).
// Isso simula um fade de LED bem suave – ótimo pra entender PWM!
// Pulse Width Modulation

const int ledPin = 5;  // GPIO2 (LED interno em muitas placas ESP32)
const int frequencia = 5000;
const int resolucao = 8;


void setup() {
  ledcAttach(ledPin, frequencia, resolucao);       // Canal 0, 5kHz, 8 bits
  // ledcAttachPin(ledPin, 0);    // Associa o pino ao canal 0
}

void loop() {
  // Fade in
  for (int brilho = 0; brilho <= 255; brilho++) {
    ledcWrite(ledPin, brilho);
    delay(5);
  }
  
  // Fade out
  for (int brilho = 255; brilho >= 0; brilho--) {
    ledcWrite(ledPin, brilho);
    delay(5);
  }
}

