
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>

// If using the breakout or shield with I2C, define just the pins connected
// to the IRQ and reset lines.  Use the values below (2, 3) for the shield!
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield

bool success;
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)


//CRITICAL:
const uint8_t pwd[7] = { 0x77, 0x78, 0x2C, 0x21, 0, 0, 0 };


Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello!");

  nfc.begin();
  nfc.SAMConfig();
  nfc.setPassiveActivationRetries(1);

  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);

  Serial.println("Waiting for an ISO14443A Card ...");
}


void loop(void) {
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    for (uint8_t i = 0; i < uidLength; i++) {
      Serial.print(uid[i], HEX);
      Serial.print(" ");
      if (uid[i] != pwd[i]) {
        Serial.println("low");
        digitalWrite(8, LOW);
      } else {
        if (i == uidLength - 1) {
          Serial.println("high");
          digitalWrite(8, HIGH);
        }
      }
    }
  } else {
    Serial.println("low");
    digitalWrite(8, LOW);
  }
  // Wait a bit before reading the card again
  delay(100);
}

