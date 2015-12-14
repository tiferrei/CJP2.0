#include <Servo.h>

Servo legE;
Servo feetE;
Servo legD;
Servo feetD; 

int tempo = 10;


void setup() {

  legE.attach(13);
  feetE.attach(12);
  legD.attach(7);
  feetD.attach(6);


  legD.write(80);
  legE.write(100);
  feetD.write(178);
  feetE.write(3);
}

void loop() {

  legD.write(80);
  legE.write(100);
  feetD.write(178);
  feetE.write(3);
  delay (500);

  legD.write(100);
  legE.write(120);
  feetD.write(178);
  feetE.write(3);
  delay (500);

 legD.write(80);
  legE.write(100);
  feetD.write(178);
  feetE.write(3);
  delay (500);
  
   legD.write(60);
  legE.write(80);
  feetD.write(178);
  feetE.write(3);
  delay (500);
}



