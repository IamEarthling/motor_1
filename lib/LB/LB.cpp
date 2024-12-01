#include"LB.h"
#include<Arduino.h>
#include<IRremote.h>
 int R=11;
 int G=12;
 int Y=13;
 int i=0;

 const int pinA=6;
 const int pinB=7;
 const int pinC=9;
 const int pinD=10;

 

byte bcd_code[4][4]=
{
  {0,0,0,0},//0
  {0,0,0,1},//1
  {0,0,1,0},//2
  {0,0,1,1},//3
};



IRrecv irrecv(IR_RECEIVE_PIN); 
decode_results results;         



MyClass::MyClass(){}


void MyClass::set()
{
    pinMode(sw1,INPUT);
    pinMode(sw2,INPUT);
    pinMode(re,INPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(ENA,OUTPUT);

    pinMode(R,OUTPUT);
    pinMode(G,OUTPUT);
    pinMode(Y,OUTPUT);

    
    Serial.begin(115200);       
    irrecv.enableIRIn();        


    pinMode(pinA,OUTPUT);
    pinMode(pinB,OUTPUT);
    pinMode(pinC,OUTPUT);
    pinMode(pinD,OUTPUT);



}

void MyClass::motor()
{
swA=analogRead(sw1);
swB=analogRead(sw2);
if (irrecv.decode(&results)) { 
        long int decCode = results.value; 
        Serial.println(decCode, HEX);   

    if (swB==1|decCode ==0xFFA25D)
    {
            digitalWrite(R,HIGH);
            digitalWrite(IN1,HIGH);
            digitalWrite(IN2,LOW);

        if (swA==1|decCode ==0xFF02FD)
        {   
            commutatorLED();
            digitalWrite(R,HIGH);
            digitalWrite(IN1,HIGH);
            digitalWrite(IN2,LOW);
        }
        else if (swA==0|decCode ==0xFF22DD)
        {
            commutatorLED();
            digitalWrite(R,HIGH);
            digitalWrite(IN1,LOW);
            digitalWrite(IN2,HIGH);
        }
    }
    else 
    {
        digitalWrite(R,LOW);
        digitalWrite(G,HIGH);
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,LOW);

    }
    irrecv.resume();
}
}

void MyClass::commutatorLED()
{
    for (i;i>5;i++)
    {
        if (i==i)
        {
            digitalWrite(Y,HIGH);
            delay(500);
        }
    }
}
 

void MyClass::PWM()
{  
    ret=analogRead(re);
   
    ret=map(motorangle,0,1023,0,255);

    analogWrite(ENA,motorangle);
}


void dp()
{
    if (motorangle==0)
    {
        sevendisp(0);
    }
    else if (motorangle==64)
    {
        sevendisp(1);
    }
    else if (motorangle==127)
    {
        sevendisp(2);
    }
    else if (motorangle==190)
    {
        sevendisp(3);
    }
    else if (motorangle==255)
    {
        sevendisp(4);
    }

}





void sevendisp(byte d){
  digitalWrite(pinA, bcd_code[d][3]);
  digitalWrite(pinB, bcd_code[d][2]);
  digitalWrite(pinC, bcd_code[d][1]);
  digitalWrite(pinD, bcd_code[d][0]);
}
