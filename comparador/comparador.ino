int diente_de_sierra = 11;
int PWM = 12;
int frecuencia = 6;

float sawtooth(){
  float a = float(frecuencia*(millis() % (int(1000/frecuencia))))*0.255;
  return a;
}

void setup() {
 Serial.begin(112500);
 pinMode(diente_de_sierra, OUTPUT);
 pinMode(PWM, INPUT);
}

void loop() {
  float st = sawtooth();
  float in = digitalRead(PWM);
  
  analogWrite(diente_de_sierra, st);
 
  Serial.print(st);
  Serial.print(" ");
  Serial.println(in);
}
