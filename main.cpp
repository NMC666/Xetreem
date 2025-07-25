#include "XeTreEm.h"

XeTreEm xe(2, 4, 16, 17, 34, 35, 5, 18 , 19, 20 , 21 );  // khai báo chân thực tế cho ESP32

void setup() {
  Serial.begin(115200);
}

void loop() {
  xe.tien(120);      
  delay(1000);
  xe.dunglai();   
  delay(500);
  xe.lui(120);       
  delay(1000);
  xe.doline();
  xe.tranhvatcan();
  int trai = xe.docIRTrai();
  int giua = xe.docIRGiua();
  int phai = xe.docIRPhai();

  // Các em tự viết điều kiện điều khiển
  if (trai == 0 && giua == 0 && phai == 0) {
  xe.dunglai();
} else if (trai == 0 && giua == 0 && phai == 1) {
  xe.quaytrai(130);
} else if (trai == 0 && giua == 1 && phai == 0) {
  xe.tien(150);
} else if (trai == 0 && giua == 1 && phai == 1) {
  xe.quaytrai(100);
} else if (trai == 1 && giua == 0 && phai == 0) {
  xe.quayphai(130);
} else if (trai == 1 && giua == 0 && phai == 1) {
  xe.tien(100);
} else if (trai == 1 && giua == 1 && phai == 0) {
  xe.quayphai(100);
} else if (trai == 1 && giua == 1 && phai == 1) {
  xe.tien(100);
}

}
