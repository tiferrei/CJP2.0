// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
