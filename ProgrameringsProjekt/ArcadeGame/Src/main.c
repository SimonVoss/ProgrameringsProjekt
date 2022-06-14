#include <bullets.h>
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "ADCread.h"
#include "ex2.h"
#include "timer.h"
#include "buzz.h"
#include "PCBJoystick.h"
#include "gameBoard.h"
#include "letters.h"



static int32_t flag = 0;
static int32_t c = 0<<8;



//Initialicering af Programmer Start
void TIM1_BRK_TIM15_IRQHandler(void) {
	c=c+(1<<8);
	TIM15->SR &= ~0x0001; // Clear interrupt bit
}

//Initialicering af Programmer Slut


int main(void) {
	//Initialicering af forbindelse
	uart_init(115200);


	//Initialicering af Programmer i main Start
	ADCConfig();
	BuzzConfig();
	clockInit();
	PCBinfoJoystick();

	//Initialicering af Programmer i main Slut


	//Statisk info Start




	//Statisk info Slut


	//	bgcolor(0);
		makeBoard();
		int32_t start = 20;
		letters(0,start,start);
		letters(1,start+13,start);
		letters(1,start,start+7);



	while(1){

		//Hentning af kontinuerlig info Start

		int32_t JoystickWay = ADCread();
		int32_t buzzTest = PCBreadJoystick();

		//Hentning af kontinuerlig info Slut


		//	Testområde

		buzz(buzzTest,&c, &flag);



	}
}
