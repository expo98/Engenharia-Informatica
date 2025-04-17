
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

long lastDebounceTime=0;
long debounceDelay=50;

const long longPressDelay=3000;

int contador;
int resultado;

unsigned int randomNumber;



  void setup()
  {
    Serial.begin(9600);
    for (int leds=3; leds<=13; leds++){
      pinMode(leds, OUTPUT); // Prepara todos os LedPins
    }
    pinMode(buttonPin, INPUT); // Prepara o pin do botão
    randomSeed(analogRead(A0));
    
    
    Serial.println("Press button to start!");
  }



  void loop(){ 
	contador =1;
    resultado=0;
    loseScreen();
  }

  
void pressCounter(){
  
  int reading = digitalRead(buttonPin);
   if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        Serial.println("etc etc");
      
      }
    }
  }
  
  
   lastButtonState = reading;
}
  
  

void singlePress(){
  int reading = digitalRead(2);
  
  if (reading != lastButtonState){
  lastDebounceTime = millis();
   
  	if((millis() - lastDebounceTime) > debounceDelay){ 
        Serial.println("O JOGO VAI COMECAR");
   }
    if(buttonState!=reading){
    	buttonState=reading;
    }

 } 
}

void winScreen(){
  if (contador == resultado){
   //varrimento 
  }
}

void loseScreen(){
    for (int i=6;i<=13;i++){
      if (i%2 == 0){
      	digitalWrite(ledPinRgbB,HIGH);
        delay(1000);
      }
      else{
        digitalWrite(ledPinRgbB,LOW);
      	delay(200);
      }
    }
  }

void game(){
}

void timer(){
  millis();
}

