#ifndef XeTreEm_H
#define XeTreEm_H

#include <Arduino.h>

class XeTreEm {
  private:
    int _in1, _in2, _in3, _in4;
    int _ena, _enb;  // Enable pins for speed control  
    int _sensorLeft, _sensorMiddle, _sensorRight;
    int _trigPin, _echoPin;

  public:
    XeTreEm(int ena, int enb, int in1, int in2, int in3, int in4,
           int sensorLeft, int sensorMiddle, int sensorRight,
           int trigPin, int echoPin);
    
    void tien(int tocdo);      // Move forward
    void lui(int tocdo);       // Move backward
    void quaytrai(int tocdo);    // Turn left
    void quayphai(int tocdo);    // Turn right
    void dunglai();             // Stop
    void doline();              // Line follower logic
    void tranhvatcan();         // Avoid obstacles
    void inramanhinh(String noiDung); // Print debug info
    int docIRTrai();
    int docIRGiua();
    int docIRPhai();
    void docTatCaIR(int &trai, int &giua, int &phai);

};

#endif
