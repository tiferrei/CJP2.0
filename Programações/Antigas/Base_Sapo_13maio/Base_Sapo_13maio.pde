

#include <Wire.h>                   // required by Omni3MD.cpp and compass
#include <Omni3MD.h>                // biblioteca para programar o omni

//constants definitions|

#define COMPASS_ADDRESS 0x60         // Defines address of CMPS10
#define OMNI3MD_ADDRESS 0x30        // default factory address

Omni3MD myOmni;    // [byte omniAddress]

//variable declarations
byte highByte, lowByte, fine;              // highByte and lowByte store high and low bytes of the bearing and fine stores decimal place of bearing

int bearing;         // Stores full bearing -> orientação,  pitch and roll values of CMPS10


byte linear_speed;                // linear speed varies from 0 (stopped) to 100 (max speed)
byte rotational_speed;          // rotation varies from 0 (CCW) to 200 (CW). At 100 it doesn't rotate.
int direc=0;                        // direction varies from 0 (front) to 359 degrees.


void setup()
{



  //setup routines
  Serial.begin(9600);             // set baud rate to 9600 bps
  Wire.begin();    // Conects I2C

  myOmni.i2c_connect(OMNI3MD_ADDRESS); //set i2c connection
  delay(10);                      // pause 10 milliseconds
  myOmni.set_way(0x01);           // set the correct way value according to the motor gearbox [byte way]
  delay(10);                     // pause 10 milliseconds
  //myOmni.calibrate_omni();        // send the calibration comand to configure the OMmni3MD board
  //delay(11000);                   // wait 11s for calibration to end
  myOmni.stop_motors();           // stops all motors
  delay(10);

  myOmni.set_PID(80,80,60);        // set PID parameters Kp, Ki and Kd [word Kp, word Ki, word Kd]
  delay(10);


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
  myOmni.mov_omni_pid(30,140,180); //Movimentar o robô direcao 120
  delay (1000);

}


//----------------------------

void rodaCW()
{   
  myOmni.mov_omni_pid(0,140,100); //Movimentar o robô direcao 120
  delay (1000);

}

//----------------------------

void rodaCCW()
{   
  myOmni.mov_omni_pid(0,60,100); //Movimentar o robô direcao 120
  delay (1000);

}
//-----------------------------
void dirE()
{   

  myOmni.mov_omni_pid(50,100,90); 
  delay (1000); 
  myOmni.stop_motors();           // stops all motors
  delay(10);

}

//-----------------------------
void dirD()
{   

  myOmni.mov_omni_pid(50,100,270); 
  delay (1000); 
  myOmni.stop_motors();           // stops all motors
  delay(10);

}


//------------------------------------------------
void alinha_publico() // Rotina para alinhar o robô
{

  ler_bussola(); 
  while (bearing<0 || bearing>30)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial 80-180)
  {
    myOmni.mov_omni_pid(0,60,0); //Movimentar o robô
    delay (100);
    ler_bussola();        //Ler a bússola
    delay (30);

  }  
  myOmni.stop_motors();           // stops all motors
  delay(10);
}



//------------------------------------------------
void alinha_orq() // Rotina para alinhar o robô
{

  ler_bussola(); 
  while (bearing<180 || bearing>210)  // Enquanto o robô estiver desalinhado   ||->ou lógico   &&->e lógico (valor inicial 80-180)
  {
    myOmni.mov_omni_pid(0,60,0); //Movimentar o robô
    delay (100);
    ler_bussola();        //Ler a bússola
    delay (30);

  }  
  myOmni.stop_motors();           // stops all motors
  delay(10);
}

//---------------------------------------
void ler_bussola()
{
  Wire.beginTransmission(COMPASS_ADDRESS);           //começa a comunicação com CMPS10
  Wire.send(2);                              //Envia o registo, queremos iniciar a leitura de
  Wire.endTransmission();

  Wire.requestFrom(COMPASS_ADDRESS, 4);              // Request 4 bytes from CMPS10
  while(Wire.available() < 4);               // Aguarde bytes para se tornar disponível
  highByte=Wire.receive();  
  lowByte = Wire.receive();            



  bearing = ((highByte<<8)+lowByte)/10;      // Calculate full bearing
  fine = ((highByte<<8)+lowByte)%10;         // Calculate decimal place of bearing
  delay(50);
}




























