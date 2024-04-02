#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;
#define PWM_RLED   25
#define PWM_GLED  23

bool running = true;

int main() {
  wiringPiSetupGpio();
  pinMode(PWM_RLED, PWM_OUTPUT);
  pinMode(PW<_GLED, PWM_OUTPUT);
  wiringPiISR(BUTTON_GPIO, INT_EDGE_RISING, &buttonPress);
  pwmSetRange(1000);

while(running) {
  for(int i= 1; i < 1000; i++){
    pwmWrite(PWM_RLED,i);
    usleep(1000);
  }
  for(int i = 999; i>=0; i--){
    pwmWrite(PWM_RLED, i);
    usleep(1000);
    }
  }
  for(int i= 1; i < 1000; i++){
    pwmWrite(PWM_GLED,i);
    usleep(1000);
  }
  for(int i = 999; i>=0; i--){
    pwmWrite(PWM_GLED, i);
    usleep(1000);
    }
  }
  return 0;
}
