/*
 * MSYSTICK_Private.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Khaled Shehab
 */

#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS    (0xE000E010)

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SYSTICK_t;

#define SYSTICK  ((volatile SYSTICK_t*)SYSTICK_BASE_ADDRESS)

/* CTRL register bits */
#define CTRL_ENABLE          0
#define CTRL_TICKINT         1
#define CTRL_CLKSOURCE       2
#define CTRL_COUNTFLAG       16

/* define systick clock modes */
#define SYSTICK_CLK_AHB_DIV_8       0
#define SYSTICK_CLK_AHB         1

#endif /* MSYSTICK_PRIVATE_H_ */
