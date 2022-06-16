

#ifndef LCD_H_
#define LCD_H_
#include "include.h"
#include "sets.h"

void createScoreLCD(int32_t score, int16_t buffer[]);
void lcd_write_string(char string[], int16_t buffer[], int16_t position);
void lcd_write_heart(int8_t filled,int8_t antal, int16_t buffer[], int16_t position);


#endif /* LCD_H_ */
