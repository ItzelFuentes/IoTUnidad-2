#include <ezButton.h>

#define VRX_PIN  27 // Arduino pin connected to VRX pin
#define VRY_PIN  26 // Arduino pin connected to VRY pin
#define SW_PIN   12  // Arduino pin connected to SW  pin

int redPin = 35;
int greenPin = 32;
int bluePin = 33;

ezButton button(SW_PIN);

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int bValue = 0; // To store value of the button

void setup() {
  Serial.begin(9600) ;
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}


void loop() {
  button.loop(); // MUST call the loop() function first

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // Read the button value
  bValue = button.getState();

  if(xValue == 0 && yValue == 0){
    digitalWrite(redPin, 0);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
  }else if(xValue > 2000 && yValue > 2000  && xValue < 4000 && yValue < 4000){
    digitalWrite(redPin, 255);
    digitalWrite(greenPin,255);
    digitalWrite(bluePin,255);
  }else if(xValue > 2000 && yValue == 0 && xValue < 4000){
    digitalWrite(redPin, 0);
    digitalWrite(greenPin,0);
    digitalWrite(bluePin,255);
  }else if(xValue == 0 && yValue > 2000 && yValue < 4000){
    digitalWrite(redPin, 255);
    digitalWrite(greenPin,0);
    digitalWrite(bluePin,0);
  }else if(xValue > 4000 && yValue > 4000){
    digitalWrite(redPin, 0);
    digitalWrite(greenPin,255);
    digitalWrite(bluePin,0);
  }

  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.print(yValue);
  Serial.print(" : button = ");
  Serial.println(bValue);

}