// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Wire.h>                  // preciso para Omni3MD.cpp e bussola
#include <Omni3MD.h>               // biblioteca para programar o omni

//constants definitions|

#define ADDRESS 0x60               // define adereço para CMPS10
#define OMNI3MD_ADDRESS 0x30       // endereço padrão de fábrica


//variable declarations
byte highByte, lowByte, fine;       // highByte and lowByte store high and low bytes of the bearing and fine stores decimal place of bearing
int bearing, pitch, roll;          // Stores full bearing -> orientation, pitch and roll values of CMPS10

int leds= 2;                          // define a variável leds

Omni3MD omni;    // [byte omniAddress]

int lin_speed;
int rot_speed;
int dir;                       // direção varia entre 0 (frontal) a 359 graus.

void setup()
{
  //setup routines
  Serial.begin(115200);               // set baud rate to 115200bps for printing values in serial monitor. Press (ctrl+shift+m) after uploading
  //  Wire.begin();
  omni.i2c_connect(OMNI3MD_ADDRESS);  // set i2c connection
  delay(10);                          // pausa 10 millisegundos

  omni.stop_motors();                 // pára todos os motores
  delay(10);

  omni.set_i2c_timeout(0); // parâmetro de segurança -> I2C a comunicação deve ocorrer a cada [byte timeout] x 100 milisegundos para o movimento do motor
  delay(5);                 // 5ms pause required for Omni3MD eeprom writing

  omni.set_PID(750,300,600); // Ajuste os parâmetros para o controle PID [word Kp, word Ki, word Kd]
  //  omni.set_PID(750,300,600); // Ajuste os parâmetros para o controle PID [word Kp, word Ki, word Kd]
  delay(15);                 // 15ms pausa necessária para Omni3MD escrita eeprom

  omni.set_ramp(800,1572,400);   // void set_ramp(int time, int slope, int Kl);set acceleration ramp and limiar take off parameter gain[word ramp_time, word slope, word Kl]
  delay(15);                 // 10ms puasa requerida para Omni3MD

  pinMode (leds, OUTPUT);
}

void loop(){

  alinha();
  delay(3000);
  rodaCW();
  rodaCCW();
  rodaCCW();
  rodaCW();
  rodaCCW();
  rodaCW();
  rodaCCW();
  rodaCW();
  rodaCCW();
  rodaCW();
  rodaCCW();
  rodaCW();
  rodaCCW();
  alinha();
  frente_zero();
  frente_90();
  frente_180();
  frente_270();
  alinha();
  espiral();
  alinha();



}



//------------------------------------------------

void rodaCW()
{
  omni.mov_omni(0,100,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  delay(750);
  omni.mov_omni(0,0,0);
  delay(300);

}
//------------------------------------------------
void rodaCCW()
{
  omni.mov_omni(0,-100,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  delay(750);
  omni.mov_omni(0,0,0);
  delay(300);

}
//------------------------------------------------
void frente_zero()
{
  omni.mov_omni(40,0,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  delay (2000);
  omni.mov_omni(0,0,0);
  delay(1000);
}
//------------------------------------------------
void frente_90()
{
  omni.mov_omni(40,0,90); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  delay (2000);
  omni.mov_omni(0,0,0);
  delay(1000);
}
//------------------------------------------------
void frente_180()
{
  omni.mov_omni(40,0,180); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  delay (2000);
  omni.mov_omni(0,0,0);
  delay(1000);
}

//------------------------------------------------
void frente_270()
{
  omni.mov_omni(40,0,270); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  delay (2000);
  omni.mov_omni(0,0,0);
  delay(1000);
}


//------------------------------------------------
void espiral()
{
  omni.mov_omni(40,25,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
  Serial.println("Espiral");
  digitalWrite(leds, HIGH);
  delay (7000);
  digitalWrite(leds, LOW);
  omni.mov_omni(0,0,0);
  delay(1000);
}

//------------------------------------------------
void alinha() // Rotina para alinhar o robô
{
  Serial.println("Alinha");

  ler_bussola();
  Serial.print("Bearing:");
  Serial.println(bearing);


  while(bearing<230 || bearing>250)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial)
  {
    omni.mov_omni(0,40,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
    delay (100);
    ler_bussola();        //Ler a bússola
    Serial.print("Bearing:");
    Serial.println(bearing);
    delay (30);
  }
  omni.stop_motors();           // pára todos os motores
  delay(10);
}

//------------------------------------------------
void alinha_contrario() // Rotina para alinhar o robô
{
  ler_bussola();
  while (bearing<0 || bearing>40)  // 200 Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial 80-180)
  {
    omni.mov_omni(0,40,0); //omni.mov_omni(linear ,rotação ,direção)Movimentar o robô
    delay (100);
    ler_bussola();        //Ler a bússola
    Serial.print("Bearing:");
    Serial.println(bearing);
    delay (30);
  }
  omni.stop_motors();           // pára todos os motores
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
  bearing = ((highByte<<8)+lowByte)/10;      // Calcula full bearing
  fine = ((highByte<<8)+lowByte)%10;         // Calcula decimal place of bearing
  delay(100);
}

//-------------------------------------
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
