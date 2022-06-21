#include "include.h"



static int16_t flagF, flagE, flagR = 0;
static int32_t c1, c2, c3 = 0<<8;
static int16_t score, highScore = 0;
static int8_t level = 1;
static int16_t position = 475;
static int8_t sel = 1;
static int8_t game = 0;
static int8_t bossKeyMode = 0;

static int8_t buzzCountBullet = 3;
static int8_t buzzStartBullet = 1;
static int8_t buzzCountLvl = 5;
static int8_t buzzStartLvl = 1;
static int8_t buzzCountEnemy = 3;
static int8_t buzzStartEnemy = 1;
static int8_t buzzCountPlayer = 8;
static int8_t buzzStartPlayer = 1;



void TIM1_BRK_TIM15_IRQHandler(void) {
	c1=c1+(1<<8);
	c2=c2+(1<<8);
	c3=c3+(1<<8);
	TIM15->SR &= ~0x0001; //s Clear interrupt bit
}


int main(void) {
	uart_init(500000);
	color(15,0);
	int8_t buffer[512];
	makeBoard();
	int8_t timeOut = 0;
	int8_t reload = 0;
	int8_t missileTimeOut = 0;
	int16_t aSpawn = 0;
	int8_t ledTimeOut = 0;
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
	bossKeyMode = 0;
	GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high Red
	GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high Green
	GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high Blue
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
			ledTimeOut = 0;
			memset(buffer,0x00,512);
			createScoreLCD(score,buffer, 0);
			createScoreLCD(highScore,buffer, 1);
			lcd_write_string(lives, buffer,2*128);
			lcd_write_heart(1,3,buffer,3*128);
			lcd_write_missil(buffer,1,485);
			createPlayer(&player);
			initArrayEnemy(enemyA, 20);
			initArrayBullets(bulletE, 50);
			initArrayBullets(bulletF, 50);
			initArrayAstroid(astroidA, 5);
			createMissile(&missile);
			game = 1;
			clockCounter(score, &c1, &c2, &c3, &flagF, &flagE, &flagR, &level, 1);
		}
		if(game == 0) {
			int8_t button = buttonRead();
			int8_t joystickWay = adcRead2();
			menuMove(joystickWay,&sel);
			menuSelect(button,&sel,&game);
			if(button == 3 && joystickWay == 2) {
				bossKey();
				bossKeyMode = 1;
				while(bossKeyMode==1) {
					int8_t button = buttonRead();
					int8_t joystickWay = adcRead2();
					if(button == 3 && joystickWay == 2) {
						makeBoard();
						bossKeyMode = 0;
						menu('m',1,'o',0,&sel);
					}
				}
			}
		}
		if(game == 1) {
			int8_t button = buttonRead();
			int8_t joystickWayLR = adcRead1();
			int8_t joystickWayUD = adcRead2();
			clockCounter(score, &c1, &c2, &c3, &flagF, &flagE, &flagR, &level, 0);
			lcd_write_level(level,buffer);
			if(button == 3 && joystickWayUD == 2) {
				bossKey();
				bossKeyMode = 1;
				while(bossKeyMode==1) {
					int8_t button = buttonRead();
					int8_t joystickWayUD = adcRead2();
					if(button == 3 && joystickWayUD == 2) {
						makeBoard();
						bossKeyMode = 0;
						playerDraw(player.x,player.y);
					}
				}
			}
			if(ledTimeOut >= 0 && ledTimeOut < 4) {
				ledTimeOut++;
			} else {
				ledTimeOut = 0;
				GPIOB->ODR |= (0x0001 << 4); //Red off
				GPIOC->ODR |= (0x0001 << 7); //Green off
				GPIOA->ODR |= (0x0001 << 9); //Blue off
			}
			if (flagF == 1){
				movePlayer(&player, joystickWayLR);
				if(timeOut>0 && timeOut<7) {
					timeOut++;
				} else {
					timeOut=0;
				}
				if(button==1 && timeOut==0) {
					bulletSpaceship(player.x, player.y-1, bulletF);
					timeOut++;
					buzzStartBullet = 1;
				}
//				buzzBullet
				if(buzzStartBullet == 1){
					buzzCountBullet--;

					if(buzzCountBullet == 3){
						buzz(11, buzzCountBullet);
					}
					if(buzzCountBullet == 2){
						buzz(12, buzzCountBullet);
					}
					if(buzzCountBullet == 1){
						buzz(13, buzzCountBullet);
					}
					if(buzzCountBullet == 0){
						buzzCountBullet = 3;
						buzzStartBullet = 0;
						TIM2->CR1 = 0x0000; // Disable timer
					}
				}

//				buzzLvlUp
				if(buzzStartLvl == 1){
					buzz(11, buzzCountLvl);
					buzzCountLvl++;

					if(buzzCountLvl == 0){
						buzzStartLvl = 5;
						buzzStartBullet = 0;
						TIM2->CR1 = 0x0000; // Disable timer
					}
				}


//				buzzHitsEnemy



//				buzzPlayerHit
				if(reload==1) {
					if(missileTimeOut==15) {
						position++;
						lcd_write_missil(buffer,3,position);
						if(position==512){
							GPIOB->ODR |= (0x0001 << 4); //Red off
							GPIOC->ODR |= (0x0001 << 7); //Green off
							GPIOA->ODR &= ~(0x0001 << 9); //Blue on
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
				updateBullet(bulletF);
				updateBullet(bulletE);
				score = missileUpdate(&missile, enemyA, astroidA, score);
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
				ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);
				ADC_StartConversion(ADC1); // Start ADC read
				while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
				aSpawn = ADC_GetConversionValue(ADC1);
				ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);
				ADC_StartConversion(ADC1); // Start ADC read
				while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
				aSpawn += ADC_GetConversionValue(ADC1);
				aSpawn = aSpawn%10;
				aSpawn = aSpawn/2;
				if(aSpawn < 4) {
					createEnemy(enemyA);
				} else {
					createAstroid(astroidA);
				}
				flagR = 0;
			}
			if(player.life==0) {
				if (score >= highScore){
					highScore = score;
					createScoreLCD(highScore,buffer, 1);
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
			GPIOB->ODR |= (0x0001 << 4); //Red off
			GPIOC->ODR |= (0x0001 << 7); //Green off
			GPIOA->ODR |= (0x0001 << 9); //Blue off
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
