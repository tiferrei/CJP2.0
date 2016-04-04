// Copyright (c) 2014 The CJP2.0 Team

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Wire.h>                   // required by Omni3MD.cpp
#include <Omni3MD.h>

#define OMNI3MD_ADDRESS 0x30        // default factory address
#define PARAMETRO 0
#define GET_VAL   1
#define SET_VAL   2
#define MOVIMENTO 3

Omni3MD omni;          //declaration of object variable to control the Omni3MD

int inPar = 0;   // for incoming serial data
int inVal = 0;   // for incoming serial data
int estado=PARAMETRO;  // Menu

int rot_speed=0;
int dir=0;
int lin_speed=50;
int kp=0; //750
int ki=0; //300
int kd=0;//600;
int ramp_time=1000;//400;
int ramp_slope=1100;
int limiar_factor=0;//;400;

void setup()
{
    Serial.begin(57600);     // opens serial port, sets data rate to 9600 bps
    omni.i2c_connect(OMNI3MD_ADDRESS);  // set i2c connection
    delay(10);                          // pause 10 milliseconds
    omni.stop_motors();                 // stops all motors
    delay(10);

    omni.set_i2c_timeout(0); // safety parameter -> I2C communication must occur every [byte timeout] x 100 miliseconds for motor movement
    delay(5);                 // 5ms pause required for Omni3MD eeprom writing

    omni.set_PID(kp,ki,kd); // Adjust paramenters for PID control [word Kp, word Ki, word Kd]
    delay(20);      // 15ms pause required for Omni3MD eeprom writing

    omni.set_ramp(ramp_time,ramp_slope,limiar_factor);   // set acceleration ramp and limiar take off parameter gain[word ramp_time, word Kl]
    delay(20);                 // 10ms pause required for Omni3MD eeprom writing               // 10ms pause required for Omni3MD eeprom writing
}

int counter=0;

void loop()
{
   Serial.println("Parametro a ajustar: v p i d t s l ");
   while(estado==PARAMETRO)
   {

        delay(100);
        counter+=100;
        Serial.print(".");

        int serial_count=0;
        if (Serial.available() > 0)
        {
            // read the incoming byte:
            inPar =(int) Serial.read();

            // say what you got:
            Serial.println();
//            Serial.print("E1 I received: ");
//            Serial.println(inPar);
            serial_count++;
        }

        if(serial_count>0)
        {
           estado=GET_VAL;
            switch(inPar)
            {
                case 112:  // Kp
                case 80:
                        Serial.print("Kp=");
                        Serial.print(kp);
                        Serial.print("  Definir novo Kp:");
                        break;
                case 105:    //Ki
                case 73:
                        Serial.print("Ki=");
                        Serial.print(ki);
                        Serial.print("  Definir novo Ki:");
                        break;
                case 68:    //Kd
                case 100:
                        Serial.print("Kd=");
                        Serial.print(kd);
                        Serial.print("  Definir novo Kd:");
                        break;
                case 84:    //Time
                case 116:
                        Serial.print("Ramp Time=");
                        Serial.print(ramp_time);
                        Serial.print("  Definir novo Ramp Time:");
                        break;
                case 115:     //Slope
                case 83:
                        Serial.print("Ramp Slope=");
                        Serial.print(ramp_slope);
                        Serial.print("  Definir novo Ramp Slope:");
                        break;
                case 108:    //Limiar
                case 76:
                        Serial.print("Limiar Kl=");
                        Serial.print(limiar_factor);
                        Serial.print("  Definir novo Limiar Kl:");
                        break;
                case 118:     //VLin
                case 86:
                        Serial.print("VLinear=");
                        Serial.print(lin_speed);
                        Serial.print("  Definir novo VLinear:");
                        break;
                default:
                        Serial.println("Input Invalido!");
                        delay(500);
                        estado=PARAMETRO;
                        break;
            }
        }

        if(counter>2100)
        {
            counter=0;
            estado=MOVIMENTO;
            Serial.println("Movimento!");
        }
   }
   while(estado==GET_VAL)
   {
         int serial_count=0;
        // send data only when you receive data:
        if (Serial.available() > 0)
        {
                // read the incoming byte:
                inVal =(int) Serial.parseInt();

                // say what you got:
 //               Serial.print("E2 I received: ");
                Serial.println(inVal);
                serial_count++;
        }
        delay(100);
        if(serial_count>0) //Condição de saída
        {
            estado=SET_VAL;
        }

   }

   if(estado==SET_VAL)
   {
      switch(inPar)
      {
          case 112:  // Kp
          case 80:
                  kp=inVal;
                  break;
          case 105:    //Ki
          case 73:
                  ki=inVal;
                  break;
          case 68:    //Kd
          case 100:
                  kd=inVal;
                  break;
          case 84:    //Time
          case 116:
                  ramp_time=inVal;
                  break;
          case 115:     //Slope
          case 83:
                  ramp_slope=inVal;
                  break;
          case 108:    //Limiar
          case 76:
                  limiar_factor=inVal;
                  break;
          case 118:     //VLin
          case 86:
                  lin_speed=inVal;
                  break;
      }

      omni.set_PID(kp,ki,kd); // Adjust paramenters for PID control [word Kp, word Ki, word Kd]
      delay(20);                 // 15ms pause required for Omni3MD eeprom writing
      omni.set_ramp(ramp_time,ramp_slope,limiar_factor);   // set acceleration ramp and limiar take off parameter gain[word ramp_time, word Kl]
      delay(20);                 // 10ms pause required for Omni3MD eeprom writing

      Serial.print("  kp=");Serial.print(kp);
      Serial.print("  ki=");Serial.print(ki);
      Serial.print("  kd=");Serial.print(kd);

      Serial.print("  time=");Serial.print(ramp_time);
      Serial.print("  slope=");Serial.print(ramp_slope);
      Serial.print("  limiar=");Serial.println(limiar_factor);

       estado=MOVIMENTO;
   }

   if(estado==MOVIMENTO) //Movimento
   {
     move(270);
     move(90);
//     move(90);
//     move(0);
     estado=PARAMETRO;
   }
}

void move(int direcao)
{
    dir=direcao;
    omni.mov_omni(lin_speed,rot_speed,dir);    //move motors
    Serial.println();
    Serial.print(" Vlin="); Serial.print(lin_speed);
    Serial.print("  Vang=");Serial.print(rot_speed);
    Serial.print("  Dir=");Serial.println(dir);
    delay(2500);

    omni.stop_motors();
    Serial.println("Stoped!");
    delay(2000);
}
