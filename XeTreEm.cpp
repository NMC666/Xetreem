#include "XeTreEm.h"

XeTreEm::XeTreEm(int ena, int enb, int in1, int in2, int in3, int in4,
         int sensorLeft, int sensorMiddle, int sensorRight,
         int trigPin, int echoPin) {
  _ena = ena; _enb = enb;  // Enable pins for PWM speed control  
  _in1 = in1; _in2 = in2; _in3 = in3; _in4 = in4;  
  _sensorLeft = sensorLeft;
  _sensorMiddle = sensorMiddle;
  _sensorRight = sensorRight;
  _trigPin = trigPin; _echoPin = echoPin;

  // Initialize all pins
  pinMode(_ena, OUTPUT);
  pinMode(_enb, OUTPUT);
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
  pinMode(_sensorLeft, INPUT);
  pinMode(_sensorMiddle, INPUT);
  pinMode(_sensorRight, INPUT);
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

// Set speed via ENA/ENB (PWM), direction via IN1-IN4 (HIGH/LOW)
void XeTreEm::tien(int tocdo) {
  analogWrite(_ena, tocdo);  
  analogWrite(_enb, tocdo);  
  digitalWrite(_in1, HIGH);  
  digitalWrite(_in2, LOW);   
  digitalWrite(_in3, HIGH);  
  digitalWrite(_in4, LOW);   
}

void XeTreEm::lui(int tocdo) {
  analogWrite(_ena, tocdo);  
  analogWrite(_enb, tocdo);  
  digitalWrite(_in1, LOW);   
  digitalWrite(_in2, HIGH);  
  digitalWrite(_in3, LOW);   
  digitalWrite(_in4, HIGH);  
}

void XeTreEm::quaytrai(int tocdo) {
  analogWrite(_ena, tocdo);  
  analogWrite(_enb, tocdo);  
  digitalWrite(_in1, LOW);   
  digitalWrite(_in2, HIGH);  // Left motor backward  
  digitalWrite(_in3, HIGH);  // Right motor forward  
  digitalWrite(_in4, LOW);   
}

void XeTreEm::quayphai(int tocdo) {
  analogWrite(_ena, tocdo);  
  analogWrite(_enb, tocdo);  
  digitalWrite(_in1, HIGH);  // Left motor forward  
  digitalWrite(_in2, LOW);   
  digitalWrite(_in3, LOW);   // Right motor backward  
  digitalWrite(_in4, HIGH);  
}

void XeTreEm::dunglai() {
  analogWrite(_ena, 0);      // Disable motors  
  analogWrite(_enb, 0);  
  digitalWrite(_in1, LOW);  
  digitalWrite(_in2, LOW);  
  digitalWrite(_in3, LOW);  
  digitalWrite(_in4, LOW);  
}

void XeTreEm::doline() {
  int left = digitalRead(_sensorLeft);
  int middle = digitalRead(_sensorMiddle);
  int right = digitalRead(_sensorRight);

  if (left == 1 && middle == 0 && right == 0) {
    quayphai(150); // Turn right to correct
  } else if (left == 0 && middle == 1 && right == 0) {
    tien(150); // Move forward
  } else if (left == 0 && middle == 0 && right == 1) {
    quaytrai(150); // Turn left to correct
  } else if (left == 1 && middle == 1 && right == 0) {
    quayphai(120); // Slightly turn right
  } else if (left == 0 && middle == 1 && right == 1) {
    quaytrai(120); // Slightly turn left
  } else if (left == 1 && middle == 1 && right == 1) {
    dunglai(); // Stop
  } else if (left == 1 && middle == 0 && right == 1) {
    dunglai(); // Stop or take corrective action
  } else {
    dunglai(); // Stop or take corrective action
  }
}

void XeTreEm::tranhvatcan() {
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  long duration = pulseIn(_echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < 15) {
    dunglai();
    delay(200);
    lui(150);
    delay(300);
    quaytrai(150);
    delay(400);
  } else {
    tien(150); 
  }
}

// Spin in place


void XeTreEm::inramanhinh(String noiDung) {
  Serial.println(noiDung);
}
int XeTreEm::docIRTrai() {
  return digitalRead(_sensorLeft);
}

int XeTreEm::docIRGiua() {
  return digitalRead(_sensorMiddle);
}

int XeTreEm::docIRPhai() {
  return digitalRead(_sensorRight);
}

void XeTreEm::docTatCaIR(int &trai, int &giua, int &phai) {
  trai = digitalRead(_sensorLeft);
  giua = digitalRead(_sensorMiddle);
  phai = digitalRead(_sensorRight);
}

