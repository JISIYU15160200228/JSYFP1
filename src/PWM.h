#ifndef _PWM_H
#define _PWM_H
#include "lpc11xx.h"

void TIM32B0_PWM(uint32_t cycle_us, uint8_t duty);
void Set_pwm(uint32_t cycle_us, uint8_t duty);
void key_bee(void);             //������Ч
void alarm(void);               //������Ч
void starSound(void);           //������Ч

#endif




