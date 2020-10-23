int outA = 13;
int outB = 12;
int outZ = 11;
int A_last = 0;
int pulsos = 0;

void setup() {
  Serial.begin(230400);
  A_last = digitalRead(outA);
}

void loop() {
  int A = digitalRead(outA);
  int B = digitalRead(outB);
  int Z = digitalRead(outZ);

  if (A != A_last) {
    if (A == B) {
      if (A == HIGH) {
        pulsos++;
        if ((Z == LOW) and (pulsos > 0)) {
          Serial.print("Pulsos última vuelta: ");
          Serial.println(pulsos);
          pulsos = 0;
        }
      }
      else {
        if (A == HIGH) {
          pulsos--;
        }
      }
    }
    A_last = A;
  }
}
