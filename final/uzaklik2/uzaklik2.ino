/*
pin 7 led
pin 9 servo
90 derecede led geri bildirmi yapıcak

*/
#include<Servo.h>
Servo servomotor;
const int servoPin=9;
const int ledPin=7;
void setup(){
  pinMode(ledPin,OUTPUT);
  servomotor.attach(ServoPin);
}
void loop(){
  servoTarama(0,180,1);
  servoTarama(180,0,1);
}

void servoTarama(int baslangic,int bitis,int adim){
  if (baslangic<bitis){
    for(int aci=baslangic;aci<=bitis;aci+=adim){
      servomotor.write(aci);
      kontrolled(aci);
      delay(20);
    }
  }
  else{
    for(int aci=baslangic;aci>=bitis;aci-=adim){
      servomotor.write(aci);
      kontrolled(aci);
      delay(20);
    }
  }
}
void kontrolled(int aci){
  if(aci==90){
    digital.Write(ledPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
  }
  
}