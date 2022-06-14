#include "timer.h"



void clockInit(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 2;
	TIM15->CR1 = 0x0000; TIM15->ARR = 63999; // Set auto reload value
	TIM15->PSC = 9; // Set pre-scaler value
	TIM15->DIER |= 0x0001; // Enable timer interrupt
	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0);
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
	TIM15->CR1 |= 0x0001; // Enable timer
}

void delay(int32_t d,int32_t *c,int32_t *flag){
	int32_t time = d<<8;
	if (*c >= time){
			*flag = 1;
			*c=0;
		}
}


void clockCounter(int32_t score,int32_t *c,int32_t *flag){
	int32_t nextInterval = 100<<8;
	int32_t time = 1000<<8;
	if (score < nextInterval){
		if (*c >= time){
			*flag = 1;
			*c=0;
		}
	}else if (score == nextInterval){
		time = FIX8_MULT(time, 0xCC);
		if (*c >= time){
			*flag = 1;
			*c=0;
		}
		nextInterval = nextInterval<<1;
	}

}


