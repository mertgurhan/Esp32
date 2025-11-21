#include <WiFi.h>

const char* ssid="Bihtus";
const char* password="Mertebru2002";

int ledPin = 4;
int ledSari =14 ;
int ledYesil= 27;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Baglaniyor...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi baglandi!");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());
}
void loop() {
  // put your main code here, to run repeatedly:

}
