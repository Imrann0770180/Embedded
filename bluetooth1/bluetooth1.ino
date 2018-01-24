/*
  Bluetooth communication

  By putting Serial this will print the messages in the serial monitor
  By putting Serial1 this will print the messages in putty window

  Was unsure what you wanted for task 14 of the lab but I understand how to display the message in
  the arduino program and external program like putty.
 */
int led1 = 11;                          // Use digital pin 11 for the led
char inVal;                             // Use this to read a character from the serial port

/****************************************************************************************************************************/

void setup() 
{
  pinMode(led1, OUTPUT);                // Initialise digital pin for the LED
  //Serial.begin(115200);                // Set the Baudrate to 115200 on putty as well (note which serial port) 
  Serial1.begin(115200);
}

/***************************************************************************************************************************/

void loop() 
{
  if (Serial1.available()>0)            // Will only read the serial when something is entered (have to enter the x twice to stop)
    {
    inVal=Serial1.read();               // Reads data from the serial port
    
    if(inVal == '1')                    // If you enter 1 the  first LED will turn on then off
    {                                   
      digitalWrite(led1, HIGH);         // Turns the LED 1 on
      Serial1.println("You entered 1"); // Prints out this message
      delay(200);                      // Wait for 2 seconds
      //digitalWrite(led1, LOW);          // Turns the LED 1 off
    }

   else                                 // If there is no input from the serial line, turn the LED's off and displays a message
  {
      digitalWrite(led1, LOW);
      Serial1.println("Waiting for command.......");   
      delay(20);
  }
    }
}
