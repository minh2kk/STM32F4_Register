/*
 * gpio.h
 *
 *  Created on: Jan 4, 2023
 *      Author: MINH
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_


#include "define.h"

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

typedef struct{


}GPIO_InitTypeDef;

#define MODER_IN		0
#define MODER_OUT		1
#define MODER_ALT		2
#define MODER_ANA		3

#define OTYPER_PP		0
#define OTYPER_OD		1

#define OSPEEDR_L		0
#define OSPEEDR_M		1
#define OSPEEDR_H		2
#define OSPEEDR_VH		3

#define PUPDR_NONE		0
#define PUPDR_PU		1
#define PUPDR_PD		2

typedef enum{
	GPIO_PIN_0 	=  0,
	GPIO_PIN_1 	=  1,
	GPIO_PIN_2 	=  2,
	GPIO_PIN_3 	=  3,
	GPIO_PIN_4 	=  4,
	GPIO_PIN_5 	=  5,
	GPIO_PIN_6 	=  6,
	GPIO_PIN_7 	=  7,
	GPIO_PIN_8	=  8,
	GPIO_PIN_9	=  9,
	GPIO_PIN_10 = 10,
	GPIO_PIN_11 = 11,
	GPIO_PIN_12 = 12,
	GPIO_PIN_13 = 13,
	GPIO_PIN_14 = 14,
	GPIO_PIN_15 = 15
}Pin_Number;

void GPIO_Init(GPIO_TypeDef* GPIOx, Pin_Number Pinx, uint8_t Mode, uint8_t Otype, uint8_t Speed, uint8_t PuPd);
#endif /* INC_GPIO_H_ */
