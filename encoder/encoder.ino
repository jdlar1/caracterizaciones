int outA = 13;
int outB = 12;
int outZ = 11;
int pos = 0;
int A_last = 0;
int vuelta = 0;
int pulsos[15];

void setup() {
  pinMode(outA, INPUT);
  pinMode(outB, INPUT);
  pinMode(outZ, INPUT);
  Serial.begin(115200);
  int A_last = digitalRead(outA);
}

void loop() {
  int A = digitalRead(outA);
  int B = digitalRead(outB);
  int Z = digitalRead(outZ);

  if (Z == 0){
    delay(1000);
    while (Z != 0){
      if (A != A_last){
        if (A == B){
          pos++;
        }
      }
    }
    pulsos[vuelta] = pos;
    vuelta++;
    pos = 0;
    delay(200);
    Serial.println("vuelta");
  }

  if (vuelta == 14){
    float prom = average_array(pulsos);
    Serial.println(prom);
    for(int i = 0; i < 15; i++){
      Serial.print(pulsos[i]);
      Serial.print(" ");
    }
    delay(10000);
  }
}

float average_array(int narray[]){
  long sum = 0 ;  // sum will be larger than an item, long for safety.
  for (int i = 0 ; i < 15 ; i++){
    sum += narray[i];
  return  sum / 15 ;  // average will be fractional, so float may be appropriate.
}
}
