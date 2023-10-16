/*
 * MGPIO_Program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MGPIO_Private.h"
#include "../include/MGPIO_Config.h"
#include "../include/MGPIO_Interface.h"

void MGPIO_SetMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (((Copy_u8Pin == PIN13) || (Copy_u8Pin == PIN14) || (Copy_u8Pin == PIN15))))
	{
		/* NOTHING */
	}
	else if((Copy_u8Port == PORTB) && ((Copy_u8Pin == PIN3) || (Copy_u8Pin == PIN4)))
	{
		/* NOTHING */
	}
	else
	{
		/* switching for port */
		/* then select mode by clearing 2 response bits then set it with selected mode*/
		/* without affect other bits */
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOA->MODER |= (Copy_u8Mode<<(Copy_u8Pin * 2));
			break;
		case PORTB:
			GPIOB->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOB->MODER |= (Copy_u8Mode<<(Copy_u8Pin * 2));
			break;
		case PORTC:
			GPIOC->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOC->MODER |= (Copy_u8Mode<<(Copy_u8Pin * 2));
			break;
		default:
			break;
		}
	}
}
void MGPIO_SetOutputPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutType, u8 Copy_u8Speed)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (((Copy_u8Pin == PIN13) || (Copy_u8Pin == PIN14) || (Copy_u8Pin == PIN15))))
	{
		/* NOTHING */
	}
	else if((Copy_u8Port == PORTB) && ((Copy_u8Pin == PIN3) || (Copy_u8Pin == PIN4)))
	{
		/* NOTHING */
	}
	else
	{
		/* switching for port */
		/* then select output bin type by clearing 1 response bits then set it with selected type*/
		/* without affect other bits */
		/* then select output bin speed by clearing 2 response bits then set it with selected speed*/
		/* without affect other bits */
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->OTYPER &= ~(1<<(Copy_u8Pin));
			GPIOA->OTYPER |= (Copy_u8OutType<<Copy_u8Pin);

			GPIOA->OSPEEDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOA->OSPEEDR |= (Copy_u8Speed<<(Copy_u8Pin * 2));
			break;
		case PORTB:
			GPIOB->OTYPER &= ~(1<<(Copy_u8Pin));
			GPIOB->OTYPER |= (Copy_u8OutType<<Copy_u8Pin);

			GPIOB->OSPEEDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOB->OSPEEDR |= (Copy_u8Speed<<(Copy_u8Pin * 2));
			break;
		case PORTC:
			GPIOC->OTYPER &= ~(1<<(Copy_u8Pin));
			GPIOC->OTYPER |= (Copy_u8OutType<<Copy_u8Pin);

			GPIOC->OSPEEDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOC->OSPEEDR |= (Copy_u8Speed<<(Copy_u8Pin * 2));
			break;
		default:
			break;
		}
	}
}
void MGPIO_SetInputPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InputMode)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (((Copy_u8Pin == PIN13) || (Copy_u8Pin == PIN14) || (Copy_u8Pin == PIN15))))
	{
		/* NOTHING */
	}
	else if((Copy_u8Port == PORTB) && ((Copy_u8Pin == PIN3) || (Copy_u8Pin == PIN4)))
	{
		/* NOTHING */
	}
	else
	{
		/* switching for port */
		/* then select input bin mode by clearing 2 response bits then set it with selected mode*/
		/* without affect other bits */
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->PUPDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOA->PUPDR |= (Copy_u8InputMode<<(Copy_u8Pin * 2));
			break;
		case PORTB:
			GPIOB->PUPDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOB->PUPDR |= (Copy_u8InputMode<<(Copy_u8Pin * 2));
			break;
		case PORTC:
			GPIOC->PUPDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin * 2));
			GPIOC->PUPDR |= (Copy_u8InputMode<<(Copy_u8Pin * 2));
			break;
		default:
			break;
		}
	}
}
void MGPIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8Data)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (Copy_u8Pin == PIN13 || Copy_u8Pin == PIN14 || Copy_u8Pin == PIN15))
	{
		/* Nothing */
	}
	else if((Copy_u8Port == PORTB) && (Copy_u8Pin == PIN3 || Copy_u8Pin == PIN4))
	{
		/* Nothing */
	}
	else
	{
		/* switching for port */
		/* then get data from IDR register */
		switch(Copy_u8Port)
		{
		case PORTA:
			*Copy_pu8Data = GET_BIT(GPIOA->IDR,Copy_u8Pin);
			break;
		case PORTB:
			*Copy_pu8Data = GET_BIT(GPIOB->IDR,Copy_u8Pin);
			break;
		case PORTC:
			*Copy_pu8Data = GET_BIT(GPIOC->IDR,Copy_u8Pin);
			break;
		default:
			break;
		}
	}
}
void MGPIO_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, PIN_Value_t Copy_PinValue)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (Copy_u8Pin == PIN13 || Copy_u8Pin == PIN14 || Copy_u8Pin == PIN15))
	{
		/* Nothing */
	}
	else if((Copy_u8Port == PORTB) && (Copy_u8Pin == PIN3 || Copy_u8Pin == PIN4))
	{
		/* Nothing */
	}
	else
	{
		/* switch for pinvalue */
		switch(Copy_PinValue)
		{
		case OUTPUT_HIGH:
			/* switch for port */
			/* then set bin in ODR register */
			switch(Copy_u8Port)
			{
			case PORTA:
				SET_BIT(GPIOA->ODR,Copy_u8Pin);
				break;
			case PORTB:
				SET_BIT(GPIOB->ODR,Copy_u8Pin);
				break;
			case PORTC:
				SET_BIT(GPIOC->ODR,Copy_u8Pin);
				break;
			default:
				break;
			}
			break;
			case OUTPUT_LOW:
				/* switch for port */
				/* then clear bin in ODR register */
				switch(Copy_u8Port)
				{
				case PORTA:
					CLR_BIT(GPIOA->ODR,Copy_u8Pin);
					break;
				case PORTB:
					CLR_BIT(GPIOB->ODR,Copy_u8Pin);
					break;
				case PORTC:
					CLR_BIT(GPIOC->ODR,Copy_u8Pin);
					break;
				default:
					break;
				}
				break;
				default:
					break;
		}
	}

}
void MGPIO_SetResetValue(u8 Copy_u8Port, u8 Copy_u8Pin, PIN_Value_t Copy_PinValue)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (((Copy_u8Pin == PIN13) || (Copy_u8Pin == PIN14) || (Copy_u8Pin == PIN15))))
	{
		/* NOTHING */
	}
	else if((Copy_u8Port == PORTB) && ((Copy_u8Pin == PIN3) || (Copy_u8Pin == PIN4)))
	{
		/* NOTHING */
	}
	else
	{
		/* check for set */
		if(Copy_PinValue == OUTPUT_HIGH)
		{
			/* switch for port */
			/* then assign 1 for selected pin in BSRR register */
			switch(Copy_u8Port)
			{
			case PORTA:
				GPIOA->BSRR = (1<<Copy_u8Pin);
				break;
			case PORTB:
				GPIOB->BSRR = (1<<Copy_u8Pin);
				break;
			case PORTC:
				GPIOC->BSRR = (1<<Copy_u8Pin);
				break;
			default:
				break;
			}
		}
		/* check for reset */
		else if(Copy_PinValue == OUTPUT_LOW)
		{
			/* reset bits in BSRR register from 16 ---> 31 */
			Copy_u8Pin += 16;
			/* switch for port */
			/* then assign 1 for selected pin in BSRR register */
			switch(Copy_u8Port)
			{
			case PORTA:
				GPIOA->BSRR = (1<<Copy_u8Pin);
				break;
			case PORTB:
				GPIOB->BSRR = (1<<Copy_u8Pin);
				break;
			case PORTC:
				GPIOC->BSRR = (1<<Copy_u8Pin);
				break;
			default:
				break;
			}
		}
	}
}

void MGPIO_Toggle_pin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	/* Checking to avoid debug pins */
	if((Copy_u8Port == PORTA) && (((Copy_u8Pin == PIN13) || (Copy_u8Pin == PIN14) || (Copy_u8Pin == PIN15))))
	{
		/* NOTHING */
	}
	else if((Copy_u8Port == PORTB) && ((Copy_u8Pin == PIN3) || (Copy_u8Pin == PIN4)))
	{
		/* NOTHING */
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			TOG_BIT(GPIOA->ODR,Copy_u8Pin);
			break;
		case PORTB:
			TOG_BIT(GPIOB->ODR,Copy_u8Pin);
			break;
		case PORTC:
			TOG_BIT(GPIOC->ODR,Copy_u8Pin);
			break;
		default:
			break;
		}
	}
}
void MGPIO_SetAlternativeFuncPin(u8 Copy_u8Port,u8 Copy_u8Pin,u8  Copy_u8Data){
	if(Copy_u8Port==PORTA && (Copy_u8Pin==PIN13 || Copy_u8Pin==14 || Copy_u8Pin==15))
	{
		/* Do Nothing */
	}
	else if(Copy_u8Port==PORTB && (Copy_u8Pin==PIN3 || Copy_u8Pin==4 ))
	{
		/* Do Nothing */
	}
	else
	{
		switch (Copy_u8Port) {
		case PORTA:
			if(Copy_u8Pin<=7)
			{
				GPIOA->AFRL &=~(Alternative_Mask<<(Copy_u8Pin*4));
				GPIOA->AFRL |=(Copy_u8Data<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOA->AFRH &=~(Alternative_Mask<<((Copy_u8Pin-8)*4));
				GPIOA->AFRH |=(Copy_u8Data<<((Copy_u8Pin-8)*4));
			}
			break;
		case PORTB:
			if(Copy_u8Pin<=7)
			{
				GPIOB->AFRL &=~(Alternative_Mask<<(Copy_u8Pin*4));
				GPIOB->AFRL |=(Copy_u8Data<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOB->AFRH &=~(Alternative_Mask<<((Copy_u8Pin-8)*4));
				GPIOB->AFRH |=(Copy_u8Data<<((Copy_u8Pin-8)*4));
			}
			break;
		case PORTC:
			if(Copy_u8Pin<=7)
			{
				GPIOC->AFRL &=~(Alternative_Mask<<(Copy_u8Pin*4));
				GPIOC->AFRL |=(Copy_u8Data<<(Copy_u8Pin*4));
			}
			else
			{
				GPIOC->AFRH &=~(Alternative_Mask<<((Copy_u8Pin-8)*4));
				GPIOC->AFRH |=(Copy_u8Data<<((Copy_u8Pin-8)*4));
			}
			break;
		default:
			break;
		}
	}
}
