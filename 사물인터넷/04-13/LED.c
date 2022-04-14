#include <wiringPi.h>
#include <stdio.h>

#define LedPin	0

int main (void) {
	//when initialize wiring failed, print message to screen
	if(wiringPiSetup() == -1) {
		printf("setup wiringPi failed !");
		return 1;
		}
	
	pinMode(LedPin, OUTPUT);
	
	while(true) {
		digitalWrite(LedPin, LOW);
		printf("...LED on\n");
		delay(500);
		digitalWrite(LedPin, HIGH);
		printf("LED off...\n");
		delay(500);
	}
	
	return 0;
}