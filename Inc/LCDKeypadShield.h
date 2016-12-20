/*
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  + File Name          : LCDKeypadShield.c
  + Description        : Initialization code for the LCD Keypaf Shield 
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	*/
	
#ifndef LCD_Keypad_Shield
#define LCD_Keypad_Shield
/* --------------------------------------------------------- */
#include "stm32f1xx_hal.h"
#include "gpio.h"
/* --------------------------------------------------------- */
#define LCD_K_ON				HAL_GPIO_WritePin(GPIOB, LCD_K_Pin,  GPIO_PIN_SET) 		//light ON
#define LCD_K_OFF				HAL_GPIO_WritePin(GPIOB, LCD_K_Pin,  GPIO_PIN_RESET)	//light OFF   
#define LCD_RS_Command 	HAL_GPIO_WritePin(GPIOA, LCD_RS_Pin, GPIO_PIN_RESET) 	//for send command word
#define LCD_RS_Data 		HAL_GPIO_WritePin(GPIOA, LCD_RS_Pin, GPIO_PIN_SET)	 	//for send data word
#define LCD_D4_0 				HAL_GPIO_WritePin(GPIOB, LCD_D4_Pin, GPIO_PIN_RESET) 	//data or command  
#define LCD_D5_0 				HAL_GPIO_WritePin(GPIOB, LCD_D5_Pin, GPIO_PIN_RESET)
#define LCD_D6_0 				HAL_GPIO_WritePin(GPIOB, LCD_D6_Pin, GPIO_PIN_RESET)
#define LCD_D7_0 				HAL_GPIO_WritePin(GPIOA, LCD_D7_Pin, GPIO_PIN_RESET)
#define LCD_D4_1				HAL_GPIO_WritePin(GPIOB, LCD_D4_Pin, GPIO_PIN_SET)
#define LCD_D5_1				HAL_GPIO_WritePin(GPIOB, LCD_D5_Pin, GPIO_PIN_SET)
#define LCD_D6_1				HAL_GPIO_WritePin(GPIOB, LCD_D6_Pin, GPIO_PIN_SET)
#define LCD_D7_1				HAL_GPIO_WritePin(GPIOA, LCD_D7_Pin, GPIO_PIN_SET)
#define LCD_E_Start			HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET) 	//start chip select for send
#define LCD_E_Finish 		HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET) //finish chip select
/* --------------------------------------------------------- */
void LCD_Clear(void);
void LCD_SendChar(char ch);
void LCD_SendStr(char* str);
void LCD_SetPosition(uint8_t x, uint8_t y);
void LCD_Init(void);
void LCD_Start(void);
void LCD_Timer(uint32_t i);
/* --------------------------------------------------------- */
#endif /* LCD_Keypad_Shield */
