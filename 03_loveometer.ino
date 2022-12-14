const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600); //Ver valores en PC, 9600 velocidad a la que se comunica arduino con PC
  Serial.print("Empieza");

  for(int pinNumber = 2; pinNumber < 5; pinNumber++){ //Todo apagado
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  int sensorVal = analogRead(sensorPin); //lectura temp

  Serial.print("Valor del sensor: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Voltios: ");
  Serial.print(voltage);

  Serial.print(", grados C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  } else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  } else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);  
    
  }

  delay(1);

}
