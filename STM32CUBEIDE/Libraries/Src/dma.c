/*
 * dma.c
 *
 *  Created on: Jan 7, 2023
 *      Author: MINH
 */

#include "dma.h"

void DMA_Init(DMA_TypeDef* DMAx, DMA_Config* Config, uint32_t StreamNumber){
	uint32_t tmp = 0x00000000;
	tmp |= (Config->FlowController<<5);
	tmp |= (Config->Dir<<6);
	tmp |= (Config->ModeCircular<<8);
	tmp |= (Config->PSize<<11);
	tmp |= (Config->MSize<<13);
	tmp |= (Config->Priority<<16);
	tmp |= (Config->Channel<<25);

	DMAx->Stream[StreamNumber].CR = tmp;
	DMAx->Stream[StreamNumber].NDTR = Config->NumDaTranfer;
	DMAx->Stream[StreamNumber].PAR = Config->Source;
	DMAx->Stream[StreamNumber].M0AR = Config->Destination;
}

void DMA_Cmd(DMA_TypeDef* DMAx, uint32_t StreamNumber, uint32_t NewState){
	if(NewState == ENABLE){
		DMAx->Stream[StreamNumber].CR |= 1<<0;
	}else{
		DMAx->Stream[StreamNumber].CR &= ~(1<<0);
	}
}





