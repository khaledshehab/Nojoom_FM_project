/*
 * HSTP_Program.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/HSTP_Config.h"
#include "../include/HSTP_Private.h"
#include "../include/HSTP_Interface.h"

#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"

void HSTP1_voidInit(void)
{
	MGPIO_SetMode(PORTA,PIN1,OUTPUT);
	MGPIO_SetMode(PORTA,PIN2,OUTPUT);
	MGPIO_SetMode(PORTA,PIN3,OUTPUT);

	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW);
	MGPIO_SetOutputPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL,OUTPUT_LOW);
	MGPIO_SetOutputPinMode(PORTA,PIN3,OUTPUT_PUSH_PULL,OUTPUT_LOW);
}
void HSTP2_voidInit(void)
{
	MGPIO_SetMode(PORTC,PIN13,OUTPUT);
	MGPIO_SetMode(PORTC,PIN14,OUTPUT);
	MGPIO_SetMode(PORTC,PIN15,OUTPUT);

	MGPIO_SetOutputPinMode(PORTC,PIN13,OUTPUT_PUSH_PULL,OUTPUT_LOW);
	MGPIO_SetOutputPinMode(PORTC,PIN14,OUTPUT_PUSH_PULL,OUTPUT_LOW);
	MGPIO_SetOutputPinMode(PORTC,PIN15,OUTPUT_PUSH_PULL,OUTPUT_LOW);
}


void HSTP1_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7;Local_s8Counter>=0;Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_s8Counter);

		MGPIO_SetResetValue(HSTP_SERIAL_DATA1,Local_u8Bit);

		MGPIO_SetResetValue(HSTP_SHIFT_CLOCK1,OUTPUT_HIGH);
		MSYSTICK_voidDelayus(3);
		MGPIO_SetResetValue(HSTP_SHIFT_CLOCK1,OUTPUT_LOW);
		MSYSTICK_voidDelayus(3);
	}
	MGPIO_SetResetValue(HSTP_STORE_CLOCK1,OUTPUT_HIGH);
	MSYSTICK_voidDelayus(3);
	MGPIO_SetResetValue(HSTP_STORE_CLOCK1,OUTPUT_LOW);
	MSYSTICK_voidDelayus(3);
}

void HSTP2_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7;Local_s8Counter>=0;Local_s8Counter--)
	{
		Local_u8Bit = !GET_BIT(Copy_u8DataToSend,Local_s8Counter);

		MGPIO_SetResetValue(HSTP_SERIAL_DATA2,Local_u8Bit);

		MGPIO_SetResetValue(HSTP_SHIFT_CLOCK2,OUTPUT_HIGH);
		MSYSTICK_voidDelayus(3);
		MGPIO_SetResetValue(HSTP_SHIFT_CLOCK2,OUTPUT_LOW);
		MSYSTICK_voidDelayus(3);
	}
	MGPIO_SetResetValue(HSTP_STORE_CLOCK2,OUTPUT_HIGH);
	MSYSTICK_voidDelayus(3);
	MGPIO_SetResetValue(HSTP_STORE_CLOCK2,OUTPUT_LOW);
	MSYSTICK_voidDelayus(3);
}
