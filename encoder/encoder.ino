int outA = 13;
int outB = 12;
int outZ = 11;
int A_last = 0;
int pulsos = 0;
int index = 0;
int arr[6];

float pulsos_prom(int arr[]) {
  int t1 = arr[1] - arr[0];
  int t2 = arr[2] - arr[1];
  int t3 = arr[3] - arr[2];
  int t4 = arr[4] - arr[3];
  int t5 = arr[5] - arr[4];

  float ans = (t1 + t2 + t3 + t4 + t5) / 5;

  return ans;
}

void setup() {
  Serial.begin(112500);
  A_last = digitalRead(outA);
}

void loop() {
  int A = digitalRead(outA);
  int B = digitalRead(outB);
  int Z = digitalRead(outZ);

  if (A != A_last) {
    if (A == B) {
      pulsos++;
      A_last = A;
     if((Z == HIGH) and (A == HIGH)){
      arr[index] = pulsos;
      index++;
      pulsos = 0;
      if(index == 6){
        Serial.print("El promedio de pulsos por 6 vueltas son: ");
        Serial.println(pulsos_prom(arr));
        index = 0;
      }
     }  
    }
    else {
      Serial.println("Giro en sentido opuesto al contador...");
    }
  }
}
