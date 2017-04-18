int lightLevel = 0;
const int lightThreshold = 5;
const int opAmpOutPin = 2;
const int speakerPin = 6;
int speakerLevel = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
  //digitalWrite(speakerPin, HIGH);
  //delay(1000);
  //digitalWrite(speakerPin, LOW);
  //delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = analogRead(opAmpOutPin);
  if(lightLevel <= lightThreshold)
  {
    Serial.println("There is not enough light");
  }else{
    Serial.println(lightLevel);
    tone(speakerPin, 2000, 500);
    delay(1000);
  }
  delay(1000);
}
