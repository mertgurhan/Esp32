#include <Servo.h>
Servo bariyer;

void setup(){
bariyer.attach(9); //burada pini tanımlıyoruz

}
void loop(){
  bariyer.write(0);
  delay(100);
  bariyer.write(90);
  delay(1000);
  bariyer.write(180);
  delay(1000);


}