/*
 * MGPIO_Private.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Khaled Shehab
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS   (0x40020000)
#define GPIOB_BASE_ADDRESS   (0x40020400)
#define GPIOC_BASE_ADDRESS   (0x40020800)

typedef struct
{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIOx_t;

#define GPIOA  ((volatile GPIOx_t*)GPIOA_BASE_ADDRESS)
#define GPIOB  ((volatile GPIOx_t*)GPIOB_BASE_ADDRESS)
#define GPIOC  ((volatile GPIOx_t*)GPIOC_BASE_ADDRESS)

#define Alternative_Mask      0x0000000f

#endif /* MGPIO_PRIVATE_H_ */
