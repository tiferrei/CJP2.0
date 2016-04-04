// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

int r = 9;    //
int g = 10;
int b = 11;

int fadetime=3;
int f;
int contagem;
int atime=1;
int a;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}


void loop()
{
f_amarelo();
f_b();
f_amarelo();
f_g();
f_amarelo();
f_r();
f_w();
violeta();
azul_bebe();
laranja();
f_amarelo();
f_b();
f_amarelo();
f_g();
f_amarelo();
f_r();
f_w();
violeta();
azul_bebe();
laranja();f_amarelo();
f_b();
f_amarelo();
f_g();
f_amarelo();
f_r();
f_w();
violeta();
azul_bebe();
laranja();f_amarelo();
f_b();
f_amarelo();
f_g();
f_amarelo();
f_r();
f_w();
violeta();
azul_bebe();
laranja();f_amarelo();
f_b();
f_amarelo();
f_g();
f_amarelo();
f_r();
f_w();
violeta();
azul_bebe();
laranja();f_amarelo();
f_b();
f_amarelo();
f_g();
f_amarelo();

f_r2();
f_amarelo2();
f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();
f_amarelo2();f_r2();


delay(10000);
}

//-----------------------------
void violeta()
{

  analogWrite(r, 255);
  analogWrite(b, 80);
  delay (1800);
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

void f_amarelo()
{

  for (f = 0; f < 255; f++)
  {
    analogWrite(r, f);
    analogWrite(g,f);
    delay (fadetime);
  }
  for (f = 255; f >0; f--)
  {
    analogWrite(r, f);
    analogWrite(g,f);
    delay (fadetime);
  }
}

void azul_bebe()
{

  analogWrite(r, 100);
  analogWrite(b,255);
  analogWrite(g,100);
  delay (1800);

  analogWrite(g, 0);
  analogWrite(b, 0);
  analogWrite(r, 0);
}

void laranja()
{

  analogWrite(r, 255);

  analogWrite(g, 150);
  delay (1800);

  analogWrite(r, 0);
  analogWrite(g, 0);
}

void f_r2()
{
  // fade from vermelho
  for (a = 0; a < 255; a++)
  {
    analogWrite(r, a);
    delay (atime);
  }
  for (a = 255; a > 0; a--)
  {
    analogWrite(r, a);
    delay (atime);
  }
  analogWrite(r, 0);
}

void f_amarelo2()
{
 for (a = 0; a < 255; a++)
  {
    analogWrite(r, a);
    analogWrite(g,a);
    delay (atime);
  }
  for (a = 255; a >0; a--)
  {
    analogWrite(r, a);
    analogWrite(g,a);
    delay (atime);
  }
}
