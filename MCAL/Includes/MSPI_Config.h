/*
 * MSPI_Config.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Khaled Shehab
 */

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

#define MSPI1_STATUS         MSPI_ENABLE
#define MSPI1_CLOCK_MODE     MSPI_MODE_3
#define MSPI1_MASTER_SLAVE   MSPI_MASTER
#define MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_2
#define MSPI1_DATA_ORDER     MSPI_MSB_FIRST
#define MSPI1_SS_MANAGE      MSPI_SW_SLAVE_MANAGEMENT
#define MSPI1_DATA_SIZE      MSPI_8BIT_DATA
#define MSPI1_INT_STATUS     MSPI_INT_DISABLE

#define MSPI_SS_PORT        PORTA
#define MSPI_SS_PIN         PIN0



#endif /* MSPI_CONFIG_H_ */
