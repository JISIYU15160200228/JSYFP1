#include "LPC11xx.h"                    // Device header
#include "PWM.h"
#include "KEY.h"

void TIM32B0_PWM(uint32_t cycle_us, uint8_t duty)
{
	cycle_us = 1000000 /cycle_us ;
	if((duty>=100)&&(duty<=0))return;
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);			//ʹ��TIM32B0ʱ��
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);  		// ʹ��IOCONʱ��
	LPC_IOCON->PIO0_1 &= ~0x07;
	LPC_IOCON->PIO0_1 |= 0x02;	      				//��P0_1������ΪMAT2
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);  	// ����IOCONʱ��

	LPC_TMR32B0->TCR = 0x02;		 	 						//��λ��ʱ����bit1��д1��λ��
	LPC_TMR32B0->PR  = 0x00;		  						//��Ԥ��Ƶ�Ĵ�����0��ʹPC+1��TC+1
	LPC_TMR32B0->PWMC= (1<<2);		  					//����MAT2ΪPWM�������
	LPC_TMR32B0->MCR = 0x02<<9;       				//����MR3ƥ��ʱ��λTC,Ҳ���ǰ�MR3�������ڼĴ���
	LPC_TMR32B0->MR3 = 48*cycle_us;		  			//��������
	LPC_TMR32B0->MR2 = 48*cycle_us*(100-duty)/100;//����ռ�ձ�
	LPC_TMR32B0->TCR = 0x01;			  					//������ʱ��
}

void Set_pwm(uint32_t cycle_us, uint8_t duty)
{
	cycle_us = 1000000 /cycle_us ;
	LPC_TMR32B0->TCR = 0x02;												//����pwmռ�ձ�ǰ��Ҫ��λ��ʱ��
	LPC_TMR32B0->MR3 = 48*cycle_us;		 
	LPC_TMR32B0->MR2 = 48*cycle_us*(100-duty)/100;
	LPC_TMR32B0->TCR = 0x01;			
}

void key_bee()                                    //��������
{
			 Set_pwm(2000,5);
			 delay();
	     delay();
			 Set_pwm(7000,5);
			 delay();
			 Set_pwm(0,0);
}

void starSound()                                   //������Ч
{
			 Set_pwm(1000,20);
			 delay_long();
			 Set_pwm(2000,20);
			 delay_long();
			 Set_pwm(3000,20);
			 delay_long();
			 Set_pwm(4000,20);
			 delay_long();
			 Set_pwm(5000,20);
			 delay_long();
			 Set_pwm(6000,20);
			 delay_long();
			 Set_pwm(0,0);
}

void alarm()                                  //������Ч
{
			 Set_pwm(2000,20);
			 delay();
			 Set_pwm(3000,20);
			 delay();
			 Set_pwm(4000,20);
			 delay();
	     Set_pwm(5000,20);
			 delay();
			 Set_pwm(0,0);
}
