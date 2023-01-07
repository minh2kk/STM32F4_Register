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

#define GPIO_Pin_0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /* Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /* All pins selected */




#define GPIOA 	((GPIO_TypeDef*)GPIOA_BASE_ADDR)
#define GPIOB 	((GPIO_TypeDef*)GPIOB_BASE_ADDR)
#define GPIOC 	((GPIO_TypeDef*)GPIOC_BASE_ADDR)
#define GPIOD 	((GPIO_TypeDef*)GPIOD_BASE_ADDR)
#define GPIOE 	((GPIO_TypeDef*)GPIOE_BASE_ADDR)
#define GPIOF 	((GPIO_TypeDef*)GPIOF_BASE_ADDR)

void GPIO_Init(GPIO_TypeDef* GPIOx, uint32_t Pinx, uint32_t Mode, uint32_t Otype, uint32_t Speed, uint32_t PuPd);
void GPIO_InitAlternate(GPIO_TypeDef* GPIOx, uint32_t Pinx, uint32_t Alternate, uint32_t Otype, uint32_t Speed, uint32_t PuPd);
void SetPinAsInput(GPIO_TypeDef* GPIOx, uint32_t Pinx);
void SetPinAsOutput(GPIO_TypeDef* GPIOx, uint32_t Pinx);
uint8_t  ReadDataPin(GPIO_TypeDef* GPIOx, uint32_t Pinx);
uint16_t  ReadDataPort(GPIO_TypeDef* GPIOx);
void WriteDataPin(GPIO_TypeDef* GPIOx, uint32_t Pinx, uint32_t NewState);
void WriteDataPort(GPIO_TypeDef* GPIOx, uint32_t NewState);
void TogglePin(GPIO_TypeDef* GPIOx, uint32_t Pinx);


#endif /* INC_GPIO_H_ */
