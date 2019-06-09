#define TRIG_PIN D0
#define ECHO_PIN D1

void setupFuelLevel(){
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

double checkFuelLevel(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  double distance = calculate(duration);
  Serial.print("---> Level : ");
  Serial.println(distance);
  return distance;
}

double calculate(uint32_t duration) {
  double soundSpeed = 331.4;
  double distance = (soundSpeed * duration) / 1000000;
  return distance;
}
