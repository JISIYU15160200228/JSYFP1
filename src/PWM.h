#ifndef _PWM_H
#define _PWM_H
#include "lpc11xx.h"

void TIM32B0_PWM(uint32_t cycle_us, uint8_t duty);
void Set_pwm(uint32_t cycle_us, uint8_t duty);
void key_bee(void);             //按键音效
void alarm(void);               //报警音效
void starSound(void);           //开机音效

#endif




