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


  for (int v = 178; v>158; v=v-1)//movimento para inclinar para fora direita
  { 
    feetD.write(v);
    delay (tempo); 
  } 

}

void loop() {


  for (int v = 80; v>50; v--) // movimento do servo de cima para rodar
  { 
    legD.write(v);
    delay (tempo);
  }


  for (int v = 158; v<178; v++)// volta à posição de equilibrio
  { 
    feetD.write(v);
    delay (tempo);
  }
  //-----------------------
  for (int v = 3; v<23; v++)//movimento para inclinar para fora esquerda
  {  
    feetE.write(v);
    delay (tempo);
  }
  //----------------------

  for (int v = 50; v<80; v++)// volta à posição de equilibrio
  {
    legD.write(v);
    delay (tempo);
  }


  for (int v = 80; v<110; v++)// movimento do servo de cima para rodar
  {    
    legE.write(v);
    delay (tempo);
  }

  for (int v = 23; v>3; v--)// volta à posição de equilibrio
  { 
    feetE.write(v);
    delay (tempo);
  }

  for (int v = 178; v>158 ;v--)//movimento para inclinar para fora direita
  { 
    feetD.write(v);
    delay (tempo); 
  }

  for (int v = 110; v>80; v--)// volta à posição de equilibrio
  { 
    legE.write(v);
    delay (tempo);
  }

}








