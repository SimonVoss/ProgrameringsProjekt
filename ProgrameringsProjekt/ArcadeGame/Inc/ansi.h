#ifndef _ANSI_H_
#define _ANSI_H_

/* Includes -------------------------------------------------------------*/
#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"

/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
/* Exported macro -------------------------------------------------------*/
// #define // Whatever needs to be defined

/* Exported functions -------------------------------------------------- */
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);

#endif /* _ANSI_H_ */
