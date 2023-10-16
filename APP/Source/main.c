/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MRCC_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"
#include "../include/MEXTI_Interface.h"
#include "../include/MSPI_Interface.h"
#include "../include/HTFT_Interface.h"
#include "../include/HIR_Interface.h"
#include "../include/HR2RDAC_Interface.h"
#include "../include/HLEDMATRIX_Interface.h"
#include "../include/HSTP_Interface.h"
#include "../include/Image.h"
#include "../include/Amr.h"
#include "../include/Monir.h"

u8 Name[3][69]={
				{
				0,0,0,0,0,0,0,124,
				126, 11, 9, 11, 126, 124, 0, 127,
				127, 14, 28, 14, 127, 127, 0, 65,
				127, 127, 9, 25, 127, 102, 0, 65,
				127, 127, 65, 99, 62, 28, 0, 0,
				0, 65, 127, 127, 65, 0, 0, 124,
				126, 11, 9, 11, 126, 124, 0, 65,
				127, 127, 73, 73, 127, 54, 0,0,
				0,0,0,0,0
				},
				{
				0,0,0,0,0,0,0,127,
				127, 14, 28, 14, 127, 127, 0, 62,
				127, 65, 65, 65, 127, 62, 0, 63,
				127, 64, 64, 64, 127, 63, 0, 127,
				127, 6, 12, 24, 127, 127, 0, 0,
				0, 65, 127, 127, 65, 0, 0, 65,
				127, 127, 9, 25, 127, 102, 0,0,
				0,0,0,0,0
				},
				{
				0,0,0,0,0,0,0,62,
				127, 65, 65, 65, 127, 62, 0, 65,
				127, 127, 73, 29, 1, 3, 0, 65,
				127, 127, 73, 29, 1, 3, 0,0,
				0,0,0,0,0
				}
			   };

extern u8 data;
u8 LedMat_Count=2;
u8 TFT_Count=0;
u8 LocalCounter=0;
u8 i=0;
u8 j=0;
u8 k=0;
u8 Flag=4;
u32 Song_counter=0;

void Led_Animation(void)
{
	static u8 round=0;
	if(round == 0)
	{
		MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_LOW);
		MGPIO_SetResetValue(PORTA,PIN9,OUTPUT_HIGH);
		MGPIO_SetResetValue(PORTA,PIN10,OUTPUT_LOW);
		round = 1;
	}
	else if(round == 1)
	{
		MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_LOW);
		MGPIO_SetResetValue(PORTA,PIN9,OUTPUT_LOW);
		MGPIO_SetResetValue(PORTA,PIN10,OUTPUT_HIGH);
		round = 2;
	}
	else if(round == 2)
	{
		MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_HIGH);
		MGPIO_SetResetValue(PORTA,PIN9,OUTPUT_LOW);
		MGPIO_SetResetValue(PORTA,PIN10,OUTPUT_LOW);
		round=0;
	}

}

void ISR(void)
{
	HIR_voidStoreData();
	switch(data)
	{
	case HIR_40_BUTTON: //Amr
		Flag=2;
		TFT_Count =1;
		LedMat_Count=0;
		i=0;
		j=0;
		k=0;
		LocalCounter=0;
		Song_counter=0;
		HTFT_voidDisplay(image[TFT_Count]);
		break;
	case HIR_41_BUTTON: //Monir
		Flag=3;
		TFT_Count =2;
		LedMat_Count=1;
		i=0;
		j=0;
		k=0;
		LocalCounter=0;
		Song_counter=0;
		HTFT_voidDisplay(image[TFT_Count]);
		break;
	case HIR_42_BUTTON: //OFF
		Flag=0;
		TFT_Count =0;
		LedMat_Count=2;
		MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_LOW);
		MGPIO_SetResetValue(PORTA,PIN9,OUTPUT_LOW);
		MGPIO_SetResetValue(PORTA,PIN10,OUTPUT_LOW);
		HTFT_voidDisplay(image[TFT_Count]);
		break;
	default:
		break;
	}
}

int main(void)
{
	MRCC_Init();
	MSYSTICK_voidInit();

	/* Enable peripheral used in project */
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOC);
	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SPI1);
	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SYSCFG);

	/* RGB Pins */
	MGPIO_SetMode(PORTA,PIN8,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN8,OUTPUT_PUSH_PULL,SPEED_MEDIUM);
	MGPIO_SetMode(PORTA,PIN9,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN9,OUTPUT_PUSH_PULL,SPEED_MEDIUM);
	MGPIO_SetMode(PORTA,PIN10,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN10,OUTPUT_PUSH_PULL,SPEED_MEDIUM);
	MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_HIGH);

	/* Pins for SPI */
	/* A0 */
	MGPIO_SetMode(PORTA,PIN6,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN6,OUTPUT_PUSH_PULL,SPEED_MEDIUM);
	/* RST */
	MGPIO_SetMode(PORTA,PIN4,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,SPEED_MEDIUM);
	/* Alternative Pins */
	MGPIO_SetMode(PORTA,PIN5,ALT_FUNC);
	MGPIO_SetMode(PORTA,PIN7,ALT_FUNC);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN5,5);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN7,5);
	/*****************************************/
	/* External Interrupt */
	MGPIO_SetMode(PORTA,PIN0,INPUT);
	MGPIO_SetInputPinMode(PORTA,PIN0,NO_PULL_UP_DOWN);
	MEXTI_voidCallBack(HIR_voidRecieveFrame,EXTI_LIN0);
	MNVIC_VoidEnableInterrupt(6);
	MEXIT_voidInterruptSetport(EXTI_LIN0,EXTI_PORTA);
	MEXTI_voidInterruptTrigger(EXTI_LIN0,EXTI_FALLING);
	MEXTI_voidInterruptEnableDisable(EXTI_LIN0,EXTI_ENABLE);

	MSYSTICK_voidCtrlIntState(SYSTICK_DISABLE);
	MESYSTICK_voidCallBack(ISR);
	MSPI1_voidInit();
	HTFT_voidInit();
	HSTP1_voidInit();
	HSTP2_voidInit();
	HR2RDAC_voidInit();


	while(1)
	{
		if(Flag == 2)
		{
			for(i=0;i<62;i++)
			{
				Led_Animation();
				/**/
				HR2RDAC_voidSetDataOneTime(Amr[Song_counter]);
				Song_counter++;
				if(Song_counter == 41533)
					Song_counter=0;
				for(j=0;j<15;j++)
					for (LocalCounter=0;LocalCounter<8;LocalCounter++)
					{
						if(Flag == 2)
						{
						HSTP2_voidSendSynchronus(0);
						/**/
						HR2RDAC_voidSetDataOneTime(Amr[Song_counter]);
						Song_counter++;
						if(Song_counter == 41533)
							Song_counter=0;
						HSTP1_voidSendSynchronus(Name[LedMat_Count][LocalCounter+i]);
						/**/
						HR2RDAC_voidSetDataOneTime(Amr[Song_counter]);
						Song_counter++;
						if(Song_counter == 41533)
							Song_counter=0;
						HSTP2_voidSendSynchronus(1<<LocalCounter);
						/**/
						for(k=0;k<5;k++)
						{
						HR2RDAC_voidSetDataOneTime(Amr[Song_counter]);
						Song_counter++;
						MSYSTICK_voidDelayus(80);
						if(Song_counter == 41533)
							Song_counter=0;
						}
						}
					}
			}
		}
		else if(Flag == 3)
		{
			for(i=0;i<54;i++)
			{
				Led_Animation();
				/**/
				HR2RDAC_voidSetDataOneTime(Monir[Song_counter]);
				Song_counter++;
				if(Song_counter == 41533)
					Song_counter=0;
				for(j=0;j<15;j++)
					for (LocalCounter=0;LocalCounter<8;LocalCounter++)
					{
						if(Flag == 3)
						{
						HSTP2_voidSendSynchronus(0);
						/**/
						HR2RDAC_voidSetDataOneTime(Monir[Song_counter]);
						Song_counter++;
						if(Song_counter == 52309)
							Song_counter=0;
						HSTP1_voidSendSynchronus(Name[LedMat_Count][LocalCounter+i]);
						/**/
						HR2RDAC_voidSetDataOneTime(Monir[Song_counter]);
						Song_counter++;
						if(Song_counter == 52309)
							Song_counter=0;
						HSTP2_voidSendSynchronus(1<<LocalCounter);
						/**/
						for(k=0;k<5;k++)
						{
						HR2RDAC_voidSetDataOneTime(Monir[Song_counter]);
						Song_counter++;
						MSYSTICK_voidDelayus(80);
						if(Song_counter == 52309)
							Song_counter=0;
						}
						}
					}
			}
		}
		else if(Flag == 0)
		{
			MGPIO_SetResetValue(PORTA,PIN8,OUTPUT_HIGH);
			MGPIO_SetResetValue(PORTA,PIN9,OUTPUT_HIGH);
			MGPIO_SetResetValue(PORTA,PIN10,OUTPUT_HIGH);
			for(i=0;i<30;i++)
				for(j=0;j<40;j++)
					for (LocalCounter=0;LocalCounter<8;LocalCounter++)
					{
						if(Flag == 0)
						{
						HSTP2_voidSendSynchronus(0);
						HSTP1_voidSendSynchronus(Name[LedMat_Count][LocalCounter+i]);
						HSTP2_voidSendSynchronus(1<<LocalCounter);
						MSYSTICK_voidDelayus(100);
						}
					}
			Flag=1;
		}
		else if(Flag == 1)
		{
			Led_Animation();
			MSYSTICK_voidDelayms(1000);
		}
	}

}

