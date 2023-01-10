/*
 * systick.h
 *
 *  Created on: Jan 6, 2023
 *      Author: MINH
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "define.h"

typedef struct{
	__IO uint32_t CTRL;
	__IO uint32_t LOAD;
	__IO uint32_t VAL;
	__IO uint32_t CALIB;
}SysTick_Reg;

#define SYSTICK_BASE_ADDR	0xE000E010UL
#define SYSTICK ((SysTick_Reg*)SYSTICK_BASE_ADDR)

void SysTick_Init(uint32_t SourceDiv, uint32_t Exception);
void SysTick_Cmd(uint32_t NewState);
void Delay(uint32_t DelayVal);


#endif /* INC_SYSTICK_H_ */
