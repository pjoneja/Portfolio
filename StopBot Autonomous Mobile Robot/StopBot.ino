//include servo library
#include <Servo.h>

// #DEFINE ALGORITHM PARAMETERS
//side distance threshholds
#define tooclose 6   //cm
#define toofar 14    //cm
#define diffthresh 2 //cm
#define diffcrazy 40
//front distance threshholds
#define frontthresh 20 //cm 
//photo transistor threshholds
#define PTthresh 60
#define debounceArrayLength 10 // 
//Servo positions
#define ServoLeft 200
#define ServoCenter 90 //experimentally determined center!1
#define ServoRight 0

// #DEFINE PINS
//switches
#define RWallFollowPin 10
#define LWallFollowPin 11
//hbridge
#define input1 5
#define input2 6
#define input3 3
#define input4 4
#define ServoPin 13
//sensors
#define sensor0 A0 // Right Rear Sharp IR
#define sensor1 A1 // Right Front Sharp IR 
#define sensor2 A2 // Front Right Sharp IR 
#define sensor3 A3 // Front Middle Sharp IR
#define sensor4 A4 // Front Left Sharp IR 
#define sensor5 A10 // Left Front Sharp IR
#define sensor6 A9 // Left Rear Sharp IR
#define RptPin A6 // Right phototransistor
#define LptPin A7 // Left phototransistor

// #initialize global variables
Servo launcher;
int RWallFollowSwitch; int LWallFollowSwitch;

float volt0; float volt1; float volt2;
float volt3;
float volt4; float volt5; float volt6;

int distance0; int distance1; int distance2;
int distance3;
int distance4; int distance5; int distance6;

int diff;

int Rpt;
int Lpt;
int Rpt_avg;
int Lpt_avg;
int Rptdebounce[debounceArrayLength];
int Lptdebounce[debounceArrayLength];
int shotcount = 0;
bool takeshot = true;

void setup() {
  Serial.begin(9600);

  pinMode(RWallFollowPin, INPUT);
  pinMode(LWallFollowPin, INPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  launcher.attach(ServoPin);
  delay(25);
  launcher.write(ServoCenter);
}

void loop() {

  ReadWorld();
  Serial.print(shotcount); Serial.print("\t");
  Serial.print(Lpt_avg); Serial.print("\t"); Serial.println(Rpt_avg);
  delay(20); //settle down

  if (shotcount > 15) {
    takeshot = false; //
  }

  if ((Rpt_avg < PTthresh && Lpt_avg < PTthresh) || not(takeshot)) {
    launcher.write(ServoCenter);
    shotcount = 0; //reset shotcount~!
  }

  if (Rpt_avg > PTthresh && takeshot) { //IR on the right 
    RMotorStop();
    LMotorStop();
    launcher.write(ServoRight);
    shotcount += 1;
    delay(50);
  }
  else if (Lpt_avg > PTthresh && takeshot) {//IR on the left
    RMotorStop();
    LMotorStop();
    launcher.write(ServoLeft);
    shotcount += 1;
    delay(50);
  }

  else if (RWallFollowSwitch == 0 && LWallFollowSwitch == 0) {
    RMotorStop();
    LMotorStop();
  }

  else if (RWallFollowSwitch == 1) {//Right wall follow switch
    if (diff > 40) {// sensors are crazy, stop doing anything TODO: parameterize diff
      RMotorStop();
      LMotorStop();
    }
    else if (SomethingInFront()) { //obstacle in front
      Serial.println("obstacle in front");
      while (diff < -1 * diffthresh || diff > diffthresh || SomethingInFront()) {
        ReadWorld();
        //rotate right
        RMotorForward();
        LMotorReverse();
      }
    }
   // NO OBSTACLES IN FRONT, IS THERE ANYTHING ON THE SIDE?
   /* else if (distance0 >= toofar || distance1 >= toofar) {
      //if there's nothing to the side either, turn sharp!
      LMotorForward();
      RMotorStop();
      delay(20);
      RMotorForward();
      } */

    // NO OBSTACLES IN FRONT, THERE'S SOME WALL DETECTED ON THE SIDE
    else { //reasonable distance difference on the right side

      //do not get too close
      if (distance1 <= tooclose) {
        Serial.println("Move away from the wall");
        RMotorForward();
        LMotorReverse();
        delay(10);
        LMotorForward();
      }
      //do not get too far
      else if (distance1 >= toofar) {
        Serial.println("Move closer to the wall");
        RMotorReverse();
        LMotorForward();
        delay(10);
        RMotorForward();
      }

      //WALL FOLLOW ON THE RIGHT
      else { //not too far, not too close, let's WALL FOLLOW
        //if the back is closer than the front, turn right a bit
        if (diff <= -1 * diffthresh) {
          Serial.println("Right");   // right turn command
          RMotorStop();
          LMotorForward();
          delay(10);
          RMotorForward();
        }
        else if (diff >= diffthresh) {
          Serial.println("Left"); //left turn command
          RMotorForward();
          LMotorStop();
          delay(10);
          LMotorForward();
        }
        else {
          Serial.println("Go"); //going straight command
          RMotorForward();
          LMotorForward();
        }
      }
    }
  }

  else if (LWallFollowSwitch == 1) {//Left wall follow switch
    if (diff > 40) {// sensors are crazy, stop doing anything
      RMotorStop();
      LMotorStop();
    }
    else if (SomethingInFront()) { //obstacle in front
      Serial.println("obstacle in front");
      while (diff < -1 * diffthresh || diff > diffthresh || SomethingInFront()) {
        ReadWorld();
        //rotate right
        LMotorForward();
        RMotorReverse();
      }
    }


    // NO OBSTACLES IN FRONT, IS THERE ANYTHING ON THE SIDE?
    /* else if (distance5 >= toofar || distance6 >= toofar) {
      //if there's nothing to the side either, turn sharp!
      LMotorStop();
      RMotorForward();
      delay(20);
      LMotorForward();
      } */

    // NO OBSTACLES IN FRONT, THERE'S SOME WALL DETECTED ON THE SIDE
    else { //reasonable distance difference on the left side

      //do not get too close
      if (distance5  <= tooclose) {
        Serial.println("Move away from the wall");
        LMotorForward();
        RMotorReverse();
        delay(10);
        RMotorForward();
      }
      //do not get too far
      else if (distance5 >= toofar) {
        Serial.println("Move closer to the wall");
        LMotorReverse();
        RMotorForward();
        delay(10);
        LMotorForward();
      }

      //WALL FOLLOW
      else { //not too far, not too close, let's WALL FOLLOW
        //if the back is closer than the front, turn right a bit
        if (diff <= -1 * diffthresh) {
          Serial.println("Right");   // right turn command
          RMotorStop();
          LMotorForward();
          delay(10);
          RMotorForward();
        }
        else if (diff >= diffthresh) {
          Serial.println("Left"); //left turn command
          RMotorForward();
          LMotorStop();
          delay(10);
          LMotorForward();
        }
        else {
          Serial.println("Go"); //going straight command
          RMotorForward();
          LMotorForward();
        }
      }
    }
  }
}




// HELPER FUNCTIONS

void ReadWorld() {
  RWallFollowSwitch = digitalRead(RWallFollowPin);
  LWallFollowSwitch = digitalRead(LWallFollowPin);

  volt0 = analogRead(sensor0) * 0.0048828125; // value from sensor * (5/1024)
  volt1 = analogRead(sensor1) * 0.0048828125; // value from sensor * (5/1024)
  volt2 = analogRead(sensor2) * 0.0048828125; // value from sensor * (5/1024)
  volt3 = analogRead(sensor3) * 0.0048828125; // value from sensor * (5/1024)
  volt4 = analogRead(sensor4) * 0.0048828125; // value from sensor * (5/1024)
  volt5 = analogRead(sensor5) * 0.0048828125; // value from sensor * (5/1024)
  volt6 = analogRead(sensor6) * 0.0048828125; // value from sensor * (5/1024)

  Rpt = analogRead(RptPin);
  Lpt = analogRead(LptPin);

  Rpt_avg = moving_avg(Rpt,Rptdebounce);
  Lpt_avg = moving_avg(Lpt,Lptdebounce);

  //distance to wall in cm
  distance0 = 13 * pow(volt0, -1);
  distance1 = 13 * pow(volt1, -1);
  distance2 = 27.51 * pow(volt2, -1.18);
  distance3 = 27.51 * pow(volt3, -1.18);
  distance4 = 27.51 * pow(volt4, -1.18);
  distance5 = 13 * pow(volt5, -1);
  distance6 = 13 * pow(volt6, -1);

  if (RWallFollowSwitch == 1) {
    diff = distance0 - distance1;
  }
  else if (LWallFollowSwitch == 1) {
    diff = distance5 - distance6;
  }
  else {
    diff = 0;
  }
}

int moving_avg(int *pt, int *debounceArray) { //multi-use function for Left and Right side
  int sum = 0;
  int i;
  for (i = 0; i < debounceArrayLength-1; i++) { 
    debounceArray[i] = debounceArray[i+1];
    sum += debounceArray[i];
  }
  debounceArray[debounceArrayLength-1] = pt;
  sum += pt;

  return sum/debounceArrayLength;
}

bool SomethingInFront() {
  if (distance2 < frontthresh || distance3 < frontthresh || distance4 < frontthresh) {
    return true;
  }
  else {
    return false;
  }
}

void RMotorReverse() {
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
}

void RMotorForward() {
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
}

void RMotorStop() {
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
}

void LMotorReverse() {
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
}

void LMotorForward() {
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
}

void LMotorStop() {
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
}

