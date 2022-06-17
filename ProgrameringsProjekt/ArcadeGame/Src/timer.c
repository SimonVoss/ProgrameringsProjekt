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

void clockCounter(int32_t score,int32_t *c1,int32_t *c2,int32_t *c3,int16_t *flagF, int16_t *flagE, int16_t *flagR){
	static int32_t nextInterval = 100<<8;
	static int32_t time = 1000<<8;
	if (score<<8 < nextInterval){
		if (*c1 >= time>>1){
			*flagF = 1;
			*c1=0;
		}
		if (*c2 >= time<<1){
			*flagE = 1;
			*c2=0;
		}
		if (*c3>= time<<5){
			*flagR = 1;
			*c3=0;

		}

	}else if (score<<8 == nextInterval){
		time = FIX8_MULT(time, 0xE7);
		if (*c1 >= time>>1){
			*flagF = 1;
			*c1=0;
		}
		if (*c2 >= time){
			*flagE = 1;
			*c2=0;
		}
		if (*c3>= time<<5){
			*flagR = 1;
			*c3=0;
		}
		nextInterval = nextInterval<<1;
	}

}



