int ledPin = 4;
int ledSari =14 ;
int ledYesil= 27;
const int buttonPin = 33;


// variable for storing the pushbutton status 
int buttonState = 0;

void setup() {
  Serial.begin(115200);  
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  pinMode(ledSari,OUTPUT);
  pinMode(ledYesil,OUTPUT);

}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledSari,HIGH);
    digitalWrite(ledYesil,HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledSari,LOW);
    digitalWrite(ledYesil,LOW);
  }
}