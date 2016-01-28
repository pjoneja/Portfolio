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
const uint8_t pwd[7] = { 0x39, 0x11, 0xA8, 0xE0, 0, 0, 0 };
const uint8_t gagp[7] = { 0x4, 0x2D, 0x26, 0x9A, 0x12, 0x35, 0x80 };
const uint8_t gagz[7] = { 0x4, 0x2D, 0x4F, 0x9A, 0xB, 0x35, 0x80 };


Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello!");

  nfc.begin();
  nfc.SAMConfig();
  nfc.setPassiveActivationRetries(1);

  pinMode(7, OUTPUT);
  digitalWrite(7, LOW); //regular output
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW); //gag output

  Serial.println("Waiting for an ISO14443A Card ...");
}


void loop(void) {
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    for (uint8_t i = 0; i < uidLength; i++) {
      //Serial.print(uid[i], HEX);
      //Serial.print(" ");
      if ((uid[i] != pwd[i]) && (uid[i] != gagp[i]) && (uid[i] != gagz[i])) {
        Serial.println("low");
        digitalWrite(7, LOW);
        goto low;
      } else {
        if (i == uidLength - 1) {
          if (uid[i] == pwd[i]) {
            Serial.println("high");
            digitalWrite(7, HIGH);
          } else if ((uid[i] == gagp[i]) || (uid[i] == gagz[i])) {
            Serial.println("gag!");
            digitalWrite(8, HIGH);
          }
        }
      }
    }
  } else {
    Serial.println("low");
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }

low:
  // Wait a bit before reading the card again
  delay(100);
}

