#include <ESP32Servo.h>

// --- PIN TANIMLAMALARI (ESP32 Uyumlu Güvenli Pinler) ---
const int trigPin = 5;    // Eski: 9 (Değiştirildi)
const int echoPin = 18;   // Eski: 10 (Değiştirildi)

const int ledYesil = 13;  // Eski: 2
const int ledKirmizi = 12;// Eski: 3

const int servoPin = 4;   // Eski: 6

Servo bariyer;

// Değişkenler
float mesafe = 0;
long sure = 0;

void setup() {
  Serial.begin(115200); // ESP32 standardı
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // DÜZELTME: INTPUT -> INPUT
  
  pinMode(ledYesil, OUTPUT);
  pinMode(ledKirmizi, OUTPUT);
  
  bariyer.attach(servoPin);
  bariyer.write(0); // Başlangıçta kapalı olsun
}

void loop() {
  // 1. Mesafeyi Ölç
  mesafe = mesafeOlc();
  
  // 2. Ekrana Yaz
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  
  // 3. Karar Ver ve Uygula
  sistemiYonet(mesafe);
  
  delay(200); // Okuma sıklığını biraz yavaşlat
}

// --- YARDIMCI FONKSİYONLAR ---

// GÖREV 1: Sadece mesafe ölçer ve sonucu döndürür
float mesafeOlc() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // DÜZELTME: Yazım hatası giderildi
  digitalWrite(trigPin, LOW);
  
  sure = pulseIn(echoPin, HIGH, 30000); // 30ms bekleme süresi
  
  if (sure == 0) {
    return -1; // Hata durumunda -1 döndür
  }
  
  float uzaklik = (sure * 0.034) / 2.0;
  return uzaklik;
}

// GÖREV 2: Ana Karar Mekanizması (Servo'yu yönetir, LED'ciye emir verir)
void sistemiYonet(float d) {
  // Hatalı ölçümse işlem yapma
  if (d == -1) return;

  // Bariyer Kontrol Mantığı
  if (d > 20) {
    // Araç Uzakta -> GEÇİŞ SERBEST (Bariyer AÇIK)
    bariyer.write(90);
    ledIslemi(1); // 1 kodu "Geçiş Serbest" demek olsun
    Serial.println("Durum: Gecis SERBEST");
  } 
  else {
    // Araç Yakında/Yok -> KAPALI
    bariyer.write(0);
    ledIslemi(0); // 0 kodu "Kapalı" demek olsun
    Serial.println("Durum: Gecis KAPALI");
  }
}

// GÖREV 3: İsteğin üzerine LED'leri kontrol eden ÖZEL fonksiyon
void ledIslemi(int durum) {
  if (durum == 1) {
    // Geçiş Serbest Modu (Yeşil Yanar)
    digitalWrite(ledYesil, HIGH);
    digitalWrite(ledKirmizi, LOW);
  } 
  else {
    // Kapalı Modu (Kırmızı Yanar)
    digitalWrite(ledYesil, LOW);
    digitalWrite(ledKirmizi, HIGH);
  }
}
