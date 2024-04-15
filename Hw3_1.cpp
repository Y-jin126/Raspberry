#include <iostream>
#include <wiringPi.h>
using namespace std;
#define PIN_TRIG  23
#define PIN_ECHO  24
#define RANGE_MAX  200
#define RANGE_MIN  0

#define RLED_GPIO  16
#define GLED_GPIO 17
#define BLED_GPIO 21

int main(int argc, char* argv[]){
  wiringPiSetupGpio();
  unsigned int T, L;
  pinMode(PIN_TRIG,OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(RLED_GPIO, OUTPUT);  
  pinMode(GLED_GPIO, OUTPUT);
  pinMode(BLED_GPIO, OUTPUT);
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
    if (L > 0 && L < 10 ) {
      digitalWrite(RLED_GPIO,HIGH);
      digitalWrite(GLED_GPIO,LOW);
      digitalWrite(BLED_GPIO,LOW);
    }
    else if (L>=10 && L < 15){
      digitalWrite(RLED_GPIO,LOW);
      digitalWrite(GLED_GPIO,HIGH);
      digitalWrite(BLED_GPIO,LOW);
    }
    else if ( L>=15 && L < 30){
      digitalWrite(RLED_GPIO,LOW);
      digitalWrite(GLED_GPIO,LOW);
      digitalWrite(BLED_GPIO,HIGH);
    }
    else{
      digitalWrite(RLED_GPIO,LOW);
      digitalWrite(GLED_GPIO,LOW);
      digitalWrite(BLED_GPIO,LOW);
    }
       delay(100);
  }
    return 0;
  }
