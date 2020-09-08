#include <Servo.h>
Servo servo1;
int data;
int sensor=D3;// variable to store the servo position
// red to Vcc , brown to gnd, orange to data 3 continous pins
void setup() {
   pinMode(D3,INPUT);
  servo1.attach(D4); //the pin to which the server motor is attached
  
}

void loop() 
{
  
  data=digitalRead(sensor);
  if(data==HIGH)
  { 
    for(int i=0; i<=180; i++)
    {
     servo1.write(i);
      delay(20);
    }
    
  }
  else
  {
  
      for(int i=180; i>=0; i--)
      {
      servo1.write(i);
      delay(20);
      }
     
   }

   
}
