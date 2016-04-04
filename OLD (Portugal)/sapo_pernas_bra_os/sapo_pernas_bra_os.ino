// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Servo.h>

Servo braco_direito;
Servo braco_esquerdo;
Servo pe_direito;
Servo pe_esquerdo;

int led=4;

void setup() {
  pinMode (led, OUTPUT);

  braco_direito.attach(12); //esquerda faz de 0 para 50. 0 esta mais a frente
  braco_esquerdo.attach(8); // direita
  pe_direito.attach(7);
  pe_esquerdo.attach(3);

}

void loop() {
  liga();
  delay(2000);
  dois_pes();
  desliga();
  delay(2000);
  liga();

  desliga();
  delay(1000);
  liga();
  braco_dir();
  dois_bracos();
}

//====================================

void braco_esq()
{
  braco_esquerdo.write(150);
  delay(1000);
  braco_esquerdo.write(100);
  delay (1000);
}
//-------
void braco_dir()
{

  braco_direito.write(140);
  delay (1000);
  braco_direito.write(70);
  delay(1000);

}

//-------
void dois_bracos()
{
  braco_esquerdo.write(150);
  delay(1000);
  braco_direito.write(140);
  delay (1000);
  braco_direito.write(70);
  delay(1000);
  braco_esquerdo.write(100);

  delay (1000);
}

//----------------
void dois_pes()
{
  pe_direito.write(10);
  pe_esquerdo.write(90);
  delay (1000);
  pe_direito.write(70);
  pe_esquerdo.write(45);
  delay (1000);

}

//----------------~

void liga()
{
  digitalWrite (led, HIGH);
}
//--------------
void desliga()
{
  digitalWrite (led, LOW);
  delay(1000);
}
