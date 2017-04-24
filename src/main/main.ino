#include "Adafruit_FONA.h"
#include <NewPing.h>


#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

#define TRIGGER_PIN1  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN1     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN2  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN3  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN3     8  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);

#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

uint8_t type;

unsigned long time;
unsigned long start_t;
unsigned long end_t;
const int soundDuration = 7000; // the duration of the wav file is 7 seconds


const int opAmpPin = 0; //analog
const int speakerPin = 6;

void setup(){
  pinMode(opAmpPin, INPUT);
  Serial.begin(115200);
}

void loop(){
  time = millis()/60000;
  if(isDayTime()){
    printTime();
    if(time >= 10){
      //reset time
    }else{
      if(time < 8){
        if(birdDetected_new()){
          Serial.println("detected");
          playSound();
        }else{
          Serial.println("not detected");
        }//end if birdDetected
      }else{
        long totalDurationPlayed = 0;
        const long twoMinsInMS = 120000;
        while(totalDurationPlayed < twoMinsInMS ){
          playSound();
          totalDurationPlayed = totalDurationPlayed + (long)soundDuration;
        }//end while(totalDurationPlayed < 2minsInMS)
      }//end if-else (time < 8)
    }//end if-else (time >= 10)
    //printTime();
    //prints time since program started
    // wait a second so as not to send massive amounts of data
    //delay(1000);
  }else{
    //noTone(speakerPin);
    //digitalWrite(trigPin1, LOW);
    //digitalWrite(trigPin2, LOW);
  }
}

boolean isDayTime(){
  int lightLevel = 0;
  const int lightThreshold = 5; 
  lightLevel = analogRead(opAmpPin);
  if(lightLevel>lightThreshold){
    return true;
  }else{
    return false;
  }
}

void printTime(){
  time = millis()/60000;
}

boolean birdDetected_new(){
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS_one = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int uS_two = sonar2.ping();
  unsigned int uS_three = sonar3.ping();
  int distance1 = sonar.convert_cm(uS_one);
  int distance2 = sonar2.convert_cm(uS_two);
  int distance3 = sonar3.convert_cm(uS_three);
  const int distanceThreshold = 30;
  boolean detected1 = false;
  boolean detected2 = false;
  boolean detected3 = false;
  if(distance1 != 0 && distance1 <= distanceThreshold){
    detected1 = true;
  }
  if(distance2 != 0 && distance2 <= distanceThreshold){
    detected2 = true;
  }
  if(distance3 != 0 && distance3 <= distanceThreshold){
    detected3 = true;
  }
  Serial.print("Ping1: ");
  Serial.print(distance1); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  Serial.print("Ping2: ");
  Serial.print(distance2); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  Serial.print("Ping3: ");
  Serial.print(distance3); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  return detected1 | detected2 | detected3;
  
 

  
}
/*
boolean birdDetected(){
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
    
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
    
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration1 = pulseIn(echoPin1, HIGH);
  long duration2 = pulseIn(echoPin2, HIGH);
    
  // Calculating the distance
  int distance1= duration1*0.034/2;
  int distance2= duration2*0.034/2;
  Serial.print("distance1: ");
  Serial.println(distance1);
  Serial.print("distance2: ");
  Serial.println(distance2);
  const int distanceThreshold = 200;
  boolean detected1 = false;
  boolean detected2 = false;
  if(distance1 != 0 && distance1 <= distanceThreshold){
    detected1 = true;
  }
  if(distance2 != 0 && distance2 <= distanceThreshold){
    detected2 = true;
  }
  return detected1 | detected2;
}
*/

void sendText(){
  while(!Serial);
  Serial.begin(115200);
  Serial.println(F("FONA basic test"));
  Serial.println(F("Initializing....(May take 3 seconds)"));

    fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  type = fona.type();
  Serial.println(F("FONA is OK"));
  Serial.print(F("Found "));
  switch (type) {
    case FONA800L:
      Serial.println(F("FONA 800L")); break;
    case FONA800H:
      Serial.println(F("FONA 800H")); break;
    case FONA808_V1:
      Serial.println(F("FONA 808 (v1)")); break;
    case FONA808_V2:
      Serial.println(F("FONA 808 (v2)")); break;
    case FONA3G_A:
      Serial.println(F("FONA 3G (American)")); break;
    case FONA3G_E:
      Serial.println(F("FONA 3G (European)")); break;
    default: 
      Serial.println(F("???")); break;
  }
  
  // Print module IMEI number.
  char imei[16] = {0}; // MUST use a 16 character buffer for IMEI!
  uint8_t imeiLen = fona.getIMEI(imei);
  if (imeiLen > 0) {
    Serial.print("Module IMEI: "); Serial.println(imei);
  }

  char sendto[21] = "19788067578";
  char message[141] = "Battery level is low";
  fona.sendSMS(sendto, message);
}


void playSound(){
  //tone(9,2000, soundDuration);
  delay(soundDuration);
}

