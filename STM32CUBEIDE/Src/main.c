/**
 ******************************************************************************
 * @file           : main.c
 * @author         : VU VAN MINH
 * @brief          : Main program body
 ******************************************************************************
 */


#include "rcc.h"



int main(void)
{

	HSE_Config(4, 168, 2, 4);

//	tmp111 = (uint32_t*)(RCC_BASE_ADDR + RCC_AHB1ENR);


	RCC_PERIPH_Config(RCC_AHB1ENR, CLOCK_GPIOA, ENABLE);
	RCC_PERIPH_Config(RCC_AHB1ENR, CLOCK_GPIOB, ENABLE);
	RCC_PERIPH_Config(RCC_AHB1ENR, CLOCK_GPIOA, DISABLE);
	RCC_PERIPH_Config(RCC_APB2ENR, CLOCK_SDIO, ENABLE);
	RCC_PERIPH_Config(RCC_AHB1ENR, CLOCK_GPIOB, DISABLE);
	while(1){


	}

}
