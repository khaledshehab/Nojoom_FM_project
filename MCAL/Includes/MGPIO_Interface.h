/*
 * MGPIO_Interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Khaled Shehab
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

typedef enum
{
	OUTPUT_LOW,
	OUTPUT_HIGH
}PIN_Value_t;
/***************PORTS***************/
#define PORTA       0
#define PORTB       1
#define PORTC       2

/*****************pins**************/
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15

/*************Mode Macros*************/
#define INPUT           0
#define OUTPUT          1
#define ALT_FUNC        2
#define ANALOG          3

#define GPIO_MODE_MASK       0x00000003 //to modify just 2 pins

/*************output mode*************/
#define OUTPUT_PUSH_PULL      0
#define OUTPUT_OPEN_DRAIN     1

/*************output speed*************/
#define SPEED_LOW            0
#define SPEED_MEDIUM         1
#define SPEED_HIGH           2
#define SPEED_VHIGH          3

/*************input mode*************/
#define NO_PULL_UP_DOWN       0
#define PULL_UP      		  1
#define PULL_DOWN             2



/************************Prototypes*********************/
void MGPIO_SetMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_SetOutputPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutType, u8 Copy_u8Speed);
void MGPIO_SetInputPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InputMode);
void MGPIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8Data);
void MGPIO_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, PIN_Value_t Copy_PinValue);
void MGPIO_SetResetValue(u8 Copy_u8Port, u8 Copy_u8Pin, PIN_Value_t Copy_PinValue);
void MGPIO_Toggle_pin(u8 Copy_u8Port, u8 Copy_u8Pin);
void MGPIO_SetAlternativeFuncPin(u8 Copy_u8Port,u8 Copy_u8Pin,u8  Copy_u8Data);

#endif /* MGPIO_INTERFACE_H_ */
