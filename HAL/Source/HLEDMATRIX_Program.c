/*
 * HLEDMATRIX_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Khaled
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/HLEDMATRIX_Private.h"
#include "../include/HLEDMATRIX_Config.h"
#include "../include/HLEDMATRIX_Interface.h"

#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"

void HLEDMATRIX_voidInit(void)
{
	/* SET MODE PORT A FOR COLUMN */
	MGPIO_SetMode(PORTA,PIN1,OUTPUT);
	MGPIO_SetMode(PORTA,PIN2,OUTPUT);
	MGPIO_SetMode(PORTA,PIN3,OUTPUT);
	MGPIO_SetMode(PORTA,PIN4,OUTPUT);
	MGPIO_SetMode(PORTA,PIN6,OUTPUT);
	MGPIO_SetMode(PORTA,PIN8,OUTPUT);
	MGPIO_SetMode(PORTA,PIN9,OUTPUT);
	MGPIO_SetMode(PORTA,PIN10,OUTPUT);

	/* SET MODE PORT A FOR COLUMN (OUTPUT MODE)*/
	MGPIO_SetOutputPinMode(PORTA , PIN1 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN2 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN3 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN4 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN6 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN8 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN9 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTA , PIN10 , OUTPUT_PUSH_PULL , SPEED_LOW);

	/* SET MODE PORT B FOR ROW */
	MGPIO_SetMode(PORTB,PIN0,OUTPUT);
	MGPIO_SetMode(PORTB,PIN1,OUTPUT);
	MGPIO_SetMode(PORTB,PIN2,OUTPUT);
	MGPIO_SetMode(PORTB,PIN5,OUTPUT);
	MGPIO_SetMode(PORTB,PIN6,OUTPUT);
	MGPIO_SetMode(PORTB,PIN7,OUTPUT);
	MGPIO_SetMode(PORTB,PIN8,OUTPUT);
	MGPIO_SetMode(PORTB,PIN9,OUTPUT);

	/* SET MODE PORT B FOR ROW (OUTPUT MODE)*/
	MGPIO_SetOutputPinMode(PORTB , PIN0 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN1 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN2 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN5 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN6 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN7 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN8 , OUTPUT_PUSH_PULL , SPEED_LOW);
	MGPIO_SetOutputPinMode(PORTB , PIN9 , OUTPUT_PUSH_PULL , SPEED_LOW);
}
void HLEDMATRIX_voidDisableRows(void)
{
	MGPIO_SetResetValue(PORTA,PIN1,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN2,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN3,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN4,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN6,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN9,OUTPUT_LOW);
	MGPIO_SetResetValue(PORTA,PIN10,OUTPUT_LOW);
}

void HLEDMATRIX_voidSetColumnValue(u8 Copy_u8RowValue)
{
	MGPIO_SetResetValue(PORTB,PIN0,!GET_BIT(Copy_u8RowValue,0));
	MGPIO_SetResetValue(PORTB,PIN1,!GET_BIT(Copy_u8RowValue,1));
	MGPIO_SetResetValue(PORTB,PIN2,!GET_BIT(Copy_u8RowValue,2));
	MGPIO_SetResetValue(PORTB,PIN5,!GET_BIT(Copy_u8RowValue,3));
	MGPIO_SetResetValue(PORTB,PIN6,!GET_BIT(Copy_u8RowValue,4));
	MGPIO_SetResetValue(PORTB,PIN7,!GET_BIT(Copy_u8RowValue,5));
	MGPIO_SetResetValue(PORTB,PIN8,!GET_BIT(Copy_u8RowValue,6));
	MGPIO_SetResetValue(PORTB,PIN9,!GET_BIT(Copy_u8RowValue,7));
}
void HLEDMATRIX_voidDisplay(u8 *Copy_u8arr)
{
	u8 counter;
	u8 Count=0;
	for(counter=1;counter<11;counter++)
	{
		if(counter == 5 || counter == 7)
		{
			/* Nothing */
		}
		else
		{
		HLEDMATRIX_voidDisableRows();
		HLEDMATRIX_voidSetColumnValue(Copy_u8arr[Count]);
		MGPIO_SetResetValue(PORTA,counter,OUTPUT_HIGH);
		MSYSTICK_voidDelayus(2500);
		Count++;
		}
	}
}


