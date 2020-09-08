#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[]="Cdu_rMLXwGjRKYeL3uQ_Vta89AuQtfWR";
char ssid[]="Galaxy A30s";
char pass[]="1122334455";



void setup() {
 Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
 Blynk.run(); 
}
