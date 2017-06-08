#ifndef _OLED_H_
#define _OLED_H_

#include "LPC11XX.H"

#define P2_0_OUT1  (LPC_GPIO2->DATA |=(1<<0))
#define P2_1_OUT1  (LPC_GPIO2->DATA |=(1<<1))
#define P2_2_OUT1  (LPC_GPIO2->DATA |=(1<<2))
#define P2_3_OUT1  (LPC_GPIO2->DATA |=(1<<3))
#define P0_0_OUT1  (LPC_GPIO0->DATA |=(1<<0))

#define P2_0_OUT0  (LPC_GPIO2->DATA &=~(1<<0))
#define P2_1_OUT0  (LPC_GPIO2->DATA &=~(1<<1))
#define P2_2_OUT0  (LPC_GPIO2->DATA &=~(1<<2))
#define P2_3_OUT0  (LPC_GPIO2->DATA &=~(1<<3))
#define P0_0_OUT0  (LPC_GPIO0->DATA &=~(1<<0))

#define OLED_SCL1  P2_1_OUT1                 // PTD1_OUT  D0
#define OLED_SDA1  P2_2_OUT1                //PTD3_OUT    D1
#define OLED_RST1  P0_0_OUT1                 //PTC15_OUT
#define OLED_DC1   P2_3_OUT1                 //PTD2_OUT
#define OLED_CS1   P2_0_OUT1                //PTD4_OUT

#define OLED_SCL0  P2_1_OUT0                 // PTD1_OUT
#define OLED_SDA0  P2_2_OUT0                //PTD3_OUT
#define OLED_RST0  P0_0_OUT0                 //PTC15_OUT
#define OLED_DC0   P2_3_OUT0                 //PTD2_OUT
#define OLED_CS0   P2_0_OUT0                //PTD4_OUT

void OLED_Init(void);
void OLED_WrCmd(uint8_t cmd);        //写指令
void OLED_WrDat(uint8_t data);       //写数据
void OLED_Fill(uint8_t bmp_data);    //清屏
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_PutPixel(uint8_t x,uint8_t y);
void OLED_Rectangle(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t gif);
void OLED_P6x8Str(uint8_t x,uint8_t y,uint8_t ch[]);
void LCD_Write_Number(uint8_t X,uint8_t Y,int	number);
void OLED_Print(uint8_t x, uint8_t y, uint8_t ch[]);
void OLED_CLS(void);
void OLED_dlay_ms(uint8_t ms);
void Draw_BMP(u8 x0,u8 y0,u8 x1,u8 y1,u8 bmp[]);
	
	void GPIO_Pin (uint8_t n,uint8_t m,uint8_t DIR,uint8_t DATA);

#endif


