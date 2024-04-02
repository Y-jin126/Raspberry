#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;
#define PWM_LED1   13
#define PWM_LED2  18

int main() {
  wiringPiSetupGpio();
  pinMode(PWM_LED1, PWM_OUTPUT);
  pinMode(PWM_LED2, PWM_OUTPUT);
  pwmSetRange(1000);

while(true) {
  for(int i= 1; i < 1000; i++){
    pwmWrite(PWM_LED1,i);
    usleep(1000);
  }
  for(int i = 999; i>=0; i--){
    pwmWrite(PWM_LED1, i);
    usleep(1000);
    }
  for(int i= 1; i < 1000; i++){
    pwmWrite(PWM_LED2,i);
    usleep(1000);
  }
  for(int i = 999; i>=0; i--){
    pwmWrite(PWM_LED2, i);
    usleep(1000);
    }
  
  }
  return 0;
}
