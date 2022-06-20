#include "lcd.h"

void createScoreLCD(int16_t score, int8_t buffer[], int8_t hs){
	char scoreLCD [17];
	if (hs == 1){
		sprintf(scoreLCD, "Highscore: %05d",score);
		lcd_write_string(scoreLCD, buffer,128);
	}else {
		sprintf(scoreLCD, "Score: %05d",score);
		lcd_write_string(scoreLCD, buffer,0);
	}
	lcd_push_buffer(buffer);
}

void lcd_write_level(int8_t level, int8_t buffer[]){
	char levelLCD [7] = {'L','e','v','e','l',':'};
	char niveauLCD [3];
	lcd_write_string(levelLCD, buffer, 98);
	sprintf(niveauLCD, "%02d",level);
	lcd_write_string(niveauLCD, buffer, 246);
	lcd_push_buffer(buffer);

}

void lcd_write_missil(int8_t buffer[], int8_t create, int16_t position){
	char mi [8] = {'M','i','s','s','i','l',':','\0'};
	int16_t sted = 475;
	if (create == 1){
		lcd_write_string(mi,buffer,349);
		for (int j = 0; j<4; j++){
			for(int i = 0; i<9 ;i++){
				buffer[sted]=customset[6][i];
				sted++;
			}
		}

	}else if(create == 2){
		for (int j = 2; j<6; j++){
			for(int i = 0; i<9 ;i++){
				buffer[sted]=customset[j][i];
				sted++;
			}
		}

	}else if (create == 3){
		buffer[position] = 0xFF;
		position++;
	}
	lcd_push_buffer(buffer);
}

void lcd_write_string(char string[], int8_t buffer[], int16_t position){
	int8_t n = strlen(string);
	for (int j = 0; j < n; j++){
		for (int i = 0; i<5;i++){
			buffer[position]=character_data[string[j]-0x20][i];
			position++;
		}
	}
	lcd_push_buffer(buffer);
}

void lcd_write_heart(int8_t filled,int8_t antal, int8_t buffer[], int16_t position){
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
	lcd_push_buffer(buffer);

}
