#include "enemy.h"

void initArrayEnemy(badShip a[], int8_t length) {
	int8_t i;
	for (i=0; i<length;i++){
		a[i].x = 0;
		a[i].y = 0;
		a[i].alive = 0;
	}
}

void createEnemy(badShip a[]) {
	int8_t i;
	for (i=0; i<20; i++) {
		if (a[i].alive==0) {
			ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

			ADC_StartConversion(ADC1); // Start ADC read
			while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

			uint32_t randSpawn = ADC_GetConversionValue(ADC1);
			ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);

			ADC_StartConversion(ADC1); // Start ADC read
			while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

			randSpawn += ADC_GetConversionValue(ADC1);
			randSpawn = randSpawn%10;
			a[i].x = 10+randSpawn*13;
			a[i].y = 10;
			a[i].alive=1;
			enemyDraw(a[i].x, a[i].y);
			break;
		}
	}
}

void moveEnemy(badShip a[], goodShip *player) {
	int8_t i;
	for(i=0; i<20;i++) {
		if(!(a[i].alive==0)) {
			if(!((a[i].y)==(123))) {
				slideEnemy(a[i]);
				a[i].y = a[i].y+(1);
			} else {
				enemyRemove(a[i].x, a[i].y);
				a[i].alive=0;
				player->life--;
			}
		}
	}

}

void slideEnemy(badShip a) {
	fgcolor(1);
	gotoxy(a.x-3,a.y+1);
	printf("%c",219);
	gotoxy(a.x+3,a.y+1);
	printf("%c",219);
	gotoxy(a.x-1,a.y-1);
	printf("%c",219);
	gotoxy(a.x+1,a.y-1);
	printf("%c",219);
	gotoxy(a.x-2,a.y-2);
	printf("%c",219);
	gotoxy(a.x,a.y-2);
	printf("%c",219);
	gotoxy(a.x+2,a.y-2);
	printf("%c",219);
	fgcolor(11);
	gotoxy(a.x-1,a.y-3);
	printf("%c",219);
	gotoxy(a.x+1,a.y-3);
	printf("%c",219);
	gotoxy(a.x,a.y-4);
	printf("%c",219);
	fgcolor(1);
	gotoxy(a.x-1,a.y-4);
	printf("%c",219);
	gotoxy(a.x+1,a.y-4);
	printf("%c",219);
	fgcolor(0);
	gotoxy(a.x-3,a.y-4);
	printf("%c",219);
	gotoxy(a.x+3,a.y-4);
	printf("%c",219);
	fgcolor(1);
	gotoxy(a.x-3,a.y-5);
	printf("%c",219);
	gotoxy(a.x,a.y-5);
	printf("%c",219);
	gotoxy(a.x+3,a.y-5);
	printf("%c",219);
	fgcolor(0);
	gotoxy(a.x-1,a.y-5);
	printf("%c",219);
	gotoxy(a.x+1,a.y-5);
	printf("%c",219);
	fgcolor(1);
	gotoxy(a.x-4,a.y-6);
	printf("%c",219);
	gotoxy(a.x+4,a.y-6);
	printf("%c",219);
	fgcolor(0);
	gotoxy(a.x-2,a.y-6);
	printf("%c",219);
	gotoxy(a.x,a.y-6);
	printf("%c",219);
	gotoxy(a.x+2,a.y-6);
	printf("%c",219);
	gotoxy(a.x-3,a.y-7);
	printf("%c",219);
	gotoxy(a.x+3,a.y-7);
	printf("%c",219);
	gotoxy(a.x-4,a.y-8);
	printf("%c",219);
	gotoxy(a.x+4,a.y-8);
	printf("%c",219);
}

