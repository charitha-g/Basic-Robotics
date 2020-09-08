#define BLYNK_PRINT Serial  // connects to blink app
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>
//#include <D:\Aditya\Robotics & IoT\car_directiona\car_directiona.ino>
Servo servo1;
Servo servo2;
char auth[] = "Cdu_rMLXwGjRKYeL3uQ_Vta89AuQtfWR";
char ssid[] = "Galaxy A30s";
char pass[] = "1122334455";

int pos=0;

void setup()
{
  Serial.begin(9600);
   /*pinMode(p1,OUTPUT);
   pinMode(m1,OUTPUT);
   pinMode(p2,OUTPUT);
   pinMode(m2,OUTPUT);*/
  Blynk.begin(auth, ssid, pass);
  servo1.attach(D4);
  servo2.attach(S3);

  servo1.write(90);
  servo2.write(90);

}


BLYNK_WRITE(V0) // Button Widget writes to Virtual Pin V0 
{ 
  if (param.asInt() == 1)
    {
       for (pos = 10; pos <= 180; pos++) 
 {
   servo1.write(pos); 
   servo2.write(pos); 
              
    delay(15);                      
  }
    }
  else
  {
   servo1.write(90);              // tell servo to go to position in variable 'pos'
        servo2.write(90); 
}

}

BLYNK_WRITE(V6) // Button Widget writes to Virtual Pin V5 
{ 
  if (param.asInt() == 1)
    {
          for (pos = 180; pos >= 10; pos--) 
 {
   servo2.write(pos);
   servo1.write(pos);            
    delay(15);                      
  }
    }
  else
  {
   servo1.write(90);              // tell servo to go to position in variable 'pos'
        servo2.write(90); 
}

}
void loop()
{
  Blynk.run();
   
}  
