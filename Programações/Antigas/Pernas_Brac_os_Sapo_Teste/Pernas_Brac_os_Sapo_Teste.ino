#include <Servo.h>

Servo teste;
Servo teste1;
Servo leftarm;
Servo rightarm;


int tempo = 10;


void setup() {

  teste1.attach(13); //esquerda faz de 0 para 50. 0 esta mais a frente
  teste.attach(6); // direita
  leftarm.attach(7);
  rightarm.attach(12);



}

void loop() {

  rightarm.write(40);
  rightarm.write(20);
  delay (1000);


}
void tes() {
  teste.write(0); //passa de 80 para 60
  teste1.write(0);
  leftarm.write(40);
  rightarm.write(40);
  delay (1000);

  teste.write(40); //passa de 80 para 60
  teste1.write(40);
  leftarm.write(0);
  rightarm.write(0);
  delay (1000);

  delay (1000);
}




