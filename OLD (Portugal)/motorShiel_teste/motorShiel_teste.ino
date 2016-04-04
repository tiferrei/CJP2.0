// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Motor A definições
int DIR_A = 12;
int SPEED_A = 3;
int BREAK_A = 9;

// Motor B definições
int DIR_B = 13;
int SPEED_B = 11;
int BREAK_B = 8;

void setup()
{
  pinMode(SPEED_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  pinMode(BREAK_A, OUTPUT);

  pinMode(SPEED_B, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(BREAK_B, OUTPUT);
  // release break
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}

void loop()
{
  frente();
  traz();
  spin_direita();
  spin_esquerda();
  roda_direita_direita_parada();
  roda_esquerda_esquerda_parada();

}

//-----------------------------------------------------------------------------
// rotinas


void frente()
{
  // frente velocidade média.  Max is 250.
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, HIGH);
  analogWrite(SPEED_A, 250);
  analogWrite(SPEED_B, 250);
  delay(5000);   // wait 5 seconds

  // parar motor
  digitalWrite(BREAK_A, HIGH);
  digitalWrite(BREAK_B, HIGH);
  delay(100);
  // release break.  If BREAK_A e B continues to be HIGH, the motor will not move
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}

void traz()
{
  // mover motor traz velocidade média.  Max is 250.
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  analogWrite(SPEED_A, 125);
  analogWrite(SPEED_B, 125);
  delay(5000);   // wait 5 seconds

  // parar motor
  digitalWrite(BREAK_A, HIGH);
  digitalWrite(BREAK_B, HIGH);
  delay(100);
  // release break.  If BREAK_A e B continues to be HIGH, the motor will not move
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}

void spin_direita()
{
  // roda- rodas em sentido inverso velocidade média.  Max is 250.
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  analogWrite(SPEED_A, 250);
  analogWrite(SPEED_B, 250);
  delay(5000);   // wait 5 seconds

  // parar motor
  digitalWrite(BREAK_A, HIGH);
  digitalWrite(BREAK_B, HIGH);
  delay(100);
  // release break.  If BREAK_A e B continues to be HIGH, the motor will not move
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}

void spin_esquerda()
{
  // roda- rodas em sentido inverso velocidade média.  Max is 250.
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  analogWrite(SPEED_A, 250);
  analogWrite(SPEED_B, 250);
  delay(5000);   // wait 5 seconds

  // parar motor
  digitalWrite(BREAK_A, HIGH);
  digitalWrite(BREAK_B, HIGH);
  delay(100);
  // release break.  If BREAK_A e B continues to be HIGH, the motor will not move
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}

void roda_direita_direita_parada()
{
  // roda- rodas em sentido inverso velocidade média.  Max is 250.
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  analogWrite(SPEED_A, 250);
  analogWrite(SPEED_B, 0);
  delay(5000);   // wait 5 seconds

  // parar motor
  digitalWrite(BREAK_A, HIGH);
  digitalWrite(BREAK_B, HIGH);
  delay(100);
  // release break.  If BREAK_A e B continues to be HIGH, the motor will not move
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}
void roda_esquerda_esquerda_parada()
{
  // roda- rodas em sentido inverso velocidade média.  Max is 250.
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  analogWrite(SPEED_A, 0);
  analogWrite(SPEED_B, 250);
  delay(5000);   // wait 5 seconds

  // parar motor
  digitalWrite(BREAK_A, HIGH);
  digitalWrite(BREAK_B, HIGH);
  delay(100);
  // release break.  If BREAK_A e B continues to be HIGH, the motor will not move
  digitalWrite(BREAK_A, LOW);
  digitalWrite(BREAK_B, LOW);
}
