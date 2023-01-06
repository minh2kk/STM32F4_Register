/*
 * gpio.c
 *
 *  Created on: Jan 4, 2023
 *      Author: MINH
 */


#ifndef INC_GPIO_H
#define INC_GPIO_H

#include "gpio.h"

void GPIO_Init(GPIO_TypeDef* GPIOx, uint32_t Pinx, uint32_t Mode, uint32_t Otype, uint32_t Speed, uint32_t PuPd){
	uint32_t pinpos = 0;
	for(pinpos = 0; pinpos <  15; ++pinpos){
		if((Pinx&(1<<pinpos)) != 0){
			GPIOx->MODER &= ~(3<<(pinpos*2));
			GPIOx->MODER |= Mode<<(pinpos*2);

			GPIOx->OTYPER &= ~(1<<pinpos);
			GPIOx->OTYPER |= Otype<<pinpos;

			GPIOx->OSPEEDR &= ~(3<<(pinpos*2));
			GPIOx->OSPEEDR |= Speed<<(pinpos*2);

			GPIOx->PUPDR &= ~(3<<(pinpos*2));
			GPIOx->PUPDR |= PuPd<<(pinpos*2);
		}
	}
}

void GPIO_InitAlternate(GPIO_TypeDef* GPIOx, uint32_t Pinx, uint32_t Alternate, uint32_t Otype, uint32_t Speed, uint32_t PuPd){
	uint32_t pinpos = 0;
	for(pinpos = 0; pinpos <  15; ++pinpos){
		if((Pinx&(1<<pinpos)) != 0){
			/*pinpos>>3: lay vi tri luu tru trong mang AFR 			[Ex: Pin 10 --(>>3)----> AFR[1]) ]
			 * pinpos&0x07: Lay vi tri Bit trong dia chi cua AFR		[Ex: Pin 10 --(&0x07)--> 8(Bit thu 8)]
			 * */
			GPIOx->AFR[pinpos>>3] = (GPIOx->AFR[pinpos>>3]&(~(0x0F << (4 * (pinpos & 0x07))))) | (Alternate << (4 * (pinpos & 0x07)));
		}
	}
	GPIO_Init(GPIOx, Pinx, MODER_ALT, Otype, Speed, PuPd);
}

void SetPinAsInput(GPIO_TypeDef* GPIOx, uint32_t Pinx){
	uint32_t pinpos = 0;
	for(pinpos = 0; pinpos <  15; ++pinpos){
		if((Pinx&(1<<pinpos)) != 0){
			GPIOx->MODER &= ~(3<<(pinpos*2));
		}
	}
}


void SetPinAsOutput(GPIO_TypeDef* GPIOx, uint32_t Pinx){
	uint32_t pinpos = 0;
	for(pinpos = 0; pinpos <  15; ++pinpos){
		if((Pinx&(1<<pinpos)) != 0){
			GPIOx->MODER &= ~(3<<(pinpos*2));
			GPIOx->MODER |= 1<<(pinpos*2);
		}
	}
}


uint8_t ReadDataPin(GPIO_TypeDef* GPIOx, uint32_t Pinx){
	if(((GPIOx->IDR)&(Pinx)) == Pinx) return 1;
	return 0;
}

uint16_t  ReadDataPort(GPIO_TypeDef* GPIOx){
	return ((uint16_t)GPIOx->IDR);
}

void WriteDataPin(GPIO_TypeDef* GPIOx, uint32_t Pinx, uint32_t NewState){
	if(NewState == SET){
		GPIOx->BSRR = Pinx;
	}else{
		GPIOx->BSRR = Pinx<<16;
	}
}

void WriteDataPort(GPIO_TypeDef* GPIOx, uint32_t NewState){
	GPIOx->ODR = NewState;
}


void TogglePin(GPIO_TypeDef* GPIOx, uint32_t Pinx){
	GPIOx->ODR ^= Pinx;
}

#endif



