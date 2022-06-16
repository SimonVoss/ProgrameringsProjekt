#include "lcd.h"

void createScoreLCD(int32_t score, int16_t buffer[]){
	char scoreLCD [13];
	sprintf(scoreLCD, "Score: %05d",score);
	lcd_write_string(scoreLCD, &buffer,0);
}

void lcd_write_string(char string[], int16_t buffer[], int16_t position){
	int8_t n = strlen(string);
	for (int j = 0; j < n; j++){
		for (int i = 0; i<5;i++){
			buffer[position]=character_data[string[j]-0x20][i];
			position++;
		}
	}
}

void lcd_write_heart(int8_t filled,int8_t antal, int16_t buffer[], int16_t position){
	char space[2] = {' ', '\0'};
	if (filled == 1){
		for (int j = 0; j<antal; j++){
			for(int i = 0; i<9 ;i++){
				buffer[position]=customset[0][i];
				position++;
			}
			lcd_write_string(space,buffer,position);
			position++;
		}
	} else{
		for (int j = 0; j<antal; j++){
			for(int i = 0; i<9 ;i++){
				buffer[position]=customset[1][i];
				position++;
			}
			lcd_write_string(space,buffer,position);
			position++;
		}

	}

}
