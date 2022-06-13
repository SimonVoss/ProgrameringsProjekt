
#ifndef EX2_H_
#define EX2_H_

#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"

void clrsrc(void);
void clreol(void);
void gotoxy(int32_t x, int32_t y);
void underline(int32_t on);
void blink(int32_t on);
void inverse(int32_t on);
void window(int32_t x1, int32_t y1, int32_t x2, int32_t y2, char title[], int32_t style);


#endif /* EX2_H_ */
