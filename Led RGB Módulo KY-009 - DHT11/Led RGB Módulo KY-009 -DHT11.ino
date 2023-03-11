
int B = 19; // OUTPUT PIN blue
int R = 23; // OUTPUT PIN red
int G = 22; // OUTPUT PIN green

#include <DHTesp.h>
DHTesp dht;

void setup()
{
 Serial.begin(115200); 
 pinMode(R, OUTPUT);
 pinMode(G, OUTPUT);
 pinMode(B, OUTPUT);
 dht.setup(2,DHTesp::DHT11);
}
 
void loop()
{ 
 TempAndHumidity data = dht.getTempAndHumidity();
  Serial.println("Temperatura");
  Serial.println(data.temperature);
  delay(2000);
  Serial.println("Humedad");
  delay(2000);
  Serial.println(data.humidity);

  //Si la temperatura es mayor a 20 grados abrir ventana
  if(data.humidity >= 80){
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    delay(1000);
  }

  //Si la temperatura es menor a 10°C cerrar la ventana
  if(data.humidity <= 80 ){
     digitalWrite(B, LOW);
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    delay(1000);
  }
 // GREEN
 
 
 // GREEN + BLUE = CYON

 
}