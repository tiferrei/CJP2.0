// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Servo.h>

Servo servoMotor;
int servoPin = 13;


void setup() {

  servoMotor.attach(servoPin);
}

void loop()
{


passaroco();
passaroco();passaroco();passaroco();passaroco();passaroco();passaroco();passaroco();passaroco();
delay(120000);
passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();


}



void passaroco(){

  servoMotor.write(15);
delay(1000);
servoMotor.write(75);
delay(1000);
}

void passaroco2(){

  servoMotor.write(15);
delay(500);
servoMotor.write(75);
delay(5000);
}
