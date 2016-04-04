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

//constants definitions

#define OMNI3MD_ADDRESS 0x30        // default factory address

Omni3MD myOmni;    // [byte omniAddress]

//variable declarations
byte linear_speed=0;                // linear speed varies from 0 (stopped) to 100 (max speed)
byte rotational_speed=100;          // rotation varies from 0 (CCW) to 200 (CW). At 100 it doesn't rotate.
int direc=0;                        // direction varies from 0 (front) to 359 degrees.

float myOmniTemperature=0;
float myOmniBattery=0;
float myOmniFirmware=0;



void debug()
{
  Serial.print("Temperature:");
  Serial.println(myOmniTemperature);    // prints temperature Value
  Serial.print("Battery:");
  Serial.println(myOmniBattery);        // prints battery Value
  Serial.print("Firmware:");
  Serial.println(myOmniFirmware);       // prints firmware Value
  Serial.print("Control Time:");
  Serial.println(control_time);
}

void setup()
{
    //setup routines
    Serial.begin(9600);             // set baud rate to 9600 bps
    myOmni.i2c_connect(OMNI3MD_ADDRESS); //set i2c connection
    delay(10);                      // pause 10 milliseconds
    myOmni.set_way(0x01);           // set the correct way value according to the motor gearbox [byte way]
    delay(10);                     // pause 10 milliseconds
    //myOmni.calibrate_omni();        // send the calibration comand to configure the OMmni3MD board
    //delay(11000);                   // wait 11s for calibration to end
    myOmni.stop_motors();           // stops all motors
    delay(10);
    control_time=(1000/myOmni.read_control_rate())*2;

    myOmni.set_i2c_timeout (control_time/20);  // [byte timeout] x 100 miliseconds to receive i2C Commands or 0x00 for no timeout
    delay(10);
    myOmni.set_PID(40,40,20);        // set PID parameters Kp, Ki and Kd [word Kp, word Ki, word Kd]
    delay(10);

    //reading routines
    myOmniTemperature=myOmni.read_temperature();  //read Temperature Value
    myOmniBattery=myOmni.read_battery();          //read Battery Value
    myOmniFirmware=myOmni.read_firmware();        //read Firmware version

    debug();                        // print debug information
}

void loop()
{
  linear_speed=20;                                                  //20% of maximum speed
  direc=180;                                                       //direction forward

  for (rotational_speed= 0 ; rotational_speed < 200; rotational_speed+=10)
  {
     myOmni.mov_omni_pid(linear_speed,rotational_speed,direc);     //[byte linear_speed,byte rotational_speed,word direction]
     delay(control_time);                                          //pause
  }
  for (rotational_speed= 200 ; rotational_speed > 0; rotational_speed-=10)
  {
     myOmni.mov_omni_pid(linear_speed,rotational_speed,direc);     //[byte linear_speed,byte rotational_speed,word direction]
     delay(control_time);                                          // pause
  }
}
