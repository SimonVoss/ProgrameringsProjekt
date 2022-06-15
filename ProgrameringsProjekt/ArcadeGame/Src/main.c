#include "include.h"



static int32_t flag = 0;
static int32_t c = 0<<8;




//Initialicering af Programmer Start



void TIM2_IRQHandler(void) {
	c=c+(1<<8);
	TIM2->SR &= ~0x0001; // Clear interrupt bit
}


//Initialicering af Programmer Slut


int main(void) {
	//Initialicering af forbindelse
	uart_init(1000000);
	int32_t i;
	color(15,0);
	//Initialicering af Programmer i main Start
	config();
	//BuzzConfig();
	makeBoard();
	goodShip player;
	createPlayer(&player);
	badShip enemy;
	createEnemy(&enemy);
	//Initialicering af Programmer i main Slut

	//Hentning af Statisk info Start
	//buzz(200);


	//Hentning af Statisk info Slut

	//Klad af funktioner
	while(1){
		//Hentning af kontinuerlig info Start
		int32_t joystickWay = ADCread();
		movePlayer(&player, joystickWay);
		moveEnemy(&enemy);
		for(i=0; i<=100000;i++){}

		//Hentning af kontinuerlig info Slut


//	Testområde

	}
}
