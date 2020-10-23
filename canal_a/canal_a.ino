int outA = 13;
int outB = 12;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(digitalRead(outA));
  Serial.print(" ");
  Serial.println(digitalRead(outB));
}
