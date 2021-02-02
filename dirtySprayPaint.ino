#include <Ps3Controller.h>
#include <ESP32Servo.h>
#include "Laser.h"
#include "SolenoidValve.h"

#define LASER_PIN_S  23
#define SOLENOIDVALVE_PIN_COIL1  22

Laser laser(LASER_PIN_S);
SolenoidValve solenoidValve(SOLENOIDVALVE_PIN_COIL1);

Servo servoL;
Servo servoB;

int lX;
int lY;

int posL = 90;
int posB = 90;

void notify() {

  lX = (Ps3.data.analog.stick.lx);
  lY = (Ps3.data.analog.stick.ly);

  if (lY < -5 && posL < 180) {
    posL++;
    servoL.write(posL);
    if (posL >= 90) {
      servoL.write(90);
    }
  }
  if (lY > 5 && posL > 0) {
    posL--;
    servoL.write(posL);
    if (posL >= 90) {
      servoL.write(90);
    }
  }
  if (lX < -5 && posB < 180) {
    posB++;
    servoB.write(posB);
  }
  if (lX > 5 && posB > 0)
  {
    posB--;
    servoB.write(posB);

  }

  if ( abs( Ps3.event.button_down.l3)) {
    posB = 90;
    servoB.write(posB);
    posL = 90;
    servoL.write(posL);
  }

  if ( Ps3.event.button_down.cross ) {

    solenoidValve.on(); // 1. turns on
    if (laser.getState() == 0) {
      laser.on();
    }
  }

  if (Ps3.event.button_up.cross) {
    solenoidValve.off();// 3. turns off
    if (laser.getState() == 1) {
      laser.off();
    }
  }

  if ( Ps3.event.button_down.r2 ) {
    Serial.println(laser.getState());
    if (laser.getState() == 0) {
      laser.on();
    } else {
      laser.off();
    }
  }


  if ( Ps3.event.button_down.triangle ) {
  }

}

void onConnect() {
  Serial.println("Connected.");

}

void setup()
{
  Serial.begin(115200);
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("14:7d:da:77:bd:a8");
  Serial.println("Ready.");

  servoL.attach(18);
  servoB.attach(19);
  servoL.write(posL);
  servoB.write(posB);

}

void loop()
{
  if (!Ps3.isConnected())
    return;
  delay(2000);
}
