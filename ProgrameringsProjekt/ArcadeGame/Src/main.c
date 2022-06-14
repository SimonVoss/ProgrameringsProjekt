#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "ADCread.h"
#include "ex2.h"
#include "Bullets.h"
#include "timer.h"
#include "buzz.h"
#include "PCBJoystick.h"



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
	uart_init(115200);


	//Initialicering af Programmer i main Start
	ADCConfig();
	BuzzConfig();
	clockInit();

	//Initialicering af Programmer i main Slut

	//Hentning af Statisk info Start
	buzz(0, &c, flag);



	//Hentning af Statisk info Slut

	//Klad af funktioner


	while(1){
		//Hentning af kontinuerlig info Start
		int JoystickWay = ADCread();



		//Hentning af kontinuerlig info Slut


//	Testområde

	}
}
