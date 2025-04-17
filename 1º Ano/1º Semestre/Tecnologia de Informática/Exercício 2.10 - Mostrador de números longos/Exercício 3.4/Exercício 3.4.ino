int ledR =5; int ledB =4; int ledG =3;
int num;
int distancia;
int input = 550;
int volt;

void setup() {
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  
  randomSeed(analogRead(0));

}

void loop() {
	//num = random(1024);
  	num=550;
  	Serial.println("O numero aleatorio e: ");
  	Serial.print(num);
  
  	Serial.println(" ");
  
	distancia = abs(input - num);
  
  	Serial.println("A distancia entre o numero aleatorio e a tentativa e: ");
  	Serial.print(distancia);
  	
  	volt = (1024 - distancia)/4 ;
  
    
  	if (input == num){
  		digitalWrite(ledG, HIGH);
    	analogWrite(ledR,  LOW);
  	}
 	 if (input > num){
   		analogWrite(ledR, volt); 
  		analogWrite(ledG,LOW);
 	}	
  	if (input < num){
  		analogWrite(ledR, volt);
    	analogWrite(ledG, volt);
  	}
  
}