#include <Wire.h>
#include <Adafruit_GFX.h> // grafik tabanli projeler icin
#include <Adafruit_SSD1306.h> // metin tabanli projeler icin
#define SCREEN_WIDTH 128 // genislik
#define SCREEN_HEIGHT 64 // yukseklik
// sda-scl pinleri
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // i2c adresi
    Serial.println(F("SSD1306 baglanti prob"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("merhaba dunya!");
  display.display(); 
}
void loop() {
}