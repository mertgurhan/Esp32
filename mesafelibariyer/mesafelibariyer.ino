#include <ESP32Servo.h>

Servo bariyer;

const int ledsari = 27; // Tanımlı ama kullanılmıyor, sorun değil.
const int servopin = 4;
const int ledmavi = 32; 
const int trigPin = 5;
const int echoPin = 18;


 long sure=0;
 float mesafe=0;
void setup() {
  pinMode(ledmavi, OUTPUT);
  pinMode(ledsari, OUTPUT); 
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  bariyer.attach(servopin);

Serial.begin(9600);
  Serial.println("Mesafe Bazli Servo Uygulaması basladi");
}

void loop() {
 mesafe=mesafeOlc();
 Serial.print("Mesafe");
 Serial.print(mesafe);
 Serial.println("cm");
 bariyerKontrol(mesafe);
 delay(200);

}

float mesafeOlc(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  sure = pulseIn(echoPin, HIGH);


  return(sure*0.034)/2.0;
}

void bariyerKontrol(float d){
  if(d>20){
    bariyer.write(90);
    digitalWrite(ledmavi,HIGH);
    digitalWrite(ledsari,LOW);
  Serial.println("Durum:Gecis Serbest(Bariyer Acik)");
  }
  else if(d>=0 && d<=20){
    bariyer.write(0);
    digitalWrite(ledsari,HIGH);
    digitalWrite(ledmavi,LOW);
    Serial.println("Durum:Bariyer Kapali");
  }
}