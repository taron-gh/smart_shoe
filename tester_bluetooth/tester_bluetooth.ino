#include <Servo.h>



Servo camrot, camheight, armrot, armheight, elbow, finger; 
 


void setup() {
  Serial.begin(9600);
  camrot.attach(7);
  camheight.attach(6);
  armrot.attach(5);
  armheight.attach(4);
  elbow.attach(9);
  finger.attach(8);
}

void loop() {
  if(Serial.available() >= 2){
    unsigned int firstnum = Serial.read();
    unsigned int secnum = Serial.read();
    unsigned int realnum = (secnum * 256) + firstnum;

    if (realnum >= 1000 && realnum < 1180) {
      int camrota = realnum;
      camrota = map(camrota, 1000, 1180, 0, 180);
      camrot.write(camrota);
      delay(10);
    }
    if (realnum >= 2000 && realnum < 2180) {
      int camheighta = realnum;
      camheighta = map(camheighta, 2000, 2180, 0, 180);
      camheight.write(camheighta);
      delay(10);
    }
    if (realnum >= 3000 && realnum < 3180) {
      int armrota = realnum;
      armrota = map(armrota, 3000, 3180, 0, 180);
      armrot.write(armrota);
      delay(10);
    }
    if (realnum >= 4000 && realnum < 4180) {
      int armheighta = realnum;
      armheighta = map(armheighta, 4000, 4180, 0, 180);
      armheight.write(armheighta);
      delay(10);
    }
    if (realnum >= 5000 && realnum < 5180) {
      int elbowa = realnum;
      elbowa = map(elbowa, 5000, 5180, 0, 180);
      elbow.write(elbowa);
      delay(10);
    }
    if (realnum >= 6000 && realnum < 6180) {
      int  fingera = realnum;
      fingera = map(fingera, 6000, 6180, 0, 180);
      finger.write(fingera);
      delay(10);
    }
  }
}
