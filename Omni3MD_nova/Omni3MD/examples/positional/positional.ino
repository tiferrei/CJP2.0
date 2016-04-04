/*
 Omnidireccional 3 motor PID control using Omni3MD (www.botnroll.com)
 List of available routines to control Omni3MD board;
 - this code assumes you are using 1,2 or 3 DC motors with encoders attached to Omni3MD board;
 - this example was developed using Arduino 1.0.4 open-source Arduino environment
 - this example is compatible with Omni3MD firmware version 1.73.00 or higher. Visit http://www.botnroll.com/omni3md/ to check if your version is updated.


Purpose:
 This example demonstrates positional movimentation:
 
 Here are the necessary steps for one motor:
 
 1-The encoder prescaler must be configured as necessary;
   Function: set_prescaler( encoder, value )
   - encoder: the encoder/motor to operate (1, 2 or 3);
   - value: the prescaler configuration value (0, 1, 2, 3 or 4)
      1-encoder count will increment every 1 pulse
      2-encoder count will increment by 1 every 100 pulses
      3-encoder count will increment by 1 every 1000 pulses       
      4-encoder count will increment by 1 every 10000 pulses
   Ex:omni.set_prescaler(1, 3);
       
 2-A motor will be loaded with the preset position;
   Function: set_enc_value( encoder , encValue )
   - encoder: the encoder/motor to operate (1, 2 or 3);
   - encValue: the preset value(actual position). This is a 2Byte int variable so values can be between -32768 to +32767;
   Ex:omni.set_enc_value(1,0);
   
 3-The motor receives the movimentation order: 
   Function: mov_pos( motor, speed, encPosition, stoptorque )
   - motor: the encoder/motor to operate (1, 2 or 3);
   - speed: the desired speed for the movement (-100 to +100)
   - encPosition: the goal position. This is a 2Byte int variable so values can be between -32768 to +32767;
   - stoptorque: define how motor stops. 1->motor stops with holding torque provided by the PID control. 0->motor stops freely.
   Ex:omni.mov_pos(1,60,3200,1);
   The motor starts running at the desired spped and will stop when the goal position is reached;

 4-You can save the actual position on eeprom when necessary;
   Function: save_position()
   This function requires a delay for eeprom writing and Omni3MD will not respond for 15ms.
   Ex: omni.save_position();
   
Note:
   There is no overflow control for the encoder positional value by the Omni3MD.
   User should select the correct prescaler and control the overflow when necessary.
   This is a 2Byte int variable so the limit values are -32768 and +32767.
   
   
 In this example Encoder values are printed in serial monitor as motors are running.
 
 IMPORTANT!
 Before you upload this example, you must calibrate and configure PID control parameters for you system. 
 
   Follow this steps:
 
   1-Use the calibration routine, setting the function parameters to 0 or 1, to define the desired postive rotation for each motor.
     Ex: omni.calibrate(1,0,0);
     
   3-Set the PID control parameters kp, ki and kd
     Function: set_PID( Kp, Ki, Kd )
     - kp: Proportional gain. For kp=1 input the value 1000, for kp=0.5 input the value 500. Positive values only!
     - ki: Integral gain. For ki=1 input the value 1000, for ki=0.5 input the value 500. Positive values only!
     - kd: Diferential gain. For kd=1 input the value 1000, for kl=0.5 input the value 500. Positive values only!
     Ex:omni.set_PID(700,400,200);
     
   Optionally you can adjust the acceleration ramp and the kl parameter:
     Function: set_ramp( ramp_time , kl )
     - ramp_time: defines the time your robot accelerates from zero to the maximum speed (ramp inclination). 
       Values should be inputed in milliseconds. For 1 second you should input the value 1000 as a parameter. Positive values only!
       The value 0 disables this function. 32 seconds is the maximum possible time for the ramp.
     - kl: is used in the particular situation when a motor receives an order to move and its previous order was "stopped". 
       In this situation a Power*kl is loaded for the integral error of the PID control. Positive values only!
       The value 0 disables this function.
       This value is collected during calibration and corresponds to the power needed to win the motor&gearbox inertia.
 
 Important routines in this example:
      //setup routines
      void i2c_connect(byte omniAddress);
      void calibrate(byte way1,byte way2,byte way3);
      void set_PID(int Kp, int Ki, int Kd);
      void set_ramp(int ramp_time, int Kl);
      void set_prescaler(byte encoder, byte value);
      void set_enc_value(byte encoder, int encValue);
      
      //movement routines
      void mov_pos(byte motor,int speed,int encPosition,byte stoptorque);

 
 Omni3MD board features: 
 - Holonomic movement integrated control of 3 motors with PID control;
 - Diferencial movement (SI units) with PID control;
 - Linear control of 3 independent motors with or without PID control;
 - Independent positional control using encoder presets and readings;
 - Encoder readings;
 - Battery reading;
 - Temperature reading;
 
 
 The circuit:
 * Omni3MD board attached to Arduino analog input 4 (SDA) and 5 (SCL), GND and 5V DC.
 
 This example was created by José Cruz (www.botnroll.com)
 on 27 September 2012
 Updated on 10 May 2013


 This code example is in the public domain. 
 http://www.botnroll.com
*/
 
#include <Wire.h>                   // required by Omni3MD.cpp
#include <Omni3MD.h>

//constants definitions
#define OMNI3MD_ADDRESS 0x30        // default factory address
#define M1  1            //Motor1
#define M2  2            //Motor2
#define M3  3            //Motor3

Omni3MD omni;          //declaration of object variable to control the Omni3MD

//Variables to read from Omni3MD
int enc1=0;            // encoder1 reading, this is the encoder incremental count for the defined prescaler (positional control)
int enc2=0;            // encoder2 reading, this is the encoder incremental count for the defined prescaler (positional control)
int enc3=0;            // encoder3 reading, this is the encoder incremental count for the defined prescaler (positional control)
float battery=0;       // battery reading
float temperature=0;   // temperature reading
byte firm_int=0;      // the firmware version of your Omni3MD board (visit http://www.botnroll.com/omni3md/ to check if your version is updated)
byte firm_dec=0;      // the firmware version of your Omni3MD board (visit http://www.botnroll.com/omni3md/ to check if your version is updated)
byte firm_dev=0;      // the firmware version of your Omni3MD board (visit http://www.botnroll.com/omni3md/ to check if your version is updated)
byte ctrl_rate;        // the control rate for your motors defined at calibration (in times per second)
int enc1_max;          // maximum count for encoder 1 at calibration, for the defined control rate
int enc2_max;          // maximum count for encoder 2 at calibration, for the defined control rate
int enc3_max;          // maximum count for encoder 3 at calibration, for the defined control rate

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
    omni.set_i2c_timeout(20); // safety parameter -> I2C communication must occur every [byte timeout] x 100 miliseconds for motor movement                             
    delay(5);                 // 5ms pause required for Omni3MD eeprom writing

    omni.set_PID(700,400,200); // Adjust paramenters for PID control [word Kp, word Ki, word Kd]
    delay(15);                 // 15ms pause required for Omni3MD eeprom writing

    omni.set_ramp(500,1200,900);   // set acceleration ramp and limiar take off parameter gain[word ramp_time, word slope, word Kl] 
    delay(15);                 // 10ms pause required for Omni3MD eeprom writing
    
    //set_prescaler(byte encoder, byte value)  value: 0 - 1 pulse; 1 - 10 pulses; 2 - 100 pulses; 3 - 1000 pulses; 4 - 10000 pulses
    omni.set_prescaler(M1, 0);     //sets the prescaler to 1; encoder count will increment every 1 pulse [byte encoder, byte value]
    delay(10);                     // 10ms pause required for Omni3MD eeprom writing
    omni.set_prescaler(M2, 2);     //sets the prescaler to 100; encoder count will increment by 1 each 100 pulses [byte encoder, byte value]
    delay(10);                     // 10ms pause required for Omni3MD eeprom writing
    omni.set_prescaler(M3, 3);     //sets the prescaler to 1000; encoder count will increment by 1 each 1000 pulses [byte encoder, byte value]
    delay(10);                     // 10ms pause required for Omni3MD eeprom writing

    omni.read_firmware(&firm_int,&firm_dec,&firm_dev); // read firmware version value
    Serial.print("Firmware:");  
    Serial.print(firm_int);             // prints firmware value
    Serial.print(".");  
    Serial.print(firm_dec);             // prints firmware value
    Serial.print(".");  
    Serial.println(firm_dev);             // prints firmware value
    ctrl_rate=omni.read_control_rate();   // read the control rate value
    Serial.print("Control_Rate:");
    Serial.println(ctrl_rate);            // prints control rate value
    enc1_max=omni.read_enc1_max();        // read encoder1 maximum value at calibration (usefull for detecting a faulty encoder)
    Serial.print("Encoder1_max:");
    Serial.println(enc1_max);              // prints encoder1 maximum calibration value
    enc2_max=omni.read_enc2_max();        // read encoder1 maximum value at calibration (usefull for detecting a faulty encoder)
    Serial.print("Encoder2_max:");
    Serial.println(enc2_max);              // prints encoder2 maximum calibration value 
    enc3_max=omni.read_enc3_max();        // read encoder1 maximum value at calibration (usefull for detecting a faulty encoder)
    Serial.print("Encoder3_max:");
    Serial.println(enc3_max);              // prints encoder3 maximum calibration value
    battery=omni.read_battery();          // read battery value
    Serial.print("Battery:");
    Serial.println(battery);              // prints battery value
    temperature=omni.read_temperature();  // read temperature value
    Serial.print("Temperature:");
    Serial.println(temperature);          // prints temperature value
    delay(2000);   
}

//Print values in serial monitor
void print_enc_values()
{
     Serial.print("enc1:");
     Serial.print(enc1);           // prints encoder 1 positional value
     Serial.print(" enc2:");
     Serial.print(enc2);           // prints encoder 2 positional value
     Serial.print(" enc3:");
     Serial.println(enc3);           // prints encoder 3 positional value
}

void loop()
{
    //Variables for motion control
    int speed1=90;
    int speed2=-90;
    int speed3=90;
    int preset1=-3200;
    int preset2=32;
    int preset3=-3;
    int pos1=3200;
    int pos2=-32;
    int pos3=3;

    //Encoder preset
    omni.set_enc_value(M1,preset1);      // resets to zero the encoder value [byte encoder, word encValue]
    omni.set_enc_value(M2,preset2);      // resets to zero the encoder value [byte encoder, word encValue]
    omni.set_enc_value(M3,preset3);      // resets to zero the encoder value [byte encoder, word encValue]
    omni.read_encoders(&enc1,&enc2,&enc3); // read all encoders at once (in a single I2C request) 
    print_enc_values();    //Print values in serial monitor
    delay(1000);
    
    //Send movement instructions    
    omni.mov_pos(M1,speed1,pos1,1);  // move motor1 at speed1 until encoder count reaches the defined position and then stop with holding torque
    delay(1);                        // wait 1ms for Omni3MD to process information
    omni.mov_pos(M2,speed2,pos2,0);  // move motor2 at speed2 until encoder count reaches the defined position  and then stop without holding torque
    delay(1);                        // wait 1ms for Omni3MD to process information
    omni.mov_pos(M3,speed3,pos3,1);  // move motor3 at speed3 until encoder count reaches the defined position  and then stop with holding torque
    delay(1);                        // wait 1ms for Omni3MD to process information
    while(enc1<pos1 && enc2>pos2 && enc3<pos3)
    {
      omni.read_encoders(&enc1,&enc2,&enc3); // read all encoders at once (in a single I2C request) 
      print_enc_values(); //Print values in serial monitor
      delay(100);
    }
    omni.save_position();  //save encoders positional data to eeprom
    delay(15);             // 15ms pause required for Omni3MD eeprom writing
    delay(2000);  // pause 2 seconds
}
