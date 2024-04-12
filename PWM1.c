/*
 * PWM1.c
 *
 * Created: 11/04/2024 22:34:19
 *  Author: lisar
 */ 
#define F_CPU 16000000UL
#include "PWM1.h"
#include <util/delay.h>


void initPWM1FastA(uint8_t inverted, uint16_t prescaler){
	//Configurando el pin PD9 como salida (OC1A) hace referencia a PB1
	DDRB |=(1<<DDB1);
	
	
	if (inverted){
	//Configurando OC1A como invertido
	TCCR1A |= (1<<COM1A1)|(1<<COM1A0);
			
	}else{
		//Configurando OC1A como no invertido
		TCCR1A|= (1<<COM1A1);
	}
	
	//Configurando Modo PWM FAST TOP = ICR1
	TCCR1A|= (1<<WGM11);
	TCCR1B|= (1<<WGM13)|(1<<WGM12);
	
	//Prescaler de 1024
	
	if (prescaler == 1024){
		//Prescaler 1024
		TCCR1B|= (1<<CS12);
	
	}
}

void initPWM1FastB(uint8_t inverted, uint16_t prescaler){
	
	//Configurando el pin PD10 como salida (OC1B)
	DDRB |=(1<<DDB2);
	
	if(inverted){
	//Configurando OC1B como invertido
	TCCR1A |= (1<<COM1B1)|(1<<COM1B0);	
	
	}else{
	//Configurando OC1B como no invertido	
	TCCR1A |= (1<<COM1B1);
	}
	
    //Configurando Modo PWM FAST TOP = ICR1
    TCCR1A |= (1<<WGM13)|(1<<WGM12)|(1<<WGM11);
		
	//Prescaler de 1024
	TCCR1B |= (1<<CS12);
}

void updateDutyCycleA(int frecuencia,uint16_t duty){
	uint16_t TOP = F_CPU/(1024 * frecuencia) -1;
	ICR1 = TOP;
	OCR1A = (TOP*duty)/100;
}

void updateDutyCycleB(int frecuencia,uint16_t duty){
	uint16_t TOP = F_CPU/(1024 * frecuencia) -1;
	ICR1 = TOP;
	OCR1B = (TOP*duty)/100;
}
