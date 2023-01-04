#ifndef	INC_RCC_H
#define INC_RCC_H

#include "define.h"



typedef struct{

	__IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
	__IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
	__IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
	__IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
	__IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	__IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	__IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
	__IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	__IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
	__IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	__IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	__IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
	__IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	__IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
	__IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	__IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	__IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
	__IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	__IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
	__IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
	__IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
	uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
	__IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */

}RCC_TypeDef;

#define RCC_BASE_ADDR			0x40023800UL


/*
 * AHB1ENR
 * */
#define CLOCK_GPIOA			0
#define CLOCK_GPIOB			1
#define CLOCK_GPIOC			2
#define CLOCK_GPIOD			3
#define CLOCK_GPIOE			4
#define CLOCK_GPIOF			5
#define CLOCK_DMA1			21
#define CLOCK_DMA2			22


/*
 * APB1ENR
 * */
#define CLOCK_TIM2			0
#define CLOCK_TIM3			1
#define CLOCK_TIM4			2
#define CLOCK_TIM5			3
#define CLOCK_TIM6			4
#define CLOCK_TIM7			5
#define CLOCK_TIM12			6
#define CLOCK_TIM13			7
#define CLOCK_TIM14			8
#define CLOCK_WWDG			11
#define CLOCK_SPI2			14
#define CLOCK_SPI3			13
#define CLOCK_USART2		17
#define CLOCK_USART3		18
#define CLOCK_UART4			19
#define CLOCK_UART5			20
#define CLOCK_I2C1			21
#define CLOCK_I2C2			22
#define CLOCK_I2C3			23
#define CLOCK_PWR			28


/*
 * APB2ENR
 * */
#define CLOCK_TIM1			0
#define CLOCK_TIM8			1
#define CLOCK_USART1		4
#define CLOCK_USART6		5
#define CLOCK_ADC1			8
#define CLOCK_ADC2			9
#define CLOCK_ADC3			10
#define CLOCK_SDIO			11
#define CLOCK_SPI1			12
#define CLOCK_TIM9			16
#define CLOCK_TIM10			17
#define CLOCK_TIM11			18

#define RCC ((RCC_TypeDef*)RCC_BASE_ADDR)

/*
 * Order of RCC_PERIPH_EN() Function
 * */
#define RCC_AHB1ENR	0
#define RCC_APB1ENR	1
#define RCC_APB2ENR	2

#define DISABLE		0
#define ENABLE		1



void RCC_DeInit(void);
void RCC_Init(void);
void RCC_PERIPH_Config(uint32_t Source, uint32_t Periph_Name, uint32_t NewState);
void HSE_Config(uint32_t PLL_M, uint32_t PLL_N, uint32_t PLL_P, uint32_t PLL_Q);

#endif

