/*
 * MEXTI_Interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Khaled Shehab
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

typedef enum{
	EXTI_ENABLE,
	EXTI_DISABLE
}EXTI_IS;

typedef enum{
	EXTI_RISING,
	EXTI_FALLING,
	EXTI_ONCHANGE
}EXTI_MODE;

typedef enum
{
	EXTI_LIN0,
	EXTI_LIN1,
	EXTI_LIN2,
	EXTI_LIN3,
	EXTI_LIN4,
	EXTI_LIN5,
	EXTI_LIN6,
	EXTI_LIN7,
	EXTI_LIN8,
	EXTI_LIN9,
	EXTI_LIN10,
	EXTI_LIN11,
	EXTI_LIN12,
	EXTI_LIN13,
	EXTI_LIN14,
	EXTI_LIN15,
}EXTI_LINE;

typedef enum
{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC,
	EXTI_PORTD,
	EXTI_PORTE,
	EXTI_PORTH=7
}EXTI_PORT;

void MEXIT_voidInterruptSetport(EXTI_LINE Copy_u8Line,EXTI_PORT Copy_u8Port);
void MEXTI_voidInterruptEnableDisable(EXTI_LINE Copy_u8IntLine , EXTI_IS Copy_u8EXTI_Is);
void MEXTI_voidInterruptTrigger(EXTI_LINE Copy_u8IntLine,EXTI_MODE Copy_u8Trig);
void MEXTI_voidCallBack(void (*ptr)(void),EXTI_LINE Copy_u8IntLine);
void EXTI0_IRQHandler(void);

#endif /* MEXTI_INTERFACE_H_ */
