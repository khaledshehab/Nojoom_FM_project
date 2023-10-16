/*
 * MSYSTICK_Interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Khaled Shehab
 */

#ifndef MSYSTICK_INTERFACE_H_
#define MSYSTICK_INTERFACE_H_

/* systick state */
typedef enum
{
	SYSTICK_ENABLE=0,
	SYSTICK_DISABLE
}SYSTICKState;

/***********APIs Prototypes**************/
void MSYSTICK_voidInit(void);

void MSYSTICK_voidStart(u32 Copy_u32Loadvalue);

void MSYSTICK_voidSetIntervalSignalus(u32 Copy_u32Ticks,void (*Copy_ptr)(void));

void MSYSTICK_voidDelayus(u32 Copy_u32DelayValue);

void MSYSTICK_voidDelayms(u32 Copy_u32DelayValue);

u8 MSYSTICK_u8ReadFlag(void);

void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);

void MSYSTICK_voidEnable(void);

void MSYSTICK_voidDisable(void);
void MESYSTICK_voidCallBack(void (*ptr)(void));


#endif /* MSYSTICK_INTERFACE_H_ */
