#ifndef _ANSI_H_
#define _ANSI_H_

/* Includes -------------------------------------------------------------*/
#include "include.h"

/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
/* Exported macro -------------------------------------------------------*/
// #define // Whatever needs to be defined

/* Exported functions -------------------------------------------------- */
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clrsrc(void);
void clreol(void);
void gotoxy(int32_t x, int32_t y);
void underline(int32_t on);
void blink(int32_t on);
void inverse(int32_t on);
void window(int32_t x1, int32_t y1, int32_t x2, int32_t y2, char title[], int32_t style);


#endif /* _ANSI_H_ */
