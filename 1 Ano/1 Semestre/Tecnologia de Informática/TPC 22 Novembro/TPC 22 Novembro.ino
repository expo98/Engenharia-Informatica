
int ledPin=3;
int poten=0;
int volt;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
	volt = analogRead(poten);
	analogWrite(ledPin,volt/4);
}