const int sensorPin = A0;
int baselineTemp;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  for(int pinNumber = 2 ; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
  int sensorVal = analogRead(sensorPin);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperatura = (voltage - 0.5) * 100;
  
  baselineTemp = temperatura;

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print("Voltage Value: ");
  Serial.println(voltage);
  
  float temperatura = (voltage - 0.5) * 100;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  
  if(temperatura > baselineTemp && temperatura < baselineTemp+1){
      
    for(int pinNumber = 2 ; pinNumber<5; pinNumber++)
      digitalWrite(pinNumber, LOW);
      
  } else if(temperatura >= baselineTemp+1 && temperatura < baselineTemp+2){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    
  } else if(temperatura >= baselineTemp+2 && temperatura < baselineTemp+3){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
  } else if(temperatura >= baselineTemp+3){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
  }
    
    
  
  
  
  
  delay(1000);
}
