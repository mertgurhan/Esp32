#include <ESP32Servo.h>

Servo servo_motor;

const int ledsari = 14; // Tanımlı ama kullanılmıyor, sorun değil.
const int servopin = 4;
const int ledmavi = 32; 

void kontrolled(int aci){
  // Açı 90 olduğunda LED'i yak, 1 saniye bekle, söndür.
  if(aci == 90){
    digitalWrite(ledmavi, HIGH);
    digitalWrite(ledsari,HIGH);
    delay(1000); // Motor burada 1 saniye duraksar
    digitalWrite(ledmavi, LOW);
    digitalWrite(ledsari, LOW);
  }
}

void servoTarama(int baslangic, int bitis, int adim){
  if(baslangic < bitis){
    // İLERİ YÖN (0 -> 180)
    // aci += adim (Artırarak git)
    for(int aci = baslangic; aci <= bitis; aci += adim){
      servo_motor.write(aci);
      kontrolled(aci);
      delay(20);
    }
  }
  else{
    // GERİ YÖN (180 -> 0)
    // aci -= adim (Azaltarak git)
    for(int aci = baslangic; aci >= bitis; aci -= adim){
      servo_motor.write(aci);
      kontrolled(aci);
      delay(20);
    }
  }
}

void setup() {
  pinMode(ledmavi, OUTPUT);
  // Sarı LED'i kullanacaksan onun da pin modunu açmalısın:
   pinMode(ledsari, OUTPUT); 
  
  servo_motor.attach(servopin);
}

void loop() {
  servoTarama(0, 180, 1); // İleri git
  servoTarama(180, 0, 1); // Geri gel

}
