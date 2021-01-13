//Using FSR as an input to on an LED
//Written for ThatsEngineering
//Date: 13/01/2021

//Specify Pins
int LEDpin = 2;
int FSRpin = A0;

//Temp variable to hold FSR analog reading
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  value = analogRead(FSRpin);

  //If FSR recieves a force the LED will light up
  if (value > 0) {
    digitalWrite(LEDpin, HIGH);
  }
  else{
    digitalWrite(LEDpin, LOW);
  }

  Serial.print("Analog reading from FSR: ");
  Serial.println(value);
}
