#ifndef MENU_H_
#define MENU_H_

#include "include.h"

void menuMove(int8_t pil, int8_t *sel);
void menuSelect(int8_t button, int8_t *sel, int8_t *game);
void menu(char q, int8_t pil, char overstNederst, int16_t points, int8_t *sel);

#endif
