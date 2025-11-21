#define ledKirmizi 4
#define ledSari    14 
#define ledYesil   27
#define ledMavi    32
#define button     33

int dugme = 0;
const int leds[] = {4, 14, 27, 32};

void setup() {
  for (int i = 0; i < 4; i++) pinMode(leds[i], OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int durum = digitalRead(button);

  if (durum == LOW) {
    dugme++;
    while (digitalRead(button) == LOW);  // buton bırakılana kadar bekle
    delay(20); // debounce

    if (dugme == 1) {
      for (int i = 0; i < 4; i++) digitalWrite(leds[i], HIGH);
    }
    else {
      for (int i = 0; i < 4; i++) digitalWrite(leds[i], LOW);
      dugme = 0;  // tekrar başa dön
    }
  }
}



/*
int a = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledKirmizi, OUTPUT);
  pinMode(ledSari, OUTPUT);
  pinMode(ledYesil, OUTPUT);
  pinMode(ledMavi, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button) == LOW) {   // Buton basıldığında
    a++;
    while (digitalRead(button) == LOW);  // Bırakılana kadar bekle
  }

  if (a == 1) {
    digitalWrite(ledKirmizi, HIGH);
    digitalWrite(ledSari, HIGH);
    digitalWrite(ledYesil, HIGH);
    digitalWrite(ledMavi, HIGH);
  }

  if (a == 2) {
    a = 0;
    digitalWrite(ledKirmizi, LOW);
    digitalWrite(ledSari, LOW);
    digitalWrite(ledYesil, LOW);
    digitalWrite(ledMavi, LOW);
  }
}
*/
