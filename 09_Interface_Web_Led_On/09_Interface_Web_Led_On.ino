#include <WiFi.h>       // Inclui a biblioteca para conexão WiFi
#include <WebServer.h>  // Inclui a biblioteca para criar um servidor web

// Substitua com suas credenciais WiFi
const char* ssid = "Brad";             // Nome da rede WiFi
const char* password = "catingueiro";  // Senha da rede WiFi

WebServer server(80);  // Cria um servidor web escutando na porta 80 (padrão HTTP)

const int ledPin1 = 4;  // Define o pino 2 como o pino onde o LED está conectado
const int ledPin2 = 21;
const int ledPin3 = 22;

// Função para tratar a rota raiz "/"
void handleRoot() {
  String html = "<html><body><h1>Controle do LED</h1>";
  html += "<p><a href=\"/led1\"><button>Led1</button></a></p>";      // Botão para ligar o LED
  html += "<p><a href=\"/led2\"><button>Led2</button></a></p>";  // Botão para desligar o LED
  html += "<p><a href=\"/led3\"><button>Led3</button></a></p>";  // Botão para desligar o LED
  html += "<p><a href=\"/desligarTudo\"><button>Desligar Tudo</button></a></p>";  // Botão para desligar o LED
  html += "</body></html>";
  server.send(200, "text/html", html);  // Envia a página HTML para o navegador
}

// Função para tratar a rota "/on"
void led1() {
  digitalWrite(ledPin1, HIGH);
  server.send(200, "text/html", "<html><head><meta http-equiv='refresh' content='0;url=/' /></head><body></body></html>");
}


// Função para tratar a rota "/off"
void led2() {
  digitalWrite(ledPin2, HIGH);
  server.send(200, "text/html", "<html><head><meta http-equiv='refresh' content='0;url=/' /></head><body></body></html>");
}


void led3() {
  digitalWrite(ledPin3, HIGH);                                                 // Liga o LED
  server.send(200, "text/html", "<html><head><meta http-equiv='refresh' content='0;url=/' /></head><body></body></html>");
}

void desligarTudo() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);                                                  // Liga o LED
  server.send(200, "text/html", "<html><head><meta http-equiv='refresh' content='0;url=/' /></head><body></body></html>");
 }
void setup() {
  Serial.begin(115200);        // Inicializa a comunicação serial
  pinMode(ledPin1, OUTPUT);    // Define o pino do LED como saída
  pinMode(ledPin2, OUTPUT);    // Define o pino do LED como saída
  pinMode(ledPin3, OUTPUT);    // Define o pino do LED como saída
  digitalWrite(ledPin1, LOW);  // Garante que o LED comece desligado
  digitalWrite(ledPin2, LOW);  // Garante que o LED comece desligado
  digitalWrite(ledPin3, LOW);  // Garante que o LED comece desligado

  WiFi.begin(ssid, password);  // Inicia a conexão WiFi com as credenciais fornecidas
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");  // Aguarda a conexão e imprime pontos enquanto conecta
  }
  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.println(WiFi.localIP());  // Exibe o IP local atribuído ao dispositivo

  // Define os "caminhos" (rotas) para o servidor responder
  server.on("/", handleRoot);  // Quando acessa "/", chama handleRoot
  server.on("/led1", led1);    // Quando acessa "/on", chama handleOn
  server.on("/led2", led2);    // Quando acessa "/off", chama handleOff
  server.on("/led3", led3);    // Quando acessa "/off", chama handleOff
  server.on("/desligarTudo", desligarTudo);    // Quando acessa "/off", chama handleOff

  server.begin();  // Inicia o servidor web
  Serial.println("Servidor iniciado!");
}

void loop() {
  server.handleClient();  // Mantém o servidor web ativo, tratando requisições
}
