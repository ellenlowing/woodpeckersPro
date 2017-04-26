# WoodpeckersPro
WoodpeckersPro is a product design prototype that mainly detects and deters woodpeckers with the goal of house protection. Ultrasonic sensors are used to detect presence of woodpeckers or any invading birds, and predator call is played when detected and regularly as a protection mechanism.
It also has the following minor functionalities: automatically turns off at night, recharges with solar panel, and notifies house owner when battery falls under 70%.

# Circuit components
- 2 Arduinos: control overall operation of device
- Sparkfun MP3 player shield: facilitate mp3 playing
- Adafruit FONA 808 Shield: notify house owner when battery level is low
- SIM card and GSM Antenna: enable SMS messaging
- Lipoly battery: charge FONA 808 shield
- RC rechargeable battery: power Arduinos and other circuit components
- Solar panel: charge battery with sunlight
- Lightdiode and op amp: enable automatic switch off at night
- Ultrasonic sensors: sense presence of woodpeckers
- Speakers: deter woodpeckers with predator call
- Resistors: act as sensor for voltage

# Programming
There are 2 folders - src and test - that respectively contain source code for both Arduinos and individual tests for all components. 
- main: upload to main Arduino
- main_2: upload to second Arduino (the one with only MP3 player shield)

