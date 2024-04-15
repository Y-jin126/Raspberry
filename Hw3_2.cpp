#include<iostream>
#include<unistd.h>
#include<wiringPi.h>
#include<iomanip>
using namespace std;

#define USING_DHT11      true   // The DHT11 uses only 8 bits
#define DHT_GPIO         22      // Using GPIO 22 for this example
#define LH_THRESHOLD     26      // Low=~14, High=~38 - pick avg.

#define RLED_GPIO 16
#define GLED_GPIO 17

int main(){
 int humid = 0, temp = 0;
 cout << "Starting the one-wire sensor program" << endl;
wiringPiSetupGpio();
piHiPri(99);
TRYAGAIN:                        // If checksum fails (come back here)
unsigned char data[5] = {0,0,0,0,0};
pinMode(DHT_GPIO, OUTPUT);                 // gpio starts as output
digitalWrite(DHT_GPIO, LOW);               // pull the line low
usleep(18000);                             // wait for 18ms
digitalWrite(DHT_GPIO, HIGH);              // set the line high
pinMode(DHT_GPIO, INPUT);                  // now gpio is an input

do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==HIGH);
do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==LOW);
do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==HIGH);

for(int d=0; d<5; d++) {       // for each data byte
 for(int i=0; i<8; i++) {    // for each bit of data
  do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==LOW);
   int width = 0;           // measure width of each high
   do {
    width++;
    delayMicroseconds(1);
    if(width>1000) break; // missed a pulse -- data invalid! 
   } while(digitalRead(DHT_GPIO)==HIGH);    // time it!
    data[d] = data[d] | ((width > LH_THRESHOLD) << (7-i));
    }
 }
 if (USING_DHT11)
      temp = data[2] * 10;             // multiplying to keep code concise
  else
   temp = (data[2]<<8 | data[3]);   
unsigned char chk = 0;   // the checksum will overflow automatically
for(int i=0; i<4; i++){ chk+= data[i]; }
if(chk==data[4]){
 cout << "The temperature is " << (float)temp/10 << "°C" << endl;
 if((float)temp/10 >= 28){
    digitalWrite(RLED_GPIO, HIGH);
  digitalWrite(GLED_GPIO, LOW);
 }
 else {
   digitalWrite(GLED_GPIO, HIGH);
  digitalWrite(RLED_GPIO, LOW);
 }

}
else {
cout << "Checksum bad - data error - trying again!" << endl;
usleep(2000000);   // have to delay for 1-2 seconds between readings
goto TRYAGAIN;     // a GOTO!!! call yourself a C/C++ programmer!
}
return 0;
}




