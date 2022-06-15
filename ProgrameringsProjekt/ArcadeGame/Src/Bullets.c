#include "bullets.h"

void initArrayBullets(bullet a[], int8_t length){
	int8_t i;
	for (i=0; i<length;i++){
		a[i].x = 0;
		a[i].y = 0;
		a[i].alive = 0;
		a[i].vec.x = 0;
		a[i].vec.y = 0;
	}
}


void bulletSpaceship(int8_t x, int8_t y, bullet a[]){
	int8_t i;
	for (i=0 ; i<50; i++){
		if (a[i].alive == 0){
			a[i].x = x<<8;
			a[i].y = y<<8;
			a[i].alive = 1<<8;
			a[i].vec.x = 0<<8;
			a[i].vec.y = -2<<8;
			gotoxy(x,y);
			fgcolor(2);
			printf("%c",254);
			return;
		}
	}

}

void bulletEnemy(int8_t x, int8_t y, bullet a[]){
	int32_t i;
	for (i=0 ; i<50; i++){
		if (a[i].alive == 0){
			a[i].x = x<<8;
			a[i].y = y<<8;
			a[i].alive = 1<<8;
			a[i].vec.x = 0<<8;
			a[i].vec.y = 2<<8;
			gotoxy(x,y);
			fgcolor(13);
			printf("%c",254);
			break;
		}
	}
}

void updateBulletFriendly(bullet a[]){
	int32_t i;
	for (i=0 ; i<50; i++){
		if (a[i].alive==0){
			return;
		}
		int32_t x = a[i].x>>8;
		int32_t y = a[i].y>>8;
		a[i].x = a[i].x+a[i].vec.x;
		a[i].y = a[i].y+a[i].vec.y;
		int32_t newX = a[i].x>>8;
		int32_t newY = a[i].y>>8;
		if (y<122 && y>3){
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
			a[i].alive = 0;
		}
	}

}

void updateBulletEnemy(bullet a[]){
	int32_t i;
	for (i=0 ; i<50; i++){
		if (a[i].alive==0){
			return;
		}
		int32_t x = a[i].x>>8;
		int32_t y = a[i].y>>8;
		a[i].x = a[i].x+a[i].vec.x;
		a[i].y = a[i].y+a[i].vec.y;
		int32_t newX = a[i].x>>8;
		int32_t newY = a[i].y>>8;
		if (y<122 && y>3){
			gotoxy(x,y);
			fgcolor(0);
			printf("%c",254);
			gotoxy(newX,newY);
			fgcolor(13);
			printf("%c",254);
		}else {
			gotoxy(x,y);
			fgcolor(0);
			printf("%c",254);
			a[i].alive = 0;
		}
	}

}
