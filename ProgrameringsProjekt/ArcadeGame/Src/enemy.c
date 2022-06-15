#include "enemy.h"

void createEnemy(badShip *enemy) {
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	uint32_t randSpawn = ADC_GetConversionValue(ADC1);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	randSpawn += ADC_GetConversionValue(ADC1);
	randSpawn = randSpawn%10;
	gotoxy(2,2);
	printf("%0ld",randSpawn);
	enemy->x = 10+randSpawn*13;
	enemy->y = 10;
	enemy->exist=1;
	enemyDraw(enemy->x, enemy->y);
}

void moveEnemy(badShip *enemy) {
	if(!(enemy->y==123)) {
		slideEnemy(enemy);
	} else {
		enemyRemove(enemy->x, enemy->y);
	}
}

void slideEnemy(badShip *enemy) {
	fgcolor(1);
	gotoxy(enemy->x-3,enemy->y+1);
	printf("%c",219);
	gotoxy(enemy->x+3,enemy->y+1);
	printf("%c",219);
	gotoxy(enemy->x-1,enemy->y-1);
	printf("%c",219);
	gotoxy(enemy->x+1,enemy->y-1);
	printf("%c",219);
	gotoxy(enemy->x-2,enemy->y-2);
	printf("%c",219);
	gotoxy(enemy->x,enemy->y-2);
	printf("%c",219);
	gotoxy(enemy->x+2,enemy->y-2);
	printf("%c",219);
	fgcolor(11);
	gotoxy(enemy->x-1,enemy->y-3);
	printf("%c",219);
	gotoxy(enemy->x+1,enemy->y-3);
	printf("%c",219);
	gotoxy(enemy->x,enemy->y-4);
	printf("%c",219);
	fgcolor(1);
	gotoxy(enemy->x-1,enemy->y-4);
	printf("%c",219);
	gotoxy(enemy->x+1,enemy->y-4);
	printf("%c",219);
	fgcolor(0);
	gotoxy(enemy->x-3,enemy->y-4);
	printf("%c",219);
	gotoxy(enemy->x+3,enemy->y-4);
	printf("%c",219);
	fgcolor(1);
	gotoxy(enemy->x-3,enemy->y-5);
	printf("%c",219);
	gotoxy(enemy->x,enemy->y-5);
	printf("%c",219);
	gotoxy(enemy->x+3,enemy->y-5);
	printf("%c",219);
	fgcolor(0);
	gotoxy(enemy->x-1,enemy->y-5);
	printf("%c",219);
	gotoxy(enemy->x+1,enemy->y-5);
	printf("%c",219);
	fgcolor(1);
	gotoxy(enemy->x-4,enemy->y-6);
	printf("%c",219);
	gotoxy(enemy->x+4,enemy->y-6);
	printf("%c",219);
	fgcolor(0);
	gotoxy(enemy->x-2,enemy->y-6);
	printf("%c",219);
	gotoxy(enemy->x,enemy->y-6);
	printf("%c",219);
	gotoxy(enemy->x+2,enemy->y-6);
	printf("%c",219);
	gotoxy(enemy->x-3,enemy->y-7);
	printf("%c",219);
	gotoxy(enemy->x+3,enemy->y-7);
	printf("%c",219);
	gotoxy(enemy->x-4,enemy->y-8);
	printf("%c",219);
	gotoxy(enemy->x+4,enemy->y-8);
	printf("%c",219);
	enemy->y++;
}

