#include <Servo.h>

int led = 3;       // porta onde esta ligado a rele para controlar o led

Servo legE;
Servo legD;

Servo armD; 
Servo armE;

void setup() {

  pinMode (led, OUTPUT);

  legE.attach(31);
  legD.attach(33);
  armE.attach(35);
  armD.attach(37);


  legD.write(80);
  legE.write(100);
  armD.write(100);
  armE.write(70);
}

void loop() {




}



//------------------------------------------------
void pisca() // Rotina para alinhar o robô
{
  for (int i=0; i <= 5; i++){
    digitalWrite (led, LOW);
    delay (300);
    digitalWrite(led, HIGH);
    delay (300);
  } 

}


