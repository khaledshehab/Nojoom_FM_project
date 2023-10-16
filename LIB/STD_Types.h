/*
 * STD_Types.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled shehab
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

typedef void(*pf)(void);

typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned long int  u32;
typedef signed char        s8;
typedef signed short int   s16;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;
typedef long double        f128;

typedef enum
{
	EOK,
	ENOK,
	PARAMRETER_OUT_RANGE,
	PARAMETER_NULL_PTR

}tenuErrorStatus;

#define NULL_PTR (void *) 0

#endif /* LIB_STD_TYPES_H_ */
