const int ledPar=2;
const int ledMltp3=3;
const int ON=HIGH;
const int OFF=LOW;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPar, OUTPUT);
  pinMode(ledMltp3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int numero=300;numero<=400;numero++){

      delay(500);
      Serial.println(numero);
      delay(500);

      while((numero%2)==0){
      digitalWrite(ledPar, ON);
      delay(1000);
      digitalWrite(ledPar, OFF);
     }

      while((numero%3)==0){
      digitalWrite(ledMltp3, ON);
      delay(1000);
      digitalWrite(ledMltp3, OFF);

  
      }
  }
}
