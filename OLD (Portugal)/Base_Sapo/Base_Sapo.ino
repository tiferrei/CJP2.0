// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Wire.h>   // required by Omni3MD.cpp and compass
#include <Omni3MD.h>


//constants definitions|

#define COMPASS_ADDRESS 0x60         // Defines address of CMPS10
#define OMNI3MD_ADDRESS 0x30        // default factory address

Omni3MD omni;    // [byte omniAddress]

//variable declarations
byte highByte, lowByte, fine;              // highByte and lowByte store high and low bytes of the bearing and fine stores decimal place of bearing

int bearing;         // Stores full bearing -> orientação,  pitch and roll values of CMPS10


byte linear_speed;                // linear speed varies from 0 (stopped) to 100 (max speed)
byte rotational_speed;          // rotation varies from 0 (CCW) to 200 (CW). At 100 it doesn't rotate.
int direc=0;                        // direction varies from 0 (front) to 359 degrees.


void setup()
{

    //setup routines
    Serial.begin(115200);               // set baud rate to 115200bps for printing values in serial monitor. Press (ctrl+shift+m) after uploading
    omni.i2c_connect(OMNI3MD_ADDRESS);  // set i2c connection
    delay(10);                          // pause 10 milliseconds

    omni.stop_motors();                 // stops all motors
    delay(10);
/*
    omni.calibrate(1,0,0);    // send the calibration command to configure the OMmni3MD board
    delay(95);                // wait 95s for calibration to end
*/
    omni.set_i2c_timeout(0); // safety parameter -> I2C communication must occur every [byte timeout] x 100 miliseconds for motor movement
    delay(5);                 // 5ms pause required for Omni3MD eeprom writing

    omni.set_PID(700,400,200); // Adjust paramenters for PID control [word Kp, word Ki, word Kd]
    delay(15);                 // 15ms pause required for Omni3MD eeprom writing

    omni.set_ramp(500,1200,500);   // set acceleration ramp and limiar take off parameter gain[word ramp_time, word slope, word Kl]
    delay(15);                 // 10ms pause required for Omni3MD eeprom writing




  alinha_publico();  //alinha com o juri mais ou menos 2 segundos

}

void loop()
{

  delay (6000); // esta parado 4seg
  alinha_orq();
  delay (5000);
  alinha_publico();
  delay (4500);
  dirD();  //movimentaç´es laterais durante 10 seg
  dirD();

  dirE ();
 dirE ();

  dirD();
  dirD();

 dirE ();
 dirE ();

  dirD();
  dirD();

 dirE ();
 dirE ();


  dirD();
  dirD();

 dirE ();
 dirE ();

  dirD();
  dirD();

 dirE ();
 dirE ();

  alinha_publico();
  //------------------------
  delay (4000);

  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCW();
  rodaCCW();
  rodaCCW();
  delay (500);

  dirD(); // mov laterais 4s
  dirD();

 dirE ();
 dirE ();

  dirD();
  dirD();

 dirE ();
 dirE ();


  delay (2000);
  alinha_orq();
  delay (5000);
  alinha_publico();
  delay (3000);

  espiral();
  espiral();
  espiral();
  espiral();
  delay (40000);



}

//------------------
void espiral()
{
omni.mov_omni(30,140,180); //Movimentar o robô direcao 120
  delay (1000);

}


//----------------------------

void rodaCW()
{
omni.mov_omni(0,140,100); //Movimentar o robô direcao 120
  delay (1000);

}

//----------------------------

void rodaCCW()
{
omni.mov_omni(0,60,100); //Movimentar o robô direcao 120
  delay (1000);

}
//-----------------------------
void dirE()
{

omni.mov_omni(50,100,90);
  delay (1000);
omni.stop_motors();           // stops all motors
  delay(10);

}

//-----------------------------
void dirD()
{

omni.mov_omni(50,100,270);
  delay (1000);
omni.stop_motors();           // stops all motors
  delay(10);

}


//------------------------------------------------
void alinha_publico() // Rotina para alinhar o robô
{

  ler_bussola();
  while (bearing<0 || bearing>30)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial 80-180)
  {
 omni.mov_omni(0,60,0); //Movimentar o robô
    delay (100);
    ler_bussola();        //Ler a bússola
    delay (30);

  }
omni.stop_motors();           // stops all motors
  delay(10);
}



//------------------------------------------------
void alinha_orq() // Rotina para alinhar o robô
{

  ler_bussola();
  while (bearing<180 || bearing>210)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial 80-180)
  {
 omni.mov_omni(0,60,0); //Movimentar o robô
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
  Wire.beginTransmission(COMPASS_ADDRESS);           //começa a comunicação com CMPS10
  Wire.write(2);                              //Envia o registo, queremos iniciar a leitura de
  Wire.endTransmission();

  Wire.requestFrom(COMPASS_ADDRESS, 4);              // Request 4 bytes from CMPS10
  while(Wire.available() < 4);               // Aguarde bytes para se tornar disponível
  highByte=Wire.read();
  lowByte = Wire.read();



  bearing = ((highByte<<8)+lowByte)/10;      // Calculate full bearing
  fine = ((highByte<<8)+lowByte)%10;         // Calculate decimal place of bearing
  delay(50);
}
