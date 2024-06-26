#include <stdio.h>
#include <wiringPi.h>
#include <mcp3004.h>
#define BASE 200
#define SPI_CHAN 0

#define RLED_GPIO 23
#define GLED_GPIO 24
#define BLED_GPIO 21

int main(void) {
 wiringPiSetupGpio();
  mcp3004Setup(BASE, SPI_CHAN); 
  pinMode(RLED_GPIO, OUTPUT);
  pinMode(GLED_GPIO, OUTPUT);
  pinMode(BLED_GPIO, OUTPUT);

 if (wiringPiSetup() == -1) 
           return 1;
 int x;
 
 while (true) {
 x = analogRead(BASE);
  if (x < 500)
 printf("%d\n", x);
 if (x < 50){
   digitalWrite(RLED_GPIO, HIGH);
  digitalWrite(GLED_GPIO,LOW);
  digitalWrite(BLED_GPIO,LOW);
 }
  else if(x>50 && x <150){
   digitalWrite(RLED_GPIO,LOW);
    digitalWrite(GLED_GPIO, HIGH);
   digitalWrite(BLED_GPIO, LOW);
 }
  else if(x<500 && x>150){
    digitalWrite(BLED_GPIO, HIGH);
    digitalWrite(RLED_GPIO,LOW);
  digitalWrite(GLED_GPIO,LOW);
  }
   else {
    digitalWrite(RLED_GPIO,LOW);
  digitalWrite(GLED_GPIO,LOW);
  digitalWrite(BLED_GPIO,LOW);
  }
 


  
 delay(100);
  

   
 }
 return 0;
}
