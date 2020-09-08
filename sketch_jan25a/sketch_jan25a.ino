void setup() 
{
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  // put your setup code here, to run once:

}

void loop() 
{
  for(int i=1;i<=4;i++)
  {
  digitalWrite(D3,HIGH);
  delay(50);
  digitalWrite(D3,LOW);
  delay(50);
  }
  digitalWrite(D4,HIGH);
  delay(200);
  
  digitalWrite(D4,LOW);
  
  delay(200);
  
  // put your main code here, to run repeatedly:

}
