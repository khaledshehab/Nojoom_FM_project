/*
 * HIR_Program.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/HIR_Private.h"
#include "../include/HIR_Config.h"
#include "../include/HIR_Interface.h"
#include "../include/MSYSTICK_Interface.h"
#include "../include/MGPIO_Interface.h"

volatile u32 IR_Arr[50] = {0};
volatile u8 flag=0;
volatile u8 counter=0;
u8 data=0;

void HIR_voidRecieveFrame(void)
{
	if(flag==0)
	{
		flag=1;
		MSYSTICK_voidStart(220000);
		MSYSTICK_voidCtrlIntState(SYSTICK_ENABLE);

//		MSYSTICK_voidSetIntervalSignalus(1000000,voidTakeAction);
	}
	else
	{
		IR_Arr[counter] = MSTK_u32GetElapsedTime();
		MSYSTICK_voidStart(50000);
//		MSYSTICK_voidSetIntervalSignalus(1000000,voidTakeAction);
		counter++;
	}
}

void HIR_voidStoreData(void)
{
	MSYSTICK_voidCtrlIntState(SYSTICK_DISABLE);
	flag=0;
	counter=0;
	for(u8 i=0;i<8;i++)
	{
		if((IR_Arr[24-i]>=1000)&&(IR_Arr[24-i]<=1500))
		{
			CLR_BIT(data,i);
		}
		else if((IR_Arr[24-i]>=2000)&&(IR_Arr[24-i]<=2500))
		{
			SET_BIT(data,i);
		}
	}
}
