#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;

#define LED_GPIO      17      // this is GPIO17, Pin 11
#define BUTTON_GPIO   27      // this is GPIO27, Pin 13
#define DEBOUNCE_TIME 200
bool stateLED =false;


void lightLED(void){
  static unsigned long lastISRTime = 0,  x = 1;
  unsigned long currentISRTime = millis();
  if(currentISRTime - lastISRTime > DEBOUNCE_TIME){
    digitalWrite(LED_GPIO, !stateLED);     
    stateLED = !stateLED;
    if(stateLED)
      cout << "Button pressed " << x++ << " times! LED on" << endl;
    else
      cout << "Button pressed " << x++ << " times! LED off" << endl;
  }
  lastISRTime = currentISRTime;
}

int main() {                             // must be run as root
  wiringPiSetupGpio();                  // use the GPIO numbering
  pinMode(LED_GPIO, OUTPUT);            // the LED
  pinMode(BUTTON_GPIO, INPUT);          // the Button
  digitalWrite (LED_GPIO, LOW);         // LED is off
  cout << "Press the button on GPIO " << BUTTON_GPIO << endl;
  // call the lightLED() ISR on the rising edge (i.e., button press)
  wiringPiISR(BUTTON_GPIO, INT_EDGE_RISING, &lightLED);
  for(int i=10; i>0; i--){              // countdown to program end
    cout << "You have " << i << " seconds remaining..." << endl;
    sleep(1);                          // sleep for 1 second
  }
  return 0;                             // program ends after 10s
}

