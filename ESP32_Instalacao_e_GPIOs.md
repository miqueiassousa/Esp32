
# ESP32 - Instalação no Arduino IDE, Drivers e Portas Utilizáveis

## ✅ Instalação da Placa ESP32 no Arduino IDE

1. **Abra o Arduino IDE** (versão 1.8.x ou 2.x recomendada).
2. Vá em:  
   `Arquivo > Preferências`  
   ou  
   `Arduino IDE > Settings (Configurações)` no menu superior.
3. Em **"URLs Adicionais para Gerenciadores de Placas"**, adicione:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Clique em OK.
5. Vá em:  
   `Ferramentas > Placa > Gerenciador de Placas`
6. Procure por “**esp32**” e instale o pacote da **Espressif Systems**.
7. Após a instalação, selecione:  
   `Ferramentas > Placa > ESP32 Dev Module` (ou o modelo correspondente à sua placa).

---

## 🧰 Instalação do Driver USB (CH340 / CP2102 / FTDI)

A ESP32 utiliza um chip USB-Serial para comunicação. Sem o driver correto, a placa **não aparecerá como uma porta COM**.

### 🔍 Como identificar o chip

Verifique o nome no chip próximo à porta USB:

- `CH340G` → Driver da WCH
- `CP2102` → Driver da Silicon Labs
- `FTDI` → Driver FTDI

### 🖥️ Windows

#### CH340 (mais comum)

- Baixe: https://www.wch.cn/downloads/CH341SER_EXE.html
- Instale e reinicie o computador.

#### CP2102

- Baixe: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers

### 🐧 Linux

- Geralmente **não precisa de driver**.
- Verifique com:
  ```bash
  ls /dev/ttyUSB*  # CH340
  ls /dev/ttyS*    # UART padrão
  ```

### 🍎 macOS

- **CH340**:  
  https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver  
- **CP2102**:  
  https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers

---

## 🔌 GPIOs (Portas) Utilizáveis no ESP32

### 🟢 GPIOs recomendados para uso geral

| GPIO   | Usável? | Observações                          |
|--------|---------|--------------------------------------|
| 0      | ✔️       | Boot falha se HIGH (use com cuidado) |
| 2      | ✔️       | LED interno em algumas placas        |
| 4, 5   | ✔️       | Comuns para LEDs e sensores          |
| 12     | ⚠️       | Evitar HIGH no boot                  |
| 13–15  | ✔️       | PWM, SPI                             |
| 16–19  | ✔️       | IO digitais e analógicos             |
| 21     | ✔️       | SDA (I2C)                            |
| 22     | ✔️       | SCL (I2C)                            |
| 23     | ✔️       | GPIO normal                          |
| 25–27  | ✔️       | GPIOs comuns                         |
| 32–33  | ✔️       | GPIOs e ADC                          |

### ⚠️ GPIOs com restrições

| GPIO   | Restrição                                 |
|--------|--------------------------------------------|
| 6–11   | Reservados para memória flash              |
| 34–39  | Apenas entrada (não suportam OUTPUT)       |
| 36–39  | ADC apenas (sem pull-up ou saída digital)  |

---

## ⚙️ Exemplo: Piscar um LED no GPIO 4

```cpp
const int ledPin = 4;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
```

---

## 🔋 Alimentação

- **USB (5V)**: recomendada para testes.
- **Vin**: aceita 5V a 12V (regulado internamente para 3.3V).
- **Não use 9V direto no pino 3.3V** → risco de queimar o chip!

---

## 🛠️ Dicas Finais

- Use resistores de 220Ω a 330Ω em série com LEDs.
- Sempre conecte o **GND da expansão com o GND da ESP32**.
- Para GPIOs sensíveis no boot (0, 2, 12), use **resistores pull-down** de 10kΩ se necessário.
