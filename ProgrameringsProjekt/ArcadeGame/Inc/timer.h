
#ifndef TIMER_H_
#define TIMER_H_
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( (a)*(b) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )
#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course


void clockInit();
void delay(int32_t d,int32_t *c,int32_t *flag);
void clockCounter(int32_t score,int32_t *c,int32_t *flag);



#endif /* TIMER_H_ */
