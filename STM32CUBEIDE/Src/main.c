/**
 ******************************************************************************
 * @file           : main.c
 * @author         : VU VAN MINH
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>

#define RCC_BASE_ADDR	0x40023800UL
#define RCC_AHB1ENR_OFFSET	0x30UL
#define RCC_AHB1ENR_ADDR	(RCC_BASE_ADDR+RCC_AHB1ENR_OFFSET)




int main(void)
{
    uint32_t *pRccAhb1Enr = (uint32_t*)RCC_AHB1ENR_ADDR;
    *pRccAhb1Enr |= 1<<0;

	for(;;);
}
