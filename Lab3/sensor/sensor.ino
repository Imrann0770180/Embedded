#define ECHOPIN 3
#define TRIGPIN 2
int led = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
  float distance = pulseIn(ECHOPIN, HIGH); 
  distance = distance/29 / 2;
  Serial.print(distance);
  Serial.println("cm");
  delay(200);
  if (distance < 10) 
  {
  for (int j=1; j<=5; j++) {   
    digitalWrite(led,HIGH); 
    delay(200);             
    digitalWrite(led,LOW); 
    delay(200);            
}
   }
}
