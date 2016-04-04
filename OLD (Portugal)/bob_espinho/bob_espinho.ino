// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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

// posições de equilibrio
  int legD_deg=80;
  int legE_deg=100;
  int feetD_deg=100;
  int feetE_deg=100;

  legD.write(legD_deg);
  legE.write(legE_deg);
  feetD.write(feetD_deg);
  feetE.write(feetE_deg);

  delay (5000);
}

void loop() {

  inclina_D();
  movD();
  pos_media1();

  inclina_E();
  movE();
  pos_media2();


}
void pos_media2() {
  legD.write(legD_deg+20); //passa de 80 para 60
  legE.write(legE_deg+30);
  feetD.write(feetD_deg);
  feetE.write(feetE_deg);

  delay (1000);
}

void movE() {

  legD.write(legD_deg+20); //passa de 80 para 100
  legE.write(legE_deg+30); //passa de 100 para 130
  feetD.write(feetD_deg+50);  //quando passa de 100 para 70 inclina
  feetE.write(feetE_deg);  // passa de 70 para 20
  delay (1000);
}

void inclina_E() {
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



void inclina_D() {
  // movimento inclina direita
  legD.write(85);
  legE.write(100);
  feetD.write(80);  //quando passa de 100 para 70 inclina
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
