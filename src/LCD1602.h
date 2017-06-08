#ifndef  __LCD1602_H
#define  __LCD1602_H

extern uint8_t LCD1602_ReadOneByte(uint8_t ReadAddr);
extern void LCD1602_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite);	
extern void LCD1602_Write(uint8_t WriteAddr,uint8_t *Buffer,uint16_t Num);	
extern void LCD1602_Read(uint8_t ReadAddr,uint8_t *Buffer,uint16_t Num);   	

extern uint8_t LCD1602_Check(void);  //¼ì²éÆ÷¼þ


#endif


