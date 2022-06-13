#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "buzz.h"


void buzz(int16_t lyd){

		if(lyd == 0){
			
			int freq = 300;
			int PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			
			
		}

	}
