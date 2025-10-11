#define LedKirmizi  4
#define LedSari 14 
#define LedYesil 27
#define LedMavi 33


void setup() {
pinMode(LedKirmizi,OUTPUT);
pinMode(LedSari,OUTPUT);
pinMode(LedYesil,OUTPUT);
pinMode(LedMavi,OUTPUT);
}

void loop() {

digitalWrite(LedKirmizi,HIGH);
digitalWrite(LedSari,LOW);
digitalWrite(LedYesil,LOW);
digitalWrite(LedMavi,LOW);
delay(5000);
digitalWrite(LedKirmizi,LOW);
digitalWrite(LedYesil,HIGH);
digitalWrite(LedMavi,LOW);
digitalWrite(LedSari,LOW);
delay(750);
digitalWrite(LedKirmizi,LOW);
digitalWrite(LedYesil,LOW);
digitalWrite(LedMavi,HIGH);
digitalWrite(LedSari,LOW);
delay(750);
digitalWrite(LedKirmizi,LOW);
digitalWrite(LedYesil,LOW);
digitalWrite(LedMavi,LOW);
digitalWrite(LedSari,HIGH);
delay(800);
}