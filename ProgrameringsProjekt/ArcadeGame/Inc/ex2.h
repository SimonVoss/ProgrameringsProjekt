
#ifndef EX2_H_
#define EX2_H_

#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"

void clrsrc(void);
void clreol(void);
void gotoxy(int8_t x, int8_t y);
void underline(int8_t on);
void blink(int8_t on);
void inverse(int8_t on);
void window(int8_t x1, int8_t y1, int8_t x2, int8_t y2, char title[], int8_t style);


#endif /* EX2_H_ */
