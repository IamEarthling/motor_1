#include <Arduino.h>
#include"LB.h"

MyClass myfuntion;


void setup() {
  myfuntion.set();
  
}

void loop() {
  myfuntion.motor();
  myfuntion.PWM();
  myfuntion.contro();

}
