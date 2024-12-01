#ifndef LB_H
#define LB_H

#define sw1 A0
#define sw2 A1
#define re A2
#define IN1 2
#define IN2 3
#define ENA 5
#define IR_RECEIVE_PIN 8

extern int R;
extern int G;
extern int Y;
extern int i;
extern int swA;
extern int swB;
extern int ret;
extern int motorangle;


extern int pinA;
extern int pinB;
extern int pinC;
extern int pinD;






class MyClass{
public:
        MyClass();
        void set();
        void motor();
        void commutatorLED();
        void PWM();
        void sevendisp();
        void dp();
        
};
#endif

