/*
 * MSPI_Program.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Khaled Shehab
 */

#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MSPI_Private.h"
#include "../include/MSPI_Config.h"
#include "../include/MSPI_Interface.h"
#include "../include/MGPIO_Interface.h"

static void(*SPI1_ptr)(void) = {NULL_PTR};

void MSPI1_voidInit(void)
{


#if MSPI1_STATUS == MSPI_ENABLE
	SET_BIT(MSPI1->CR1,CR1_SPI_ENABLE);



#if MSPI1_CLOCK_MODE == MSPI_MODE_0
	CLR_BIT(MSPI1->CR1,CR1_CPHA);
	CLR_BIT(MSPI1->CR1,CR1_CPOL);

#elif MSPI1_CLOCK_MODE == MSPI_MODE_1
	SET_BIT(MSPI1->CR1,CR1_CPHA);
	CLR_BIT(MSPI1->CR1,CR1_CPOL);

#elif MSPI1_CLOCK_MODE == MSPI_MODE_2
	CLR_BIT(MSPI1->CR1,CR1_CPHA);
	SET_BIT(MSPI1->CR1,CR1_CPOL);

#elif MSPI1_CLOCK_MODE == MSPI_MODE_3
	SET_BIT(MSPI1->CR1,CR1_CPHA);
	SET_BIT(MSPI1->CR1,CR1_CPOL);

#endif





#if MSPI1_DATA_ORDER == MSPI_MSB_FIRST
	CLR_BIT(MSPI1->CR1,CR1_FRAME_FORMAT);

#elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST
	SET_BIT(MSPI1->CR1,CR1_FRAME_FORMAT);

#endif

#if MSPI1_SS_MANAGE == MSPI_HW_SLAVE_MANAGEMENT
	CLR_BIT(MSPI1->CR1,CR1_SOFTWARE_SLAVE_MANAGEMENT);
	SET_BIT(MSPI1->CR1,CR1_SSI);
#elif MSPI1_SS_MANAGE == MSPI_SW_SLAVE_MANAGEMENT
	SET_BIT(MSPI1->CR1,CR1_SOFTWARE_SLAVE_MANAGEMENT);
	SET_BIT(MSPI1->CR1,CR1_SSI);
#endif

#if MSPI1_DATA_SIZE == MSPI_8BIT_DATA
	CLR_BIT(MSPI1->CR1,CR1_DATA_FRAME_FORMAT);

#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA
	SET_BIT(MSPI1->CR1,CR1_DATA_FRAME_FORMAT);

#endif

#if MSPI1_MASTER_SLAVE == MSPI_SLAVE
	CLR_BIT(MSPI1->CR1,CR1_MASTER_SELECTION);

#elif MSPI1_MASTER_SLAVE == MSPI_MASTER
	SET_BIT(MSPI1->CR1,CR1_MASTER_SELECTION);
	MSPI1->CR1 |= (u32)(MSPI1_PRESCALLER<<CR1_BAUD_RATE);

#endif

#if MSPI1_INT_STATUS == MSPI_INT_DISABLE
	MSPI1->CR2 &= 0x00000000;
	//	CLR_BIT(MSPI1->CR2,CR2_TXEIE);
	//	CLR_BIT(MSPI1->CR2,CR2_TXEIE-1);
	//	CLR_BIT(MSPI1->CR2,CR2_TXEIE-2);

#elif MSPI1_INT_STATUS == MSPI_INT_ENABLE
	SET_BIT(MSPI1->CR2,CR2_TXEIE);

#endif

#elif MSPI1_STATUS == MSPI_DISABLE
	CLR_BIT(MSPI1->CR1,CR1_SPI_ENABLE);

#endif

	//#if MSPI1_STATUS == MSPI_ENABLE
	//	u32 configuration=0;
	//	configuration   |=(MSPI_8BIT_DATA<<CR1_DATA_FRAME_FORMAT)
	//					|(MSPI_SW_SLAVE_MANAGEMENT<<CR1_SOFTWARE_SLAVE_MANAGEMENT)
	//					|(1<<CR1_SSI)
	//					|(MSPI_MSB_FIRST<<CR1_FRAME_FORMAT)
	//					|(MSPI_ENABLE<<CR1_SPI_ENABLE)
	//					|(MSPI_FPCLK_DIVIDED_BY_4<<CR1_BAUD_RATE)
	//					|(MSPI_MASTER<<CR1_MASTER_SELECTION)
	//					|(MSPI_MODE_3<<CR1_CPHA);
	//
	//	MSPI1->CR1=configuration;
	//
	////MSPI1->CR1=0x0347;
	////MSPI1->CR2 &= 0x00000000;
	////
	//	configuration=0;
	//
	//	configuration   |=(0<<CR2_TXEIE)
	//					| (0<<CR2_RXNEIE)
	//					| (0<<CR2_ERRIE);
	//
	//	MSPI1->CR2=(u16)configuration;			//RESERVED is CR2
	//#endif


}
void MSPI1_u16SendDataU16(u8 Copy_u8Data, u8 *pu8Receive)
{
	MSPI1->DR = Copy_u8Data;
	while(GET_BIT(MSPI1->SR,7) == 1);
	*pu8Receive = (u8)MSPI1->DR;

	//#if MSPI1_DATA_SIZE == MSPI_8BIT_DATA
	//	return (u8)MSPI1->DR;

	//#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA
	//	return MSPI1->DR;

	//#endif
}
void MSPI1_voidSetCallBack(void(*ptr)(void))
{
	if(ptr != NULL_PTR)
	{
		SPI1_ptr = ptr;
	}
	else
	{
		/* Nothing */
	}
}

void __attribute__ ((weak, alias ("Default_Handler")))
SPI1_IRQHandler(void)
{
	if(SPI1_ptr != NULL_PTR)
	{
		SPI1_ptr();
	}
	else
	{

	}
}
