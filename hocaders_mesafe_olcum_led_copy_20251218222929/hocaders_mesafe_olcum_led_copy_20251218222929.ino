// HC-SR04 pinleri
const int trigPin = 2;      // Trigger pini
const int echoPin = 4;      // Echo pini
 
// LED pinleri (bar şeklinde gösterim için)
const int led1 = 26;         // En uzak mesafe LED'i (30–40 cm)
const int led2 = 25;         // Orta mesafe LED'i (20–30 cm)
const int led3 = 33;         // Yakın mesafe LED'i (10–20 cm)
const int led4 = 32;         // Çok yakın mesafe LED'i (0–10 cm)
 
long sure = 0;              // Echo süresi (mikrosaniye)
float mesafe = 0;           // Hesaplanan mesafe (cm)
 
void setup() {
  pinMode(trigPin, OUTPUT); // Trigger çıkış
  pinMode(echoPin, INPUT);  // Echo giriş
 
  pinMode(led1, OUTPUT);    // LED pinlerini çıkış olarak ayarla
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
 
  Serial.begin(9600);       // Seri haberleşmeyi başlat
}
 
void loop() {
  mesafe = mesafeOlc();     // Mesafeyi ölç
 
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
 
  ledGoster(mesafe);        // Mesafeye göre LED'leri kontrol et
 
  delay(200);               // Okumalar arasında kısa bekleme
}
 
// HC-SR04 ile mesafe ölçen fonksiyon
float mesafeOlc() {
  // Önce trig pinini temizle
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  // 10 µs'lik tetikleme darbesi gönder
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Echo pininde HIGH süresini ölç (maksimum 30 ms bekle)
  sure = pulseIn(echoPin, HIGH, 30000);
 
  // Eğer süre 0 ise (okuma yoksa) -1 döndür (geçersiz ölçüm)
  if (sure == 0) {
    return -1;
  }
 
  // Ses hızı ~340 m/s → 0.034 cm/µs
  // Mesafe = (sure * 0.034) / 2
  float uzaklik = (sure * 0.034) / 2.0;
 
  return uzaklik;
}
 
// Mesafeye göre LED'leri bar şeklinde kontrol eden fonksiyon
void ledGoster(float d) {
  // Önce tüm LED'leri kapat
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
 
  // Geçersiz ölçüm veya çok uzak mesafe → tüm LED'ler sönük
  if (d < 0 || d > 40) {
    return; // Hiçbir LED yakma
  }
 
  // 30–40 cm arası → sadece 1 LED
  if (d > 30 && d <= 40) {
    digitalWrite(led1, HIGH);
  }
  // 20–30 cm arası → 2 LED
  else if (d > 20 && d <= 30) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  // 10–20 cm arası → 3 LED
  else if (d > 10 && d <= 20) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  // 0–10 cm arası → 4 LED (çok yakın uyarısı)
  else if (d >= 0 && d <= 10) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}
