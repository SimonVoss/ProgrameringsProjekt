#include "bossKey.h"
//1,1 til 137,124
//53
void bossKey(void) {
	int16_t i,j;
	gotoxy(1,1);
	color(0,2);
	for(i=1; i<=137;i++) {
		printf(" ");
	}
	printf("\n");
	printf("Excel.exe       Save i guess?          Name: Excelfile.xml (clearly)      [search bar]         Your name here                          X \n");
	for(i=1; i<=137;i++) {
		printf(" ");
	}
	printf("\n");
	bgcolor(7);
	for(i=1; i<=137;i++) {
		printf(" ");
	}
	printf("\n");
	printf("   File   Home   Insert   Draw   etc...   i mean who even knows what these say?  I don't and i hope you don't either                     \n");
	for(i=1; i<=137;i++) {
		printf(" ");
	}
	printf("\n");
	printf("  %cABCDEFGHIJKLMNOPQRSTUVWXYZ....                                 a few letters here                                         more letters\n",62);
	for(i=33;i<=126;i++) {
		color(0,7);
		printf(" %c ",i);
		color(15,7);
		for(j=2;j<=135;j++) {
			printf("%c",219);
		}
		printf("\n");
	}
	for(i=128;i<=149;i++) {
		color(0,7);
		printf(" %c ",i);
		color(15,7);
		for(j=2;j<=135;j++) {
			printf("%c",219);
		}
		printf("\n");
	}
	color(0,7);
	printf(" This is the end, there is no more excel file, and there will never be anymore excel file. I am working hard, please leave               \n");

	color(0,0);
	for(i=1;i<=11;i++) {
		for(j=1;j<=11;j++) {
			gotoxy(15+i,15+j);
			printf("%c",219);
		}
	}
	playerDraw(21,17);
	color(0,0);
	for(i=1;i<=11;i++) {
		for(j=1;j<=11;j++) {
			gotoxy(37+i,37+j);
			printf("%c",219);
		}
	}
	enemyDraw(43,47);
	color(0,0);
	for(i=1;i<=11;i++) {
		for(j=1;j<=11;j++) {
			gotoxy(82+i,9+j);
			printf("%c",219);
		}
	}
	astroidDraw(88,15);
	numberText(20,100,49,0);
	numberText(40,100,49,0);
	numberText(60,100,51,0);
	fgcolor(0);
	gotoxy(35,101);
	printf("%c", 219);
	gotoxy(35,102);
	printf("%c", 219);
	gotoxy(33,103);
	printf("%c%c%c%c%c", 219,219,219,219,219);
	gotoxy(35,104);
	printf("%c", 219);
	gotoxy(35,105);
	printf("%c", 219);
	gotoxy(52,101);
	printf("%c%c%c%c%c",219,219,219,219,219);
	gotoxy(52,105);
	printf("%c%c%c%c%c",219,219,219,219,219);
	signText(90,70,1,0);
}

