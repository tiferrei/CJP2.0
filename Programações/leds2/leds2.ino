int r = 9;  //porta vermelha
int g = 10; //porta verde
int b = 11; //porta azul
int t = 1000;


int fadetime=10;
int f;
int contagem;


void setup() {
  pinMode(r, OUTPUT);// vermelho como saida
  pinMode(g, OUTPUT);// verde como saida
  pinMode(b, OUTPUT);// azul como saida
  
}

void loop(){
  

   
  digitalWrite(r, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(r, LOW);
                             // turn the LED off by making the voltage LOW
  digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(g, LOW);
                              // turn the LED off by making the voltage LOW
  digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);
  digitalWrite(b, LOW);            
 
  digitalWrite(r, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);               // wait for a second
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  
  
    digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(t);               // wait for a second
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
 
 
   digitalWrite(r, HIGH);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(t);               // wait for a second
   digitalWrite(r, LOW);
   digitalWrite(b, LOW);
   
   
   digitalWrite(r, HIGH);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(t);               // wait for a second
   digitalWrite(r, LOW);
   digitalWrite(g, LOW);
   digitalWrite(b, LOW);
 
 

  delay(5000);
  
  f_r();
  
  
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


  



