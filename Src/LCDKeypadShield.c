/*
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  + File Name          : LCDKeypadShield.c
  + Description        : Initialization code for the LCD Keypaf Shield 
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	*/

#include "LCDKeypadShield.h"

/* ----------------------------------------------------------*/
void LCD_PermitSend(void)
{
	LCD_E_Start;
	uint16_t i;
	for(i=0; i<1000; i++)
	{
		//nafing
	}
	LCD_E_Finish;
}
/* --------------------------------------------------------- */
void LCD_Send(uint8_t data)
{
	(((data>>3)&0x01)==1) ? LCD_D7_1 : LCD_D7_0; 
	(((data>>2)&0x01)==1) ? LCD_D6_1 : LCD_D6_0;
	(((data>>1)&0x01)==1) ? LCD_D5_1 : LCD_D5_0;
	( (data    &0x01)==1) ? LCD_D4_1 : LCD_D4_0;
}
/* --------------------------------------------------------- */
void LCD_Command(uint8_t data)
{
	LCD_RS_Command;
	LCD_Send(data>>4); 	//hight four bits
	LCD_PermitSend();
	LCD_Send(data); 		//little four bits
	LCD_PermitSend();
}
/* --------------------------------------------------------- */
void LCD_Data(uint8_t data)
{
	LCD_RS_Data;
	LCD_Send(data>>4); 	//hight four bits
	LCD_PermitSend();
	LCD_Send(data); 		//little four bits
	LCD_PermitSend();
}
/*------------------------------------------------------------*/
void LCD_Clear()
{
	LCD_Command(0x01);
	HAL_Delay(2);
}
/*------------------------------------------------------------*/
void LCD_SendChar(char ch)
{
	LCD_Data((uint8_t)ch);
}
/*------------------------------------------------------------*/
void LCD_SendStr(char* str)
{
	uint8_t i=0;
	while(str[i]!=0)
	{
		LCD_Data(str[i]);
		i++;
	}
}
/*------------------------------------------------------------*/
void LCD_SetPosition(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0:
			LCD_Command(x|0x80);
			break;
		case 1:
			LCD_Command((0x40+x)|0x80);
			break;
	}
}
/*------------------------------------------------------------*/
void LCD_Init(void)
{
	LCD_K_ON;      //light ON
	
	HAL_Delay(50); //delay 50ms
	
	LCD_RS_Command;
	LCD_Send(0x30); //at first 8 bit mode
	LCD_PermitSend();
	HAL_Delay(1);
	LCD_Send(0x30); //repit
	LCD_PermitSend();
	HAL_Delay(1);
	LCD_Send(0x30); //repit
	LCD_PermitSend();
	HAL_Delay(1);
	

	LCD_Command(0x28); //4 bit mode, display 2 line and 5x8 font
	HAL_Delay(1);
	LCD_Command(0x28); //repit
	HAL_Delay(1);
	LCD_Command(0x0C); //turn on the display, also enables all cursors
	HAL_Delay(1);
	LCD_Command(0x01); //clears display
	HAL_Delay(2);
	LCD_Command(0x06); //output in right to left 
	HAL_Delay(1);
	LCD_Command(0x02); //return cursor to the start position
	HAL_Delay(2);
}
/*------------------------------------------------------------*/
void LCD_Start(void)
{
	char str[16];
	sprintf(str,"STM32F103RB");
	LCD_SendStr(str);
	LCD_SetPosition(7, 1);
	sprintf(str,"Cortex-M3");
	LCD_SendStr(str);
	HAL_Delay(2500);
	LCD_Clear();
}
/*------------------------------------------------------------*/
void LCD_Timer(uint32_t i)
{
	LCD_SetPosition(12,1);
	LCD_SendChar((char) ((i/100)%10)+0x30);
	LCD_SendChar((char) ((i/10)	%10)+0x30);
	LCD_SendChar((char) ( i			%10)+0x30);
	LCD_SetPosition(15,1);
	LCD_SendChar('s');
	
}
/*------------------------------------------------------------*/
