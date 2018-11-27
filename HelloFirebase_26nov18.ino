#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>



//Config Connected Router
#define WiFi_SSID "MastreEWTC_2.4G"
#define WiFi_Password "12345abcde"

//Config Connected Firebase Database
#define Firebase_Host "greenhouse-2ee0d.firebaseio.com"
#define Firebase_Auth "YaSVvF9q3BWZsXV5djPX2KUwqhUEveA1VBHMKuXd"

//Config SwitchLED
#define SwitchLED D1

//Explicit
int countInt = 0;
int sinalFirebase = 0;



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

//    Start Connected Firebase
    Firebase.begin(Firebase_Host, Firebase_Auth);

//    Config OutPut
    pinMode(SwitchLED, OUTPUT);

 
} // setup

void loop() {

//    Increase countInt
    countInt++;

    Serial.print("countInt ==> ");
    Serial.println(countInt);

//    Post Valut To Firebase
    Firebase.setInt("FromNode/numberAnInt", countInt);


//    Read Value From Firebase
   sinalFirebase = Firebase.getInt("FromMobile/sinal");
   Serial.print("sinalFirbase ==> ");
   Serial.println(sinalFirebase);

   if (sinalFirebase == 1) {
      digitalWrite(SwitchLED, HIGH);
    } else {
      digitalWrite(SwitchLED, LOW);
      }
    

    delay(1000);
} // loop
