#include "LPC11xx.h"                    // Device header
#include "GPIO.h"

//oledÒý½Ågpio³õÊ¼»¯
void LCDGpio_Init(void)        
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<6);
	LPC_GPIO2->DIR  =0x0f;
	LPC_GPIO2->DATA =0x0f;
}

void Keygpio_Init()
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<6);
	LPC_GPIO3->DIR=0x00;
}

void IIC_Init()
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<6);
	LPC_GPIO0->DIR |=0x38;
	LPC_GPIO0->DATA|=0x18;
}

