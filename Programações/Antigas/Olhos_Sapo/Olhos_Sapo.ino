#include <Servo.h>

Servo Motor;
int Posicao;

void setup(){
  Motor.attach(8);
}

void loop(){

    for (Posicao = 0; Posicao < 160; Posicao += 1)
 {
  Motor.write(Posicao);
  delay(5);
 }
  for (Posicao = 160; Posicao > 0; Posicao -= 1){
   Motor.write(Posicao);
  delay(5);
  }
}

