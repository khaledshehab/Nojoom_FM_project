/*
 * HR2RDAC_Program.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/HR2RDAC_Private.h"
#include "../include/HR2RDAC_Config.h"
#include "../include/HR2RDAC_Interface.h"

#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"



void HR2RDAC_voidInit(void)
{
	MGPIO_SetMode(DAC_PORT,PIN0,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN1,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN2,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN5,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN6,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN7,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN8,OUTPUT);
	MGPIO_SetMode(DAC_PORT,PIN9,OUTPUT);

	MGPIO_SetOutputPinMode(DAC_PORT , PIN0 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN1 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN2 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN5 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN6 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN7 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN8 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);
	MGPIO_SetOutputPinMode(DAC_PORT , PIN9 , OUTPUT_PUSH_PULL , SPEED_MEDIUM);

}

void HR2RDAC_voidSetData(const u8 *arr,u32 arrsize)
{
	u32 Copy_u32LocalCounter = 0;
	for(Copy_u32LocalCounter = 0 ; Copy_u32LocalCounter <arrsize ; Copy_u32LocalCounter++)
	{
		MGPIO_SetPinValue(DAC_PORT , PIN0 , GET_BIT(arr[Copy_u32LocalCounter],0));
		MGPIO_SetPinValue(DAC_PORT , PIN1 , GET_BIT(arr[Copy_u32LocalCounter],1));
		MGPIO_SetPinValue(DAC_PORT , PIN2 , GET_BIT(arr[Copy_u32LocalCounter],2));
		MGPIO_SetPinValue(DAC_PORT , PIN5 , GET_BIT(arr[Copy_u32LocalCounter],3));
		MGPIO_SetPinValue(DAC_PORT , PIN6 , GET_BIT(arr[Copy_u32LocalCounter],4));
		MGPIO_SetPinValue(DAC_PORT , PIN7 , GET_BIT(arr[Copy_u32LocalCounter],5));
		MGPIO_SetPinValue(DAC_PORT , PIN8 , GET_BIT(arr[Copy_u32LocalCounter],6));
		MGPIO_SetPinValue(DAC_PORT , PIN9 , GET_BIT(arr[Copy_u32LocalCounter],7));

		MSYSTICK_voidDelayus(100);

	}
}

void HR2RDAC_voidSetDataOneTime(u8 arr)
{
	MGPIO_SetPinValue(DAC_PORT , PIN0 , GET_BIT(arr,0));
	MGPIO_SetPinValue(DAC_PORT , PIN1 , GET_BIT(arr,1));
	MGPIO_SetPinValue(DAC_PORT , PIN2 , GET_BIT(arr,2));
	MGPIO_SetPinValue(DAC_PORT , PIN5 , GET_BIT(arr,3));
	MGPIO_SetPinValue(DAC_PORT , PIN6 , GET_BIT(arr,4));
	MGPIO_SetPinValue(DAC_PORT , PIN7 , GET_BIT(arr,5));
	MGPIO_SetPinValue(DAC_PORT , PIN8 , GET_BIT(arr,6));
	MGPIO_SetPinValue(DAC_PORT , PIN9 , GET_BIT(arr,7));
}
