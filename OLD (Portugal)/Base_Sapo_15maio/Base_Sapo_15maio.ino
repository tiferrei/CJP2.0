// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Wire.h>                   // required by Omni3MD.cpp and compass
#include <Omni3MD.h>                // biblioteca para programar o omni

//constants definitions|

#define ADDRESS 0x60         // Defines address of CMPS10
#define OMNI3MD_ADDRESS 0x30        // default factory address


//variable declarations
byte highByte, lowByte, fine;              // highByte and lowByte store high and low bytes of the bearing and fine stores decimal place of bearing
int bearing, pitch, roll;          // Stores full bearing -> orientação,  pitch and roll values of CMPS10

Omni3MD omni;    // [byte omniAddress]

int lin_speed;
int rot_speed;
int dir;                       // direction varies from 0 (front) to 359 degrees.


void setup()
{
  //setup routines
  Serial.begin(115200);               // set baud rate to 115200bps for printing values in serial monitor. Press (ctrl+shift+m) after uploading
  omni.i2c_connect(OMNI3MD_ADDRESS);  // set i2c connection
  Wire.begin();
  delay(10);                          // pause 10 milliseconds

  omni.stop_motors();                 // stops all motors
  delay(10);

  omni.set_i2c_timeout(0); // safety parameter -> I2C communication must occur every [byte timeout] x 100 miliseconds for motor movement
  delay(5);                 // 5ms pause required for Omni3MD eeprom writing

  omni.set_PID(250,400,125); // Adjust paramenters for PID control [word Kp, word Ki, word Kd]
  delay(15);                 // 15ms pause required for Omni3MD eeprom writing

  omni.set_ramp(2000,1225,1000);   // void set_ramp(int time, int slope, int Kl);set acceleration ramp and limiar take off parameter gain[word ramp_time, word slope, word Kl]
  delay(15);                 // 10ms pause required for Omni3MD

}

void loop()
{

  frente ();
  delay(10000);


  }

  //------------------------------------------------
  void frente()
  {
    omni.mov_omni(30,0,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
    delay (5000);
    omni.stop_motors();
    (10);

  }


//------------------------------------------------
void alinha() // Rotina para alinhar o robô
{

  ler_bussola();
  while (bearing<180 || bearing>210)  // 200 Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial 80-180)
  {
    omni.mov_omni(0,60,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
    delay (100);
    ler_bussola();        //Ler a bússola
    delay (30);
  }
  omni.stop_motors();           // stops all motors
  delay(10);
}

//---------------------------------------
void ler_bussola()
{
  Wire.beginTransmission(ADDRESS);           //starts communication with CMPS10
  Wire.write(2);                              //Sends the register we wish to start reading from
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS, 4);              // Request 4 bytes from CMPS10
  while(Wire.available() < 4);               // Wait for bytes to become available
  highByte=Wire.read();
  lowByte = Wire.read();
  pitch = Wire.read();
  roll = Wire.read();
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
