/*
 * PWM1.h
 *
 * Created: 11/04/2024 22:34:04
 *  Author: lisar
 */ 


#ifndef PWM1_H_
#define PWM1_H_

#include <stdint.h>
#include <avr/io.h>

#define invertido 1
#define no_invertido 0

void initPWM1FastA(uint8_t inverted, uint16_t prescaler);

void initPWM1FastB(uint8_t inverted, uint16_t prescaler);

void updateDutyCycleA(int frecuencia, uint16_t duty);

void updateDutyCycleB(int frecuencia, uint16_t duty);


#endif /* PWM1_H_ */
