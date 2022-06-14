#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ex2.h"


void text(){

}


void letters(int a,int x, int y){

	int32_t sign1 = 254;
	int32_t sign2 = 219;
	int32_t i, j, k;

	//A
	if (a == 0){
		fgcolor(2);
		gotoxy(x,y);
		for(i=0;i<=12;i++)
			printf("%c",254);
		for(i=0;i<=6;i++){
			gotoxy(x-1,y+i);
			printf("%c",254);
		}

		fgcolor(3);
		gotoxy(x+5,y);
		printf("%c",sign1);
		for (i=1;i<=5;i++){
		gotoxy(x-i+5,y+i);
		printf("%c",sign1);
		}
		for (i=1;i<=5;i++){
		gotoxy(x+i+5,y+i);
		printf("%c",sign1);
		}
		for (i=0;i<=6;i++){
		gotoxy(x-3+i+5,y+3);
		printf("%c",sign1);
		}
	}
	//C
	if (a == 1){
		fgcolor(2);
		gotoxy(x,y);
		for(i=0;i<=12;i++)
			printf("%c",254);
		for(i=0;i<=6;i++){
			gotoxy(x-1,y+i);
			printf("%c",254);
			fgcolor(3);
		}
		gotoxy(x,y);
		printf("%c",254);
		for (i=0;i<=5;i++){
		gotoxy(x+5+i,y);
		printf("%c",sign1);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+3-i+i,y+i+1);
		printf("%c",sign2);
		}




	}
	//D
	if (a == 2){
		fgcolor(2);
		gotoxy(x,y);
		for(i=0;i<=12;i++)
			printf("%c",254);
		for(i=0;i<=6;i++){
			gotoxy(x-1,y+i);
			printf("%c",254);
			fgcolor(3);
		}


		gotoxy(x,y);
		printf("%c",254);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c",sign2);
		}
		printf("\n%c",sign1);
		for (i=1;i<=5;i++){
		gotoxy(x+i,y);
		printf("%c",sign1);
		}
		for (i=1;i<=5;i++){
		gotoxy(x+i,y+6);
		printf("%c",sign1);
		}
	}

}


