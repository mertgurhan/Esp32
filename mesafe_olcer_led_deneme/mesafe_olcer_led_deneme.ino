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

#define led     32
#define trigPin 4
#define echoPin 16

long duration;
float distance;

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &SPI,
  OLED_DC,
  OLED_RST,
  OLED_CS
);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);   // echo giriş
  pinMode(led, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  // ULTRASONİK ÖLÇÜM
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // timeout
  distance = duration / 58.2;

  display.clearDisplay();

  if (distance > 0 && distance < 22) {
    digitalWrite(led, HIGH);
    display.setCursor(0, 10);
    display.print("Ampul YANIYOR");
  } else {
    digitalWrite(led, LOW);
    display.setCursor(0, 10);
    display.print("Ampul SONDU");
  }

  display.setCursor(0, 30);
  display.print("Mesafe: ");
  display.print(distance);
  display.print(" cm");

  display.display();
  delay(200);
}
