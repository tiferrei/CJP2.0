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


  legD.write(80);
  legE.write(80);
  feetD.write(70);
  feetE.write(115);


}

void loop() {

  for (int v = 70; v>50; v--)//movimento para inclinar para fora direita
  {
    feetD.write(v);
    delay (tempo);
  }


  for (int v = 80; v>50; v--) // movimento do servo de cima para rodar
  {
    legD.write(v);
    delay (tempo);
  }


  for (int v = 50; v<70; v++)// volta à posição de equilibrio
  {
    feetD.write(v);
    delay (tempo);
  }

  for (int v = 50; v<80; v++)// volta à posição de equilibrio
  {
    legD.write(v);
    delay (tempo);
  }

  for (int v = 115; v<145; v++)//movimento para inclinar para fora esquerda
  {
    feetE.write(v);
    delay (tempo);
  }

  for (int v = 80; v<110; v++)// movimento do servo de cima para rodar
  {
    legE.write(v);
    delay (tempo);
  }

  for (int v = 145; v>115; v--)// volta à posição de equilibrio
  {
    feetE.write(v);
    delay (tempo);
  }


  for (int v = 110; v>80; v--)// volta à posição de equilibrio
  {
    legE.write(v);
    delay (tempo);
  }

}
