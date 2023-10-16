/*
 * MSPI_Interface.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Khaled Shehab
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/* Status */
#define MSPI_DISABLE                0
#define MSPI_ENABLE       			1

/* Clock Mode */

#define MSPI_MODE_0      			0  //CPOL --> 0 & CPHA --> 0
#define MSPI_MODE_1					1  //CPOL --> 0 & CPHA --> 1
#define MSPI_MODE_2					2  //CPOL --> 1 & CPHA --> 0
#define MSPI_MODE_3					3  //CPOL --> 1 & CPHA --> 1

/* Master or Slave */
#define MSPI_SLAVE					0
#define MSPI_MASTER					1

/* CLock Prescaler */
#define MSPI_FPCLK_DIVIDED_BY_2		0
#define MSPI_FPCLK_DIVIDED_BY_4		1
#define MSPI_FPCLK_DIVIDED_BY_8		2
#define MSPI_FPCLK_DIVIDED_BY_16	3
#define MSPI_FPCLK_DIVIDED_BY_32	4
#define MSPI_FPCLK_DIVIDED_BY_64	5
#define MSPI_FPCLK_DIVIDED_BY_128	6
#define MSPI_FPCLK_DIVIDED_BY_256	7

/* Data order */
#define MSPI_MSB_FIRST				0
#define MSPI_LSB_FIRST				1

/* select slave manage */
#define MSPI_HW_SLAVE_MANAGEMENT	0
#define MSPI_SW_SLAVE_MANAGEMENT	1

/* Data size */
#define MSPI_8BIT_DATA              0
#define MSPI_16BIT_DATA             1

/* Interrupt status */
#define MSPI_INT_DISABLE			0
#define MSPI_INT_ENABLE				1

/* APIs Prototypes */
void MSPI1_voidInit(void);
void MSPI1_u16SendDataU16(u8 Copy_u8Data, u8 *pu8Receive);
void MSPI1_voidSetCallBack(void(*ptr)(void));



#endif /* MSPI_INTERFACE_H_ */
