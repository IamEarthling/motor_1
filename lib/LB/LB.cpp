#include "LB.h"
#include <Arduino.h>
#include <IRremote.hpp>

int R = 11;
int G = 12;
int Y = 13;
int i = 0;
int button=4;
// 定義開關狀態和馬達角度
int swA ;
int swB ;
int ret ;
int motorangle;
int value;

bool motorRunning = false;
bool controlMode = false;
bool controState = false;  // LED 狀態


MyClass::MyClass() {}

void MyClass::set() {
    pinMode(sw1, INPUT);
    pinMode(sw2, INPUT);
    pinMode(re, INPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(button,INPUT);

    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(Y, OUTPUT);

   Serial.begin(115200);               // 初始化序列通訊
    IrReceiver.begin(IR_RECEIVE_PIN);   // 啟動紅外線接收器
    Serial.println("Ready to receive IR signal");
}
void MyClass::motor() {
    swA = analogRead(sw1); // 使用 sw1 作為開關讀取
    swB = analogRead(sw2); // 使用 sw2 作為開關讀取
    if (IrReceiver.decode()) {
        Serial.print("Command Received: 0x");
        Serial.println(IrReceiver.decodedIRData.command, HEX); // 使用 command 提取命令

        // 判斷按鍵命令
        switch (IrReceiver.decodedIRData.command) {
            case 0x47: // 遙控器按鍵 0x47
                digitalWrite(R, HIGH);
                digitalWrite(G, LOW);
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                value = 1;  // 設置 value 為 1
                break;

            case 0x46: // 遙控器按鍵 0x46
                digitalWrite(R, LOW);
                digitalWrite(G, HIGH);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                value = 0;  // 設置 value 為 0
                break;

            default:
                break;
        }

        // 如果 value == 1，進行進一步處理
        if (value == 1) {
            switch (IrReceiver.decodedIRData.command) {
                case 0x40: // 遙控器按鍵 0x40
                    commutatorLED();
                    digitalWrite(R, HIGH);
                    digitalWrite(IN1, HIGH);
                    digitalWrite(IN2, LOW);
                    break;

                case 0x44: // 遙控器按鍵 0x44
                    commutatorLED();
                    digitalWrite(R, HIGH);
                    digitalWrite(IN1, LOW);
                    digitalWrite(IN2, HIGH);
                    break;

                default:
                    break;
            }
        }
        IrReceiver.resume(); // 準備接收下一個紅外線信號
    }
}


void MyClass::commutatorLED() {
    for (i = 0; i < 5; i++) { // 修正迴圈條件
        digitalWrite(Y, HIGH); // 打開黃色LED
        delay(500); // 等待500毫秒
        digitalWrite(Y, LOW); // 關閉黃色LED
        delay(500); // 等待500毫秒
    }
}

void MyClass::PWM() {  
    ret = analogRead(re); // 從re引腳讀取值（假設這是某種控制信號）
    ret = map(ret, 0, 1023, 0, 255); // 將讀取值映射到PWM範圍
    analogWrite(ENA, ret); // 發送PWM信號到馬達驅動器
    delay(300);
    Serial.println(ret);
}
void MyClass::contro(){
if (digitalRead(button) == LOW) 
  {  
    controlMode=false;
  }
else if(digitalRead(button) == HIGH)
  {
    controlMode=true;
  }
}