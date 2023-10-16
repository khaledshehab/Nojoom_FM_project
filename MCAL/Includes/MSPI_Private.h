/*
 * MSPI_Private.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Khaled Shehab
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

#define MSPI1_BASE_ADDRESS   (0x40013000)

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}MSPI_t;

#define MSPI1   ((volatile MSPI_t*)MSPI1_BASE_ADDRESS)



/* CR1 register bits */
#define CR1_CPHA            			0
#define CR1_CPOL            			1
#define CR1_MASTER_SELECTION 			2
#define CR1_BAUD_RATE		 			3
#define CR1_SPI_ENABLE        			6
#define CR1_FRAME_FORMAT      			7
#define CR1_SSI			      			8
#define CR1_SOFTWARE_SLAVE_MANAGEMENT	9
#define CR1_DATA_FRAME_FORMAT      		11

/* CR2 TX empty interrupt enable */
#define CR2_ERRIE         				5
#define CR2_RXNEIE         				6
#define CR2_TXEIE         				7

#endif /* MSPI_PRIVATE_H_ */
