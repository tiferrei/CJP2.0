#include <Wire.h>                   // required by Omni3MD.cpp
#include <Omni3MD.h>

//constants definitions
#define OMNI3MD_ADDRESS 0x30        // default factory address
#define COMPASS_ADDRESS 0x60

Omni3MD omni;          //declaration of object variable to control the Omni3MD
//Variables to read from Omni3MD

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
    Wire.begin();  
    delay(10);                          // pause 10 milliseconds

    omni.stop_motors();                 // stops all motors
    delay(10);

    omni.set_i2c_timeout(0); // safety parameter -> I2C communication must occur every [byte timeout] x 100 miliseconds for motor movement                             
    delay(5);                 // 5ms pause required for Omni3MD eeprom writing

    omni.set_PID(250,400,125); // Adjust paramenters for PID control [word Kp, word Ki, word Kd]
    delay(15);                 // 15ms pause required for Omni3MD eeprom writing

    omni.set_ramp(500,1500,1000);   // set acceleration ramp and limiar take off parameter gain[word ramp_time, word slope, word Kl] 
    delay(15);                 // 10ms pause required for Omni3MD eeprom writing
    
    omni.stop_motors();
}

void loop()
{
   imprime_valores();
  alinhar_robo(); // chamar esta rotina sempre que quiser alinhar o robô


}


//------------------------------------------------
void alinhar_robo() // Rotina para alinhar o robô
{

  ler_bussola(); 
  while (bearing<0 || bearing>160)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico
  {
    omni.mov_omni(0,60,0); //Movimentar o robô
    delay (50);
    ler_bussola();        //Ler a bússola
    delay (30);
  }

  omni.stop_motors();

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
  pitch = Wire.read();              
  roll = Wire.read();

  bearing = ((highByte<<8)+lowByte)/10;      // Calculate full bearing
  fine = ((highByte<<8)+lowByte)%10;         // Calculate decimal place of bearing
  delay(50);
}

void imprime_valores()
{
  Serial.print("\nBearing:");
  Serial.println(bearing);    // prints bearing Value on screen
  Serial.print("Pitch:");
 
  delay(500);
}




