/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */


//  #include <LiquidCrystal.h>

// LiquidCrystal lcd(13, 4, 12, 11, 10, 9);
// //                BS  E  D4 D5  D6 D7

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int st1 = 5;
int st2 = 6;
int st3 = 7;
int st4 = 8;
int led = 13;
int cnt = 0;
int b1 = 2;  //
int b2 = 3;
// int an0 = A0;
int pos1;
long cnt5 = 0;
int val;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(st1, OUTPUT);
  pinMode(st2, OUTPUT);
  pinMode(st3, OUTPUT);
  pinMode(st4, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);

  digitalWrite(st1, HIGH);
  digitalWrite(st2, HIGH);
  digitalWrite(st3, HIGH);
  digitalWrite(st4, HIGH);
  Serial.begin(9600);
  Serial.println("WELL COME");
  // pinMode(an0, INPUT);
  // lcd.begin(16, 2);
  // Serial.println("Wel")
  // lcd.setCursor(0, 0);  lcd.print("WELL COME ");
  delay(500);
  // lcd.clear();
}

// the loop routine runs over and over again forever:
void loop() {
 turnRight();
}
void turnLeft() {
  digitalWrite(st1, LOW);
  digitalWrite(st2, HIGH);
  delay(50);
  digitalWrite(st3, HIGH);
  digitalWrite(st4, LOW);
}
void turnRight() {
  digitalWrite(st1, HIGH);
  digitalWrite(st2, LOW);
  delay(50);
  digitalWrite(st3, LOW);
  digitalWrite(st4, HIGH);
}
void fwd() {
  digitalWrite(st1, LOW);
  digitalWrite(st2, HIGH);
  digitalWrite(st3, LOW);
  digitalWrite(st4, HIGH);
}
void rev() {
  digitalWrite(st1, HIGH);
  digitalWrite(st2, LOW);
  digitalWrite(st3, HIGH);
  digitalWrite(st4, LOW);
}
void stop1() {
  digitalWrite(st1, HIGH);
  digitalWrite(st2, HIGH);
  digitalWrite(st3, HIGH);
  digitalWrite(st4, HIGH);
}