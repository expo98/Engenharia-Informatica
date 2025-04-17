const int buttonPin=7;
const int ledPin=13;

int deslocamento=0;
int n1=1;
int buttonState;
int lastButtonState = LOW;

long lastDebounceTime = 0;
long debounceDelay = 50;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if(reading != lastButtonState){
      lastDebounceTime = millis();
  }
  
  if((millis() - lastDebounceTime) > debounceDelay){
    if(buttonState!=reading)  buttonState = reading;
      while(deslocamento < 7){
      Serial.println(n1 << deslocamento, DEC);
      deslocamento++;
   }
  }

  


  lastButtonState = reading;
  
  
  
}
