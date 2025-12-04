#include <WiFi.h>
#include <dht11.h>

#define DHT11PIN 2
dht11 DHT11;

const char* ssid = "Bihtus";
const char* pass = "Mertebru2002";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {

  WiFiClient client = server.available();
  if (!client) return;

  while(!client.available()) delay(1);
  client.readStringUntil('\n'); 

  // DHT11 okuma
  DHT11.read(DHT11PIN);
  float h = DHT11.humidity;
  float t = DHT11.temperature;

  // Web sayfası
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<html><body>");
  client.print("Nem: "); client.print(h); client.println(" %<br>");
  client.print("Sicaklik: "); client.print(t); client.println(" C");
  client.println("</body></html>");
  client.stop();
}

