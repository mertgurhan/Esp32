#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Ekran çözünürlüğü
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// PIN TANIMLARI (senin bağlantına göre)
#define OLED_MOSI 23   // SDA
#define OLED_CLK  18   // SCK
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
  display.setCursor(0, 10);   // X=0, Y=10 → daha yukarı
  pinMode(led,OUTPUT);

  display.print("Ampul yaniyor!");

  display.display();
}

void loop() {
  digitalWrite(led,HIGH);
  delay(2000);
  digitalWrite(led,LOW);

  if(led==HIGH){
    display.print("Ampul Yaniyor");
  }
  else{
    display.print("Ampul Sondu!");
  }

}
