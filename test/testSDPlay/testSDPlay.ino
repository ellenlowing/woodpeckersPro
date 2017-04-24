#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
  }

  char file[] = "81.wav"; //change file name in sd card to 81
  tmrpcm.setVolume(6);
  tmrpcm.play(file);
}

void loop(){  }
