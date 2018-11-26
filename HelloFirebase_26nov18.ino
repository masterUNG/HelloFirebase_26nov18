#include <ESP8266WiFi.h>


//Config Connected Router
#define WiFi_SSID "MastreEWTC_2.4G"
#define WiFi_Password "12345abcde"

//Explicit
int countInt = 0;



void setup() {

  Serial.begin(9600);

//  Connected Router
  WiFi.mode(WIFI_STA);
  WiFi.begin(WiFi_SSID, WiFi_Password);
  Serial.print("Conecting");

  while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }

    Serial.println();
    Serial.print("Success Connected : ");
    Serial.println(WiFi.localIP());

    

 
} // setup

void loop() {

//    Increase countInt
    countInt++;

    Serial.print("countInt ==> ");
    Serial.println(countInt);

    delay(1000);
} // loop
