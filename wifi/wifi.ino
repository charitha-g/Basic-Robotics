#include <ESP8266WiFi.h>  //gpio pin numbers: D7=13  // it is used to on the wifi in node mcu 
#include <Servo.h>

const char* ssid = "Galaxy A30s";     //wifi name
const char* password = "1122334455";   //wifi password

int ledPin = 13 ;//GPIOl3
WiFiServer Server(80);
Servo myservo;
 
void setup() 
{
Serial.begin(115200);  //specific baud rate previously present
delay(10);

pinMode(ledPin, OUTPUT);
digitalWrite(ledPin,LOW);  //led offs in the starting position
myservo.attach(2);
myservo.write(0);

//Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid,password);  //this func connects to the wifi

while (WiFi.status() != WL_CONNECTED)   //it shows ...... if not connected
{
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

//Start the server
Server.begin();
Serial.println("Server started");

//Print the IP address
Serial.print("Use this URL to connect:");
Serial.print("http://");
Serial.print(WiFi.localIP()); //used to get ipaddress of node mcu
Serial.println("/");

}

void loop() {
//Check if a client has connected
WiFiClient client = Server.available();
if (!client){
  return;
}

//Wait until the clent sends some data
Serial.println("new clent");
while(!client.available()){
  delay(1);
}

// Read the first line of the request
String request = client.readStringUntil('\r');
Serial.println(request);
client.flush();

//Match the request

int value = LOW;
if (request.indexOf("/LED=ON") != -1) {
  digitalWrite(ledPin, HIGH);
  value = HIGH;
  myservo.write(180);
}
if(request.indexOf("/LED=OFF") != -1) {
  digitalWrite(ledPin, LOW);
  value = LOW;
  myservo.write(90);
}

//Set ledPin according to the 
//digitalWrite(ledPin, Value);

//Return the response
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");

client.print("Led pin is now : ");

if (value == HIGH) {
  client.print("On");
}else {
  client.print("Off");
}
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href =\"/LED=OFF\"\"><button>Turn Off </button></a><br/>");
  client.println("</html>");

  delay(1);
 Serial.println("Client disconnected");
  Serial.println("");
  
}
