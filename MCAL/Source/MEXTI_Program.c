/*
 * MEXTI_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MEXTI_Private.h"
#include "../include/MEXTI_Config.h"
#include "../include/MEXTI_Interface.h"

static void (*Global_EXTIPtr[16])(void) = {NULL_PTR};

void MEXIT_voidInterruptSetport(EXTI_LINE Copy_u8Line,EXTI_PORT Copy_u8Port)
{
	SYSCFG->EXTICR[Copy_u8Line/DIV_FAC] &= ~(SYSCFG_MASK<<(4*(Copy_u8Line%DIV_FAC)));
	SYSCFG->EXTICR[Copy_u8Line/DIV_FAC] |= (Copy_u8Port<<(4*(Copy_u8Line%DIV_FAC)));
}

void MEXTI_voidInterruptEnableDisable(EXTI_LINE Copy_u8IntLine , EXTI_IS Copy_u8EXTI_Is)
{
	switch (Copy_u8EXTI_Is){
	case EXTI_ENABLE:
		SET_BIT(MEXTI->IMR,Copy_u8IntLine);
		break;
	case EXTI_DISABLE:
		/*Do it*/
		CLR_BIT(MEXTI->IMR,Copy_u8IntLine);
		break;
	default:  break;
	}
}
void MEXTI_voidInterruptTrigger(EXTI_LINE Copy_u8IntLine,EXTI_MODE Copy_u8Trig)
{
	switch (Copy_u8Trig){
	case EXTI_FALLING:
		SET_BIT(MEXTI->FTSR,Copy_u8IntLine);
		CLR_BIT(MEXTI->RTSR,Copy_u8IntLine);
		break;
	case EXTI_RISING:
		/*Do it*/
		SET_BIT(MEXTI->RTSR,Copy_u8IntLine);
		CLR_BIT(MEXTI->FTSR,Copy_u8IntLine);
		break;
	case EXTI_ONCHANGE:
		/*do it*/
		SET_BIT(MEXTI->RTSR,Copy_u8IntLine);
		SET_BIT(MEXTI->FTSR,Copy_u8IntLine);
		break;
	default:
		break;
	}
}
void MEXTI_voidCallBack(void (*ptr)(void),EXTI_LINE Copy_u8IntLine)
{
	if(ptr!=NULL_PTR)
	{
		Global_EXTIPtr[Copy_u8IntLine] = ptr;
	}
	else
	{
		/* Nothing */
	}
}

void EXTI0_IRQHandler(void)
{
	if(Global_EXTIPtr[0] != NULL_PTR)
	{
		Global_EXTIPtr[0]();
	}
	SET_BIT(MEXTI->PR,EXTI_LIN0);
}

void EXTI1_IRQHandler(void)
{
	if(Global_EXTIPtr[1] != NULL_PTR)
	{
		Global_EXTIPtr[1]();
	}
	SET_BIT(MEXTI->PR,EXTI_LIN1);
}

void EXTI6_IRQHandler(void)
{
	if(Global_EXTIPtr[0] != NULL_PTR)
	{
		Global_EXTIPtr[0]();
	}
	SET_BIT(MEXTI->PR,EXTI_LIN6);
}
