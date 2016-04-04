// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Servo.h>

int led = 3;       // porta onde esta ligado a rele para controlar o led

Servo legE;
Servo legD;

Servo armD;
Servo armE;

void setup() {

  pinMode (led, OUTPUT);

  legE.attach(31);
  legD.attach(33);
  armE.attach(35);
  armD.attach(37);


  legD.write(80);
  legE.write(100);
  armD.write(100);
  armE.write(70);
}

void loop() {




}



//------------------------------------------------
void pisca() // Rotina para alinhar o robô
{
  for (int i=0; i <= 5; i++){
    digitalWrite (led, LOW);
    delay (300);
    digitalWrite(led, HIGH);
    delay (300);
  }

}
