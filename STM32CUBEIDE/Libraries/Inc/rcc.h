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




/*
 * AHB1ENR
 * */
#define CLOCK_GPIOA			0x00000001UL
#define CLOCK_GPIOB			0x00000002UL
#define CLOCK_GPIOC			0x00000004UL
#define CLOCK_GPIOD			0x00000008UL
#define CLOCK_GPIOE			0x00000010UL
#define CLOCK_GPIOF			0x00000020UL
#define CLOCK_DMA1			0x00200000UL
#define CLOCK_DMA2			0x00400000UL


/*
 * APB1ENR
 * */
#define CLOCK_TIM2			0x00000001UL
#define CLOCK_TIM3			0x00000002UL
#define CLOCK_TIM4			0x00000004UL
#define CLOCK_TIM5			0x00000008UL
#define CLOCK_TIM6			0x00000010UL
#define CLOCK_TIM7			0x00000020UL
#define CLOCK_TIM12			0x00000040UL
#define CLOCK_TIM13			0x00000080UL
#define CLOCK_TIM14			0x00000100UL
#define CLOCK_WWDG			0x00000800UL
#define CLOCK_SPI2			0x00004000UL
#define CLOCK_SPI3			0x00008000UL
#define CLOCK_USART2		0x00020000UL
#define CLOCK_USART3		0x00040000UL
#define CLOCK_UART4			0x00080000UL
#define CLOCK_UART5			0x00100000UL
#define CLOCK_I2C1			0x00200000UL
#define CLOCK_I2C2			0x00400000UL
#define CLOCK_I2C3			0x00800000UL
#define CLOCK_PWR			0x10000000UL


/*
 * APB2ENR
 * */
#define CLOCK_TIM1			0x00000001UL
#define CLOCK_TIM8			0x00000002UL
#define CLOCK_USART1		0x00000010UL
#define CLOCK_USART6		0x00000020UL
#define CLOCK_ADC1			0x00000100UL
#define CLOCK_ADC2			0x00000200UL
#define CLOCK_ADC3			0x00000400UL
#define CLOCK_SDIO			0x00000800UL
#define CLOCK_SPI1			0x00001000UL
#define CLOCK_TIM9			0x00010000UL
#define CLOCK_TIM10			0x00020000UL
#define CLOCK_TIM11			0x00040000UL

#define RCC_BASE_ADDR			0x40023800UL
#define RCC ((RCC_TypeDef*)RCC_BASE_ADDR)

/*
 * Order of RCC_PERIPH_EN() Function
 * */
#define RCC_AHB1ENR	0x30
#define RCC_APB1ENR	0x40
#define RCC_APB2ENR	0x44



void RCC_DeInit(void);
void RCC_Init(void);
void RCC_PERIPH_Config(uint32_t Source, uint32_t Periph_Name, uint32_t NewState);
void HSE_Config(uint32_t PLL_M, uint32_t PLL_N, uint32_t PLL_P, uint32_t PLL_Q);

#endif

