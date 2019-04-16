int analogvalue = 0;
double temp = 0;

void setup()
{
  Particle.variable("analogvalue", analogvalue);
  Particle.variable("temp", temp);
 pinMode(A0, INPUT);
Particle.subscribe("hook-response/temp", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {
  // Handle the webhook response
}




void loop() {
  

  analogvalue = analogRead(A0);

  temp = (((analogvalue * 3.3)/4095) - 0.5) * 100;
  
  Particle.publish("temp", String(temp), PRIVATE);
  delay(30000);               // Wait for 30 seconds

}