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
  int legD_deg=70;
  int legE_deg=100;
  int feetD_deg=100;
  int feetE_deg=80;

  legD.write(legD_deg);
  legE.write(legE_deg);
  feetD.write(feetD_deg);
  feetE.write(feetE_deg);

}


void loop(){

  feetD.write(120);
  feetE.write(100);
  delay(100);
  feetD.write(100);
  feetE.write(80);
  danca();



}

void danca(){

  legD.write(100); //passa de 80 para 60
  legE.write(130);

  delay (100);

  legD.write(100); //passa de 80 para 100
  legE.write(130); //passa de 100 para 130

  delay (100);

  legD.write(60); //passa de 80 para 60
  legE.write(70);

  delay (100);

  legD.write(60); //passa de 80 para 60
  legE.write(70);

  delay (100);

  legD.write(80);
  legE.write(100);

  delay (100);
}
