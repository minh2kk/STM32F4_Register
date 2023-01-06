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




	RCC_PERIPH_Config(RCC_AHB1ENR, CLOCK_GPIOA, ENABLE);
	GPIO_Init(GPIOA, GPIO_Pin_6|GPIO_Pin_7, MODER_OUT, OTYPER_PP, OSPEEDR_H, PUPDR_PU);
	GPIOA->ODR &= ~(1<<6);
	GPIOA->ODR |= 1<<7;
	WriteDataPin(GPIOA, GPIO_Pin_6, RESET);
	tmp[0] = ReadDataPin(GPIOA, GPIO_Pin_6);
	tmp[1] = ReadDataPin(GPIOA, GPIO_Pin_7);
	tmp[2] = ReadDataPort(GPIOA);
 	while(1){
 		TogglePin(GPIOA, GPIO_Pin_6 | GPIO_Pin_7);
		for(int i = 0; i < 500000; ++i){}

	}

}
