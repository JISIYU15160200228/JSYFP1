#include "LPC11xx.h"                    // Device header
#include "UI.h"
#include "GPIO.h"
#include "KEY.h"
#include "ADC.h"
#include "UART.h"
#include "LCD1602.h"
#include <stdio.h>
#include <string.h>
#include "PWM.h"
#include "INIT.h"

unsigned char star[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0xC0,0xE0,0xF0,0xF0,0xF8,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,
0xC0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0x8E,0xCF,0xCF,0xCF,0xE7,
0xE3,0xE1,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF8,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xF0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0x0F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
0x3F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x03,0x03,0x03,
0x03,0x03,0x03,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


uint8_t arg=2;          //箭头位置
         
	
void UI_MAIN(void)
{
	uint32_t i;
	uint8_t s0[22]="    never give up     ";
	uint8_t s1[22]="----------------------";
  uint8_t s2[22]="    UI temperature    ";
	uint8_t s3[22]="    save              ";
	uint8_t s4[22]="    uart              ";
	
	uint8_t ss[22]="->";
	uint8_t sp[22]="  ";
	
	for(i=0;i<200;i++)
	{
	Draw_BMP(0,0,125,5,star);
	}
	
  LCD_CLS();
  starSound();              //开机音效
	keysend();                //按键扫描
	while(1)
	{
  switch(key)
	 {
		case 0:LCD_P6x8Str(0,arg,ss);        
		       break;
		case 1:LCD_P6x8Str(0,arg,sp);        //清空箭头
		       LCD_P6x8Str(0,arg,ss); 
		       key=0;
		       arg--; 
		       if(arg<2) arg=4;
		       LCD_P6x8Str(0,arg,ss);
		       break;
		case 2:if(arg==2)
			     UI_temperature();              //进入显示温度界面
		       else if(arg==3)
					 save();                        //进入保存界面
		       else if(arg==4)
					 uart_temperature();            //进入串口通信
		       break;
		case 4:LCD_P6x8Str(0,arg,sp);
		       key=0;
		       arg++;
		       if(arg>4) arg=2;
		       LCD_P6x8Str(0,arg,ss);
		       break;
		default:
					break;
	 }
	LCD_P6x8Str(0,arg,ss);
	LCD_P6x8Str(0,0,s0);
	LCD_P6x8Str(0,1,s1);
	LCD_P6x8Str(0,2,s2);
	LCD_P6x8Str(0,3,s3);
	LCD_P6x8Str(0,4,s4);
	LCD_P6x8Str(0,arg,ss);
  }
	
}

//ui显示温度
void UI_temperature()
{
	uint32_t x;
  uint32_t temp;

	uint8_t s0[22]="temperature";
	LCD_CLS();
   while(1)
	 {
		temp= LCD1602_ReadOneByte(0x00);      //读取报警值
		x=AD_read();                          //读取温度值
		LCD_Write_Number(0,2,x);
		 if(temp<=x)                          //报警
		 {
       alarm();
		 }
		if(key==3)
		{
			break;
		}
	 }
}

//串口显示函数
void uart_temperature()
{
	char data[20];
	uint32_t ulADCData;
	uint8_t s0[22]="reading.....  ";

	LCD_CLS();
	while(1)
	{
		ulADCData=AD_read();
		sprintf(data,"VIN0=%4d mV\r\n",ulADCData);
		LCD_P6x8Str(0,0,s0);
	  UART_SendStr(data);
		if(key==3)
			break;
	}
}

void save()
{
	int y=1;         //正负标志
	int x=0;    
	uint8_t s[22]="alarm temperature";
	uint8_t s0[22]="  -";        //负号
	uint8_t s1[22]=" ";
	LCD_CLS();
	while(1)
		{
			switch(key)
			{
			case 1:x= LCD1602_ReadOneByte(0x00);
				     y= LCD1602_ReadOneByte(0x01);
             if(y==1)                          //为正
						 {
				     x+=1;
				     LCD1602_WriteOneByte(0x00, x);
						 LCD1602_WriteOneByte(0x01, y);
				     key = 0;
			       break;
						 }
						 else                             //为负
						 {
							 if(x==0)
							 {
								 x++;
								 y=1;
								 LCD1602_WriteOneByte(0x00, x);
						     LCD1602_WriteOneByte(0x01, y);
							   key=0;
							   break;
							 }
							 else
							 {
							 x--;
							 y=0;
							 LCD1602_WriteOneByte(0x00, x);
						   LCD1602_WriteOneByte(0x01, y);
							 key=0;
							 break;
						 }
					 }
			case 4:x= LCD1602_ReadOneByte(0x00);
				     y= LCD1602_ReadOneByte(0x01);
						 if(y==1)                        //为负     与上键相反
						 {
							 if(x==0)
							 {
						    y=0;
							  x++;
				        LCD1602_WriteOneByte(0x00, x);
						    LCD1602_WriteOneByte(0x01, y);
				        key = 0;
			          break;
							 }
							 else
							 {
						   x=x-1;
						   y=1;
				       LCD1602_WriteOneByte(0x00, x);
						   LCD1602_WriteOneByte(0x01, y);
				       key = 0;
			         break;
						   }
						 }
						 else                            //为正
						 {
							 x++;
							 y=0;
							 LCD1602_WriteOneByte(0x00, x);
						   LCD1602_WriteOneByte(0x01, y);
				       key = 0;
			         break;
							 
						 }
							 
			case 3:break;
			}
			if(key==3)
			break;
      

			
			x= LCD1602_ReadOneByte(0x00);              //读取温度
			y= LCD1602_ReadOneByte(0x01);
			if(y==1)
			{
				LCD_P6x8Str(0,0,s);
				LCD_P6x8Str(0,1,s1);
			  LCD_Write_Number(0,1,x);              
			}
			else
			{
				LCD_P6x8Str(0,0,s);
				LCD_P6x8Str(0,1,s0);
			  LCD_Write_Number(0,1,x);
				LCD_P6x8Str(0,1,s0);
		  }
}
}


