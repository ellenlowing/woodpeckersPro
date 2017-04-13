/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 9; //digital
const int echoPin = 10; //digital
const int speakerPin = 6; //digital
const int opAmpPin = 0; //analog

// defines variables
long duration;
int distance;
int lightLevel = 0;
const int lightThreshold = 5;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//pinMode(speakerPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
  lightLevel = analogRead(opAmpPin);
  if(lightLevel > lightThreshold)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance= duration*0.034/2;
    
    // Prints the distance on the Serial Monitor
    if(distance <= 200){
      tone(speakerPin, 2000);
      Serial.println(distance);
    }else{
      noTone(speakerPin);
    }
  }
}
