#include "rcc.h"

void RCC_DeInit(void){

}

void RCC_Init(void){

}

/*
 *	SYSCLK 168MHz
 *	PCLK1: 42MHz	+ TIMx: 84MHz
 *	PCLK2: 84MHz	+ TIMx: 168MHz
 */
void HSE_Config(uint32_t PLL_M, uint32_t PLL_N, uint32_t PLL_P, uint32_t PLL_Q){
	//Enable HSE
	RCC->CR |= 1<<16;
	//Wait till the HSE flag is ready
	while((RCC->CR&(1<<17)) == RESET){};
	//Disable PLL
	RCC->CR &= ~(1<<24|1<<25);

	RCC->CFGR |= 6<<29;

	//Configuration PLL
	RCC->PLLCFGR = (PLL_M<<0) | (PLL_N<<6) | (PLL_P<<16) | (1<<22) | (PLL_Q<<24);
	//AHB prescaler: Not div
	RCC->CFGR &= ~(0xF<<4);
	//APB Low speed prescaler (APB1): div by 4
	RCC->CFGR |= 5<<10;
	//APB high-speed prescaler (APB2): div by 2
	RCC->CFGR |= 4<<13;
	//Latency + Prefetch enable + Instruction cache is enabled + Data cache is enabled
	FLASH->ACR |= (5<<0) | (1<<8) | (1<<9) | (1<<10);
	//Enable PLL
	RCC->CR |= 1<<24;
	//Wait till the PLL flag is ready
	while((RCC->CR&(1<<25)) == RESET){};
	//System clock switch: PLL selected as system clock
	RCC->CFGR |= 2<<0;
	//Wait till the PLL used as the system clock
	while((RCC->CFGR&0x3) != 0x2){};

}

/*
 *  ____________________________________________________________________________________________________
 * |		Source		| 								Periph_Name 									|
 *  ****************************************************************************************************
 * |					| CLOCK_GPIOA, CLOCK_GPIOB, CLOCK_GPIOC, CLOCK_GPIOD, CLOCK_GPIOE, CLOCK_GPIOF,	|
 * |	RCC_AHB1ENR		| CLOCK_DMA1, CLOCK_DMA2														|
 * |					|																				|
 *  ****************************************************************************************************
 * |					| CLOCK_TIM2, CLOCK_TIM3, CLOCK_TIM4, CLOCK_TIM5, CLOCK_TIM6, CLOCK_TIM7,		|
 * |	RCC_APB1ENR		| CLOCK_TIM12, CLOCK_TIM13, CLOCK_TIM14, CLOCK_WWDG, CLOCK_SPI2, CLOCK_SPI3,	|
 * |					| CLOCK_USART2, CLOCK_USART3, CLOCK_UART4, CLOCK_UART5, CLOCK_I2C1, CLOCK_I2C2,	|
 * |					| CLOCK_I2C3, CLOCK_PWR															|
 *  ****************************************************************************************************
 * |					| CLOCK_TIM1, CLOCK_TIM8, CLOCK_USART1, CLOCK_USART6, CLOCK_ADC1, CLOCK_ADC2,	|
 * |	RCC_APB2ENR		| CLOCK_ADC3, CLOCK_SDIO, CLOCK_SPI1, CLOCK_TIM9, CLOCK_TIM10, CLOCK_TIM11		|
 * |					|																				|
 *  ****************************************************************************************************
 *
 */

void RCC_PERIPH_Config(uint32_t Source, uint32_t Periph_Name, uint32_t NewState){
	uint32_t tmp;
	tmp = (RCC_BASE_ADDR + Source);
	if(NewState){
		*((uint32_t*)(tmp)) = *((uint32_t*)(tmp))|(1<<Periph_Name);
	}else{
		*((uint32_t*)(tmp)) = *((uint32_t*)(tmp))&(~(1<<Periph_Name));
	}
}
