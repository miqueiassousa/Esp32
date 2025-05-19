#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Brad";
const char* password = "catingueiro";

WebServer server(80);

const int ledPin1 = 4;
const int ledPin2 = 21;
const int ledPin3 = 22;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led1", led1);
  server.on("/led2", led2);
  server.on("/led3", led3);
  server.on("/desligarTudo", desligarTudo);

  server.begin();
  Serial.println("Servidor iniciado!");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <title>Controle de LED</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; margin-top: 50px; }
      button { padding: 12px 24px; margin: 10px; font-size: 16px; }
      body {background-color: black; color: white}
    </style>
    <script>
      function enviarComando(rota) {
        fetch(rota)
          .then(response => response.text())
          .then(data => {
            document.getElementById('status').innerText = data;
          });
      }
    </script>
  </head>
  <body>
    <h1>Controle dos LEDs</h1>
    <button onclick="enviarComando('/led1')">Ligar LED 1</button>
    <button onclick="enviarComando('/led2')">Ligar LED 2</button>
    <button onclick="enviarComando('/led3')">Ligar LED 3</button>
    <button onclick="enviarComando('/desligarTudo')">Desligar Tudo</button>
    <p id="status">Aguardando comando...</p>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void led1() {
  digitalWrite(ledPin1, HIGH);
  server.send(200, "text/plain", "LED 1 ligado");
}

void led2() {
  digitalWrite(ledPin2, HIGH);
  server.send(200, "text/plain", "LED 2 ligado");
}

void led3() {
  digitalWrite(ledPin3, HIGH);
  server.send(200, "text/plain", "LED 3 ligado");
}

void desligarTudo() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  server.send(200, "text/plain", "Todos os LEDs desligados");
}
