#include <Servo.h>
Servo servo;
const int led=7;
const int servopin=9;


void servoTarama(int baslangic,int bitis,adim){
  if(baslangic<bitis){
    for(int aci=baslangic,aci<=bitis;aci+=adim){
      servo.write(aci);
      kontrolled(aci);
      delay(20);
    }
  }

  else{
    for(int aci=baslangic;aci>=bitis;aci-=adim){
      servo.write(aci);
      kontrolled(aci);
      delay(20);
    }
  }
}

void kontrolled(int aci){
  if(aci==90){
    digitalWrite(ledpin,HIGH);
    delay(1000);
    digitalWrite(ledpin,LOW);
  }
}

void setup(){
servo.attach(servopin);
pinMode(ledpin,OUTPUT);
}
void loop(){
servoTarama(0,180,1);
servoTarama(180,0,1);
}