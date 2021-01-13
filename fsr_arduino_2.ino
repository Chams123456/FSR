//Reading approximate force from FSR
//Written for ThatsEngineering
//Date:13/01/2021

// Pins and variables
int FSRpin = A0;
int value;
int voltage;
unsigned long resistance = 0;
unsigned long conductance = 0;
int force = 0;

void setup(void) {
  Serial.begin(9600);
}

void loop() {

  //Obtain analog reading from pin A0 (FSR)
  value = analogRead(FSRpin);
  Serial.print("Analog reading from FSR = ");
  Serial.println(value);

  // Map analog value to obtain Vo in mV
  voltage = map(value, 0, 1023, 0, 5000);

  if (voltage == 0) {
    Serial.println("No force applied");
    delay(1000);
    return;
  }

  Serial.print("Vo = ");
  Serial.print(voltage);
  Serial.println(" mV ");

  //Calculate resistance using voltage divider equation
  //R_fsr = [(Vin*R)/Vo] - R
  resistance = 50e6 / voltage;
  resistance = resistance - 10000;

  //Calculate conductance in micro mho(1/R)
  conductance = 1000000 / resistance;                       //Convert to micro mhos

  //Use the FSR resistance vs. force graphs to estimate the force
  if (conductance <= 1000) {
    force = conductance / 80;
  }
  else {
    force = (conductance - 1000) / 30;
  }

  Serial.print("Force =  ");
  Serial.print(force);
  Serial.println(" N ");

  Serial.println("--------------------");
  delay(1000);
}
