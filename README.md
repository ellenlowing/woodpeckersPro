# WoodpeckersPro
WoodpeckersPro is a product design prototype that mainly detects and deters woodpeckers with the goal of house protection. Ultrasonic sensors are used to detect presence of woodpeckers or any invading birds, and predator call is played when detected and regularly as a protection mechanism.
It also has the following minor functionalities: automatically turns off at night, recharges with solar panel, and notifies house owner when battery falls under 70%.

# Circuitry
## Circuit Diagram
![alt text](https://github.com/ellenlowing/woodpeckersPro/blob/master/assets/EK210%20Woodpecker%20circuit.png)
Remark:
- FONA 808 Shield is not shown in the diagram. Simply put the shield on top of the main Arduino (the one without MP3 player shield) 
- Resistor used in series with solar panel depends on the voltage of solar panel and RC battery
- Resistors used to indicate voltage have to be of the same value
- Plug in the speaker's audio jack to the MP3 player shield
## Bill of Materials
- 2 Arduinos: control overall operation of device
- Sparkfun MP3 player shield: facilitate mp3 playing
- Adafruit FONA 808 Shield: notify house owner when battery level is low
- SIM card and GSM Antenna: enable SMS messaging
- Lipoly battery: charge FONA 808 shield
- RC rechargeable battery: power Arduinos and other circuit components
- Solar panel: charge battery with sunlight
- Lightdiode and LMC6482 Op Amp: enable automatic switch off at night
- Ultrasonic sensors: sense presence of woodpeckers
- Speakers: deter woodpeckers with predator call
- Resistors: act as sensor for voltage

# Programming
There are 2 folders - src and test - that respectively contain source code for both Arduinos and individual tests for all components. 
## src
- main: upload to main Arduino
- main_2: upload to second Arduino (the one with only MP3 player shield)
## test
- testDeterWoodpeckers: test if lightdiode sends correct signal to speaker
- testLightDiode: test if lightdiode functions
- testFona: test if FONA shield functions
- testShowVoltage: test if Arduino senses voltage correctly (need multimeter to check accuracy)
- testSpeaker: test if MP3 shield and SFEMP3Shield library work
- testUltrasonicSensor: test if ultrasonic sensor functions
- testArduinoCommunication: test if main Arduino sends correct signal to second Arduino
- testNewPingLib: test if NewPing Library enhances functioning of ultrasonic sensor

