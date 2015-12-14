int r = 9;  //porta vermelha
int g = 10; //porta verde
int b = 11; //porta azul
int t = 1000;


int fadetime=1;
int f;
int contagem;


void setup() {
  pinMode(r, OUTPUT);// vermelho como saida
  pinMode(g, OUTPUT);// verde como saida
  pinMode(b, OUTPUT);// azul como saida
  
}

void loop(){
    
  f_r();
  f_g();
  f_b();
  f_g();
  
  
}
  
  void f_r()
{
  // fade from vermelho
  for (f = 0; f < 255; f++) 
  { 
    analogWrite(r, f);
    delay (fadetime);
  }
  for (f = 255; f > 0; f--) 
  { 
    analogWrite(r, f);
    delay (fadetime);
  }
  analogWrite(r, 0);
}

//__________________________
  
void f_g(){
  
// fade from verde
  for (f = 0; f < 255; f++) 
  { 
    analogWrite(g, f);
    delay (fadetime);
  }
  // fade from verde
  for (f = 255; f >0; f--) 
  { 
    analogWrite(g, f);
    delay (fadetime);
  }  

}  

//-----------------------

void f_b()
{
  // fade from azul
  for (f = 0; f < 255; f++)
  { 
    analogWrite(b, f);
    delay (fadetime);
  }
  // fade from azul
  for (f = 255; f > 0; f--)
  { 
    analogWrite(b, f);
    delay (fadetime);
  }
}


  



