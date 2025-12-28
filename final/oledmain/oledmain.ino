
OLED     ESP32
CS               -5
Res             -4
Dc               -2
Sda             -23
Scl              -18
Vcc            -3.3V
Gnd           -gnd
---------------------------------KOD-----------------------------------------------
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Pin tanımları
#define TFT_CS     5   // Chip Select
#define TFT_RST    4   // Reset
#define TFT_DC     2   // Data/Command
// MOSI (SDA) = GPIO 23 (varsayılan)
// SCK (SCL)  = GPIO 18 (varsayılan)

// ST7735 nesnesi oluştur
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void testText() {
  tft.fillScreen(ST77XX_BLACK);
  
  tft.setCursor(10, 10);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.println("ESP32 + ST7735");
  
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println("SEDAT !");
  
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.println("TFT Ekran Test");
}

void testRectangles() {
  tft.fillScreen(ST77XX_BLACK);
  
  tft.fillRect(10, 10, 40, 30, ST77XX_RED);
  tft.fillRect(60, 10, 40, 30, ST77XX_GREEN);
  tft.fillRect(10, 50, 40, 30, ST77XX_BLUE);
  tft.fillRect(60, 50, 40, 30, ST77XX_YELLOW);
  
  tft.drawRect(5, 5, 110, 85, ST77XX_WHITE);
}

void testLines() {
  tft.fillScreen(ST77XX_BLACK);
  
  for (int i = 0; i < tft.height(); i += 5) {
    tft.drawLine(0, 0, tft.width(), i, ST77XX_CYAN);
  }
  
  for (int i = 0; i < tft.width(); i += 5) {
    tft.drawLine(0, 0, i, tft.height(), ST77XX_MAGENTA);
  }
}

void testCircles() {
  tft.fillScreen(ST77XX_BLACK);
  
  int centerX = tft.width() / 2;
  int centerY = tft.height() / 2;
  
  for (int r = 10; r < 60; r += 10) {
    tft.drawCircle(centerX, centerY, r, ST77XX_WHITE);
  }
  
  tft.fillCircle(centerX, centerY, 5, ST77XX_RED);
}

void testCounter() {
  for (int i = 0; i < 10; i++) {
    tft.fillScreen(ST77XX_BLACK);

    tft.setCursor(10, 15);
    tft.setTextColor(ST77XX_GREEN);
    tft.setTextSize(2);
    tft.print("Sayac:");

    tft.setCursor(30, 35);
    tft.setTextColor(ST77XX_YELLOW);
    tft.setTextSize(3);
    tft.print(i);

    delay(500);
  }
}
void setup() {
  Serial.begin(115200);
  Serial.println("ST7735 Test");

  // 0.96" 80x160 TFT ekranı için özel başlatma
  tft.initR(INITR_MINI160x80);  // veya INITR_MINI160x80_PLUGIN

  // Ekranı temizle
  tft.fillScreen(ST77XX_BLACK);

  // Yönlendirme (0-3 arası)
  // 0 = 80x160 (dikey), 1 = 160x80 (yatay)
  tft.setRotation(1);

  Serial.println("Ekran hazir!");
}

void loop() {
  // Örnek 1: Metin yazdırma
  testText();
  delay(2000);
  
  // Örnek 2: Renkli kutular
  testRectangles();
  delay(2000);
  
  // Örnek 3: Çizgiler
  testLines();
  delay(2000);
  
  // Örnek 4: Daireler
  testCircles();
  delay(2000);
  
  // Örnek 5: Sayaç
  testCounter();
  delay(2000);
}

