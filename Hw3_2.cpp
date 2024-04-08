#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <iomanip>
using namespace std;
#define USING_DHT11 true 
#define DHT_GPIO 22 
#define LH_THRESHOLD 26

int main(){
 int humid = 0, temp = 0;
 wiringPiSetupGpio();
 piHiPri(99);
TRYAGAIN: // If checksum fails (come back here)
 unsigned char data[5] = {0,0,0,0,0};
 pinMode(DHT_GPIO, OUTPUT); // gpio starts as output
  while(
 digitalWrite(DHT_GPIO, LOW); // pull the line low
 usleep(18000); // wait for 18ms
 digitalWrite(DHT_GPIO, HIGH); // set the line high
 pinMode(DHT_GPIO, INPUT); // now gpio is an input

}
