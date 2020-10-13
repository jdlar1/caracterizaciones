int diente_de_sierra = 11;
int frecuencia = 6;

float sawtooth(){
  float a = float(frecuencia*(millis() % (int(1000/frecuencia))))*0.255;
  return a;
}

void setup() {
 Serial.begin(112500);
}

void loop() {
  float a = sawtooth();
  Serial.println(a);
}
