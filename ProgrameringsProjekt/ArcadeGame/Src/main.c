#include "include.h"



static int16_t flagF, flagE, flagR = 0;
static int32_t c1, c2, c3 = 0<<8;
static int32_t score = 0;




//Initialicering af Programmer Start



void TIM1_BRK_TIM15_IRQHandler(void) {
	c1=c1+(1<<8);
	c2=c2+(1<<8);
	c3=c3+(1<<8);
	TIM15->SR &= ~0x0001; //s Clear interrupt bit
}


//Initialicering af Programmer Slut


int main(void) {
	//Initialicering af forbindelse
	uart_init(500000);
	int8_t timeOut = 0;
	int8_t aSpawn = 0;
	color(15,0);
	//Initialicering af Programmer i main Start
	config();
	clockInit();
	//BuzzConfig();
	makeBoard();
	goodShip player;
	createPlayer(&player);
	badShip enemyA[20];
	initArrayEnemy(enemyA, 20);
	bullet bulletE[50];
	bullet bulletF[50];
	initArrayBullets(bulletE, 50);
	initArrayBullets(bulletF, 50);
	bigRock astroidA[5];
	initArrayAstroid(astroidA, 5);

	//Initialicering af Programmer i main Slut

	//Hentning af Statisk info Start
	//buzz(200);
//	for(int i = 0;i<100000;i++);
//	moveAstroid(&astroidA);
	//Hentning af Statisk info Slut

	//Klad af funktioner
	while(1){
		int8_t button = buttonRead();
		int8_t joystickWay = adcRead();
		clockCounter(score, &c1, &c2, &c3, &flagF, &flagE, &flagR);
		//Hentning af kontinuerlig info Start
		if (flagF == 1){
			movePlayer(&player, joystickWay);
			if(button==1) {
				if(timeOut==0) {
					bulletSpaceship(player.x, player.y-1, bulletF);
					timeOut++;
				}
			}
			if(timeOut>0 && timeOut<7) {
				timeOut++;
			} else {
				timeOut=0;
			}
			updateBulletFriendly(bulletF);
			updateBulletEnemy(bulletE);
			score = bulletHitEnemy(bulletF, enemyA, score);
			bulletHitPlayer(bulletE, &player);
			bulletHitAstroid(bulletE, astroidA);
			bulletHitAstroid(bulletF, astroidA);
			collision(enemyA, astroidA, &player);
			if(player.life==0) {
				playerRemove(player.x,player.y);
				while(1) {}
			}
			flagF = 0;
		}
		if (flagE == 1){
			moveEnemy(enemyA, &player);
			moveAstroid(astroidA);
			flagE = 0;
		}
		if (flagR == 1) {
			bulletEnemy(enemyA, bulletE);
			if(aSpawn < 4) {
//				createAstroid(astroidA);
				createEnemy(enemyA);
				aSpawn++;
			} else {
				createAstroid(astroidA);
				aSpawn=0;
			}
			flagR = 0;
		}
		fgcolor(15);
		gotoxy(3,2);
		printf("%d",score);
		gotoxy(3,3);
		printf("%d",player.life);

		//Hentning af kontinuerlig info Slut


//	Testområde

	}
}
