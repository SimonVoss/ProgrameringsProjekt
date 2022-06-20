#include "include.h"



static int16_t flagF, flagE, flagR = 0;
static int32_t c1, c2, c3 = 0<<8;
static int16_t score, highScore = 0;
static int8_t level = 1;
static int16_t position = 485;




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
	int8_t reload = 0;
	int8_t aSpawn = 0;
	lcd_init();
	int32_t i;
	int8_t buffer[512];
	memset(buffer,0x00,512);
	createScoreLCD(score,buffer, 0);
	createScoreLCD(score,buffer, 1);
	char lives[7] = {'L','i','v','e','s',':','\0'};
	lcd_write_string(lives, buffer,2*128);
	lcd_write_heart(1,3,buffer,3*128);
	lcd_write_missil(buffer,1,position);
//	lcd_push_buffer(buffer);
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
	boomRod missile;
	createMissile(&missile);
	//Initialicering af Programmer i main Slut


//	missileDraw(15,2);
//	for(i=0;i<1000000;i++);
//	missileRemove(15,2);
	//Hentning af Statisk info Start
	//buzz(200);
	//Hentning af Statisk info Slut

	//Klad af funktioner
	while(1){

		int8_t button = buttonRead();
		int8_t joystickWay = adcRead();
		clockCounter(score, &c1, &c2, &c3, &flagF, &flagE, &flagR, &level);
		lcd_write_level(level,buffer);
		//Hentning af kontinuerlig info Start
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
			if(reload>0 && reload<100) {
				reload++;
			} else {
				reload=0;
			}
			if(button==2 && missile.alive==0 && reload==0) {
				missileShoot(&missile, &player);
				reload++;
			}
			updateBulletFriendly(bulletF);
			updateBulletEnemy(bulletE);
			missileUpdate(&missile, enemyA, astroidA);
			score = bulletHitEnemy(bulletF, enemyA, score);
			createScoreLCD(score,buffer, 0);
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
			playerRemove(player.x,player.y);
			while(1) {}
		}
		if(player.life==1){
			lcd_write_heart(0,2,buffer,394);
		}
		if(player.life==2){
			lcd_write_heart(0,1,buffer,404);
		}

		//Hentning af kontinuerlig info Slut


//	Testområde

	}
}
