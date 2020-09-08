int data;
int sensor=D3;
int led=D4;
void setup() {
  // put your setup code here, to run once:
  pinMode(D3,INPUT);
  pinMode(D4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data=digitalRead(sensor);
  if(data==HIGH){
  digitalWrite(led,HIGH);
  }
  else
  
    digitalWrite(led,LOW);
  
   

}
