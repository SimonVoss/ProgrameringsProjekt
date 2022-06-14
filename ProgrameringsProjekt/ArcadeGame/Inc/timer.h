
#ifndef TIMER_H_
#define TIMER_H_
#include "math.h"
#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course


void clockInit();
void clockCounter(int32_t score,int32_t *c,int32_t *flag);



#endif /* TIMER_H_ */
