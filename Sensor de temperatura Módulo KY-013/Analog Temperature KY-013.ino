int v = 13

void setup(){
 Serial.begin(9600);
}

void loop(){
 //Read value from module connected at pin 13
 int V_input = analogRead(v);

 //calculate thermometer resistance by comparing it to the modules onboard 10K-ohm resistor
 float R_ohms = 1000 * (1023.0 / (float)V_input - 1.0);

 //calculate temperature in Celsius
 float temp_C = (1.0 / (0.00129148 + (0.000234125*log(R_ohms)) + 0.0000000876741*log(R_ohms)*log(R_ohms)))-273.15;

 //output result to serial
  Serial.print("Temperature (degC): ");
  Serial.println(temp_C);"
}
