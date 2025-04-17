
const int ledPinRed4=13;
const int ledPinRed3=12;
const int ledPinRed2=11;
const int ledPinRed1=10;

const int ledPinGreen4=9;
const int ledPinGreen3=8;
const int ledPinGreen2=7;
const int ledPinGreen1=6;

  const int ledPinRgbR=5;
  const int ledPinRgbB=4;
  const int ledPinRgbG=3;

  const int buttonPin=2;


  int buttonState;
  int lastButtonState=LOW;
  int pressed=0;

  long lastDebounceTime=0;
  long debounceDelay=50;

  void setup()
  {
    Serial.begin(9600);
    for (int leds=3; leds<=13; leds++){
      pinMode(leds, OUTPUT); // Prepara todos os LedPins
    }
    pinMode(buttonPin, INPUT); // Prepara o pin do botão
    
    Serial.println("Press button to start!");
  }



  void loop()
  {
    if(debunceButton(buttonState) == HIGH && buttonState=LOW){
      pressed++;
      buttonState = HIGH;
    }
    else if(debounceButton(buttonState) == LOW && buttonState == HIGH){
      buttonState = LOW;
    }
    if(pressed == 10){
      digitalWrite(5,HIGH);
    }
  }

  bool debounceButton(bool state){
      bool stateNow = digitalRead(buttonPin);
      if(state!=stateNow){
        delay(10);
        stateNow=digitalRead(buttonPin);
      }
      return stateNow;
  }

