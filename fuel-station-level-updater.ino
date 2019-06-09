void setup() {
  Serial.begin(9600);
  Serial.println("*****************************STARTING*******************************");
  setupWifi();
  setupButton();
  setupFuelLevel();
  setupPump();
}

void loop() {

  double fuelLevel = checkFuelLevel();
  checkButton();
  updateLevel(fuelLevel, fuelLevel - 1);

  delay(5000);
  

}
