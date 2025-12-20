#include <ESP32Servo.h>

Servo servo_motor;


const int ledsari = 12;

const int ledmavi = 32; 

void setup() {
  
  pinMode(ledsari, OUTPUT);
  pinMode(ledmavi, OUTPUT); 
  
  servo_motor.attach(4); 
}

void loop() {

  servo_motor.write(0);
  digitalWrite(ledsari, HIGH);  
  delay(1000);


  servo_motor.write(90);
  

  digitalWrite(ledsari, LOW);   
  digitalWrite(ledmavi, HIGH); 
  delay(1000);


  servo_motor.write(180);
  digitalWrite(ledmavi, HIGH); 
  digitalWrite(ledsari, HIGH);  
  delay(1000);
  

 digitalWrite(ledmavi, LOW); 
  digitalWrite(ledsari, LOW);  
}