#include "UART.h"
#include "PWM.h"
#include "INIT.h"
#include "UI.h"
#include "LCD1602.h"
void Init_all()
{
	uint32_t i;
	LCDGpio_Init();
	Keygpio_Init();
	ADC_Init();
	LCD_Init();
	UART_Init();
	I2C_Init(0);
	TIM32B0_PWM(0,0);
}
