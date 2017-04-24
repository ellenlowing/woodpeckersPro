/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
//trigPin and echoPin are the ultrasonic sensor's pins
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
Serial.begin(9600); // Starts the serial communication
}

//1. Detects light level
//2.1 If it's too dark, speaker doesn't make any sound and sensor is not triggered
//2.2 If it's day time, we first trigger ultrasonic sensor to generate ultrasound and then we read if there's pulse
//    If the distance detected is close enough, we play sound from file
//3. Regardless of motion detection mechanism, we play sound for a duration of two minutes every ten minutes
//   (only during day time)

void loop() {
  lightLevel = analogRead(opAmpPin);
  Serial.println(lightLevel);
  if(lightLevel > lightThreshold){
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
      //if distance detected is too far
      noTone(speakerPin);
    }
    
  }else{
    //if light level is low
    noTone(speakerPin);
    digitalWrite(trigPin, LOW);
  }
}
