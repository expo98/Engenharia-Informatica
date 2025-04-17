const int ledPin[] = {4,5,6,7};
const int buttonPin = 8;


long numAleat;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int buttonState;
int lastButtonState = LOW;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for (int i=0;i<4;i++){
  pinMode(ledPin[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}
void loop() {
int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
 if ((millis() - lastDebounceTime) > debounceDelay) {
   if (reading != buttonState) {  
      buttonState = reading;
      numAleat = random();
        Serial.println(numAleat);
        Serial.println(numAleat,BIN);
          for(int i=0;i<=32;i++){
          if(bitRead(numAleat,i) ==1){    
            digitalWrite(ledPin[((4+i)%4)], HIGH);
            }
          if(bitRead(numAleat,i) ==0){        
            digitalWrite(ledPin[((4+i)%4)], LOW);
            }
          delay(1000);
          for(int a=0;a<4;a++){
              digitalWrite(ledPin[a], LOW);
                }
          delay(1000);  
  }
      }
  }
  lastButtonState = reading;
}

