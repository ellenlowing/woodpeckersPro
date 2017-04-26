void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.00/1023.00) *2;
  Serial.print("Voltage: ");
  Serial.println(voltage);
}
