/*
 * systick.h
 *
 *  Created on: Jan 6, 2023
 *      Author: MINH
 */



#include <systick.h>

void SysTick_Init(uint32_t SourceDiv, uint32_t Exception){
	SYSTICK->CTRL = Exception<<1 | SourceDiv<2;
}

void SysTick_Cmd(uint32_t NewState){
	if(NewState == ENABLE){
		SYSTICK->CTRL |= 1<<0;
	}else{
		SYSTICK->CTRL &= ~(1<<0);
	}
}

void Delay(uint32_t DelayVal){
	if(SYSTICK->CTRL&(1<<2)){

	}
}

