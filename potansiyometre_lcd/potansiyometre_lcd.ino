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

#define LED_PIN 32
#define POT_PIN 34

int potValue=0;
Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &SPI,
  OLED_DC,
  OLED_RST,
  OLED_CS
);

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    // Ekran başlamazsa burada takıl
    while (true) {}
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Basliyor...");
  display.display();

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);              // Pot oku
  Serial.print("Pot: ");
  Serial.print(potValue);
 
  // LED YANIYOR
  digitalWrite(LED_PIN, HIGH);
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Ampul YANIYOR");



  display.display();


  // LED SONDU
  digitalWrite(LED_PIN, LOW);
  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Ampul SONDU");


  display.setCursor(0, 30);
  display.print("Potansiyometre Degeri");
  display.print(potValue);
  
  display.display();
}
