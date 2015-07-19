//button states for 0-9 and "back"
int button[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int prev_button[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  for (int i = 2; i < 13; i++) {
    pinMode(i, INPUT);
  }
  Keyboard.begin();
}

void loop() {
  for (int n = 0; n < 11; n++) {
    button[n] = digitalRead(n + 2); //pins and buttons offset by 2
    if ((button[n] != prev_button[n]) && (button[n] == HIGH)) { //debounce
      if (n == 10) {
        Keyboard.print("b"); //for "back" button, print "b"
      } else {
        Keyboard.print(n); //for 0-9 buttons, print 0-9 accordingly
      }
    }
    prev_button[n] = button[n];
  }
}

