int r = 11;
int g = 9;
int b = 10;

int fadetime=10;
int f;
int contagem;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}


void loop() 
{
  w_max();
  delay (5000);
  r_max();
  b_max();

  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  f_r();
  f_b();
  f_g();
  f_b();
  f_r();
  delay (1000);
  w_max();
  violeta();
  turquesa();
  amarelo();
  g_max();
  b_max();


  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  violeta();
  turquesa();
  amarelo();
  g_max();
  b_max();
  r_max();
  b_max();
  delay (1000);

  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  f_r();
  f_b();


  f_g();
  f_b();
  f_r();
  w_max();
  violeta();
  turquesa();
  amarelo();
  violeta();
  turquesa();
  amarelo();
  delay (1000);
  r_max();
  b_max();
  delay (1000);
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  f_r();
  f_b();
  f_g();
  f_b();

  delay (1000);
  f_r();
  w_max();
  violeta();
  turquesa();
  amarelo();
  g_max();
  b_max();
  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  violeta();
  turquesa();
  amarelo();
  g_max();
  b_max();
  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  r_max();
  b_max();
  delay (1000);

  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  f_r();
  f_b();
  f_g();
  f_b();
  f_r();
  w_max();
  violeta();
  turquesa();
  amarelo();
  violeta();
  turquesa();
  amarelo();

  delay (1000);
  r_max();
  b_max();
  delay (1000);
  g_max();
  amarelo();
  turquesa();
  delay (1000);

  violeta();
  w_max();
  f_r();
  f_b();
  f_g();
  f_b();
  f_r();
  w_max();
  violeta();
  turquesa();
  amarelo();
  g_max();
  b_max();


  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  violeta();
  turquesa();
  amarelo();
  g_max();
  b_max();
  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();
  w_max();
  r_max();
  b_max();
  g_max();
  amarelo();
  turquesa();
  violeta();


  w_max();
  f_r();
  f_b();
  f_g();
  f_b();
  f_r();
  w_max();
  violeta();
  turquesa();
  amarelo();
  violeta();
  turquesa();


  amarelo();
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
  delay (800);
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
  delay (800);
  analogWrite(r, 0);
}
//------------------------------
void b_max()
{
  analogWrite(b, 255);
  delay (800);
  analogWrite(b, 0);
}

//-----------------------------
void g_max()
{

  analogWrite(g, 255);
  delay (800);
  analogWrite(g, 0);
}



//--------------------------------
void w_max()
{

  analogWrite(r, 255);
  analogWrite(b,255);
  analogWrite(g,255);
  delay (800);

  analogWrite(g, 0);
  analogWrite(b, 0);
  analogWrite(r,0);
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


