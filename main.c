#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "PWM1/PWM1.h"



int main(void)
{
	initPWM1FastA(invertido,1024);
	initPWM1FastB(no_invertido,1024);
	
	int frec = 120;
	int dutyCA = 75;
	int dutyCB = 25;
	
	while (1)
	{
		updateDutyCycleA(frec, dutyCA);
		updateDutyCycleB(frec, dutyCB);
	
		_delay_ms(50);
		
		dutyCA += 10;
		if (dutyCA>100){
			dutyCA = 0;
		}
		
		dutyCB += 5;
		if (dutyCB > 100){
			dutyCB = 0;
		}
		
	}
}
