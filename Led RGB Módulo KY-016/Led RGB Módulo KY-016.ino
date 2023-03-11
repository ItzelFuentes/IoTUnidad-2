int redpin = 13; // select the pin for the red LED
int bluepin =2; // select the pin for the  blue LED
int greenpin =12; // select the pin for the green LED
int val;
void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  for(val = 255; val > 0; val--)
  {
    analogWrite(13, val);
    analogWrite(2, 255 - val);
    analogWrite(12, 128 - val);
    Serial.println(val, DEC);
    delay(5); 
  }
  for(val = 0; val < 255; val++)
  {
    analogWrite(13, val);
    analogWrite(2, 255 - val);
    analogWrite(12, 128 - val);
    
    Serial.println(val, DEC);
    delay(5); 
  }
} 