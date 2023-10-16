/*
 * MSYSTICK_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MSYSTICK_Private.h"
#include "../include/MSYSTICK_Config.h"
#include "../include/MSYSTICK_Interface.h"

static void (*SYSTICK_callback)(void);

void MSYSTICK_voidInit(void)
{
	/* chose system clock */
#if SYSTICK_CLK == SYSTICK_CLK_AHB_DIV_8
	CLR_BIT(SYSTICK->CTRL,CTRL_CLKSOURCE);   // CTRL_CLKSOURCE = 2 , clear bit 2 in register CTRL

#elif SYSTICK_CLK == SYSTICK_CLK_AHB
	SET_BIT(SYSTICK->CTRL,CTRL_CLKSOURCE); // CTRL_CLKSOURCE = 2 , set bit 2 in register CTRL

#endif
}

void MSYSTICK_voidStart(u32 Copy_u32Loadvalue)
{
	/* sequence to start count */
	/* load value in LOAD register then clear VAL register then enable to start count */
	SYSTICK->LOAD = Copy_u32Loadvalue;
	SYSTICK->VAL  = 0;
	SET_BIT(SYSTICK->CTRL,CTRL_ENABLE);
}

//void MSYSTICK_voidSetIntervalSignalus(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
//{
//	/* Disable timer */
//	CLR_BIT(SYSTICK->CTRL,CTRL_ENABLE);
//	SYSTICK->VAL  = 0;
//#if SYSTICK_CLK == SYSTICK_CLK_AHB_DIV_8
//	SYSTICK->LOAD = Copy_u32Ticks*2;
//#elif SYSTICK_CLK == SYSTICK_CLK_AHB
//	SYSTICK->LOAD = Copy_u32Ticks*16;
//#endif
//	SET_BIT(SYSTICK->CTRL,CTRL_ENABLE);
//	SYSTICK_callback = Copy_ptr;
//	SET_BIT(SYSTICK->CTRL,1);
//}

void MSYSTICK_voidDelayus(u32 Copy_u32DelayValue)
{
	/* assuming AHB clk = HSI clk = 16 MHz */
	/* In case Systick clk = (AHB clk / 8) */
#if SYSTICK_CLK == SYSTICK_CLK_AHB_DIV_8
	MSYSTICK_voidStart(Copy_u32DelayValue*2);	//start count
	while(GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG) == 0);          //waiting for interrupt

	/* In case Systick clk = AHB clk */
#elif SYSTICK_CLK == SYSTICK_CLK_AHB
	MSYSTICK_voidStart(Copy_u32DelayValue*16);   //start count
	while(GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG) == 0);           //waiting for interrupt

#endif
}

void MSYSTICK_voidDelayms(u32 Copy_u32DelayValue)
{
	/* assuming AHB clk = HSI clk = 16 MHz */
	/* In case Systick clk = (AHB clk / 8) */
#if SYSTICK_CLK == SYSTICK_CLK_AHB_DIV_8
	MSYSTICK_voidStart(Copy_u32DelayValue*2*1000);  //start count
	while(GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG) == 0);          //waiting for interrupt

	/* In case Systick clk = AHB clk */
#elif SYSTICK_CLK == SYSTICK_CLK_AHB
	MSYSTICK_voidStart(Copy_u32DelayValue*16*1000); //start count
	while(GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG) == 0);              //waiting for interrupt

#endif
}

u8 MSYSTICK_u8ReadFlag(void)
{
	return GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG); // CTRL_COUNTFLAG = 16, read flag bit
}

void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State)
{
	/* check disable or enable */
	if(Copy_State == SYSTICK_ENABLE)
	{
		SET_BIT(SYSTICK->CTRL,CTRL_TICKINT); //CTRL_TICKINT=1, set bit 1 in CTRL register to enable
	}
	else if(Copy_State == SYSTICK_DISABLE)
	{
		CLR_BIT(SYSTICK->CTRL,CTRL_TICKINT); //CTRL_TICKINT=1, clear bit 1 in CTRL register to enable
	}
	else
	{
		/* Nothing */
	}
}

u32 MSTK_u32GetElapsedTime(void)
{
	/* elapsed time = loaded value - current value (VAL register) */
	return (((SYSTICK->LOAD) - (SYSTICK->VAL))/16); //default as HSI = 16M & AHB
}

u32 MSTK_u32GetRemainingTime(void)
{
	/* remaining rime = value remaining in VAL register */
	return ((SYSTICK->VAL)/16); //default as HSI = 16M & AHB
}

void MSYSTICK_voidEnable(void)
{
	SET_BIT(SYSTICK->CTRL,CTRL_ENABLE); //CTRL_ENABLE = 0, clear bit 0 in CTRL register for disable
}

void MSYSTICK_voidDisable(void)
{
	CLR_BIT(SYSTICK->CTRL,CTRL_ENABLE); //CTRL_ENABLE = 0, clear bit 0 in CTRL register for disable
}

void MESYSTICK_voidCallBack(void (*ptr)(void))
{
	if(ptr!=NULL_PTR)
	{
		SYSTICK_callback = ptr;
	}
	else
	{
		/* Nothing */
	}
}

//void __attribute__ ((section(".after_vectors")))
void SysTick_Handler (void)
{
	if(SYSTICK_callback != NULL_PTR)
	{
		SYSTICK_callback();
	}
	else
	{
		/* Nothing */
	}
}
