#include <NewPing.h>
#define TRIGGER_PIN1  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN1     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN2  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS_one = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int uS_two = sonar2.ping();
  Serial.print("Ping1: ");
  Serial.print(sonar.convert_cm(uS_one)); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  Serial.print("Ping2: ");
  Serial.print(sonar2.convert_cm(uS_two)); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
}


