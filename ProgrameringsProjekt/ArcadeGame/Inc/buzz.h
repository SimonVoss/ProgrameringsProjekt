
#ifndef BUZZ_H_
#define BUZZ_H_

#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "timer.h"
void BuzzConfig(void);
void buzz(int32_t lyd, int32_t *c, int32_t *flag);



#endif

