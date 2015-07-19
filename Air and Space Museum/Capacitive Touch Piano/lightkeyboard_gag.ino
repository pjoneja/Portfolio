// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h> //Library for Music Player
#include <SD.h>
#include <Wire.h>
#include "Adafruit_MPR121.h" //Library for Capacitive Sensor

// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer =
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);
////

Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

//Danger Zone
const int dangerzone[26] = {2, 1, 0, 1, 2, 2, 2, 1, 1, 1, 2, 4, 4, 2, 1, 0, 1, 2, 2, 2, 2, 1, 1, 2, 1, 0};
int pwd[26] =              {1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  //Music Player Setup
  musicPlayer.begin();
  SD.begin(CARDCS);
  musicPlayer.setVolume(20, 20);
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);

  //Capacitive Sensor Setup
  cap.begin(0x5A);
}

void loop() {
  currtouched = cap.touched();

  for (uint8_t i = 0; i < 8; i++) {
    // if any key *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      musicPlayer.stopPlaying();
      if (i == 0) {
        musicPlayer.startPlayingFile("track001.mp3");
      }
      if (i == 1) {
        musicPlayer.startPlayingFile("track002.mp3");
      }
      if (i == 2) {
        musicPlayer.startPlayingFile("track003.mp3");
      }
      if (i == 3) {
        musicPlayer.startPlayingFile("track004.mp3");
      }
      if (i == 4) {
        musicPlayer.startPlayingFile("track005.mp3");
      }
      if (i == 5) {
        musicPlayer.startPlayingFile("track006.mp3");
      }
      if (i == 6) {
        musicPlayer.startPlayingFile("track007.mp3");
      }
      if (i == 7) {
        musicPlayer.startPlayingFile("track008.mp3");
      }
      
      //HERE'S THE GAG:
      //shift register
      for (uint8_t n = 0; n < 25; n++) {
        pwd[n] = pwd[n + 1];
      }
      pwd[25] = i; //write lasttouched to last entry in array
      while (1) {
        for (uint8_t n = 0; n < 25; n++) {
          if (dangerzone[n] != pwd[n]) { //entry-by-entry comparison
            goto piano;
          }
        }
        delay(2473); //hear the last note play
        musicPlayer.stopPlaying();
        musicPlayer.startPlayingFile("danger.mp3");
        goto piano;
      }
    }
  }
piano:
  // reset our state
  lasttouched = currtouched;
  return;
}
