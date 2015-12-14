int r = 9;    //
int g = 10;
int b = 11;

int fadetime=1;
int f;
int contagem;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}


void loop() 
{
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();
amarelo();
b_max();
g_max();



f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();
f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();
f_w();f_r();
f_g();
f_b();




r_max();
amarelo2();
r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();
r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();r_max();
amarelo2();
}

//-----------------------------

void violeta()
{

  analogWrite(r, 255);
  analogWrite(b, 125);
  delay (800);
  analogWrite(r, 0);
  analogWrite(b,0);
}

//--------------------------------
void amarelo()
{

  analogWrite(r, 255);
  analogWrite(g, 255);
  delay (1000);
  analogWrite(r, 0);
  analogWrite(g, 0);
}


//--------------------------------
void turquesa()
{

  analogWrite(g, 255);
  analogWrite(b, 255);
  delay (800);
  analogWrite(g, 0);
  analogWrite(b, 0);
}
//------------------------------
void r_max()
{

  analogWrite(r, 255);
  delay (250);
  analogWrite(r, 0);
}
//------------------------------
void b_max()
{
  analogWrite(b, 255);
  delay (1000);
  analogWrite(b, 0);
}

//-----------------------------
void g_max()
{

  analogWrite(g, 255);
  delay (1000);
  analogWrite(g, 0);
}



//--------------------------------
void w_max()
{

  analogWrite(r, 255);
  analogWrite(b,255);
  analogWrite(g,255);
  delay (25);

  analogWrite(g, 0);
  analogWrite(b, 0);
  analogWrite(r, 0);
}
//---------------------------

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
//------------------------------
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
//-----------------------------
void f_g()
{
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
//--------------------------------
void f_w()
{

  for (f = 0; f < 255; f++) 
  { 
    analogWrite(r, f);
    analogWrite(b,f);
    analogWrite(g,f);
    delay (fadetime);
  }
  for (f = 255; f >0; f--) 
  { 
    analogWrite(r, f);
    analogWrite(b,f);
    analogWrite(g,f);
    delay (fadetime);
  }
}
  
  
  void amarelo2(){

  analogWrite(r, 255);
  analogWrite(g, 255);
  delay (40);
  analogWrite(r, 0);
  analogWrite(g, 0);
}



