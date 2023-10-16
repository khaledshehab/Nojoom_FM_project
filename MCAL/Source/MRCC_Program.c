/*
 * MRCC_Program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MRCC_Private.h"
#include "../include/MRCC_Config.h"
#include "../include/MRCC_Interface.h"



void MRCC_Init(void)
{
#if (SYS_CLK == RCC_HSE)
SET_BIT(RCC->CR,CR_HSE_ON);  //Enable HSE

/*Check HSE Ready Flag*/
while(!GET_BIT(RCC->CR,CR_HSE_RDY));
/*switch to HSE*/
(RCC->CFGR) &= SWITCH_MASK;
(RCC->CFGR) |= SWITCH_HSE;

#elif (SYS_CLK == RCC_HSI)
SET_BIT(RCC->CR,CR_HSI_ON);  //Enable HSI

/*Check HSI Ready Flag*/
while(!GET_BIT(RCC->CR,CR_HSE_RDY));
/*switch to HSI*/
(RCC->CFGR) &= SWITCH_MASK;
(RCC->CFGR) |= SWITCH_HSI;

#elif (SYS_CLK == RCC_PLL)
SET_BIT(RCC->CR,CR_PLL_ON); //Enable PLL

/*Check PLL Ready Flag*/
while(!GET_BIT(RCC->CR,CR_PLL_RDY));
/*switch to HSI*/
(RCC->CFGR) &= SWITCH_MASK;
(RCC->CFGR) |= SWITCH_PLL;

#endif
}
void MRCC_Enable_Peripheral(u32 Copy_32Address_Bus, u32 Copy_32Peripheral)
{
	/* Switch for data bus for peripheral */
	/* Then set peripheral bit */
	switch(Copy_32Address_Bus)
	{
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,Copy_32Peripheral);
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,Copy_32Peripheral);
		break;
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,Copy_32Peripheral);
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,Copy_32Peripheral);
		break;
	default:
		break;
	}
}
void MRCC_Disable_Peripheral(u32 Copy_32Address_Bus, u32 Copy_32Peripheral)
{
	/* Switch for data bus for peripheral */
	/* Then clear peripheral bit */
	switch(Copy_32Address_Bus)
	{
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,Copy_32Peripheral);
		break;
	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR,Copy_32Peripheral);
		break;
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR,Copy_32Peripheral);
		break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,Copy_32Peripheral);
		break;
	default:
		break;
	}
}



