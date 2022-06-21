#include "collision.h"

void collision(badShip a[], bigRock b[], goodShip *c) {
	int8_t i;
	for(i = 0; i < 20; i++) {
		if(a[i].alive==1) {
			if(a[i].y>=c->y && a[i].x-4 <= c->x+4 && a[i].x+4 >= c->x-4) {
				enemyRemove(a[i].x,a[i].y);
				a[i].x=0;
				a[i].y=0;
				a[i].alive=0;
				c->life--;
				GPIOB->ODR &= ~(0x0001 << 4); //Red on
				GPIOC->ODR |= (0x0001 << 7); //Green off
				GPIOA->ODR |= (0x0001 << 9); //Blue off
				playerDraw(c->x,c->y);
			}
		}
	}
	for(i = 0; i < 5; i++) {
		if(b[i].alive==1) {
			if(b[i].y+3>=c->y && b[i].x-4 <= c->x+4 && b[i].x+4 >= c->x-4) {
				astroidRemove(b[i].x,b[i].y);
				b[i].x=0;
				b[i].y=0;
				b[i].alive=0;
				c->life--;
				GPIOB->ODR &= ~(0x0001 << 4); //Red on
				GPIOC->ODR |= (0x0001 << 7); //Green off
				GPIOA->ODR |= (0x0001 << 9); //Blue off
				playerDraw(c->x,c->y);
			}
		}
	}
}
