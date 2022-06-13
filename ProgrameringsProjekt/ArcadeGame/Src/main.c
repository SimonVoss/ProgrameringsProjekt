#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "ADCread.h"
#include "ex2.h"
#include "Bullets.h"
#include "timer.h"



static int32_t flag = 0;
static int32_t c = 0<<8;

void TIM2_IRQHandler(void) {
	c=c+(1<<8);
	TIM2->SR &= ~0x0001; // Clear interrupt bit
}


//Initialicering af Programmer Start

void ADCConfig(void) {
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	//PA0
	GPIOA->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (0 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (0 * 2)); 		// Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (0 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	//PA1
	GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (1 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (1 * 2)); 		// Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (1 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12; // Clear ADC12 prescaler bits
	RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6; // Set ADC12 prescaler to 6
	RCC->AHBENR |= RCC_AHBPeriph_ADC12; // Enable clock for ADC12

	ADC1->CR = 0x00000000; // Clear CR register
	ADC1->CFGR &= 0xFDFFC007; // Clear ADC1 config register
	ADC1->SQR1 &= ~ADC_SQR1_L; // Clear regular sequence register 1

	ADC1->CR |= 0x10000000; // Enable internal ADC voltage regulator
	for (int i = 0 ; i < 1000 ; i++) {} // Wait for about 16 microseconds

	ADC1->CR |= 0x80000000; // Start ADC1 calibration
	while (!(ADC1->CR & 0x80000000)); // Wait for calibration to finish
	for (int i = 0 ; i < 100 ; i++) {} // Wait for a little while

	ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
	while (!(ADC1->ISR & 0x00000001)); // Wait until ready

}
//Initialicering af Programmer Slut


int main(void) {
	//Initialicering af forbindelse
	uart_init(9600);


	//Initialicering af Programmer i main Start
	ADCConfig();

	//Initialicering af Programmer i main Slut

	//Hentning af info Start

	int JoystickWay = ADCread();

	//Hentning af info Slut


//	Testområde
	printf("Value = %d\n", JoystickWay);



	while(1){}
}
