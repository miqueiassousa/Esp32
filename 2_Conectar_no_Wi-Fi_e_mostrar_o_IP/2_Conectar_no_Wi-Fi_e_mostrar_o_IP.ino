#include <WiFi.h>

const char* ssid = "Brad";
const char* password = "catingueiro";

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // nada aqui por enquanto
}
