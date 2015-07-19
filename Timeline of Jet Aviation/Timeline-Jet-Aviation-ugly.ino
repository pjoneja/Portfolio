int button0;
int button1;
int button2;
int button3;
int button4;
int button5;
int button6;
int button7;
int button8;
int button9;
int back;

int prev_button0 = HIGH;
int prev_button1 = HIGH;
int prev_button2 = HIGH;
int prev_button3 = HIGH;
int prev_button4 = HIGH;
int prev_button5 = HIGH;
int prev_button6 = HIGH;
int prev_button7 = HIGH;
int prev_button8 = HIGH;
int prev_button9 = HIGH;
int prev_back = HIGH;

void setup() {
  for (int i = 2; i < 13; i++) {
    pinMode(i, INPUT);
  }
  Keyboard.begin();
}

void loop() {
  button0 = digitalRead(2);
  if ((button0 != prev_button0) && (button0 == HIGH)) {
    Keyboard.print("0");
  }
  prev_button0 = button0;
  
  button1 = digitalRead(3);
  if ((button1 != prev_button1) && (button1 == HIGH)) {
    Keyboard.print("1");
  }
  prev_button1 = button1;
 
  button2 = digitalRead(4);
  if ((button2 != prev_button2) && (button2 == HIGH)) {
    Keyboard.print("2");
  }
  prev_button2 = button2;
  
  button3 = digitalRead(5);
  if ((button3 != prev_button3) && (button3 == HIGH)) {
    Keyboard.print("3");
  }
  prev_button3 = button3;
  
  button4 = digitalRead(6);
  if ((button4 != prev_button4) && (button4 == HIGH)) {
    Keyboard.print("4");
  }
  prev_button4 = button4;
  
  button5 = digitalRead(7);
  if ((button5 != prev_button5) && (button5 == HIGH)) {
    Keyboard.print("5");
  }
  prev_button5 = button5;
  
  button6 = digitalRead(8);
  if ((button6 != prev_button6) && (button6 == HIGH)) {
    Keyboard.print("6");
  }
  prev_button6 = button6;

  button7 = digitalRead(9);
  if ((button7 != prev_button7) && (button7 == HIGH)) {
    Keyboard.print("7");
  }
  prev_button7 = button7;

  button8 = digitalRead(10);
  if ((button8 != prev_button8) && (button8 == HIGH)) {
    Keyboard.print("8");
  }
  prev_button8 = button8;

  button9 = digitalRead(11);
  if ((button9 != prev_button9) && (button9 == HIGH)) {
    Keyboard.print("9");
  }
  prev_button9 = button9;

  back = digitalRead(12);
  if ((back != prev_back) && (back == HIGH)) {
    Keyboard.print("b");
  }
  prev_back = back;
}

