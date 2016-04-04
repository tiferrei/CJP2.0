// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Wire.h>

#define ADDRESS 0x60                                          // Defines address of CMPS10

byte highByte, lowByte, fine;              // highByte and lowByte store high and low bytes of the bearing and fine stores decimal place of bearing
int bearing, pitch, roll;          // Stores full bearing -> orientação,  pitch and roll values of CMPS10

void setup()
{
  Serial.begin(9600);             // set baud rate to 9600 bps
  Wire.begin();                                               // Conects I2C
}

void loop()
{
  imprime_valores();
  ler_bussola();
}
void ler_bussola()
{
  Wire.beginTransmission(ADDRESS);           //starts communication with CMPS10
  Wire.send(2);                              //Sends the register we wish to start reading from
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS, 4);              // Request 4 bytes from CMPS10
  while(Wire.available() < 4);               // Wait for bytes to become available
  highByte=Wire.receive();
  lowByte = Wire.receive();
  pitch = Wire.receive();
  roll = Wire.receive();


  bearing = ((highByte<<8)+lowByte)/10;      // Calculate full bearing
  fine = ((highByte<<8)+lowByte)%10;         // Calculate decimal place of bearing
  delay(100);
}

void imprime_valores()
{
  Serial.print("\nBearing:");
  Serial.println(bearing);    // prints bearing Value on screen
  Serial.print("Pitch:");
  Serial.println(pitch);        // prints pitch Value on screen
  Serial.print("Roll:");
  Serial.println(roll);       // prints roll Value on screen
  delay(500);
}
