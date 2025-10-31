
const int potPin=34;
#define ledPin 4
#define ledSari 14 
#define ledYesil 27
#define ledMavi 32
const int buttonPin = 33;


void setup() {

  Serial.begin(115200);

  pinMode(ledPin,OUTPUT);
  pinMode(ledSari,OUTPUT);
  pinMode(ledYesil,OUTPUT);
  pinMode(ledMavi,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
int ham=analogRead(potPin);
  Serial.println(ham); //degeri okuma
if(ham<300){
  digitalWrite(ledPin,HIGH);
    digitalWrite(ledSari,LOW);
  digitalWrite(ledYesil,HIGH);
  digitalWrite(ledMavi,LOW);


}
else if(ham<2500){
  digitalWrite(ledPin,LOW);
  digitalWrite(ledSari,HIGH);
  digitalWrite(ledYesil,LOW);
  digitalWrite(ledMavi,HIGH);
}
else {
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledSari,LOW);
  digitalWrite(ledYesil,LOW);
  digitalWrite(ledMavi,LOW);
  delay(1000);
  digitalWrite(ledYesil,HIGH);
  digitalWrite(ledSari,LOW);
  digitalWrite(ledPin,LOW);
  digitalWrite(ledMavi,LOW);
  delay(1000);
  digitalWrite(ledPin,LOW);
  digitalWrite(ledSari,HIGH);
   digitalWrite(ledYesil,LOW);
  digitalWrite(ledMavi,LOW);
  delay(1000);
  digitalWrite(ledPin,LOW);
   digitalWrite(ledSari,LOW); 
   digitalWrite(ledYesil,LOW);
  digitalWrite(ledMavi,HIGH);
  delay(1000);
}


}

