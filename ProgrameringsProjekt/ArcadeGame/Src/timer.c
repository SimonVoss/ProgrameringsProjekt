#include "timer.h"



void clockInit(){
	RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
	TIM2->CR1 = 0x0000;
	TIM2->ARR = 0x18FF; // Set reload value
	TIM2->PSC = 0x0000; // Set prescale value
	TIM2->DIER |= 0x0001; // Enable timer 2 interrupts
	NVIC_SetPriority(TIM2_IRQn, 0); // Set interrupt priority
	NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt
	TIM2->CR1 = 0x0001; // start timer
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


