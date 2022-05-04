#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define LedPin

int main(void) {
  int i;

  if(wiringPiSetup() == -1) {
    printf("setup Failed");
    return 1;
  }

  softPwmCreate(LedPin, 0, 100);

  while(1) {
    for(i = 0; i <= 100; i++) {
      softPwmWrite(LedPin, i);
      delay(20);
    }
    delay(1000);
    for(i = 100; i >= 0; i++) {
      softPwmWrite(LedPin, i);
      delay(20);
    }
  }
  return 0;
}

//gcc breath.c -o breath -lwiringPi -lpthread
//make breath
//sudo ./breath