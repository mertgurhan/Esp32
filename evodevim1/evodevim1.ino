#define ledPin 4
#define ledSari 14 
#define ledYesil 27
#define ledMavi 32
const int buttonPin = 33;

bool ledac=false;

void setup() {

  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  pinMode(ledSari,OUTPUT);
  pinMode(ledYesil,OUTPUT);
  pinMode(ledMavi,OUTPUT);



  digitalWrite(ledPin,   LOW);
  digitalWrite(ledSari,  LOW);
  digitalWrite(ledYesil, LOW);
  digitalWrite(ledMavi,  LOW);

}

void loop() {
if(digitalRead(buttonPin)==LOW){
  ledac= !ledac;

if(ledac==HIGH){
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledSari,HIGH);
  digitalWrite(ledYesil,HIGH);
  digitalWrite(ledMavi,HIGH);
}
else{
  digitalWrite(ledPin,LOW);
  digitalWrite(ledSari,LOW);
  digitalWrite(ledYesil,LOW);
  digitalWrite(ledMavi,LOW);   
}
delay(200);

}

}
