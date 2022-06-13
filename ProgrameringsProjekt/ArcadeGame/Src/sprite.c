#include "sprite.h"

void player(int32_t x, int32_t y) {
	fgcolor(15);
	gotoxy(x,y);
	printf("%c",219);
	gotoxy(x-3,y+1);
	printf("%c  %c  %c",219,219,219);
	gotoxy(x-3,y+2);
	printf("%c %c%c%c %c",219,219,219,219,219);
	gotoxy(x-3,y+3);
	printf("%c%c%c",219,219,219);
	fgcolor(4);
	printf("%c",219);
	fgcolor(15);
	printf("%c%c%c",219,219,219);
	gotoxy(x-2,y+4);
	printf("%c",219);
	fgcolor(4);
	printf("%c%c%c",219,219,219);
	fgcolor(15);
	printf("%c",219);
	gotoxy(x-3,y+5);
	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(x-4,y+6);
	printf("%c%c%c %c %c%c%c",219,219,219,219,219,219,219);
	gotoxy(x-4,y+7);
	printf("%c%c     %c%c",219,219,219,219);
	gotoxy(x-4,y+8);
	printf("%c       %c",219,219);

}


void enemy(int32_t x, int32_t y) {
	fgcolor(1);
	gotoxy(x-3,y);
	printf("%c     %c",219,219);
	gotoxy(x-3,y-1);
	printf("%c     %c",219,219);
	gotoxy(x-3,y-2);
	printf("%c %c %c %c",219,219,219,219);
	gotoxy(x-3,y-3);
	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	gotoxy(x-3,y-4);
	printf("%c%c",219,219);
	fgcolor(11);
	printf("%c",219);
	fgcolor(1);
	printf("%c",219);
	fgcolor(11);
	printf("%c",219);
	fgcolor(1);
	printf("%c%c",219,219);
	gotoxy(x-2,y-5);
	printf("%c%c",219,219);
	fgcolor(11);
	printf("%c",219);
	fgcolor(1);
	printf("%c%c",219,219);
	gotoxy(x-3,y-6);
	printf("%c%c %c %c%c",219,219,219,219,219);
	gotoxy(x-4,y-7);
	printf("%c%c     %c%c",219,219,219,219);
	gotoxy(x-4,y-8);
	printf("%c       %c",219,219);
}


void astroid(int32_t x, int32_t y) {
	fgcolor(7);
	gotoxy(x,y-3);
	printf("%c%c",219,219);
	gotoxy(x-3,y-2);
	printf("%c%c%c",219,219,219);
	fgcolor(8);
	printf("%c%c",219,219);
	fgcolor(7);
	printf("%c%c",219,219);
	gotoxy(x-4,y-1);
	printf("%c",219);
	fgcolor(8);
	printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	fgcolor(7);
	printf("%c",219);
	gotoxy(x-4,y);
	printf("%c",219);
	fgcolor(8);
	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
	fgcolor(7);
	printf("%c",219);
	gotoxy(x-3,y+1);
	printf("%c%c",219,219);
	fgcolor(8);
	printf("%c%c%c%c",219,219,219,219);
	fgcolor(7);
	printf("%c%c",219,219);
	gotoxy(x-1,y+2);
	printf("%c%c%c%c",219,219,219,219);
}
