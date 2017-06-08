#include "lpc11xx.h"
#include "LCD1602.h"
#include "I2C.h"


void delay_i2c(uint8_t t)
{
	uint16_t i,j;
	for(i=0;i<50000;i++)
		for(j=0;j<t;j++);
}

void LCD1602_WriteOneByte(uint8_t WriteAddr, uint8_t DataToWrite)
{				  
  I2C_Send_Ctrl(0XA0);   
	I2C_Send_Byte(WriteAddr);	 //发送地址 										  		   
	I2C_Send_Byte(DataToWrite);     //发送字节							   		    	   
  I2C_Stop();//产生一个停止条件 
	delay_I2C(4);// 这个延时绝对不能去掉	 
}


uint8_t LCD1602_ReadOneByte(uint8_t ReadAddr)
{				  
	uint8_t temp=0;
			  	    																 
	I2C_Send_Ctrl(0XA0); 	 
  I2C_Send_Byte(ReadAddr);   //发送地址    	 	   
	I2C_Send_Ctrl(0XA1);			   
  temp=I2C_Recieve_Byte();	   
  I2C_Stop();//产生一个停止条件
		    
	return temp;
}


void LCD1602_Read(uint8_t ReadAddr,uint8_t *Buffer,uint16_t Num)
{
	while(Num)
	{
		*Buffer++=LCD1602_ReadOneByte(ReadAddr++);	
		Num--;
	}
}  


void LCD1602_Write(uint8_t WriteAddr,uint8_t *Buffer,uint16_t Num)
{
	while(Num--)
	{
		LCD1602_WriteOneByte(WriteAddr,*Buffer);
		WriteAddr++;
		Buffer++;
	}
}


uint8_t LCD1602_Check(void)
{
	uint8_t temp;
	temp = LCD1602_ReadOneByte(0x00);	 // 读字节		   
	if(temp==0x88)return 0;		   
	else//排除第一次初始化的情况
	{
		LCD1602_WriteOneByte(0x00,0x88);
	  temp=LCD1602_ReadOneByte(0x00);	  
		if(temp==0X88)return 0;
	}
	return 1;											  
}



