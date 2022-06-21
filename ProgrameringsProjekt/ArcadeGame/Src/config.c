#include "config.h"

static int PRESCALER_VALUE = 9;

void pinConfig(void) {
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C

	//pin A0
	GPIOA->MODER &= ~(0x00000003 << (0 * 2)); 		// Clear mode register
	GPIOA->MODER |= (0x00000000 << (0 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (0 * 2)); 		// Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (0 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	//pin A1
	GPIOA->MODER &= ~(0x00000003 << (1 * 2)); 		// Clear mode register
	GPIOA->MODER |= (0x00000000 << (1 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (1 * 2)); 		// Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (1 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	//pin C0
	GPIOC->MODER &= ~(0x00000003 << (0 * 2)); 		// Clear mode register
	GPIOC->MODER |= (0x00000000 << (0 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); 		// Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (0 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	//pin C1
	GPIOC->MODER &= ~(0x00000003 << (1 * 2)); 		// Clear mode register
	GPIOC->MODER |= (0x00000000 << (1 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); 		// Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (1 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	//pin C2
	GPIOC->MODER &= ~(0x00000003 << (2 * 2)); 		// Clear mode register
	GPIOC->MODER |= (0x00000000 << (2 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (2 * 2)); 		// Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (2 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	//pin C3
	GPIOC->MODER &= ~(0x00000003 << (3 * 2)); 		// Clear mode register
	GPIOC->MODER |= (0x00000000 << (3 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
											 	 	//Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (3 * 2)); 		// Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (3 * 2)); 		// Set push/pull register (0x00 -
											 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	//pin PB4
	GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2));		 // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); 		// set speed register (0x01 - 10
														//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOB->OTYPER &= ~(0x0001 << (4 * 1));		 	// Clear output type register
	GPIOB->OTYPER |= (0x0000 << (4)); 				// Set output type register (0x00 -
														//Push pull, 0x01 - Open drain)

	GPIOB->MODER &= ~(0x00000003 << (4 * 2)); 		// Clear mode register
	GPIOB->MODER |= (0x00000001 << (4 * 2)); 		// Set mode register (0x00 –
														//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	//pin PC7
	GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2));		 // Clear speed register
	GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); 		// set speed register (0x01 - 10
														//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOC->OTYPER &= ~(0x0001 << (7 * 1));		 	// Clear output type register
	GPIOC->OTYPER |= (0x0000 << (7)); 				// Set output type register (0x00 -
														//Push pull, 0x01 - Open drain)

	GPIOC->MODER &= ~(0x00000003 << (7 * 2)); 		// Clear mode register
	GPIOC->MODER |= (0x00000001 << (7 * 2)); 		// Set mode register (0x00 –
														//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	//pin PA9
	GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2));		 // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); 		// set speed register (0x01 - 10
														//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOA->OTYPER &= ~(0x0001 << (9 * 1));		 	// Clear output type register
	GPIOA->OTYPER |= (0x0000 << (9)); 				// Set output type register (0x00 -
														//Push pull, 0x01 - Open drain)

	GPIOA->MODER &= ~(0x00000003 << (9 * 2)); 		// Clear mode register
	GPIOA->MODER |= (0x00000001 << (9 * 2)); 		// Set mode register (0x00 –
														//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
}

void adcConfig(void) {
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

void buzzConfig(void){
	RCC->APB1ENR |= 0x00000001; // Enable clock line to timer 2;
	TIM2->CR1 = 0x0000; // Disable timer
	TIM2->ARR = 1000; // Set auto reload value
	TIM2->PSC = PRESCALER_VALUE; // Set pre-scaler value
	TIM2->CR1 |= 0x0001; // Enable timer
	TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
	TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
	TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
	TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
	TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
	TIM2->CCMR2 |= TIM_OCPreload_Enable;
	TIM2->CCR3 = 500; // Set duty cycle to 50 %

	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // Enable clock line for GPIO bank B
	GPIOB->MODER &= ~(0x00000003 << (10 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000002 << (10 * 2)); // Set mode register

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);

	TIM2->CR1 = 0x0000; // Disable timer

}


void config(void) {
	pinConfig();
	adcConfig();
	buzzConfig();
}
