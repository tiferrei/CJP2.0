int r = 9;
int g = 10;
int b = 11; // LED connected to digital pin 9
int analogr = 10;
int analogg = 9;
int analogb = 8;// potentiometer connected to analog pin 3
int val = 0;
int val2 = 0;
int val3 = 0;// variable to store the read value
int val_red;
int val_green;
int val_blue;


void setup()
{
  Serial.begin(9600);
  pinMode(r, OUTPUT);
 pinMode(g, OUTPUT);
 pinMode(b, OUTPUT); // sets the pin as output
}

void loop()
{
  val = analogRead(analogr); // read the input pin
  analogWrite(r, val / 4);  
  val_red = val / 4;// analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  
  val2 = analogRead(analogg);// read the input pin
  analogWrite(g, val2 / 4); 
  val_green = val2 / 4; // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  
  val3 = analogRead(analogb); // read the input pin
  analogWrite(b, val3 / 4);
  val_blue = val3 / 4;  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  
    int red = analogRead(A10);
  // print out the value you read:
  Serial.println("Vermelho:");
  Serial.println(val_red);
  delay(1);        // 
  
   
    int green = analogRead(A9);
  // print out the value you read:
  Serial.println("Verde:");
  Serial.println(val_green);
  delay(1);        // 
  
    int blue = analogRead(A8);
  // print out the value you read:
  Serial.println("Azul:");
  Serial.println(val_blue);
  delay(1);        // 
}
   

