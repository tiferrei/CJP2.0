int ledPin =  13;      // the number of the LED pin
int rele= 12;

void setup() {
  pinMode(ledPin, OUTPUT);   
pinMode(rele, OUTPUT);  
}

void loop()
{
  digitalWrite(rele, HIGH);
  delay (1000);
   digitalWrite(ledPin, HIGH);
  delay (1000);
  digitalWrite(ledPin, LOW);
  delay (1000);
  digitalWrite(rele, LOW);
  delay (1000);

}





