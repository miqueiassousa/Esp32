#include <Arduino.h>


#define led1 15
#define led2 4
#define led3 5
#define frequencia 15000  // 5000 hertz (Hz) Essa frequência é usada para configurar um sinal PWM (Pulse Width Modulation), que é uma forma de gerar uma saída analógica usando sinais digitais.
#define canal1 0          //Define o número do canal PWM a ser usado. Microcontroladores como o ESP32, por exemplo, têm vários canais de PWM disponíveis. Uso comum: Cada canal pode ser configurado com uma frequência e resolução diferentes, e pode controlar um pino de saída diferente.
#define canal2 1
#define canal3 2
#define resolucao 10  // 10 Bitis (1024) pode representar valores de 0 a 1023 (2¹⁰ = 1024 valores possíveis).pode representar valores de 0 a 1023 (2¹⁰ = 1024 valores possíveis).

void setup() {
  // ledcAttach(pino, canal, frequência, resolução);
  ledcAttach(led1, frequencia, resolucao);
  ledcAttach(led2, frequencia, resolucao);
  ledcAttach(led3, frequencia, resolucao);
}
void loop() {
  // Fade in
  for (int i = 0; i <= 1024; i++) {
    // Mudando o brilho dos led com PWM
    ledcWrite(led1, i);
    ledcWrite(led2, i);
    ledcWrite(led3, i);
    delay(5);
  }

  // Fade out
  for (int i = 1024; i >= 0; i--) {
    ledcWrite(led1, i);
    ledcWrite(led2, i);
    ledcWrite(led3, i);
    delay(5);
  }
}
