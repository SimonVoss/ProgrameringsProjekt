#include "letters.h"

char a,c,d,e,f,g,h,i,j,l,m,n,o,p,r,s,w,y;

void wordText(int x, int y, int word,int color){
	bgcolor(0);
	int32_t startPositionX = x;
	int32_t startPositionY = y;

	if(word == 0){
		letters('a',startPositionX,startPositionY, color);
		letters('r',startPositionX+14,startPositionY, color);
		letters('c',startPositionX+25,startPositionY, color);
		letters('a',startPositionX+40,startPositionY, color);
		letters('d',startPositionX+54,startPositionY, color);
		letters('e',startPositionX+66,startPositionY, color);
	}
	if(word == 1){
		letters('p',startPositionX,startPositionY, color);
		letters('l',startPositionX+13,startPositionY, color);
		letters('a',startPositionX+26,startPositionY, color);
		letters('y',startPositionX+39,startPositionY, color);


	}
	if(word == 2){
		letters('h',startPositionX,startPositionY, color);
		letters('e',startPositionX+13,startPositionY, color);
		letters('l',startPositionX+26,startPositionY, color);
		letters('p',startPositionX+39,startPositionY, color);
	}
	if(word == 3){
		letters('j',startPositionX,startPositionY, color);
		letters('o',startPositionX+13,startPositionY, color);
		letters('y',startPositionX+26,startPositionY, color);
		letters('s',startPositionX+39,startPositionY, color);
		letters('t',startPositionX+52,startPositionY, color);
		letters('i',startPositionX+65,startPositionY, color);
		letters('c',startPositionX+78,startPositionY, color);

		letters('l',startPositionX+103,startPositionY, color);
//		signText(startPositionX+112,startPositionY,2, color);
		letters('r',startPositionX+122,startPositionY, color);

	}
	if(word == 4){
		letters('f',startPositionX,startPositionY, color);
		letters('i',startPositionX+13,startPositionY, color);
		letters('r',startPositionX+26,startPositionY, color);
		letters('e',startPositionX+39,startPositionY, color);

		letters('r',startPositionX+65,startPositionY, color);
		letters('e',startPositionX+78,startPositionY, color);
		letters('d',startPositionX+91,startPositionY, color);

	}
	if(word == 5){
		letters('p',startPositionX,startPositionY, color);
		letters('o',startPositionX+13,startPositionY, color);
		letters('w',startPositionX+26,startPositionY, color);
		letters('e',startPositionX+39,startPositionY, color);
		letters('r',startPositionX+52,startPositionY, color);

		letters('w',startPositionX+78,startPositionY, color);
		letters('h',startPositionX+91,startPositionY, color);
		letters('t',startPositionX+104,startPositionY, color);

	}
	if(word == 6){
		letters('e',startPositionX,startPositionY, color);
		letters('n',startPositionX+13,startPositionY, color);
		letters('d',startPositionX+26,startPositionY, color);

		letters('g',startPositionX+47,startPositionY, color);
		letters('a',startPositionX+60,startPositionY, color);
		letters('m',startPositionX+74,startPositionY, color);
		letters('e',startPositionX+86,startPositionY, color);
	}
	if(word == 7){
		letters('h',startPositionX,startPositionY, color);
		letters('i',startPositionX+13,startPositionY, color);
		letters('g',startPositionX+26,startPositionY, color);
		letters('h',startPositionX+39,startPositionY, color);

		letters('s',startPositionX+66,startPositionY, color);
		letters('c',startPositionX+78,startPositionY, color);
		letters('o',startPositionX+91,startPositionY, color);
		letters('r',startPositionX+104,startPositionY, color);
		letters('e',startPositionX+117,startPositionY, color);
	}
	if(word == 8){
		letters('y',startPositionX,startPositionY, color);
		letters('o',startPositionX+13,startPositionY, color);
		letters('u',startPositionX+26,startPositionY, color);
		letters('r',startPositionX+39,startPositionY, color);

		letters('s',startPositionX+66,startPositionY, color);
		letters('c',startPositionX+78,startPositionY, color);
		letters('o',startPositionX+91,startPositionY, color);
		letters('r',startPositionX+104,startPositionY, color);
		letters('e',startPositionX+117,startPositionY, color);
	}

	if(word == 9){
		letters('e',startPositionX,startPositionY, color);
		letters('r',startPositionX+13,startPositionY, color);
	}
	if(word == 10){
		letters('e',startPositionX,startPositionY, color);
		letters('n',startPositionX+13,startPositionY, color);
		letters('e',startPositionX+26,startPositionY, color);
		letters('m',startPositionX+39,startPositionY, color);
		letters('y',startPositionX+52,startPositionY, color);
	}
	if(word == 11){
		letters('a',startPositionX,startPositionY, color);
		letters('s',startPositionX+13,startPositionY, color);
		letters('t',startPositionX+26,startPositionY, color);
		letters('e',startPositionX+39,startPositionY, color);
		letters('r',startPositionX+52,startPositionY, color);
		letters('o',startPositionX+65,startPositionY, color);
		letters('i',startPositionX+78,startPositionY, color);
		letters('d',startPositionX+91,startPositionY, color);
	}
}
void numberText(int x, int y, int number,int color){
	//1
	int32_t i,j,k;
	int32_t sign2 = 219;
	//0
	if (48 == number){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+3+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+3+i,y+6);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+2,y+1+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+9,y+1+i);
		printf("%c%c",sign2,sign2);
		}
	}
	//1
	if (49 == number){
		fgcolor(color);
		gotoxy(x+2,y+1);
		printf("%c%c",sign2,sign2);
		for (i=0;i<=3;i++){
		gotoxy(x+3+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+3+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+5,y+1+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y+6);
		printf("%c",sign2);
		}

	}//2
	if (50 == number){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=5;i++){
		gotoxy(x+1,y+1);
		printf("%c%c",sign2,sign2);
		}
		gotoxy(x+1,y+2);
		printf("%c",sign2);

		for (i=0;i<=2;i++){
		gotoxy(x+7+i,y+1);
		printf("%c",sign2);
		}
		gotoxy(x+8,y+2);
		printf("%c%c",sign2,sign2);
		for (i=0;i<=2;i++){
		gotoxy(x+6+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+3+i,y+4);
		printf("%c",sign2);
		}
		gotoxy(x+2,y+5);
		printf("%c%c",sign2,sign2);
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}



	}
	//3
	if (51 == number){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y);
		printf("%c",sign2);
		}

		gotoxy(x+7,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+7,y+2);
		printf("%c%c",sign2,sign2);
		gotoxy(x+7,y+3);
		printf("%c%c",sign2,sign2);
		gotoxy(x+7,y+4);
		printf("%c%c",sign2,sign2);
		gotoxy(x+7,y+5);
		printf("%c%c",sign2,sign2);


		for (i=0;i<=5;i++){
		gotoxy(x+3+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y+6);
		printf("%c",sign2);
		}

	}
	//4
	if (52 == number){
		fgcolor(color);
		for (i=0;i<=3;i++){
		gotoxy(x+1,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+8,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+3+i,y+3);
		printf("%c%c",sign2,sign2);
		}


	}
	//5
	if (53 == number){
		fgcolor(color);
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}

		gotoxy(x+1,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+1,y+2);
		printf("%c%c",sign2,sign2);

		gotoxy(x+8,y+4);
		printf("%c%c",sign2,sign2);
		gotoxy(x+8,y+5);
		printf("%c%c",sign2,sign2);

	}
	//6
	if (54 == number){
		fgcolor(color);
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}

		gotoxy(x+1,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+1,y+2);
		printf("%c%c",sign2,sign2);

		gotoxy(x+8,y+4);
		printf("%c%c",sign2,sign2);
		gotoxy(x+8,y+5);
		printf("%c%c",sign2,sign2);

		gotoxy(x+1,y+4);
		printf("%c%c",sign2,sign2);
		gotoxy(x+1,y+5);
		printf("%c%c",sign2,sign2);
	}
	//7
	if (55 == number){
		fgcolor(color);
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y);
		printf("%c",sign2);
		}

		for (i=0;i<=5;i++){
		gotoxy(x+3+i,y+6-i);
		printf("%c%c",sign2,sign2);
		}
	}
	//8
	if (56 == number){
		fgcolor(color);
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}

		gotoxy(x+1,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+1,y+2);
		printf("%c%c",sign2,sign2);

		gotoxy(x+8,y+4);
		printf("%c%c",sign2,sign2);
		gotoxy(x+8,y+5);
		printf("%c%c",sign2,sign2);

		gotoxy(x+8,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+8,y+2);
		printf("%c%c",sign2,sign2);

		gotoxy(x+1,y+4);
		printf("%c%c",sign2,sign2);
		gotoxy(x+1,y+5);
		printf("%c%c",sign2,sign2);
	}
	//9
	if (57 == number){
		fgcolor(color);
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=8;i++){
		gotoxy(x+1+i,y+3);
		printf("%c",sign2);
		}
		gotoxy(x+1,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+1,y+2);
		printf("%c%c",sign2,sign2);

		gotoxy(x+8,y+1);
		printf("%c%c",sign2,sign2);
		gotoxy(x+8,y+2);
		printf("%c%c",sign2,sign2);

		for (i=0;i<=2;i++){
		gotoxy(x+8,y+4+i);
		printf("%c%c",sign2,sign2);
		}

	}
	}
void signText(int x, int y, int sign,int color){


	int32_t i,j,k;
	int32_t sign2 = 219;
	//!
	if (0 == sign){
		fgcolor(color);
		for (i=0;i<=4;i++){
		gotoxy(x+5,y+i);
		printf("%c%c",sign2,sign2);
		}

		gotoxy(x+5,y+6);
		printf("%c%c",sign2,sign2);
		}
	//:)
	if (1 == sign){
		fgcolor(color);
		for (i=0;i<=1;i++){
		gotoxy(x+2,y+i+1);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+7,y+i+1);
		printf("%c%c",sign2,sign2);
		}


		gotoxy(x+1,y+4);
		printf("%c%c",sign2,sign2);


		gotoxy(x+8,y+4);
		printf("%c%c",sign2,sign2);

		for (i=0;i<=4;i++){
		gotoxy(x+3+i,y+5);
		printf("%c",sign2);
		}
	}

	// /
	if (2 == sign){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+1+i,y-i+6);
		printf("%c%c",sign2,sign2);
		}
	}

	// ->
	if (3 == sign){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+6,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=5;i++){
		gotoxy(x+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+8,y+1+i);
		printf("%c",sign2);
		}
		for (i=0;i<=2;i++){
		gotoxy(x+9,y+2+i);
		printf("%c",sign2);
		}
		gotoxy(x+10,y+3);
		printf("%c",sign2);
	}
}
void boxText(int x, int y,int color){
	int32_t sign3 = 178;
	int32_t i, j, k;
	fgcolor(color);

	for (i=0;i<=78;i++){
	gotoxy(x+i,y-2);
	printf("%c",sign3);
	}
	for (i=0;i<=78;i++){
	gotoxy(x+i,y-2+10);
	printf("%c",sign3);
	}
	for (i=0;i<=8;i++){
	gotoxy(x,y-1+i);
	printf("%c%c",sign3,sign3);
	}
	for (i=0;i<=8;i++){
	gotoxy(x+77,y-1+i);
	printf("%c%c",sign3,sign3);
	}
}
void letters(char q,int x, int y,int color){

	int32_t sign1 = 254;
	int32_t sign2 = 219;
	int32_t i, j, k;

	//A
	if (q == 'a'){
		fgcolor(color);
		gotoxy(x+4,y);
		printf("%c%c%c",sign2,sign2,sign2);
		for (i=1;i<=6;i++){
		gotoxy(x-i+4,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=1;i<=6;i++){
		gotoxy(x+i+5,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x-3+i+5,y+3);
		printf("%c",sign2);
		}
	}
	//C
	if (q == 'c'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+5+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+2+i,y+1);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+1+i,y+2);
		printf("%c",sign2);
		}
		for (i=0;i<=2;i++){
		gotoxy(x+i+1,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+1+i,y+4);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+2+i,y+5);
		printf("%c",sign2);
		}
		for (i=0;i<=7;i++){
		gotoxy(x+4+i,y+6);
		printf("%c",sign2);
		}
	}



	//D
	if (q == 'd'){
		fgcolor(color);
		gotoxy(x,y);
		printf("%c",254);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+1+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+6+i,y+1);
		printf("%c",sign2);
		}
		for (i=0;i<=2;i++){
		gotoxy(x+8+i,y+2);
		printf("%c",sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+9+i,y+3);
		printf("%c",sign2);
		}
		for (i=0;i<=2;i++){
		gotoxy(x+8+i,y+4);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+6+i,y+5);
		printf("%c",sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}
	}
	//E
	if (q == 'e'){
		fgcolor(color);
		for (i=1;i<=9;i++){
		gotoxy(x+i,y);
		printf("%c",sign2);
		}
		for (i=1;i<=9;i++){
		gotoxy(x+i,y+6);
		printf("%c",sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=1;i<=6;i++){
		gotoxy(x+i,y+3);
		printf("%c",sign2);
		}

	}
	//F
	if (q == 'f'){
		fgcolor(color);
		for (i=1;i<=9;i++){
		gotoxy(x+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=1;i<=6;i++){
		gotoxy(x+i,y+3);
		printf("%c",sign2);
		}

	}
	//G
	if (q == 'g'){
		fgcolor(color);
		for (i=2;i<=8;i++){
		gotoxy(x+i,y);
		printf("%c",sign2);
		}
		for (i=1;i<=2;i++){
		gotoxy(x+i,y+1);
		printf("%c",sign2);
		}
		for (i=1;i<=2;i++){
		gotoxy(x+i,y+2);
		printf("%c",sign2);
		}

		for (i=1;i<=2;i++){
		gotoxy(x+i,y+3);
		printf("%c",sign2);
		}
		for (i=1;i<=2;i++){
		gotoxy(x+i,y+4);
		printf("%c",sign2);
		}
		for (i=1;i<=2;i++){
		gotoxy(x+i,y+5);
		printf("%c",sign2);
		}

		for (i=2;i<=8;i++){
		gotoxy(x+i,y+6);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+i+8,y+4);
		printf("%c",sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+i+8,y+5);
		printf("%c",sign2);
		}

		for (i=0;i<=3;i++){
		gotoxy(x+i+5,y+3);
		printf("%c",sign2);
		}
	}


	//H
	if (q == 'h'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+9,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y+3);
		printf("%c",sign2);
		}
	}

	//I
	if (q == 'i'){
		fgcolor(color);
		for (i=0;i<=10;i++){
		gotoxy(x+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+4,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=10;i++){
		gotoxy(x+i,y+6);
		printf("%c",sign2);
		}
	}

	//J
	if (q == 'j'){
		fgcolor(color);
		for (i=0;i<=5;i++){
		gotoxy(x+5+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+7,y+i+1);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+i+6,y+5);
		printf("%c",sign2);
		}
		for (i=0;i<=4;i++){
		gotoxy(x+i+2,y+6);
		printf("%c",sign2);
		}
	}

	//L
	if (q == 'l'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y+6);
		printf("%c",sign2);
		}

	}
	//M
	if (q == 'm'){
		fgcolor(color);
		for (i=0;i<=2;i++){
		gotoxy(x+2+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+1+i,y+1);
		printf("%c",sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+i,y+2);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x,y+3+i);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+5+i,y+2);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+7+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=2;i++){
		gotoxy(x+7+i,y+1);
		printf("%c",sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+9+i,y+2);
		printf("%c",sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+10,y+3+i);
		printf("%c",sign2);
		}

	}

	//N
	if (q == 'n'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (j=0;j<=5;j++){
			for (i=0;i<=1;i++){
				gotoxy(x+2+j,y+i+j);
				printf("%c",sign2);
			}
		}
		gotoxy(x+8,y+6);
		printf("%c",sign2);
		for (i=0;i<=6;i++){
		gotoxy(x+9,y+i);
		printf("%c%c",sign2,sign2);
		}

	}

	//O
	if (q == 'o'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y);
		printf("%c",sign2);
		}

		for (i=0;i<=2;i++){
		gotoxy(x+i,y+1);
		printf("%c",sign2);
		}
		for (i=0;i<=2;i++){
		gotoxy(x+8+i,y+1);
		printf("%c",sign2);
		}

		for (i=0;i<=3;i++){
		gotoxy(x,y+2+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=3;i++){
		gotoxy(x+9,y+2+i);
		printf("%c%c",sign2,sign2);
		}

		gotoxy(x+2,y+5);
		printf("%c",sign2);
		gotoxy(x+8,y+5);
		printf("%c",sign2);

		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y+6);
		printf("%c",sign2);
		}
	}

	//P
	if (q == 'p'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}

		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y);
		printf("%c",sign2);
		}

		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y+4);
		printf("%c",sign2);
		}

		for (i=0;i<=2;i++){
		gotoxy(x+9,y+1+i);
		printf("%c%c",sign2,sign2);
		}
	}

	//R
	if (q == 'r'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x,y+i);
		printf("%c%c",sign2,sign2);
		}

		for (i=0;i<=6;i++){
		gotoxy(x+2+i,y);
		printf("%c",sign2);
		}

		for (i=0;i<=7;i++){
		gotoxy(x+2+i,y+3);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+9,y+1+i);
		printf("%c%c",sign2,sign2);
		}


		gotoxy(x+3,y+4);
		printf("%c%c%c",sign2,sign2,sign2);

		gotoxy(x+5,y+5);
		printf("%c%c%c",sign2,sign2,sign2);

		gotoxy(x+7,y+6);
		printf("%c%c%c%c",sign2,sign2,sign2,sign2);
	}

	//S
	if (q == 's'){
		fgcolor(color);
		for (i=0;i<=6;i++){
		gotoxy(x+4+i,y);
		printf("%c",sign2);
		}
		gotoxy(x+2,y+1);
		printf("%c%c%c",sign2,sign2,sign2);
		gotoxy(x+3,y+2);
		printf("%c%c%c",sign2,sign2,sign2);
		gotoxy(x+5,y+3);
		printf("%c%c%c",sign2,sign2,sign2);
		gotoxy(x+7,y+4);
		printf("%c%c%c",sign2,sign2,sign2);
		gotoxy(x+5,y+5);
		printf("%c%c%c%c",sign2,sign2,sign2,sign2);

		for (i=0;i<=5;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}
	}

	//T
	if (q == 't'){
		fgcolor(color);
		for (i=0;i<=11;i++){
		gotoxy(x+i,y);
		printf("%c",sign2);
		}
		for (i=0;i<=5;i++){
		gotoxy(x+5,y+i+1);
		printf("%c%c",sign2,sign2);
		}

	}

	//U
	if (q == 'u'){
		fgcolor(color);
		for (i=0;i<=5;i++){
		gotoxy(x+1,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=5;i++){
		gotoxy(x+7,y+i);
		printf("%c%c",sign2,sign2);
		}
		for (i=0;i<=7;i++){
		gotoxy(x+1+i,y+6);
		printf("%c",sign2);
		}

	}
	//W
	if (q == 'w'){
		fgcolor(color);
		for (i=0;i<=1;i++){
		gotoxy(x,y+i);
		printf("%c",sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+1,y+i+1);
		printf("%c",sign2);
		}

		for (i=0;i<=3;i++){
		gotoxy(x+2,y+i+2);
		printf("%c",sign2);
		}
		for (i=0;i<=1;i++){
		gotoxy(x+3,y+i+5);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+4,y+i+3);
		printf("%c",sign2);
		}

		gotoxy(x+5,y+2);
		printf("%c",sign2);

		for (i=0;i<=1;i++){
		gotoxy(x+6,y+i+3);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+7,y+i+5);
		printf("%c",sign2);
		}

		for (i=0;i<=3;i++){
		gotoxy(x+8,y+i+2);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+9,y+i+1);
		printf("%c",sign2);
		}

		for (i=0;i<=1;i++){
		gotoxy(x+10,y+i);
		printf("%c",sign2);
		}
	}


	//Y
	if (q == 'y'){
		fgcolor(color);
		gotoxy(x,y);
		printf("%c%c",sign2,sign2);

		gotoxy(x+1,y+1);
		printf("%c%c",sign2,sign2);

		gotoxy(x+1,y+2);
		printf("%c%c%c%c",sign2,sign2,sign2,sign2);

		for (i=0;i<=3;i++){
			gotoxy(x+4,y+3+i);
			printf("%c%c%c",sign2,sign2,sign2);
		}

		gotoxy(x+9,y);
		printf("%c%c",sign2,sign2);

		gotoxy(x+8,y+1);
		printf("%c%c",sign2,sign2);

		gotoxy(x+6,y+2);
		printf("%c%c%c%c",sign2,sign2,sign2,sign2);
	}
}


