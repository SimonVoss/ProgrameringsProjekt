#include "Bullets.h"
#include "ex2.h"

void bulletSpaceship(int32_t x, int32_t y, bulletPos *a, vector_t *vec){
	a->x = x<<8;
	a->y = y<<8;
	vec->x = 0<<8;
	vec->y = -2<<8;
	gotoxy(x,y);
	fgcolor(2);
	printf("%c",254);
}

void bulletEnemy(int32_t x, int32_t y, bulletPos *a, vector_t *vec){
	a->x = x<<8;
	a->y = y<<8;
	vec->x = 0<<8;
	vec->y = 2<<8;
	gotoxy(x,y);
	fgcolor(13);
	printf("%c",254);
}

void updateBullet(bulletPos *a, vector_t *vec){
	int32_t x = a->x>>8;
	int32_t y = a->y>>8;
	a->x = a->x+vec->x;
	a->y = a->y+vec->y;
	int32_t newX = a->x>>8;
	int32_t newY = a->y>>8;
	if (y<123 && y>2){
		gotoxy(x,y);
		fgcolor(0);
		printf("%c",254);
		gotoxy(newX,newY);
		fgcolor(2);
		printf("%c",254);
	}else {
		gotoxy(x,y);
		fgcolor(0);
		printf("%c",254);
	}
}
