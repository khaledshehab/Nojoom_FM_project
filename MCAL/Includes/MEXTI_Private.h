/*
 * MEXTI_Private.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Khaled Shehab
 */

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

#define MEXTI_BASE_ADDRESS    (0x40013C00)
#define SYSCFG_BASE_ADDRESS    (0x40013800)

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}MEXTI_t;

typedef struct
{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 RESERVED[2];
	u32 CMPCR;
}SYSCFG_t;

#define MEXTI   ((volatile MEXTI_t*)MEXTI_BASE_ADDRESS)
#define SYSCFG   ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)

#define DIV_FAC       4
#define SYSCFG_MASK   0x0000000F

#endif /* MEXTI_PRIVATE_H_ */
