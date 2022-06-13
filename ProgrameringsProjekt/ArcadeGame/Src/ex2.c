#define ESC 0x1B
#include "ex2.h"

void clrsrc(void) {
	printf("%c[2J%c[H", 0x1B,0x1B);
}

void clreol(void) {
	printf("%c[K", 0x1B);
}

void gotoxy(int32_t x, int32_t y) {
	printf("%c[%d;%dH", 0x1B,y,x);
}

void underline(int32_t on) {
	if (on==1) {
		printf("%c[04m", 0x1B);
	}
	if (on==0) {
		printf("%c[24m", 0x1B);
	}
}

void blink(int32_t on) {
	if (on==1) {
		printf("%c[05m", 0x1B);
	}
	if (on==0) {
		printf("%c[25m", 0x1B);
	}
}

void inverse(int32_t on) {
	if (on==1) {
		printf("%c[07m", 0x1B);
	}
	if (on==0) {
		printf("%c[27m", 0x1B);
	}
}

void window(int32_t x1, int32_t y1, int32_t x2, int32_t y2, char title[], int32_t style) {
	int length = sizeof(title)/sizeof(title[0]);
	char tline[x2-x1-6-length+1];
	char bline[x2-x1-2+1];
	char tl[4], tm[3];
	char tr, vert, hori, bl, br;
	if (style == 1) {
		tl[0] = 218;
		tl[1] = 180;
		tl[2] = 219;
		tl[3] = 0;
		tm[0] = 219;
		tm[1] = 195;
		tm[2] = 0;
		tr = 191;
		vert = 179;
		hori = 196;
		bl = 192;
		br = 217;
	}
	if (style == 2) {
		tl[0] = 201;
		tl[1] = 185;
		tl[2] = 219;
		tl[3] = 0;
		tm[0] = 219;
		tm[1] = 204;
		tm[2] = 0;
		tr = 187;
		vert = 186;
		hori = 205;
		bl = 200;
		br = 188;
	}
	color(0,7);
	clrsrc();
	int i;
	for(i = 0; i < x2-x1-6-length+1; i++) {
		tline[i] = hori;
	}
	for(i = 0; i < x2-x1-2+1; i++) {
		bline[i] = hori;
	}
	printf("%s%s%s%s%c\n", tl,title,tm,tline,tr);
	for(i = 1; i <= y2-2; i++) {
		gotoxy(x1,y1+i);
		printf("%c",vert);
		gotoxy(x2,y1+i);
		printf("%c\n",vert);
	}
	printf("%c%s%c\n",bl,bline,br);
}
