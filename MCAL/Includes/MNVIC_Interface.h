/*
 * MNVIC_Interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Khaled Shehab
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_


/* Group Mode */
typedef enum
{
	Group16Sub0=3,
	Group8Sub2,
	Group4Sub4,
	Group2Sub8,
	Group0Sub16

}MNVIC_Group_t;

/* interrupt state */
#define INTERRUPT_NOT_ACTIVE     0
#define INTERRUPT_ACTIVE         1

/***********APIs Prototypes**************/
void MNVIC_VoidEnableInterrupt(u8 Copy_u8Intpos);
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntPos);
void MNVIC_VoidEnableInterruptPending(u8 Copy_u8IntPos);
void MNVIC_VoidDisableInterruptPending(u8 Copy_u8IntPos);
void MNVIC_u8IsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read);
void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 u8SubGroupNum);
void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode);



#endif /* MNVIC_INTERFACE_H_ */
