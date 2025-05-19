#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Brad";
const char* password = "catingueiro";

WebServer server(80);
const int led1 = 4;
const int led2 = 22;
const int led3 = 21;

void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>Controle do LED</title>
      <style>
        body { font-family: Arial; text-align: center; background-color: #f0f0f0; margin-top: 50px; }
        h1 { color: #333; }
        button {
          font-size: 20px;
          padding: 10px 20px;
          margin: 20px;
          border: none;
          border-radius: 8px;
          cursor: pointer;
        }
        .led1, .led2, .led3 { background-color: green; color: white; }
        .desligarTudo { background-color: red; color: white; }
      </style>
    </head>
    <body>
      <h1>Controle do LED</h1>
      <button class="led1" onclick="enviarComando('led1')">Ligar Led1</button>
      <button class="led2" onclick="enviarComando('led2')">Ligar Led2</button>
      <button class="led3" onclick="enviarComando('led3')">Ligar Led3</button>
      <button class="desligarTudo" onclick="enviarComando('desligarTudo')">Desligar Tudo</button>
      <p id="status">Status: Desconhecido</p>

      <script>
        function enviarComando(estado) {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              document.getElementById("status").innerHTML = "Status: " + this.responseText;
            }
          };
          xhttp.open("GET", "/led?state=" + estado, true);
          xhttp.send();
        }
      </script>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleLed() {

  // String state = server.arg("state");
 String led = server.arg("state");  // Pegando o valor passado por argumento na URL

  if (led == "") {
    Serial.println("Nenhum estado recebido.");
    server.send(400, "text/plain", "Parâmetro 'estado' não fornecido.");
    return;
  }

  if (led == "led1") {
    digitalWrite(led1, HIGH);
    server.send(200, "text/plain", "Led1 Ligado");
  } else if (led == "led2") {
    digitalWrite(led2, HIGH);
    server.send(200, "text/plain", "Led2 Ligado");
  } else if (led == "led3") {
    digitalWrite(led3, HIGH);
    server.send(200, "text/plain", "Led3 Ligado");
  } else if (led == "desligarTudo") {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    server.send(200, "text/plain", "Todos Desligados");
  } else {
    Serial.println("Comando desconhecido: " + led);
    server.send(400, "text/plain", "Comando desconhecido");
  }

}

  void setup() {
    Serial.begin(115200);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nWiFi conectado!");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/led", handleLed);
    server.begin();
  }

  void loop() {
    server.handleClient();
  }
