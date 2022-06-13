#include "gameBoard.h"


//1,1 til 124,133
//x-akse man kan bruge 2-132
//y-akse man kan bruge 2-123
void makeBorder(void) {
	int32_t i;
	fgcolor(3);
	gotoxy(1,1);
	printf("%c",218);
	for(i = 0; i <= 134; i++) {
		printf("%c",196);
	}
	printf("%c",191);
	for(i = 2; i <= 123; i++) {
		gotoxy(1,i);
		printf("%c",179);
		gotoxy(137,i);
		printf("%c",179);
	}
	gotoxy(1,124);
	printf("%c",192);
	for(i = 0; i <= 134; i++) {
		printf("%c",196);
	}
	printf("%c",217);
}

void makeBoard(void) {
	int32_t i;
	int32_t j;
	fgcolor(3);
	gotoxy(1,1);
	printf("%c",218);
	for(i = 0; i <= 134; i++) {
		printf("%c",196);
	}
	printf("%c",191);
	for(i = 2; i <= 123; i++) {
		gotoxy(1,i);
		printf("%c",179);
		for(j = 0; j <= 134; j++) {
			printf(" ");
		}
		printf("%c",179);
	}
	gotoxy(1,124);
	printf("%c",192);
	for(i = 0; i <= 134; i++) {
		printf("%c",196);
	}
	printf("%c",217);
}
