int led=D3;
int data;
int sen=D4;
void setup() 
{
  pinMode(sen,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() 
{
 data=digitalRead(sen);
 if(data==LOW)
 {
  
  Serial.println("obstacle");
  digitalWrite(led,HIGH);
  delay(1000);
 }
 else
 {
  Serial.println("free path");
  digitalWrite(led,LOW);
  delay(1000);
 }

}
