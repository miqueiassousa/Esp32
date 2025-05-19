// Motor A (ligado em OUT1 e OUT4)
#define IN1 7
#define IN2 8
#define ENA 9  // PWM

// Motor B (ligado em OUT3 e OUT4)
#define IN3 5
#define IN4 6
#define ENB 10  // PWM

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}


void loop() {
  // Motor A - Gira por 2 segundos
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);

  // Motor B - Gira por 2 segundos
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);

  delay(2000);
  
  // Motor A - Parar o motor
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(2000); // espera 2 segundos parado
}
