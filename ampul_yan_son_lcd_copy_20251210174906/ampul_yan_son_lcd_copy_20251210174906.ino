#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Ekran çözünürlüğü
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// PIN TANIMLARI
#define OLED_MOSI 23
#define OLED_CLK  18
#define OLED_DC   21
#define OLED_CS    5
#define OLED_RST  22
#define led 32

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &SPI,
  OLED_DC,
  OLED_RST,
  OLED_CS
);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

  pinMode(led, OUTPUT);

  display.print("Ampul yaniyor!");
  display.display();
}

void loop() {
  // LED YANIYOR
  digitalWrite(led, HIGH);
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Ampul YANIYOR");
  display.display();
  delay(1000);

  // LED SÖNÜYOR
  digitalWrite(led, LOW);
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Ampul SONDU");
  display.display();
  delay(1000);
}
