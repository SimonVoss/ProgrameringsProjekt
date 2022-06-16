#include "include.h"



static int16_t flagF, flagE, flagR = 0;
static int32_t c1, c2, c3 = 0<<8;
static int32_t score = 0;




//Initialicering af Programmer Start



void TIM1_BRK_TIM15_IRQHandler(void) {
	c1=c1+(1<<8);
	c2=c2+(1<<8);
	c3=c3+(1<<8);
	TIM15->SR &= ~0x0001; // Clear interrupt bit
}


//Initialicering af Programmer Slut


int main(void) {
	//Initialicering af forbindelse
	uart_init(2060000);
//	int32_t i;
	int8_t timeOut = 0;
	int16_t buffer[512];
	char lives[7] = {'L','i','v','e','s',':','\0'};
	lcd_write_string(lives, &buffer,2*128);
	lcd_write_heart(1,3,&buffer,3*128);
	color(15,0);
	//Initialicering af Programmer i main Start
	config();
	clockInit();
	//BuzzConfig();
	makeBoard();
	goodShip player;
	createPlayer(&player);
	badShip enemyA[20];
	initArrayEnemy(&enemyA, 20);
	bullet bulletE[50];
	bullet bulletF[50];
	initArrayBullets(&bulletE, 50);
	initArrayBullets(&bulletF, 50);

	//Initialicering af Programmer i main Slut

	//Hentning af Statisk info Start
	//buzz(200);


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
					bulletSpaceship(player.x, player.y-1, &bulletF);
					timeOut++;
				}
			}
			if(timeOut>0 && timeOut<7) {
				timeOut++;
			} else {
				timeOut=0;
			}
			updateBulletFriendly(&bulletF);
			updateBulletEnemy(&bulletE);
			score = bulletHitEnemy(&bulletF, &enemyA, score);
			createScoreLCD(score,&buffer);
			flagF = 0;
		}
		if (flagE == 1){
			moveEnemy(&enemyA);
			flagE = 0;
		}
		if (flagR == 1) {
			bulletEnemy(&enemyA, &bulletE);
			createEnemy(&enemyA);
			flagR = 0;
		}

		//Hentning af kontinuerlig info Slut


//	Testområde

	}
}
