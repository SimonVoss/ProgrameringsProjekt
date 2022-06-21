#include "missile.h"

void createMissile(boomRod *missile) {
	missile->x=0;
	missile->y=0;
	missile->alive=0;
	missile->vec.x=0;
	missile->vec.y=0;
}

void missileShoot(boomRod *missile, goodShip *player) {
	missile->x=player->x;
	missile->y=player->y-1;
	missile->alive=1;
	missile->vec.x=0;
	missile->vec.y=-1;
	missileDraw(missile->x,missile->y);
}

void missileShift(boomRod *missile) {
	gotoxy(missile->x,missile->y-1);
	fgcolor(8);
	printf("%c",219);
	gotoxy(missile->x,missile->y+1);
	fgcolor(9);
	printf("%c",219);
	gotoxy(missile->x,missile->y+2);
	fgcolor(0);
	printf("%c",219);
}

int32_t missileUpdate(boomRod *missile, badShip a[], bigRock b[], int32_t score) {
	int8_t i;
	for(i = 0; i < 20; i++) {
		if(a[i].alive==1) {
			if(missile->alive==1) {
				if(missile->y==a[i].y && missile->x>=a[i].x-4 && missile->x<=a[i].x+4) {
					a[i].alive=0;
					enemyRemove(a[i].x,a[i].y);
					a[i].x=0;
					a[i].y=0;
					missileRemove(missile->x,missile->y);
					missile->x=0;
					missile->y=0;
					missile->alive=0;
					missile->vec.x=0;
					missile->vec.y=0;
					score += 20;
				}
			}
		}
	}
	for(i = 0; i < 5; i++) {
		if(b[i].alive==1) {
			if(missile->y<=b[i].y+2 && missile->x>=b[i].x-4 && missile->x<=b[i].x+4) {
				b[i].alive=0;
				astroidRemove(b[i].x,b[i].y);
				b[i].x=0;
				b[i].y=0;
				missileRemove(missile->x,missile->y);
				missile->x=0;
				missile->y=0;
				missile->alive=0;
				missile->vec.x=0;
				missile->vec.y=0;
			}
		}
	}
	if(missile->alive==1) {
		if(missile->y > 3) {
			missile->y-=1;
			missileShift(missile);
		} else {
			missileRemove(missile->x,missile->y-1);
			missile->x=0;
			missile->y=0;
			missile->alive=0;
			missile->vec.x=0;
			missile->vec.y=0;
		}
	}
	return score;
}

