/*
 * dma.h
 *
 *  Created on: Jan 7, 2023
 *      Author: MINH
 */

#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "define.h"

#define DMA_STREAM_NUMBER  8

typedef struct{
	__IO uint32_t LISR;
	__IO uint32_t HISR;
	__IO uint32_t LIFCR;
	__IO uint32_t HIFCR;
	struct{
		__IO uint32_t CR;
		__IO uint32_t NDTR;
		__IO uint32_t PAR;
		__IO uint32_t M0AR;
		__IO uint32_t M1AR;
		__IO uint32_t FCR;
	}Stream[DMA_STREAM_NUMBER];
}DMA_TypeDef;

typedef struct{
	__IO uin32_t Source;
	__IO uint32_t Destination;
	__IO uint_32_t Dir;
	__IO uint32_t MSize;
	__IO uint32_t PSize;
	__IO uint32_t Channel;
	__IO uint32_t Priority;
	__IO uint32_t ModeCircular;
	__IO uint32_t FlowController;
}DMA_Config;

#define Priority_Low			0
#define Priority_Medium			1
#define Priority_High			2
#define Priority_VHigh			3

#define Size_Byte				0
#define Size_HalfWord			1
#define Size_Word				2

#define Circular_EN				0
#define Circular_DIS			1

#define Dir_PeriphToMem			0
#define Dir_MemToPeriph			1
#define Dir_MemToMem			2

#define Controller_By_DMA		0
#define Controller_By_Periph	1

#define Channel_0				0
#define Channel_1				1
#define Channel_2				2
#define Channel_3				3
#define Channel_4				4
#define Channel_5				5
#define Channel_6				6
#define Channel_7				7

#define DMA1 ((DMA_TypeDef*)DMA1_BASE_ADDR)
#define DMA2 ((DMA_TypeDef*)DMA2_BASE_ADDR)

void DMA_Init(DMA_TypeDef* DMAx, DMA_Config* Config);


#endif /* INC_DMA_H_ */
