const int ledPin1 = 4;
const int ledPin2 = 21;
const int ledPin3 = 22;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH); // Liga o LED
  delay(500);
  digitalWrite(ledPin1, LOW);  // Desliga o LED
  delay(500);
  digitalWrite(ledPin2, HIGH); // Liga o LED
  delay(500);
  digitalWrite(ledPin2, LOW);  // Desliga o LED
  delay(500);
  digitalWrite(ledPin3, HIGH); // Liga o LED
  delay(500);
  digitalWrite(ledPin3, LOW);  // Desliga o LED
  delay(500);
}
