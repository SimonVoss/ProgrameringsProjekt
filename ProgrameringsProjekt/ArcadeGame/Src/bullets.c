#include <bullets.h>

void initArrayBullets(bullet a[], int8_t length){
	int8_t i;
	for (i=0; i<length;i++){
		a[i].x = 0;
		a[i].y = 0;
		a[i].alive = 0;
		a[i].enemy = 0;
		a[i].vec.x = 0;
		a[i].vec.y = 0;
	}
}


void bulletSpaceship(int16_t x, int16_t y, bullet a[]){
	int8_t i;
	for (i=0 ; i<50; i++){
		if (a[i].alive == 0){
			a[i].x = x<<8;
			a[i].y = y<<8;
			a[i].alive = 1;
			a[i].vec.x = 0<<8;
			a[i].vec.y = -2<<8;
			gotoxy(x,y);
			fgcolor(10);
			printf("%c",254);
			break;
		}
	}

}

void bulletEnemy(badShip b[], bullet a[]){
	int32_t i,j;
	for(j = 0; j < 20; j++) {
		if(b[j].alive == 1) {
			for (i=0 ; i<50; i++){
				if (a[i].alive == 0){
					a[i].x = b[j].x<<8;
					a[i].y = b[j].y<<8;
					a[i].alive = 1;
					a[i].enemy = 1;
					a[i].vec.x = 0<<8;
					a[i].vec.y = 2<<8;
					gotoxy(b[j].x,b[j].y);
					fgcolor(13);
					printf("%c",254);
					break;
				}
			}
		}
	}
}

void updateBulletFriendly(bullet a[]){
	int32_t i;
	for (i=0 ; i<50; i++){
		if (!(a[i].alive==0)){
			if(a[i].enemy==0) {
				int32_t x = a[i].x>>8;
				int32_t y = a[i].y>>8;
				a[i].x = a[i].x+a[i].vec.x;
				a[i].y = a[i].y+a[i].vec.y;
				int32_t newX = a[i].x>>8;
				int32_t newY = a[i].y>>8;
				if (newY<122 && newY>3 && newX>1 && newX<136){
					gotoxy(x,y);
					fgcolor(0);
					printf("%c",254);
					gotoxy(newX,newY);
					fgcolor(10);
					printf("%c",254);
				}else {
					gotoxy(x,y);
					fgcolor(0);
					printf("%c",254);
					a[i].alive = 0;
					a[i].x=0;
					a[i].y=0;
					a[i].vec.x=0;
					a[i].vec.y=0;
				}
			}
		}
	}
}

void updateBulletEnemy(bullet a[]){
	int8_t i;
	for (i=0 ; i<50; i++){
		if (a[i].alive==1){
			if(a[i].enemy==1) {
				int32_t x = a[i].x>>8;
				int32_t y = a[i].y>>8;
				a[i].x = a[i].x+a[i].vec.x;
				a[i].y = a[i].y+a[i].vec.y;
				int32_t newX = a[i].x>>8;
				int32_t newY = a[i].y>>8;
				if (newY<122 && newY>3 && newX>1 && newX<136){
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
					a[i].enemy = 0;
					a[i].x=0;
					a[i].y=0;
					a[i].vec.x=0;
					a[i].vec.y=0;
				}
			}
		}
	}
}

int32_t bulletHitEnemy(bullet a[], badShip b[], int32_t score) {
	int8_t i,j;
	for(i = 0; i < 50; i++) {
		if(a[i].alive==1) {
			if(a[i].enemy==0) {
				for(j = 0; j < 20; j++) {
					if(!(b[j].alive==0)) {
						if((a[i].y>>8)<=(b[j].y) && (a[i].y>>8)>=(b[j].y)-5 && (a[i].x>>8) >= (b[j].x)-4 && (a[i].x>>8) <= (b[j].x)+4) {
							b[j].alive=0;
							enemyRemove(b[j].x,b[j].y);
							b[j].x=0;
							b[j].y=0;
							a[i].alive = 0;
							gotoxy(a[i].x>>8,a[i].y>>8);
							fgcolor(0);
							printf("%c", 219);
							a[i].x=0;
							a[i].y=0;
							a[i].vec.x=0;
							a[i].vec.y=0;
							score += 20;
						}
					}
				}
			}
		}
	}
	return score;
}


void bulletHitPlayer(bullet a[], goodShip *b) {
	int8_t i;
	for(i = 0; i < 50; i++) {
		if(a[i].alive==1) {
			if((a[i].y>>8)>=b->y && (a[i].y>>8)<=b->y+5 && (a[i].x>>8)>=b->x-4 && (a[i].x>>8)<=b->x+4) {
				fgcolor(0);
				gotoxy(a[i].x>>8,a[i].y>>8);
				printf("%c",219);
				playerDraw(b->x,b->y);
				a[i].alive = 0;
				a[i].x=0;
				a[i].y=0;
				a[i].vec.x=0;
				a[i].vec.y=0;
				b->life--;
			}
		}
	}
}

void bulletHitAstroid(bullet a[], bigRock b[]) {
	int8_t i, j;
	for(i = 0; i < 50; i++) {
		if(a[i].alive==1) {
			for(j = 0; j < 5; j++) {
				if(b[j].alive==1) {
					if((a[i].y>>8)<=(b[j].y+2) && (a[i].y>>8)>=(b[j].y-3) && (a[i].x>>8) >= (b[j].x-4) && (a[i].x>>8) <= (b[j].x+4)) {
						fgcolor(0);
						gotoxy(a[i].x>>8,a[i].y>>8);
						printf("%c",219);
						astroidDraw(b[j].x,b[j].y);
						a[i].x=0;
						a[i].y=0;
						a[i].alive=0;
						a[i].enemy=0;
						a[i].vec.x=0;
						a[i].vec.y=0;
					}
				}
			}
		}
	}
}
void bulletGravity(bullet a[], bigRock b[]) {
	int8_t i, j;
	for(i = 0; i < 50; i++) {
		if(a[i].alive==1) {
			for(j = 0; j < 5; j++) {
				if(b[j].alive==1) {
					if(a[i].enemy == 1){
						if((a[i].y>>8)<=(b[j].y+7) && (a[i].y>>8)>=(b[j].y-8)){
							if (a[i].x>>8 == b[j].x+8){
								rotateVector(&a[i].vec,2);
							}else if (a[i].x>>8 == b[j].x+7){
								rotateVector(&a[i].vec,6);
							}else if (a[i].x>>8 == b[j].x+6){
								rotateVector(&a[i].vec,10);
							}else if (a[i].x>>8 == b[j].x+5){
								rotateVector(&a[i].vec,14);
							}else if (a[i].x>>8 == b[j].x+4){
								rotateVector(&a[i].vec,22);
							}else if (a[i].x>>8 == b[j].x+3){
								rotateVector(&a[i].vec,30);
							}else if (a[i].x>>8 == b[j].x+2){
								rotateVector(&a[i].vec,38);
							}else if (a[i].x>>8 == b[j].x+1){
								rotateVector(&a[i].vec,46);
							}else if (a[i].x>>8 == b[j].x-8){
								rotateVector(&a[i].vec,510);
							}else if (a[i].x>>8 == b[j].x-7){
								rotateVector(&a[i].vec,506);
							}else if (a[i].x>>8 == b[j].x-6){
								rotateVector(&a[i].vec,502);
							}else if (a[i].x>>8 == b[j].x-5){
								rotateVector(&a[i].vec,498);
							}else if (a[i].x>>8 == b[j].x-4){
								rotateVector(&a[i].vec,490);
							}else if (a[i].x>>8 == b[j].x-3){
								rotateVector(&a[i].vec,482);
							}else if (a[i].x>>8 == b[j].x-2){
								rotateVector(&a[i].vec,476);
							}else if (a[i].x>>8 == b[j].x-1){
								rotateVector(&a[i].vec,468);
							}

						}
					} else if (a[i].enemy == 0){
						if((a[i].y>>8)<=(b[j].y+7) && (a[i].y>>8)>=(b[j].y-8)){
							if (a[i].x>>8 == b[j].x-8){
								rotateVector(&a[i].vec,2);
							}else if (a[i].x>>8 == b[j].x-7){
								rotateVector(&a[i].vec,6);
							}else if (a[i].x>>8 == b[j].x-6){
								rotateVector(&a[i].vec,10);
							}else if (a[i].x>>8 == b[j].x-5){
								rotateVector(&a[i].vec,14);
							}else if (a[i].x>>8 == b[j].x-4){
								rotateVector(&a[i].vec,22);
							}else if (a[i].x>>8 == b[j].x-3){
								rotateVector(&a[i].vec,30);
							}else if (a[i].x>>8 == b[j].x-2){
								rotateVector(&a[i].vec,38);
							}else if (a[i].x>>8 == b[j].x-1){
								rotateVector(&a[i].vec,46);
							}else if (a[i].x>>8 == b[j].x+8){
								rotateVector(&a[i].vec,510);
							}else if (a[i].x>>8 == b[j].x+7){
								rotateVector(&a[i].vec,506);
							}else if (a[i].x>>8 == b[j].x+6){
								rotateVector(&a[i].vec,502);
							}else if (a[i].x>>8 == b[j].x+5){
								rotateVector(&a[i].vec,498);
							}else if (a[i].x>>8 == b[j].x+4){
								rotateVector(&a[i].vec,490);
							}else if (a[i].x>>8 == b[j].x+3){
								rotateVector(&a[i].vec,482);
							}else if (a[i].x>>8 == b[j].x+2){
								rotateVector(&a[i].vec,476);
							}else if (a[i].x>>8 == b[j].x+1){
								rotateVector(&a[i].vec,468);
							}

						}


					}
				}
			}
		}
	}
}


