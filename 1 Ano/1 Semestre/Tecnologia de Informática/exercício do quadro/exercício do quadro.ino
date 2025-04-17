const int buttonPin=7;
const int ledPin=13;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long DebounceDelay = 50;






byte cnt=0;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = !digitalRead(buttonPin);

  if (reading != lastButtonState){
    lastDebounceTime = millis();

  }
  if ((millis() - lastDebounceTime) > DebounceDelay) {

    if (buttonState!=reading) buttonState = reading;
      if (buttonState!=reading) {
        buttonState = reading;
        cnt = cnt +1;
        Serial.println(cnt);
      }
  }

  if ( (cnt%3) == 0){
    digitalWrite(ledPin, buttonState);
  }

}
