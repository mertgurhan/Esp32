const int BTN_PIN = 33;
const int LED_SARI = 14;
const int LED_YESIL = 27;
const int LED_MAVI= 32;
const int LED_KIRMIZI= 4;
unsigned long sayac=0;



void setup() {
  Serial.begin(115200);
  pinMode(BTN_PIN, INPUT_PULLUP);   
  pinMode(LED_SARI, OUTPUT);
  pinMode(LED_MAVI, OUTPUT);
  pinMode(LED_YESIL, OUTPUT);
  pinMode(LED_KIRMIZI, OUTPUT);
  digitalWrite(LED_SARI, LOW);
  digitalWrite(LED_MAVI, LOW);
  digitalWrite(LED_YESIL, LOW);
  digitalWrite(LED_KIRMIZI, LOW);
}

void loop() {
  if (digitalRead(BTN_PIN) == LOW) {   // butona basıldı
    sayac++;
    Serial.print("Buton: "); Serial.println(sayac);

    // --- SARI LED: sayac kadar yanıp sönsün (1..5 arası) ---
    int n = sayac;
    if (n < 1) n = 1;
    if (n > 5) n = 5;
    for (int i = 0; i < n; i++) {
      digitalWrite(LED_SARI, HIGH); delay(500);
      digitalWrite(LED_SARI, LOW);  delay(500);
    }

   
    if (sayac % 2 == 0) {
      digitalWrite(LED_YESIL, HIGH);
      digitalWrite(LED_KIRMIZI, HIGH);
      digitalWrite(LED_MAVI, HIGH);
      delay(500);
      digitalWrite(LED_YESIL, LOW);
      digitalWrite(LED_KIRMIZI, LOW);
      digitalWrite(LED_MAVI, LOW);
    }

    // basılı tutarken tekrar saymasın (debounce)
    while (digitalRead(BTN_PIN) == LOW) { delay(10); }
    delay(150);
  }
}
