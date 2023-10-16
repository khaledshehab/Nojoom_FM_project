/*
 * HTFT_Program.c
 *
 *  Created on: Sep 22, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/HTFT_Private.h"
#include "../include/HTFT_Config.h"
#include "../include/HTFT_Interface.h"

#include "../include/MGPIO_Interface.h"
#include "../include/MSPI_Interface.h"
#include "../include/MSYSTICK_Interface.h"

void HTFT_voidInit(void)
{
	TFT_voidReset();
	TFT_voidWriteCommand(0x11);
	MSYSTICK_voidDelayms(150);
	TFT_voidWriteCommand(0x3A);
	TFT_voidWriteData(0x05);
	TFT_voidWriteCommand(0x29);
}
void HTFT_voidDisplay(const u16* Copy_pu16Image)
{
	u16 counter;
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);
	TFT_voidWriteCommand(0x2C);
	for(counter =0; counter < 20480; counter++)
	{
		TFT_voidWriteData(Copy_pu16Image[counter]>>8);
		TFT_voidWriteData(Copy_pu16Image[counter]&0x00ff);
	}
}

static void TFT_voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	/* Set A0 pin to Low */
	MGPIO_SetResetValue(TFT_A0_PIN,OUTPUT_LOW);

	/* Send Command over SPI */
	MSPI1_u16SendDataU16(Copy_u8Command,&Local_u8Temp);
}

static void TFT_voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	/* Set A0 pin to High */
	MGPIO_SetResetValue(TFT_A0_PIN,OUTPUT_HIGH);

	/* Send Data over SPI */
	MSPI1_u16SendDataU16(Copy_u8Data,&Local_u8Temp);
}

static void TFT_voidReset(void)
{
	MGPIO_SetResetValue(TFT_RST_PIN,OUTPUT_HIGH);
	MSYSTICK_voidDelayus(100);
	MGPIO_SetResetValue(TFT_RST_PIN,OUTPUT_LOW);
	MSYSTICK_voidDelayus(3);
	MGPIO_SetResetValue(TFT_RST_PIN,OUTPUT_HIGH);
	MSYSTICK_voidDelayus(100);
	MGPIO_SetResetValue(TFT_RST_PIN,OUTPUT_LOW);
	MSYSTICK_voidDelayus(100);
	MGPIO_SetResetValue(TFT_RST_PIN,OUTPUT_HIGH);
	MSYSTICK_voidDelayms(120);
}
