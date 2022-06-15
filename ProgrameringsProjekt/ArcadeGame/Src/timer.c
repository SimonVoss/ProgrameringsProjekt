#include "timer.h"


void clockInit(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 = 0x0000;
	TIM15->ARR = 0x18FF; // Set auto reload value
	TIM15->PSC = 0x0000; // Set pre-scaler value
	TIM15->DIER |= 0x0001; // Enable timer interrupt
	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0);
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
	TIM15->CR1 |= 0x0001; // Enable timer
}

void clockCounter(int32_t score,int32_t *cE,int32_t *cF,int16_t *flagF, int16_t *flagE){
	int32_t nextInterval = 100<<8;
	int32_t time = 100<<8;
	if (score < nextInterval){
		if (*cF >= time>>1){
			*flagF = 1;
			*cF=0;
		}
		if (*cE >= time){
			*flagE = 1;
			*cE=0;
		}
	}else if (score == nextInterval){
		time = FIX8_MULT(time, 0xCC);
		if (*cF >= time>>1){
			*flagF = 1;
			*cF=0;
		}
		if (*cE >= time){
			*flagE = 1;
			*cE=0;
		}
		nextInterval = nextInterval<<1;
	}

}



