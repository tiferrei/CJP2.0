#include <Servo.h>  

Servo servoMotor;       
int servoPin = 13;       


void setup() { 
    
  servoMotor.attach(servoPin);  
} 

void loop() 
{ 
  

passaroco();
passaroco();passaroco();passaroco();passaroco();passaroco();passaroco();passaroco();passaroco();
delay(120000);
passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();passaroco2();


}



void passaroco(){
  
  servoMotor.write(15);  
delay(1000);
servoMotor.write(75);
delay(1000);
}

void passaroco2(){
  
  servoMotor.write(15);  
delay(500);
servoMotor.write(75);
delay(5000);
}
