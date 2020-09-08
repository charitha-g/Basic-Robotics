#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int i=0;

void setup() {
   pinMode(D0,INPUT); //RX
  servo1.attach(D0);
   pinMode(D1,INPUT);  //D1
  servo2.attach(D1);
   pinMode(D2,INPUT); //D
  servo3.attach(D2);
   pinMode(D3,INPUT);   //S3
  servo4.attach(D3);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  delay(5000);
}

void loop() {
  for(i=10; i<=180; i++)
   {
    servo1.write(i);
    servo2.write(i);
    delay(20);
   }
   delay(100);
    for(int i=100; i>=10; i--)
   {
    servo3.write(i);
    servo4.write(i);
    delay(20);
   }
    
}
