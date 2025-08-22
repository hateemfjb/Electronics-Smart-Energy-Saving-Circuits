int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
int irSensor = 7;
int irLed = 9;

int sensorThres = 500;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(irLed, OUTPUT);
  
  pinMode(smokeA0, INPUT);
  pinMode(irSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(smokeA0);
  Serial.print("Gas Sensor: ");
  Serial.println(gasValue);

  if (gasValue > sensorThres) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }

  int irState = digitalRead(irSensor);
  if (irState == LOW) {
    digitalWrite(irLed, HIGH);  // جسم قريب
  } else {
    digitalWrite(irLed, LOW);   // لا يوجد جسم
  }

  delay(100);
}