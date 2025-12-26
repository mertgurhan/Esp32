//#bizden hcsr4 ile birlikte bariyer kontrolü istiyor
const int trigPin=9;
const int echoPin=10;

const int ledYesil=2;
const int ledKirmizi=3;

Servo bariyer;
const int servoPin=6;

float mesafe=0;
float sure=0;
void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INTPUT);
  pinMode(ledYesil,OUTPUT);
  pinMode(ledKirmizi,OUTPUT);
  bariyer.attach(servoPin);
Serial.begin(9600);

}
float mesafeOlc(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delay(Microseconds(10);
  digitalWrite(trigPin,LOW);
  sure=pulseIn(echoPin,HIGH,3000);
  if(sure==0)
  {
    return ;
  }
  
  float uzaklik=(sure*0.034)/2.0;
  return uzaklik;
}
void bariyerkontrol(float d){
if(d>20){
  bariyer.write(90);
  digitalWrite(ledYesil,HIGH);
  digitalWrite(ledKirmizi,LOW);
  Serial.println("Durum Gecisi serbest");
}
else if(d>=0 && d<=20){
    bariyer.write(0);
  digitalWrite(ledYesil,LOW);
  digitalWrite(ledKirmizi,HIGH);
  Serial.println("Durum Gecisi KAPALI");
}
}
void loop(){
  mesafe=mesafeOlc();
  Serial.println("Mesafe");
  Serial.println(mesafe);
  Serial.println("cm");
  bariyerkontrol(mesafe);
}




