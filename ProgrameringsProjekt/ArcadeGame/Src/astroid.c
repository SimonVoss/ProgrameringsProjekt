#include "astroid.h"

void initArrayAstroid(bigRock a[], int8_t length) {
	int8_t i;
	for (i=0; i<length;i++){
		a[i].x = 0;
		a[i].y = 0;
		a[i].alive = 0;
	}
}

void createAstroid(bigRock a[]) {
	int8_t i;
	for(i = 0; i <= 5; i++) {
		if(a[i].alive==0) {
			ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

			ADC_StartConversion(ADC1); // Start ADC read
			while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

			uint16_t randSpawn = ADC_GetConversionValue(ADC1);
			ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);

			ADC_StartConversion(ADC1); // Start ADC read
			while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

			randSpawn += ADC_GetConversionValue(ADC1);
			randSpawn = randSpawn%10;
			randSpawn = randSpawn/2;
			a[i].x = 15+randSpawn*26;
			a[i].y = 5;
			a[i].alive=1;
			astroidDraw(a[i].x, a[i].y);
			break;
		}
	}
}

void moveAstroid(bigRock a[]) {
	int8_t i;
	for(i=0; i<5;i++) {
		if(!(a[i].alive==0)) {
			if(!((a[i].y)==(123-2))) {
				slideAstroid(a[i]);
				a[i].y = a[i].y+1;
			} else {
				astroidRemove(a[i].x, a[i].y);
				a[i].alive=0;
			}
		}
	}
}

void slideAstroid(bigRock a) {
	fgcolor(7);
	gotoxy(a.x-1,a.y+3);
	printf("%c%c%c%c",219,219,219,219);
	gotoxy(a.x-3,a.y+2);
	printf("%c%c",219,219);
	fgcolor(8);
	printf("%c%c%c%c",219,219,219,219);
	fgcolor(7);
	printf("%c%c",219,219);
	gotoxy(a.x-4,a.y+1);
	printf("%c",219);
	fgcolor(8);
	printf("%c%c",219,219);
	gotoxy(a.x+3,a.y+1);
	printf("%c",219);
	fgcolor(7);
	gotoxy(a.x+3,a.y);
	printf("%c",219);
	fgcolor(0);
	printf("%c",219);
	fgcolor(7);
	gotoxy(a.x-3,a.y-1);
	printf("%c%c%c",219,219,219);
	gotoxy(a.x+2,a.y-1);
	printf("%c",219);
	fgcolor(0);
	gotoxy(a.x-4,a.y-1);
	printf("%c",219);
	fgcolor(7);
	gotoxy(a.x,a.y-2);
	printf("%c%c",219,219);
	fgcolor(0);
	gotoxy(a.x-3,a.y-2);
	printf("%c%c%c",219,219,219);
	gotoxy(a.x+2,a.y-2);
	printf("%c%c",219,219);
	gotoxy(a.x,a.y-3);
	printf("%c%c",219,219);

}


