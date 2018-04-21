#include <ros.h>
#include <Arduino.h>
#include <std_msgs/Empty.h>
#include "A4988.h"

// using a 200-step motor (most common)
#define MOTOR_STEPS 200
// configure the pins connected
#define STEP1 3
#define DIR1 4
#define STEP2 5
#define DIR2 6
#define STEP3 7
#define DIR3 8

ros::NodeHandle  nh;

A4988 stepper1(MOTOR_STEPS, DIR1, STEP1);
A4988 stepper2(MOTOR_STEPS, DIR2, STEP2);
A4988 stepper3(MOTOR_STEPS, DIR3, STEP3);

void startMotor1(const std_msgs::Empty& toggle_msg){
  // blink the led, to indicate motor1 has started
  digitalWrite(0, HIGH);
  stepper1.rotate(360);
  digitalWrite(0, LOW);
}

void startMotor2(const std_msgs::Empty& toggle_msg){
  // blink the blue led, to indicate motor2 has started
  digitalWrite(1, HIGH);
  stepper2.rotate(360);
  digitalWrite(1, LOW);
}

void startMotor3(const std_msgs::Empty& toggle_msg){
  // blink the red led, to indicate motor3 has started
  digitalWrite(2, HIGH);
  stepper3.rotate(360);
  digitalWrite(2, LOW);
}

ros::Subscriber<std_msgs::Empty> motor1("motor1/start", &startMotor1);
ros::Subscriber<std_msgs::Empty> motor2("motor2/start", &startMotor2);
ros::Subscriber<std_msgs::Empty> motor3("motor3/start", &startMotor3);

void setup() { 
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  
  nh.initNode();

  stepper1.begin(15, 16);
  stepper2.begin(15, 16);
  stepper3.begin(15, 16);
  
  nh.subscribe(motor1);
  nh.subscribe(motor2);
  nh.subscribe(motor3);
}

void loop() {  
  nh.spinOnce();
  delay(1);
}