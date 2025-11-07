#include <dht11.h>
#define DHT11PIN 2
#define ledPin 4
#define ledSari 14 
#define ledYesil 27
#define ledMavi 32
dht11 DHT11; //OBJE oluştur

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ardunio proje test");
  Serial.println("MAKU-DHT11 test programı");
  pinMode(ledPin,OUTPUT);
  pinMode(ledSari,OUTPUT);
  pinMode(ledYesil,OUTPUT);
  pinMode(ledMavi,OUTPUT);

}

void loop() {



  int chk=DHT11.read(DHT11PIN);

float sıcaklık = DHT11.temperature;  // Celsius değeri

 // float sıcaklık=DHT11.celcius();

  Serial.print("Nem(%):");  
  Serial.println((float)DHT11.humidity,2);

  Serial.print("Sıcaklık(fahreneit):");  
  Serial.println(DHT11.fahrenheit(),2);

  Serial.print("Sıcaklık(kelvin):");  
  Serial.println((float)DHT11.kelvin(),2);

  Serial.print("Sıcaklık(celcius):");  
  Serial.println((float)DHT11.celcius(),2);

  if(sıcaklık<25){
    digitalWrite(ledPin,LOW);
    digitalWrite(ledSari,LOW);
    digitalWrite(ledYesil,LOW);
    digitalWrite(ledMavi,HIGH);
  }
  else if(sıcaklık<35){
    digitalWrite(ledPin,LOW);
    digitalWrite(ledSari,LOW);
    digitalWrite(ledYesil,HIGH);
    digitalWrite(ledMavi,HIGH);
  }
  else{
    digitalWrite(ledSari,HIGH);
    digitalWrite(ledYesil,HIGH);
    digitalWrite(ledMavi,HIGH);
  }
}

