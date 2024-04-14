#include <Servo.h>
Servo swingPath;
const int trigPin = 13;
const int echoPin = 12;
const int linePin = 11;
const int swithPathPin = 9;

int st1 = 5;
int st2 = 6;
int st3 = 7;
int st4 = 8;

int swingPathPos = 0;
float duration, distance;
bool isCloseToObstagle = false;
const int closeRange = 25;

void motorinit() {
  pinMode(st1, OUTPUT);
  pinMode(st2, OUTPUT);
  pinMode(st3, OUTPUT);
  pinMode(st4, OUTPUT);
}
void ultrasonicInit() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void ultrasonicLogin() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  isCloseToObstagle = distance <= closeRange;
  Serial.print(distance);
  Serial.println("cm");
  delay(30);
}

bool isOnThelineIRsensor() {

  return digitalRead(linePin) == HIGH;
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
void setup() {
  swingPath.attach(swithPathPin);  // attaches the servo on pin 9 to the servo object
  ultrasonicInit();
  pinMode(linePin, INPUT);
  motorinit();
  Serial.begin(9600);
}

void moveSwingPath() {
  int angleMax = 90;
  int stepMove = 4;
  int currentPos = swingPath.read();
  for (swingPathPos = 0; swingPathPos <= angleMax; swingPathPos += stepMove) {  // goes from 0 degrees to 180 degrees
    ultrasonicLogin();
    if (!isCloseToObstagle)
      break;
    // in steps of 1 degree
    swingPath.write(swingPathPos);  // tell servo to go to position in variable 'pos'
    delay(15);                      // waits 15ms for the servo to reach the position
    currentPos = swingPath.read();  // Read the current position after move
    Serial.print("Current Servo Angle: ");
    Serial.println(currentPos);
  }
  for (swingPathPos = angleMax; swingPathPos >= 0; swingPathPos -= stepMove) {  // goes from 180 degrees to 0 degrees
    ultrasonicLogin();
    if (!isCloseToObstagle)
      break;
    swingPath.write(swingPathPos);  // tell servo to go to position in variable 'pos'
    delay(15);                      // waits 15ms for the servo to reach the position
    currentPos = swingPath.read();  // Read the current position after move
    Serial.print("Current Servo Angle: ");
    Serial.println(currentPos);
  }
  if (!isCloseToObstagle) {
    swingPath.write(90);
  }
}

void loop() {
// turnLeft();
//  fwd();
  rev();
// stop1() 
}

void theMaze() {
  ultrasonicLogin();
  if (isOnThelineIRsensor() == true) {
     // stop car
  } else {
    if (isCloseToObstagle == true) {
      // stop car
      while (isCloseToObstagle) {
        moveSwingPath();
      }
      // turnCarStepMotor(false);
       // move
    } else {
      // moveForwardStepMotor();
    }
    // delay(500);
  }
  // ultrasonicLogin();
}
