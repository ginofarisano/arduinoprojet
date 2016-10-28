const int greenLedPin = 10;
const int redLedPin = 9;
const int blueLedPin = 11;
const int greenSensorPin = A1;
const int redSensorPin = A0;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  
 // Serial.print("Raw sensor Values \t red: ");
 // Serial.print(redSensorValue);
 // Serial.print("\t Green: ");
 // Serial.print(greenSensorValue);
 // Serial.print("\t Blue: ");
//  Serial.println(blueSensorValue);
  
  redValue = redSensorValue/4;
  if(redValue < 80)
    redValue = 0;
  greenValue = greenSensorValue/4;
  if(greenValue < 80)
    greenValue = 0;
  blueValue = blueSensorValue/4;
    if(blueValue < 80)
    blueValue = 0;

Serial.print("Mapped sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);
  
  analogWrite(greenLedPin, greenValue);
  analogWrite(redLedPin, redValue);
  analogWrite(blueLedPin, blueValue);

}
