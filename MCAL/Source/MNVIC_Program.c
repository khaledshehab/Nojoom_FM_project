/*
 * MNVIC_Program.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Khaled Shehab
 */

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"
#include "../include/MNVIC_Private.h"
#include "../include/MNVIC_Config.h"
#include "../include/MNVIC_Interface.h"

/* global variable to hold group mode */
static u8 Global_u8IPR=0;

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntPos)
{
	/* check index of interrupt <= 240*/
	if(Copy_u8IntPos <= MAX_INTERRUPT_INDEX)
	{
	/* REG_DIV = 32 */
	/* (Copy_u8IntPos/REG_DIV) --> specify which ISER register */
	/* (Copy_u8IntPos%REG_DIV) --> specify which bit in ISER register */
	/* then set this bit to enable interrupt */
	SET_BIT(NVIC->ISER[(Copy_u8IntPos/REG_DIV)],(Copy_u8IntPos%REG_DIV));
	}
	else
	{
		/* Nothing */
	}
}
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntPos)
{
	/* check index of interrupt <= 240*/
	if(Copy_u8IntPos <= MAX_INTERRUPT_INDEX)
	{
	/* REG_DIV = 32 */
	/* (Copy_u8IntPos/REG_DIV) --> specify which ICER register */
	/* (Copy_u8IntPos%REG_DIV) --> specify which bit in ICER register */
	/* then set this bit to disable interrupt */
	SET_BIT(NVIC->ICER[(Copy_u8IntPos/REG_DIV)],(Copy_u8IntPos%REG_DIV));
	}
	else
	{
		/* Nothing */
	}
}
void MNVIC_VoidEnableInterruptPending(u8 Copy_u8IntPos)
{
	/* check index of interrupt <= 240*/
	if(Copy_u8IntPos <= MAX_INTERRUPT_INDEX)
	{
	/* REG_DIV = 32 */
	/* (Copy_u8IntPos/REG_DIV) --> specify which ISPR register */
	/* (Copy_u8IntPos%REG_DIV) --> specify which bit in ISPR register */
	/* then set this bit to enable interrupt pending*/
	SET_BIT(NVIC->ISPR[(Copy_u8IntPos/REG_DIV)],(Copy_u8IntPos%REG_DIV));
	}
	else
	{
		/* Nothing */
	}
}
void MNVIC_VoidDisableInterruptPending(u8 Copy_u8IntPos)
{
	/* check index of interrupt <= 240*/
	if(Copy_u8IntPos <= MAX_INTERRUPT_INDEX)
	{
	/* REG_DIV = 32 */
	/* (Copy_u8IntPos/REG_DIV) --> specify which ICPR register */
	/* (Copy_u8IntPos%REG_DIV) --> specify which bit in ICPR register */
	/* then set this bit to disable interrupt pending*/
	SET_BIT(NVIC->ICPR[(Copy_u8IntPos/REG_DIV)],(Copy_u8IntPos%REG_DIV));
	}
	else
	{
		/* Nothing */
	}
}
void MNVIC_u8IsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read)
{
	/* REG_DIV = 32 */
	/* (Copy_u8IntPos/REG_DIV) --> specify which IABR register */
	/* (Copy_u8IntPos%REG_DIV) --> specify which bit in IABR register */
	/* then get value in this bit and assign to return */
	*Copy_Read = GET_BIT(NVIC->IABR[(Copy_u8IntPos/REG_DIV)],(Copy_u8IntPos%REG_DIV));
}
void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 u8SubGroupNum)
{
	/* switch for group mode */
	switch(Global_u8IPR)
	{
	case Group16Sub0:
		/* last 4 bits in IPR register for group number */
		NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<4;
		break;
	case Group8Sub2:
		/* last 3 bits in 8 bits of IPR refer to group number */
		/* just 1 bit from last 4 bits in IPR register for sub group number */
		NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<5 | u8SubGroupNum<<4;
		break;
	case Group4Sub4:
		/* last 2 bits in 8 bits of IPR refer to group number */
		/* just 2 bit from last 4 bits in IPR register for sub group number */
		NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<6 | u8SubGroupNum<<4;
		break;
	case Group2Sub8:
		/* last 1 bits in 8 bits of IPR refer to group number */
		/* just 3 bit from last 4 bits in IPR register for sub group number */
		NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<7 | u8SubGroupNum<<4;
		break;
	case Group0Sub16:
		/* last 4 bits in IPR register for sub group number */
		NVIC->IPR[Copy_u8IntPos] = u8SubGroupNum<<4;
		break;
	default:
		break;
	}
}

void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode)
{

	Global_u8IPR=Copy_uddtGroupMode;
	/* Vect key to start write */
	SCB_AIRCR = SCB_AIRCR_VECTKEY;
	/* Vect key + group mode then assign in AIRCR register in SCB peripheral*/
	u32 Copy_u32Local = SCB_AIRCR_VECTKEY | (Copy_uddtGroupMode<<8);
	SCB_AIRCR = Copy_u32Local;
}

