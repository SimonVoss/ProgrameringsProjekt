#include "Bullets.h"
#include "ex2.h"

void bulletSpaceship(int32_t x, int32_t y, bulletPos *a){
	a->x = x<<8;
	a->y = y<<8;
	gotoxy(x,y);
	fgcolor(2);
	printf("%c",254);
}

void bulletEnemy(int32_t x, int32_t y, bulletPos *a){
	a->x = x<<8;
	a->y = y<<8;
	gotoxy(x,y);
	fgcolor(13);
	printf("%c",254);
}

void updateBulletFriendly(bulletPos *a){
	int32_t x = a->x>>8;
	int32_t y = a->y>>8;
	if (y<123 && y>2){
		gotoxy(x,y);
		fgcolor(0);
		printf("%c",254);
		a->x=a->x;
		a->y=a->y - (1<<8);
		gotoxy(x,y-1);
		fgcolor(2);
		printf("%c",254);
	}else {
		gotoxy(x,y);
		fgcolor(0);
		printf("%c",254);
	}
}

void updateBulletEnemy(bulletPos *a){
	int32_t x = a->x>>8;
	int32_t y = a->y>>8;
	if (y<123 && y>2){
		gotoxy(x,y);
		fgcolor(0);
		printf("%c",254);
		a->x=a->x;
		a->y=a->y + (1<<8);
		gotoxy(x,y+1);
		fgcolor(13);
		printf("%c",254);
	}else {
		gotoxy(x,y);
		fgcolor(0);
		printf("%c",254);
	}
}
