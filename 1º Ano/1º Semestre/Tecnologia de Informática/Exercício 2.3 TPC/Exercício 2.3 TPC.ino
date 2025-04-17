const int buttonPin=7;
const int ledPin=13;

int deslocamento=0;
int n1=1;
int buttonState;
int lastButtonState = LOW;
int lastreading=LOW;
int presscount=0;

long lastDebounceTime = 0;
long debounceDelay = 50;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if((reading==true) && (reading!=lastreading)){
      while(deslocamento < 7){
      Serial.print(n1 << deslocamento, DEC);
      Serial.print(" ");
      Serial.println(n1 << deslocamento, BIN);
      deslocamento++;
      lastreading=reading;

   }
  } 
  }


  
  
  

