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
