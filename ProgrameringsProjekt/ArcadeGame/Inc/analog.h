#ifndef ANALOG_H_
#define ANALOG_H_

#include "include.h"

#define tid0 10000
#define tid1 50000
#define tid2 70000
#define tid3 180000
#define tid4 180000


int8_t adcRead1(void);
int8_t adcRead2(void);
int8_t buttonRead(void);
void buzz(int32_t lyd, int32_t *c, int32_t *flag);

#endif
