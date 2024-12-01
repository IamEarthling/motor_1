#include <Arduino.h>
#include"LB.h"

MyClass myfuntion;


void setup() {
  myfuntion.set();
  
}

void loop() {
  myfuntion.motor();
  myfuntion.commutatorLED();
  myfuntion.PWM();
  myfuntion.dp();
  myfuntion.sevendisp();
}
