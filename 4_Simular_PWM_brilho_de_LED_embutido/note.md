# O que é PWM no ESP32?

## Introdução

PWM (Pulse Width Modulation), ou Modulação por Largura de Pulso, é uma técnica usada para controlar a quantidade de energia fornecida a dispositivos eletrônicos. No ESP32, essa técnica é muito utilizada para controlar motores, LEDs, buzinas e outros dispositivos que precisam de um sinal variável.

## Como funciona o PWM?

O PWM funciona como um **interruptor muito rápido**, que liga e desliga a alimentação de um dispositivo em alta velocidade. O tempo que o sinal fica ligado em comparação ao tempo que fica desligado é chamado de **ciclo de trabalho** ou **duty cycle**, e é representado em **percentual (%)**.

- **0%** → sinal sempre desligado  
- **50%** → metade do tempo ligado, metade desligado  
- **100%** → sinal sempre ligado

## Resolução em bits

No ESP32, você pode configurar a resolução do PWM, ou seja, quantos **níveis diferentes de duty cycle** você pode usar. Essa resolução é dada em **bits**, e funciona assim:

| Bits | Níveis possíveis | Valor para 50% |
|------|------------------|----------------|
| 8    | 256 (0 a 255)    | 128            |
| 10   | 1024 (0 a 1023)  | 512            |
| 12   | 4096 (0 a 4095)  | 2048           |

> Exemplo: Se você estiver usando **10 bits**, o valor do duty cycle vai de `0` a `1023`. Para gerar um sinal com **50% de duty cycle**, você deve usar o valor `512`.

## PWM no ESP32

O ESP32 possui **canais PWM** que podem ser configurados para gerar sinais com diferentes frequências e ciclos de trabalho. Isso permite, por exemplo, controlar o brilho de um LED ou a velocidade de um motor.

### Características principais:

- **Até 16 canais PWM** disponíveis  
- Frequência ajustável (até cerca de 40 MHz)  
- Resolução de até 16 bits  
- Pode ser aplicado em **qualquer pino digital**

## Exemplo prático: Controlando o brilho de um LED

Aqui está um exemplo de código usando Arduino IDE para controlar o brilho de um LED com PWM no ESP32, usando resolução de 8 bits:

```cpp
int ledPin = 16;        // Pino onde o LED está conectado
int canalPWM = 0;       // Canal PWM
int freq = 5000;        // Frequência em Hz
int resolucao = 8;      // Resolução de 8 bits (0-255)

void setup() {
  ledcAttach(canalPWM, freq, resolucao); // Configura o canal
}

void loop() {
  for (int brilho = 0; brilho <= 255; brilho++) {
    ledcWrite(canalPWM, brilho); // Define o ciclo de trabalho (brilho)
    delay(10);
  }
  for (int brilho = 255; brilho >= 0; brilho--) {
    ledcWrite(canalPWM, brilho);
    delay(10);
  }
}
