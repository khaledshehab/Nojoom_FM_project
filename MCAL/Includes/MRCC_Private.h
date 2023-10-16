/*
 * MRCC_Private.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Khaled Shehab
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

/*********Define registers Addresess***********/
#define RCC_BASE_ADDRESS   (0x40023800)

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 RESERVED1;
	u32 RESERVED2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 RESERVED3;
	u32 RESERVED4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 RESERVED5;
	u32 RESERVED6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 RESERVED7;
	u32 RESERVED8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 RESERVED9;
	u32 RESERVED10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 RESERVED11;
	u32 RESERVED12;
	u32 BDCR;
	u32 CSR;
	u32 RESERVED13;
	u32 RESERVED14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 RESERVED15;
	u32 DCKCFGR;
}RCC_t;

#define RCC ((volatile RCC_t*)RCC_BASE_ADDRESS)

/*************Clock options***************/
#define RCC_HSE       0
#define RCC_HSI       1
#define RCC_PLL       2

/*HSE options*/
#define HSE_RC            0
#define HSE_CRYSTAL       1

/*System clock switch*/
#define SWITCH_HSI    0
#define SWITCH_HSE    1
#define SWITCH_PLL    2
#define SWITCH_MASK   (0xFFFFFFFC)

/*CR Register bits*/
#define CR_HSI_ON      0
#define CR_HSI_RDY     1
#define CR_HSE_ON      16
#define CR_HSE_RDY     17
#define CR_PLL_ON      24
#define CR_PLL_RDY     25





#endif /* MRCC_PRIVATE_H_ */
