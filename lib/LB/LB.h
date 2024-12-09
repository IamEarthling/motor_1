#ifndef LB_H
#define LB_H

#define sw1 A0 //開關
#define sw2 A1//搖頭
#define re A2
#define IN1 2
#define IN2 3
#define ENA 5
#define IR_RECEIVE_PIN 8


extern int R;
extern int G;
extern int Y;
extern int i;
extern int swA; // 開關A狀態
extern int swB; // 開關B狀態
extern int ret; // 返回值
extern int motorangle; // 馬達角度
extern int value;
extern bool motorRunning;
extern bool controlMode;
extern bool ledState ;
extern int button;


class MyClass {
public:
    MyClass();
    void set();
    void motor();
    void commutatorLED();
    void PWM();
    void contro();

};

#endif