🔧 Fiação — onde conectar cada peça

Sensor Ultrassônico HC-SR04

O sensor tem 4 pinos:

Pino do sensor           Conecta no Arduino

VCC----------------------5V
GND----------------------GND
TRIG---------------------Pino digital 9
ECHO---------------------Pino digital 10

Servo Motor SG90

O servo tem 3 fios:
Cor do fio                    Conecta no Arduino

Vermelho----------------------5V
Marrom/preto------------------GND
Laranja/Amarelo---------------Pino digital 6

⚠️ Dica importante: tanto o sensor quanto o servo compartilham o 5V e o GND do
Arduino. Na protoboard, use as fileiras + (vermelho) para 5V e - (azul/preto) para GND,
e distribui dali pra cada componente. Fica muito mais organizado.

🧠 Entendendo a lógica
O raciocínio do código é simples:

1. O sensor manda um pulso de som e mede quanto tempo ele demora pra voltar
2. Com esse tempo, calcula a distância em cm
3. Se alguém tiver a menos de 20cm, o servo gira e abre a lixeira
4. Após 3 segundos, fecha automaticamente

O valor 20 na linha DISTANCIA_ATIVACAO você pode mudar amanhã dependendo de como o
sensor estiver posicionado na lixeira. Se tiver abrindo fácil demais, diminui. Se não
tiver detectando, aumenta.