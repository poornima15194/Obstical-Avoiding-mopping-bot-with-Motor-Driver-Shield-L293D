#include <AFMotor.h>

const int trigPin = 9;
const int echoPin = 10;
int Distance;
long duration;
int distance;
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);

void setup() {
  Serial.begin(9600); 
  motor1.setSpeed(200);          
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Distance_Calc(); 
  if (distance >=20){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    Serial.println("Forward");
 }
 if (distance <=20){
    motor1.run(FORWARD);
    motor2.setSpeed(0);
    Serial.println("Turn Right");
    delay(1000);
    motor1.run(FORWARD);
    motor2.setSpeed(200);
    motor2.run(FORWARD);
    Serial.println("Forward");
    if(distance <=3){
      motor1.run(LOW);
      motor1.setSpeed(0);
      motor2.run(FORWARD);
      Serial.println("Turn Left");
      delay(5000);
      motor1.setSpeed(200);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      Serial.println("Forward");
    }
  }
}

int Distance_Calc(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
