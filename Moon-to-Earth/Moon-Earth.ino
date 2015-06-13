int A = 13;
int B = 12;
int C = 11;
int D = 10;
int E = 9;
int F = 8;
int G = 7;
int H = 6;
int X = 5;
int pushButton = 4;
int TIME = 46; //time-step in ms
int buttonState1 = 0;
int buttonState2 = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(A, OUTPUT);  
  pinMode(B, OUTPUT); 
  pinMode(C, OUTPUT); 
  pinMode(D, OUTPUT); 
  pinMode(E, OUTPUT);  
  pinMode(F, OUTPUT); 
  pinMode(G, OUTPUT); 
  pinMode(H, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(pushButton, INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState1 = digitalRead(pushButton);
  delay(2);
  buttonState2 = digitalRead(pushButton);
  
  //initial state: all LEDS off
  digitalWrite(X, HIGH);
  digitalWrite(E, LOW);   
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
  
  if (buttonState1 == buttonState2){
    if (buttonState2 == 1){
  digitalWrite(X, HIGH);
  digitalWrite(E, HIGH);   
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, HIGH);
 delay(TIME);
  digitalWrite(E, LOW);   
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, HIGH);
 delay(TIME); 
  digitalWrite(E, HIGH);   
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, HIGH);
 delay(TIME); 
  digitalWrite(E, LOW);   
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, HIGH);
 delay(TIME); 
  digitalWrite(E, HIGH);   
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
 delay(TIME);
  digitalWrite(E, LOW);   
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
 delay(TIME); 
  digitalWrite(E, HIGH);   
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
 delay(TIME); 
  digitalWrite(E, LOW);   
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
 delay(TIME); 
  digitalWrite(E, HIGH);   
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
 delay(TIME); 
  digitalWrite(E, LOW);   
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
 delay(TIME); 
  digitalWrite(E, HIGH);   
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
 delay(TIME); 
  digitalWrite(E, LOW);   
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
 delay(TIME);		    //turning off second chip
  digitalWrite(E, LOW);   
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(X, LOW);     //first chip
  digitalWrite(A, HIGH);   
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
 delay(TIME);         
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
 delay(TIME); 
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
 delay(TIME);
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
 delay(TIME); 
  digitalWrite(A, HIGH);   
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
 delay(TIME);
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
 delay(TIME); 
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
 delay(TIME);  
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
 delay(TIME);  
  digitalWrite(A, HIGH);   
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
 delay(TIME);
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
 delay(TIME);  
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
 delay(TIME); 
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
 delay(TIME);
  digitalWrite(A, HIGH);   
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
 delay(TIME);
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
 delay(TIME);
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
 delay(TIME); 
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
//final state: all LEDs off
  digitalWrite(E, LOW);   
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, HIGH);
  
  //clear buttonStates
  buttonState1 = 0;
  buttonState2 = 0;
  }
  }
  delay(100);
}
