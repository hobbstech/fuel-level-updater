#define PUMP_PIN D2

void setupPump(){
  pinMode(PUMP_PIN, OUTPUT);
}

void turnOnPump(){
  digitalWrite(PUMP_PIN, HIGH);
}

void turnOffPump(){
  digitalWrite(PUMP_PIN, LOW);
}
