#include <WiFi.h>

const char* ssid = "Bihtus";
const char* password = "Mertebru2002";

WiFiServer server(80);

int ledKirmizi = 4;
int ledSari    = 14;
int ledYesil   = 27;

void setup() {
  Serial.begin(115200);

  pinMode(ledKirmizi, OUTPUT);
  pinMode(ledSari, OUTPUT);
  pinMode(ledYesil, OUTPUT);

  // WiFi'ye bağlan
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String req = client.readStringUntil('\n');

  // AÇ
  if (req.indexOf("/on") != -1) {
    digitalWrite(ledKirmizi, HIGH);
    digitalWrite(ledSari, HIGH);
    digitalWrite(ledYesil, HIGH);
  }

  // KAPAT
  if (req.indexOf("/off") != -1) {
    digitalWrite(ledKirmizi, LOW);
    digitalWrite(ledSari, LOW);
    digitalWrite(ledYesil, LOW);
  }

  // Basit HTML cevap
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<h1>ESP32 3 LED Kontrol</h1>");
  client.println("<p><a href='/on'>LEDLERİ AÇ</a></p>");
  client.println("<p><a href='/off'>LEDLERİ KAPAT</a></p>");

  client.stop();
}
