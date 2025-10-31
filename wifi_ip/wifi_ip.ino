/*
int ledPin = 4;
int ledSari =14 ;
int ledYesil= 27;
const int buttonPin = 33;
*/

#include <WiFi.h>
#include <WebServer.h>

const char* SSID = "Bihtus";
const char* PASS = "Mertebru2002";

const int LED_PIN = 27;
WebServer server(80);
int durum = LOW;

String sayfa() {
  return String("<h2>ESP32 LED</h2>Durum: ") + (durum?"ACIK":"KAPALI") +
         "<br><a href='/on'>AÇ</a> | <a href='/off'>KAPAT</a>";
}

void handleRoot(){ server.send(200,"text/html",sayfa()); }
void handleOn(){  durum=HIGH; digitalWrite(LED_PIN,durum); handleRoot(); }
void handleOff(){ durum=LOW;  digitalWrite(LED_PIN,durum); handleRoot(); }

void setup() {
  pinMode(LED_PIN, OUTPUT); digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
  WiFi.begin(SSID, PASS);
  while (WiFi.status()!=WL_CONNECTED){ delay(300); Serial.print("."); }
  Serial.println("\nIP: " + WiFi.localIP().toString());
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop(){ server.handleClient(); }
