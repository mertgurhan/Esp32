#define echoPin 18
#define trigPin 5
#define led 32
#define buzzer 4
long duration; 
float distance; 

void setup() {
  Serial.begin(115200); 
  pinMode(buzzer,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  

  distance = duration / 58.2;

if(distance <22){
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH);
}
else{
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
}
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000); 
}