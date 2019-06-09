#define BUTTON_PIN D3

#define FUEL_MIN_LEVEL 10

void setupButton() {
  pinMode(BUTTON_PIN, OUTPUT);
}

void checkButton() {
  Serial.println("Button pressed");
  if (digitalRead(BUTTON_PIN)) {
    if (checkFuelLevel() > FUEL_MIN_LEVEL) {
      turnOnPump();
    } else {
      turnOffPump();
    }
  } else {
    turnOffPump();
  }
}
