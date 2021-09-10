
#include "thingProperties.h"
#include "DHT.h"

#define PIN 12                          // defining the pin to which the temperature sensor is attached to the arduino
#define TYPE DHT22                     // defining the sensor type. Here, it is DHT22
DHT dht(PIN, TYPE);                 // Initializing the DHT sensor
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  dht.begin();
}

void loop() {
  ArduinoCloud.update(); 
  temp= dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C ");
  
  

}




void onLedChange() {
  // Do something
  digitalWrite(LED_BUILTIN, led);                        
}
