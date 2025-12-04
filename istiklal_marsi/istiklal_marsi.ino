
 // Buzzer modülünün bağlı olduğu pini tanımlıyoruz
int buzzerPin = 4;
 
// Buzzer modülünden gelen ses verilerini inceleyip, kalınlık durumuna göre notalarına ayırarak belirtiyoruz
int kdo = 262;  // Do notası
int re = 294;   // Re notası
int mi = 330;   // Mi notası
int fa = 349;   // Fa notası
int sol = 392;  // Sol notası
int la = 440;   // La notası
int si = 494;   // Si notası
int ido = 523;  // Do üstü notası
 
void setup()
{
  // Melodiyi oluşturan her notayı sırayla çaldırıyoruz
 
  // "Do" notasını çal
  tone(buzzerPin, kdo);   // Buzzer'dan "Do" sesi çıkar
  delay(400);             // 400 ms bekle
  noTone(buzzerPin);      // Sesi durdur
  delay(10);              // Kısa bir ara ver
 
  // Yine "Do" notasını tekrar çal
  tone(buzzerPin, kdo);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Sol" notasını çal
  tone(buzzerPin, sol);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // Yine "Sol" notasını çal
  tone(buzzerPin, sol);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "La" notasını çal
  tone(buzzerPin, la);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "La" notasını tekrar çal
  tone(buzzerPin, la);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Sol" notasını çal
  tone(buzzerPin, sol);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Fa" notasını çal
  tone(buzzerPin, fa);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Fa" notasını tekrar çal
  tone(buzzerPin, fa);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Mi" notasını çal
  tone(buzzerPin, mi);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Mi" notasını tekrar çal
  tone(buzzerPin, mi);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Re" notasını çal
  tone(buzzerPin, re);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Re" notasını tekrar çal
  tone(buzzerPin, re);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // "Do" notasını tekrar çal
  tone(buzzerPin, kdo);
  delay(400);
  noTone(buzzerPin);
  delay(10);
 
  // Yukarıdaki mantıkla diğer notaları sırasıyla çaldırabilirsiniz
}
 
void loop()
{
  // Loop kısmı boş çünkü melodiyi tek seferde çalıyoruz
}