

#ifndef LCD_H_
#define LCD_H_
#include "include.h"
#include "sets.h"

void createScoreLCD(int16_t score, int8_t buffer[], int8_t hs);
void lcd_write_level(int8_t level, int8_t buffer[]);
void lcd_write_missil(int8_t buffer[], int8_t create, int16_t position);
void lcd_write_string(char string[], int8_t buffer[], int16_t position);
void lcd_write_heart(int8_t filled,int8_t antal, int8_t buffer[], int16_t position);


#endif /* LCD_H_ */
