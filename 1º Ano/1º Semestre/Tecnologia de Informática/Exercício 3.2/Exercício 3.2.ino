// PMW available pins on the arduino connected to the RGB leds
const int redLedPin=6; const int blueLedPin=5; const int greenLedPin=3;

int voltagem;
String stringVoltagem="";
String cor="";

void setup(){
  //Prepares serial
  		Serial.begin(9600);
  		pinMode(redLedPin, OUTPUT);
  		pinMode(blueLedPin, OUTPUT);
  		pinMode(greenLedPin, OUTPUT); 
}


void loop(){
  
  	Serial.println("Introduza valor e opcao");
  
  	//While there is not user input the program does nothing
    //so it doesn't loop through the loop() function indefinitely
  	while(Serial.available() ==0){}
  
  
  	//We obtain the string numbers and convert them to integer
	if (Serial.available() >0){
		stringVoltagem = Serial.readString();
   	    voltagem = converteStr(stringVoltagem);
     	Serial.println("Numero = " + stringVoltagem);
    	Serial.println("Introduza opcao");
      
      if (0<=voltagem<=255){
      //While there is no user input after they've input the 
      //voltage value, the program, again, does nothing
      while(Serial.available() ==0){}
      
      //We read the user input for the color
  		if (Serial.available() >0){
  			cor = Serial.readString();
    		Serial.println("opcao = " + cor);
  		

    		if ( (cor == "b") || (cor == "B") ){
        		analogWrite(blueLedPin, voltagem);
    		}
    		if ( (cor == "r") || (cor == "R") ){
        		analogWrite(redLedPin, voltagem);
    		}
    		if ( (cor == "g") || (cor == "G") ){
        		analogWrite(greenLedPin, voltagem);
      		}
    		delay(5000);
    		analogWrite(greenLedPin,0);
    		analogWrite(redLedPin,0);
    		analogWrite(blueLedPin,0);
    		Serial.println("desligando");
      } //Closes if statemente for reading the color
	 } // Closes the if statement of voltage value (0,250)
	}// Closes the if statement for reading the voltage
  
} // Closes loop function


// Function that converts Serial.readString input string
// What is read on Serial needs to be Serial.readString
// For it to work, if it isn't it just spits out ascii values
int converteStr(String stringVoltagem){
  int val=0;
  int pot=1;

  for (int i=stringVoltagem.length()-1;i>=0;i=i-1){
    if((stringVoltagem[i]>='0') && (stringVoltagem[i]<='9')){
		val=val+(stringVoltagem[i]-48)*pot;
        pot=pot*10;
    } else return(-1);
  }
  return(val);
}

