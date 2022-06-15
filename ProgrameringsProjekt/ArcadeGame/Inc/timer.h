
#ifndef TIMER_H_
#define TIMER_H_
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( (a)*(b) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )

#include "include.h"

void clockInit();
void clockCounter(int32_t score,int32_t *c,int32_t *flag);



#endif /* TIMER_H_ */
