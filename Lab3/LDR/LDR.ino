
int sensorPin = A0;            
unsigned int sensorValue = 0; 
int led = 8; 

void setup()
{
  pinMode(led, OUTPUT);

  Serial.begin(9600);        
}

void loop()
{
  
  sensorValue = analogRead(sensorPin);     

  Serial.println(sensorValue);
  if(sensorValue<400)
  {
    for(int i; i<=5; i++)
    {
      digitalWrite(led,HIGH);
      delay(200);
      digitalWrite(led,LOW);
      delay(200);
    }
  }

}
