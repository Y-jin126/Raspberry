#include <iostream>
#include <wiringPi.h>
using namespace std;
#define PIN_TRIG  23
#define PIN_ECHO  24
#define RANGE_MAX  200
#define RANGE_MIN  0

#define RLED_GPIO  4
#define GLED_GPIO 17
#define BLED_GPIO 27

int main(int argc, char* argv[]){
  wiringPiSetupGpio();
  unsigned int T, L;
  pinMode(PIN_TRIG,OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(RLED_GPIO, OUTPUT);  
  pinMode(GLED_GPIO, OUTPUT);
  pinMode(YLED_GPIO, OUTPUT);
  while(1){
    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(20);
    digitalWrite(PIN_TRIG, LOW);
    while(digitalRead(PIN_ECHO) == LOW);

    unsigned int startTime = micros();
    while(digitalRead(PIN_ECHO) == LOW);
    T= micros() - startTime;
    L = T / 58.2;
    if (L > 0 || L < 10 ) {
      degitalWrite(RLED_GPIO,HIGH);
      degitalWrite(GLED_GPIO,LOW);
      degitalWrite(BLED_GPIO,LOW);
    }
    else if (L>=10 || L < 15){
      degitalWrite(RLED_GPIO,LOW);
      degitalWrite(GLED_GPIO,HIGH);
      degitalWrite(BLED_GPIO,LOW);
    }
    else if ( L>=15 || L < 30){
      degitalWrite(RLED_GPIO,LOW);
      degitalWrite(GLED_GPIO,LOW);
      degitalWrite(BLED_GPIO,HIGH);
    }
    else{
      degitalWrite(RLED_GPIO,LOW);
      degitalWrite(GLED_GPIO,LOW);
      degitalWrite(BLED_GPIO,LOW);
    }
      
    delay(100);
  
  }
