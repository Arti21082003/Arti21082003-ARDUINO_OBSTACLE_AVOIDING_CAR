#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN A4 
#define ECHO_PIN A5 
#define MAX_DISTANCE 200 
#define MAX_SPEED 150 
#define MAX_SPEED_OFFSET 20 
#define COLLISION_DISTANCE 30 

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ); 
AF_DCMotor motor4(4, MOTOR34_1KHZ); 
Servo myservo;

boolean goesForward = false;
int distance = 100;
int speedSet = 0;

void setup() {
  Serial.begin(9600); 
  myservo.attach(10); 
  myservo.write(90); 
  delay(2000); 
  
  motor1.setSpeed(MAX_SPEED);
  motor2.setSpeed(MAX_SPEED);
  motor3.setSpeed(MAX_SPEED);
  motor4.setSpeed(MAX_SPEED);
  
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  int distanceR = 0;
  int distanceL = 0;
  delay(40);

  distance = readPing();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= COLLISION_DISTANCE) {
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    moveForward();
  }
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250; 
  }
  return cm;
}

int lookRight() {
  myservo.write(50); 
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90); 
  return distance;
}

int lookLeft() {
  myservo.write(170); 
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90); 
  return distance;
}

void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  goesForward = false;
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
}

void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(500);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}