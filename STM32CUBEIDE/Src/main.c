/**
 ******************************************************************************
 * @file           : main.c
 * @author         : VU VAN MINH
 * @brief          : Main program body
 ******************************************************************************
 */


#include "rcc.h"
#include "gpio.h"

uint32_t tmp[3];
int main(void)
{

	HSE_Config(4, 168, 2, 4);

	RCC_PERIPH_Config(RCC_AHB1ENR, CLOCK_GPIOA|CLOCK_GPIOE, ENABLE);
	RCC_PERIPH_Config(RCC_APB1ENR, CLOCK_SPI2|CLOCK_TIM4, ENABLE);
	RCC_PERIPH_Config(RCC_APB2ENR, CLOCK_SDIO|CLOCK_TIM1, ENABLE);
	GPIO_Init(GPIOA, GPIO_Pin_6|GPIO_Pin_7, MODER_OUT, OTYPER_PP, OSPEEDR_H, PUPDR_PU);
	GPIOA->ODR &= ~(1<<6);
	GPIOA->ODR |= 1<<7;
	GPIO_Init(GPIOE, GPIO_Pin_3|GPIO_Pin_4, MODER_IN, OTYPER_PP, OSPEEDR_H, PUPDR_PU);
 	while(1){
 		if(ReadDataPin(GPIOE, GPIO_Pin_3)==0){
 			while(ReadDataPin(GPIOE, GPIO_Pin_3)==0);
 			TogglePin(GPIOA, GPIO_Pin_6 | GPIO_Pin_7);
 		}
// 		for(int i = 0; i < 500000; ++i){}

	}

}
