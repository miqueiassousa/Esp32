// Pra ver quanto de memória sua ESP32 está usando em tempo real:

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Heap livre: ");
  Serial.println(ESP.getFreeHeap());
  delay(1000);
}
