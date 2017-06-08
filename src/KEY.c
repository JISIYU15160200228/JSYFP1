#include "LPC11xx.h"                    // Device header
#include "GPIO.h"
#include "KEY.h"
#include "string.h"
#include "PWM.h"

#define KEY1      ((LPC_GPIO3->DATA&(1<<0))!=(1<<0))
#define KEY2      ((LPC_GPIO3->DATA&(1<<1))!=(1<<1))
#define KEY3      ((LPC_GPIO3->DATA&(1<<2))!=(1<<2))
#define KEY4      ((LPC_GPIO3->DATA&(1<<3))!=(1<<3))

int key=0;

void delay()
{
	uint32_t i,j;
	for(i=0;i<400;i++)
	for(j=0;j<200;j++);
}

void delay_long()                 //³¤ÑÓÊ±
{
	delay();delay();delay();
}
	
void keysend()                   //°´¼ü
{
	LPC_GPIO3->IE =0x0f;
	LPC_GPIO3->IS =0x00;
	LPC_GPIO3->IEV =0x00;
	NVIC_EnableIRQ(EINT3_IRQn);
}

void PIOINT3_IRQHandler()
{
	delay();
	if(KEY1)                  //ÉÏ¼ü
	{
		key_bee();
		LPC_GPIO3->IC=0x0f;
		key=1;
	}
	else if(KEY2)             //ÓÒ¼ü
	{
		key_bee();
		LPC_GPIO3->IC=0x0f;
    key=2;
	}
  else if(KEY3)             //×ó¼ü
	{
		key_bee();
		LPC_GPIO3->IC=0x0f;
		key=3;
	}
  else if(KEY4)              //ÏÂ¼ü
	{
		key_bee();
		LPC_GPIO3->IC=0x0f;
		key=4;	 
	}
	else
		key=0;
}



