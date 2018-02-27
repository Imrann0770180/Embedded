
//////////// Mini project:  Traffic Light Controller


// The calling function is declare here and some value

#define ECHOPIN 3
#define TRIGPIN 2
void regular_mode();
void pedestrian_mode();
void light_depend();
void sensor_distance();
void sensor_distance1();
void sensor_Value();
int sensorPin = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int x;
int buzzer = 8; // buzzer is connected to digital pin 8
int red = 9; // red led is connected to digital pin 9
int yellow = 10; // yellow led is connected to digital pin 10
int green = 11; // green led is connected to digital pin 11
float distance;
char var; // this is the varable to hold the user serail input 
String inString = "";    // string to hold input


// the setup routine runs once when you press reset:
void setup() 
{                

// initialize the digital pin as an output.
Serial.begin(9600);
 pinMode(red, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(ECHOPIN, INPUT);
 pinMode(TRIGPIN, OUTPUT);
 pinMode(buzzer, OUTPUT);
}
void loop() 
{ 
  
 // the loop routine runs over and over again forever:
 if (Serial.available()>0)
 {
  var=Serial.read();
    switch(var)
    {
      
      case 'r': // this case work in regular mode

      
      {
        Serial.println(var);
do{
   
      regular_mode(); // calling function
      if (Serial.available()>0)
    {
      var=Serial.read();
    }
    
    }      
  while (var == 'r');
    }
      
        break;    
     
   
      
    case 'p': // this case work in pedestrian mode
    
    {
     Serial.println(var);
while(var == 'p') {

            pedestrian_mode();
            sensor_distance();
          if(Serial.available() > 0)
          {
            var=Serial.read();
      Serial.println(var);
          }

  }
  
  
    }     
  break;
   
   case 'n': // this mode work in night mode

   {
      Serial.println(var);
 do{
      light_depend();
      
      
      //sensor_Value();
     if (Serial.available()>0)
      {
        var=Serial.read();
      }
          
   }
    while (var =='n');
  }
    break;
     
   }
 }

}

// Calling function code

void regular_mode()

         {
            digitalWrite(red, HIGH);
            delay(2000);
            digitalWrite(red, LOW);
            digitalWrite(yellow, HIGH);
            delay(1000);
            digitalWrite(yellow, LOW);
            digitalWrite(green, HIGH);
            delay(2000);
            digitalWrite(green, LOW);
            digitalWrite(yellow, HIGH);
            delay(1000);
            digitalWrite(yellow, LOW);
         } 

void pedestrian_mode()

      {
          digitalWrite(TRIGPIN, LOW); 
          delayMicroseconds(2);
          digitalWrite(TRIGPIN,HIGH);
          delayMicroseconds(10);
          digitalWrite(TRIGPIN,LOW); 
          distance = pulseIn(ECHOPIN, HIGH); // return 0 if no high pulse in 1sec
          distance = distance/58;
          Serial.print(distance);
          Serial.println("cm");
          delay(200);
          
        if (distance<10)
          {
           
        for (int x = 0; x <= 10; x++) 
         {
           tone(8,9600);
           digitalWrite(yellow, HIGH);   // set the LED on
           delay(100);             
           digitalWrite(yellow, LOW);    // set the LED off
           delay(100);
         }
   
     

   

     }

      else {
              noTone(8);
      regular_mode();
     
      }
      }
      
void sensor_distance()

      {
      /*  if (distance<10)
          {
           tone(8,9600);
          // for (int x = 0; x <= 10; x++) 
         //{
           digitalWrite(yellow, HIGH);   // set the LED on
           delay(100);             
           digitalWrite(yellow, LOW);    // set the LED off
           delay(100);
           goto imran;  
        // }
           noTone(8);
         }*/
       if  (distance>10)
     {
     regular_mode();
     pedestrian_mode();
   

     }
       }

  
void light_depend()

   {
    sensorValue = analogRead(sensorPin); // read the value from the sensor
    Serial.println(sensorValue); //prints the values coming from the sensor on the screen
    delay(100);
     if (sensorValue > 800)
    {
      regular_mode();
      
      
//      sensor_distance1();
    } 
      
        else
     
    {
      int io =0;
      digitalWrite(red, HIGH);
      while( io == 0 )
      {
       
          digitalWrite(TRIGPIN, LOW); 
          delayMicroseconds(2);
          digitalWrite(TRIGPIN,HIGH);
          delayMicroseconds(10);
          digitalWrite(TRIGPIN,LOW); 
          distance = pulseIn(ECHOPIN, HIGH); // return 0 if no high pulse in 1sec
          distance = distance/58;
          Serial.print(distance);
          Serial.println("cm");
          delay(200);

          if ( distance < 10)
          {
            digitalWrite(green, HIGH);
            digitalWrite(red, LOW);
          }
          else
          {
            digitalWrite(green, LOW);
            io++;
          }
      }
    }
    }

    
   
    
void sensor_Value()

    {

      
      if (sensorValue<450)
    {
      pedestrian_mode();
      sensor_distance1();
    } 
      
        else
     
    {
       regular_mode();
       light_depend();
    }
    }
    

void sensor_distance1()

   {
    
    if (distance<10)
    {
      digitalWrite(green, HIGH);
      digitalWrite(green,HIGH);
    }
    else
    {
     digitalWrite(red, LOW);
      digitalWrite(red, LOW);
    }
   
}
