#include <Servo.h>  // biblioteca do servo, já vem no Arduino IDE

Servo meuServo;

// pinos
const int TRIG = 9;
const int ECHO = 10;
const int SERVO_PINO = 6;

// distância em cm pra ativar (ajuste conforme necessário)
const int DISTANCIA_ATIVACAO = 20;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  meuServo.attach(SERVO_PINO);
  meuServo.write(0);    // começa fechado
  Serial.begin(9600);   // pra monitorar a distância no PC
}

float medirDistancia() {
  // envia pulso ultrassônico
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // calcula a distância com base no tempo de retorno
  long duracao = pulseIn(ECHO, HIGH);
  float distancia = duracao * 0.034 / 2;
  return distancia;
}

void loop() {
  float distancia = medirDistancia();

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < DISTANCIA_ATIVACAO) {
    meuServo.write(90);   // abre (gira 90 graus)
    delay(3000);          // fica aberto 3 segundos
    meuServo.write(0);    // fecha
  }

  delay(200); // pequena pausa entre leituras
}