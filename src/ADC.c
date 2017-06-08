#include "LPC11xx.h"                    // Device header
#include "ADC.h"
#include "UART.h"
#include "stdio.h"
#include "string.h"

void ADC_Init()
{
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);
	LPC_IOCON->R_PIO1_0 &=~0XBF;
	LPC_IOCON->R_PIO1_0 |=0x02;
	LPC_SYSCON->SYSAHBCLKCTRL &=~(1<<16);
	LPC_SYSCON->PDRUNCFG &=~(1<<4);
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<13);
	LPC_ADC->CR =(0x01<<1)|                                  //sel=1，选择dac1
	             ((SystemCoreClock/1000000-1)<<8)|        //转换时钟1mhz
	             (0<<16)|                                 //软件控制转换操作
	             (0<<17)|                                 //使用11clocks
	             (0<<24)|                                 //adc停止转换
	             (0<<27);    
}

uint32_t AD_read()
{
	uint8_t i;
	uint32_t ulADCData;
	uint32_t ulADCBuf;
	uint32_t res_value;
	uint32_t temp,k;
	while(1)
	{
	 ulADCData=0;
		for(i=0;i<5;i++)
		{
			LPC_ADC->CR |=(1<<24);
			while((LPC_ADC->DR[1]&0x80000000)==0);
			LPC_ADC->CR |=(1<<24);
			while((LPC_ADC->DR[1]&0x80000000)==0);
			ulADCBuf=LPC_ADC->DR[1];
			ulADCBuf=(ulADCBuf>>6)&0x3ff;
			ulADCData+=ulADCBuf;
		}
		ulADCData=ulADCData/5;
		ulADCData=(ulADCData*3300)/1024;
    res_value=((ulADCData*10000)/(3300-ulADCData));
			if( (res_value<29371)&&(res_value>18680) )  // 0~10???
		{
			 k = 1069;
       temp = ((29370-res_value)/k)+0;
		}
		
		else if( (res_value<18681)&&(res_value>12240) ) // 10~20
     {
       k = 644;
       temp = ((18680-res_value)/k)+7;
     }
	 
    else if( (res_value<12241)&&(res_value>8221) ) // 20~30
     {
        k = 402;
        temp = ((12240-res_value)/k)+17;
     }
		 
    else if( (res_value<8222)&&(res_value>5648) ) // 30~40
     {
        k = 250;
        temp = ((8221-res_value)/k)+28;
     }
		 
    else if( (res_value<5649)&&(res_value>3958) ) // 40~50
     {
        k = 169;
        temp = ((5648-res_value)/k)+40;
     }
		 
		 else if( (res_value<3958)&&(res_value>2832) ) // 50~60
     {
        k = 113;
        temp = ((3957-res_value)/k)+50;
     }
		 
		 
		 else if( (res_value<2832)&&(res_value>2047) ) // 60~70
     {
        k = 76;
        temp = ((2831-res_value)/k)+60;
     }
		 
		 
		 else if( (res_value<2047)&&(res_value>1506) ) // 70~80
     {
        k = 54;
        temp = ((2046-res_value)/k)+70;
     }
		 
		 else if( (res_value<1506)&&(res_value>1124) ) // 80~90
     {
        k = 38;
        temp = ((1505-res_value)/k)+80;
     }
		 
		 else if( (res_value<1124)&&(res_value>850) ) // 90~100
     {
        k = 28;
        temp = ((1123-res_value)/k)+90;
     }
		return temp;
   }
}





