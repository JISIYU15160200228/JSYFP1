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
	I2C_Send_Byte(WriteAddr);	 //���͵�ַ 										  		   
	I2C_Send_Byte(DataToWrite);     //�����ֽ�							   		    	   
  I2C_Stop();//����һ��ֹͣ���� 
	delay_I2C(4);// �����ʱ���Բ���ȥ��	 
}


uint8_t LCD1602_ReadOneByte(uint8_t ReadAddr)
{				  
	uint8_t temp=0;
			  	    																 
	I2C_Send_Ctrl(0XA0); 	 
  I2C_Send_Byte(ReadAddr);   //���͵�ַ    	 	   
	I2C_Send_Ctrl(0XA1);			   
  temp=I2C_Recieve_Byte();	   
  I2C_Stop();//����һ��ֹͣ����
		    
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
	temp = LCD1602_ReadOneByte(0x00);	 // ���ֽ�		   
	if(temp==0x88)return 0;		   
	else//�ų���һ�γ�ʼ�������
	{
		LCD1602_WriteOneByte(0x00,0x88);
	  temp=LCD1602_ReadOneByte(0x00);	  
		if(temp==0X88)return 0;
	}
	return 1;											  
}



