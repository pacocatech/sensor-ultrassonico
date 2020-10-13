/**
   Criado por Paçoca Tech
   
   Youtube: https://www.youtube.com/channel/UCW6OP5j28zFsnKxpQ2v9CsA
   Instagram: http://instagram.com/pacocatech
   Github: http://github.com/pacocatech
   E-mail: pacocatech@gmail.com
   
   
   Manipulando sensor de distância ultrassônico.
*/

#define PIN_TRIGGER 7
#define PIN_ECHO 6

const float VelocidadeSom_MporS = 0.000340; // em metros por microsegundo

void setup() {
  //iniciando o monitor serial
  Serial.begin(9600);

  //configuramos o pino trigger como saída
  pinMode(PIN_TRIGGER, OUTPUT);
  digitalWrite(PIN_TRIGGER, LOW);

  //configuramos o pino echo como entrada
  pinMode(PIN_ECHO, INPUT); 
}

void loop() {
  //Disparamos um pulso ultrassonico, temos que enviar para o pino de trigger um sinal HIGH
  // por pelo menos 10us
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  //obtem o tempo de duração do sinal no pino de leitura(us)
  float tempoResposta = pulseIn(PIN_ECHO, HIGH);

  Serial.print("Distância em metros: ");
  Serial.println(converterEmMetros(tempoResposta));
  Serial.print("Distância em centimetros: ");
  Serial.println(converterEmMetros(tempoResposta)*100);

  //aguardamos 2 segundos e fazemos o fluxo novamente
  delay(2000);
}

float converterEmMetros(float tempoResposta){
  return((tempoResposta*VelocidadeSom_MporS)/2);
}
