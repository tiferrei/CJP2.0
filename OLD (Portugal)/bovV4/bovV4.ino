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
  legE.write(100);
  feetD.write(178);
  feetE.write(3);
}

void loop() {

  legD.write(80);
  legE.write(100);
  feetD.write(178);
  feetE.write(3);
  delay (500);

  legD.write(100);
  legE.write(120);
  feetD.write(178);
  feetE.write(3);
  delay (500);

 legD.write(80);
  legE.write(100);
  feetD.write(178);
  feetE.write(3);
  delay (500);

   legD.write(60);
  legE.write(80);
  feetD.write(178);
  feetE.write(3);
  delay (500);
}
