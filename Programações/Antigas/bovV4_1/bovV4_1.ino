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
  feetD.write(100);
  feetE.write(70);
}

void loop() {

  inlina_D();
  movD();
  pos_media1();

  inlina_E();
  movE();
  pos_media2();


}
void pos_media2() {
  legD.write(100); //passa de 80 para 60
  legE.write(130);
  feetD.write(100);  
  feetE.write(70);

  delay (1000);
}

void movE() {

  legD.write(100); //passa de 80 para 100
  legE.write(130); //passa de 100 para 130
  feetD.write(150);  //quando passa de 100 para 70 inclina
  feetE.write(100);  // passa de 70 para 20
  delay (1000);
}

void inlina_E() {
  // movimento inclina equerda
  legD.write(80);
  legE.write(100);
  feetD.write(160);  //quando passa de 100 para 150 inclina
  feetE.write(100);  // passa de 70 para 100 
  delay (1000);
}

void pos_media1() {
  legD.write(60); //passa de 80 para 60
  legE.write(70);
  feetD.write(100);  
  feetE.write(70); 
  delay (1000);
}


void movD() {
  legD.write(60); //passa de 80 para 60
  legE.write(70);
  feetD.write(70);  //quando passa de 100 para 70 inclina
  feetE.write(20);  // passa de 70 para 20
  delay (1000);
}



void inlina_D() {
  // movimento inclina direita
  legD.write(80);
  legE.write(100);
  feetD.write(90);  //quando passa de 100 para 70 inclina
  feetE.write(20);  // passa de 70 para 20
  delay (1000);
}

void posicao_eq() {


  legD.write(80);
  legE.write(100);
  feetD.write(100);
  feetE.write(70); 
  delay (1000);

}

void danca(){

  legD.write(100); //passa de 80 para 60
  legE.write(130);
  feetD.write(100);
  feetE.write(70);
  delay (100);

  legD.write(100); //passa de 80 para 100
  legE.write(130); //passa de 100 para 130
  feetD.write(100);
  feetE.write(70);
  delay (100);

  legD.write(60); //passa de 80 para 60
  legE.write(70);
  feetD.write(100);
  feetE.write(70);
  delay (100);

  legD.write(60); //passa de 80 para 60
  legE.write(70);
  feetD.write(100);
  feetE.write(70);
  delay (100);

  legD.write(80);
  legE.write(100);
  feetD.write(100);
  feetE.write(70); 
  delay (100);

} 




