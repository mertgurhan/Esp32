#include <Servo.h>


//ledler
const int led1=2;
const int led2=3;
//mesafe ölçer
const int trigPin=9;
const int echoPin=10;
Servo bariyer;
const int servopin=6;

long sure=0;
float mesafe=0;


void setup(){
bariyer.attach(servopin);

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
Serial.println("Mesafe Bazli Servo Bariyer Uygulamasi Basladi!");
}

float mesafeOlc(){
  digitalWrite(trigPin,LOW);
  delayMicroSeconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroSeconds(10);
  digitalWrite(trigPin,LOW);
  sure=pulseIn(echoPin,HIGH,3000);
  if(sure==0) return -1;
  return(sure*0.034)/2.0;
}
voidbariyerkontrol(float d){

  if(d>20){
    bariyer.write(90);
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    Serial.println("Geçiş Serbest");
  }
  else if(d>=0 && d<=20){
    bariyer.write(0);
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
    Serial.println("Geçiş Durdu!");
  }
}
void loop(){
mesafe=mesafeOlc();
Serial.println("Mesafe");
Serial.println(mesafe);
Serial.println("cm");
bariyerkontrol(mesafe);
delay(200);
}