#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 199
#define DATAPIN    8
#define CLOCKPIN   9
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

int next[5] = {0, 0, 0, 0, 0};
int LEDpos[5] = {54, 95, 156, 169, 34};
int LEDcount[5] = {40, 56, 12, 30, 19};
bool firstRead;
bool toggleBell = false;
const uint32_t red = 0xFF0000;
const uint32_t blue = 0x0000FF;

void bounce (int pinNumber) {
  Serial.print("bouncing signal at pin: ");
  Serial.println(pinNumber);
  digitalWrite(pinNumber, LOW);
  delay(200);
  digitalWrite(pinNumber, HIGH);
}

void ding () {
  Serial.println("ding");
  digitalWrite(52, HIGH);
  delay(200);
  digitalWrite(52, LOW);
}

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
  //setup arduino inputs
  for (int i = 2; i < 7; i++) {
    Serial.print("hello ");
    Serial.println(i);
    pinMode(i, INPUT); //2,3,4,5,6 input
  }

  for (int j = 0; j < 15; j++) {
    pinMode(2 * j + 23, OUTPUT); //23 thru 51 output
    digitalWrite(2 * j + 23, HIGH); //initialize HIGH
  }

  //initialize bell output as LOW
  pinMode(52, OUTPUT);
  digitalWrite(52, LOW);

  //initialize lamp screen output as LOW
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);

  //initialize gag input
  pinMode(13, INPUT);

  //wait until player turns on
  delay(4000);
  ding();
  delay(300);
  ding();

  //select "track 1" and pause
  for (int k = 0; k < 5; k++) {
    Serial.print("start showing map at:");
    Serial.println(k);
    //bounce for "track 1"
    bounce(6 * k + 23); //pins 23,29,35,41,47
    delay(650);
    //bounce for "pause"
    bounce(6 * k + 27); //pins 27,33,39,45,51
  }
}

void loop() {
  for (int n = 0; n < 5; n++) {
    //ding-ding-ding and lamp screen
    /*for (int a = 0; a < 5; a++) {
      if (next[a] != 1) {
        goto skip;
      } else if (a == 4) {
        digitalWrite(10, HIGH); //lamp screen on
        if (toggleBell == false) {
          toggleBell = true;
          for (int b = 0; b < 3; b++) {
            ding();
            delay(300);
          }
        }
      }
    }*/

    if ((next[0] == 1) && (next[1] == 1) && (next[2] == 1) && (next[3] == 1) && (next[4] == 1)) {
      digitalWrite(10, HIGH); //lamp screen on
      if (toggleBell == false) {
        toggleBell = true;
        for (int b = 0; b < 3; b++) {
          ding();
          delay(300);
        }
      }
    }

//skip:
    firstRead = digitalRead(n + 2);
    delay(2); //debounce
    if (firstRead && digitalRead(n + 2)) {
      if (((next[n] == 0) && (next[n - 1] == 1)) || ((n == 0) && (next[0] == 0))) {
        ding(); //bell
        //show description
        Serial.print("show description at:");
        Serial.println(n);
        //bounce for "track 2"
        bounce(6 * n + 25); //pins 25,31,37,43,49
        //delay(650); //turn on LEDs while waiting.....
        Serial.print("LED section #");
        Serial.println(n);
        for (int head = 0; head < LEDcount[n]; head++) {
          strip.setPixelColor(head + LEDpos[n], red);
          strip.setPixelColor(head + LEDpos[n] - 1, blue);
          strip.show();
          Serial.print("LEDpos: ");
          Serial.println(head);
          delay(50);
        }
        if (n == 3) { //pacific ocean wrap-around leg
          for (int head = 5; head < 31; head++) {
            strip.setPixelColor(head, red);
            strip.setPixelColor(head - 1, blue);
            strip.show();
            Serial.print("LEDpos: ");
            Serial.println(head);
            delay(50);
          }
        }
        //bounce for "pause"
        bounce(6 * n + 27); //pins 27,33,39,45,51
        delay(100);
        next[n] = 1;
      } else if (next[n] == 1) {
        //stay on description
        Serial.print("stay on description at:");
        Serial.println(n);
      }
    } else {
      if (next[n] == 1) {
        toggleBell = false;
        digitalWrite(10, LOW);
        //LED off
        for (int c = n; c < 5; c++) {
          next[c] = 0;
          for (int head = 0; head <= LEDcount[c]; head++) {
            strip.setPixelColor(head + LEDpos[c] - 1, 0);
            strip.show();
            delay(1);
          }
          if (c == 3) {
            for (int head = 5; head <= 31; head++) {
              strip.setPixelColor(head - 1, 0);
              strip.show();
              delay(1);
            }
          }
          //show map
          Serial.print("show map at:");
          Serial.println(c);
          //bounce for "track 1"
          bounce(6 * c + 23); //pins 23,29,35,41,47
        }
        delay(650); // delay for player
        for (int c = n; c < 5; c++) {
          //bounce for "pause"
          bounce(6 * c + 27); //pins 27,33,39,45,51
        }
      } else if (next[n] == 0) {
        //stay on map
        Serial.print("stay on map at:");
        Serial.println(n);
      }
    }
  }

  while (digitalRead(13)) {
    ding();
    delay(300);
  }
}


