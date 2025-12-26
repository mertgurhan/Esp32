// #bana uzaklıga göre led yakan mesafe
// HC-SR04 pinleri (Düzeltildi: // eklendi)
const int trigPin = 2;      
const int echoPin = 4;      
 
// LED pinleri (bar şeklinde gösterim için)
const int led1 = 26;         // En uzak mesafe LED'i (30–40 cm)
const int led2 = 25;         // Orta mesafe LED'i (20–30 cm)
const int led3 = 33;         // Yakın mesafe LED'i (10–20 cm)
const int led4 = 32;         // Çok yakın mesafe LED'i (0–10 cm)

long duration = 0;
float mesafe = 0;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); // Düzeltildi: Parantez kapatıldı ')'
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  mesafe = mesafeOlc();
  
  Serial.print("Mesafe: "); // Yan yana yazması için println yerine print kullandım
  Serial.print(mesafe);
  Serial.println(" cm");
  
  ledGoster(mesafe);
  delay(200); // 2000 çok yavaş, 200ms (0.2 saniye) daha seri çalışır
}

float mesafeOlc(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Timeout süresini 30000 (30ms) yaptım, daha kararlı ölçer.
  duration = pulseIn(echoPin, HIGH, 30000); 
  
  if(duration == 0){
    return -1;
  }
  
  float uzaklik = (duration * 0.034) / 2.0;
  return uzaklik;
}

void ledGoster(float d){
  // Önce hepsini söndür
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  if(d < 0 || d > 40){
    return;
  }
  
  // Bar grafiği mantığı (kümülatif yakma)
  if(d > 30 && d <= 40){
    digitalWrite(led1, HIGH);
  }
  else if (d > 20 && d <= 30) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if (d > 10 && d <= 20) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (d >= 0 && d <= 10) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

