#include "include.h"



static int16_t flagF, flagE, flagR = 0;
static int32_t c1, c2, c3 = 0<<8;
static int16_t score, highScore = 0;
static int8_t level = 1;
static int16_t position = 475;
static int8_t sel = 1;
static int8_t game = 0;
static nextInterval = 100<<8;;




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
	int8_t buffer[512];
	makeBoard();
	int8_t timeOut = 0;
	int8_t reload = 0;
	int8_t missileTimeOut = 0;
	int8_t aSpawn = 0;
	clockInit();
	char lives[7] = {'L','i','v','e','s',':','\0'};
	menu('m',1,'o',0,&sel);
	color(15,0);
	config();
	lcd_init();
	goodShip player;
	badShip enemyA[20];
	bullet bulletE[50];
	bullet bulletF[50];
	bigRock astroidA[5];
	boomRod missile;

	//Hentning af Statisk info Start
	//buzz(200);
	//Hentning af Statisk info Slut
	//Klad af funktioner
	while(1){
		if(game == 3) {
			flagF, flagE, flagR = 0;
			c1, c2, c3 = 0<<8;
			score = 0;
			level = 1;
			position = 475;
			sel = 1;
			timeOut = 0;
			reload = 0;
			missileTimeOut = 0;
			aSpawn = 0;
			memset(buffer,0x00,512);
			createScoreLCD(score,buffer, 0);
			createScoreLCD(score,buffer, 1);
			lcd_write_string(lives, buffer,2*128);
			lcd_write_heart(1,3,buffer,3*128);
			lcd_write_missil(buffer,1,485);
			createPlayer(&player);
			initArrayEnemy(enemyA, 20);
			initArrayBullets(bulletE, 50);
			initArrayBullets(bulletF, 50);
			initArrayAstroid(astroidA, 5);
			createMissile(&missile);
			nextInterval=100<<8;;
			game = 1;
		}
		if(game == 0) {
			int8_t button = buttonRead();
			int8_t joystickWay = adcRead2();
			menuMove(joystickWay,&sel);
			menuSelect(button,&sel,&game);
		}
		if(game == 1) {
			int8_t button = buttonRead();
			int8_t joystickWay = adcRead1();
			clockCounter(score, &c1, &c2, &c3, &flagF, &flagE, &flagR, &level, &nextInterval);
			lcd_write_level(level,buffer);
			if (flagF == 1){
				movePlayer(&player, joystickWay);
				if(timeOut>0 && timeOut<7) {
					timeOut++;
				} else {
					timeOut=0;
				}
				if(button==1 && timeOut==0) {
					bulletSpaceship(player.x, player.y-1, bulletF);
					timeOut++;
				}
				if(reload==1) {
					if(missileTimeOut==15) {
						position++;
						lcd_write_missil(buffer,3,position);
						if(position==512){
							reload = 0;
							position = 475;
						}
						missileTimeOut = 0;
					} else {
						missileTimeOut++;
					}
				}
				if(button==2 && missile.alive==0 && reload==0) {
					missileShoot(&missile, &player);
					lcd_write_missil(buffer,2,position);
					reload = 1;
					position=475;
				}
				updateBulletFriendly(bulletF);
				updateBulletEnemy(bulletE);
				missileUpdate(&missile, enemyA, astroidA);
				score = bulletHitEnemy(bulletF, enemyA, score);
				createScoreLCD(score,buffer, 0);
				bulletGravity(bulletE, astroidA);
				bulletGravity(bulletF, astroidA);
				bulletHitPlayer(bulletE, &player);
				bulletHitAstroid(bulletE, astroidA);
				bulletHitAstroid(bulletF, astroidA);
				collision(enemyA, astroidA, &player);
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
			if(player.life==0) {
				if (score > highScore){
					createScoreLCD(score,buffer, 1);
				}
				lcd_write_heart(0,3,buffer,384);
				makeBoard();
				game = 2;
			}
			if(player.life==1){
				lcd_write_heart(0,2,buffer,394);
			}
			if(player.life==2){
				lcd_write_heart(0,1,buffer,404);
			}
		}
		if(game == 2) {
			menu('e',1,'o',score,&sel);
			int8_t button = buttonRead();
			if(button == 2) {
				game=0;
				makeBoard();
				menu('m',1,'o',0,&sel);
			}
		}

	}
}
