/*
 * BIT_MATH.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Khaled shehab
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define CLR_BIT(REG , BIT)       REG &= ~(1<<BIT)
#define SET_BIT(REG , BIT)       REG |= (1<<BIT)
#define TOG_BIT(REG , BIT)       REG ^= (1<<BIT)
#define GET_BIT(REG , BIT)       ((REG >> BIT) & 1)

#endif /* LIB_BIT_MATH_H_ */
