#include <Adafruit_DHT.h>


#define DHTPIN D2     // what pin I'm connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino


void setup() {
  // Subscribe to the webhook response event
  Particle.subscribe("hook-response/temp", myHandler, MY_DEVICES);
  dht.begin();
}



void myHandler(const char *event, const char *data) {
  // Handle the integration response
}
  



void loop() {

  float temperature = dht.getTempCelcius();

  String temp = String(temperature);  
 Particle.publish("temp", temp, PRIVATE);
  delay(30000);               // Wait for 30 seconds
    
}
