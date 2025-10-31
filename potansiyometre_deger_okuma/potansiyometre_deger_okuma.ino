
const int potPin=34;

//potansiyometre degerini saklamak için değişken
int potValue=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(1000);


}

void loop() {
  // put your main code here, to run repeatedly:

//deger okuma
potValue=analogRead(potPin);
Serial.println(potValue);
delay(500);

}
