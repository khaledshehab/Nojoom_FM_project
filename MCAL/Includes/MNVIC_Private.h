/*
 * MNVIC_Private.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Khaled Shehab
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS    (0xE000E100)

typedef struct
{
	u32 ISER[8];
	u32 RESERVED1[24];
	u32 ICER[8];
	u32 RESERVED2[24];
	u32 ISPR[8];
	u32 RESERVED3[24];
	u32 ICPR[8];
	u32 RESERVED4[24];
	u32 IABR[8];
	u32 RESERVED5[56];
	u8 IPR[240];
	u32 RESERVED6[580];
	u32 STIR;
}NVIC_t;

#define NVIC    ((volatile NVIC_t*)NVIC_BASE_ADDRESS)

/* access for register AIRCR --> to chose group mode */
#define SCB_AIRCR  *((volatile u32*)0xE000ED0C)
#define SCB_AIRCR_VECTKEY     (0x05FA0000)

#define REG_DIV                  32
#define MAX_INTERRUPT_INDEX      240


#endif /* MNVIC_PRIVATE_H_ */
