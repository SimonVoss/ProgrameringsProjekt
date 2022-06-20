#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course

//Joystick
#define pin1 0
#define pin2 1
#define pin3 4
#define pin4 0
#define pin5 5

//LED'er
#define pin6 4
#define pin7 7
#define pin8 9

void PCBinfoJoystick(){
// tÆND ALLE CLOKS
RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C
// Højre PC0
GPIOC->MODER &= ~(0x00000003 << (pin1 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000000 << (pin1 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
										 	 	//Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (pin1 * 2)); 		// Clear push/pull register
GPIOC->PUPDR |= (0x00000002 << (pin1 * 2)); 		// Set push/pull register (0x00 -
										 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

// Venstre PC1
GPIOC->MODER &= ~(0x00000003 << (pin2 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000000 << (pin2 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
										 	 	//Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (pin2 * 2)); 		// Clear push/pull register
GPIOC->PUPDR |= (0x00000002 << (pin2 * 2)); 		// Set push/pull register (0x00 -
										 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

// Op PA4
GPIOA->MODER &= ~(0x00000003 << (pin3 * 2)); // Clear mode register
GPIOA->MODER |= (0x00000000 << (pin3 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
										 	 	//Alternate Function, 0x03 - Analog in/out)
GPIOA->PUPDR &= ~(0x00000003 << (pin3 * 2)); 		// Clear push/pull register
GPIOA->PUPDR |= (0x00000002 << (pin3 * 2)); 		// Set push/pull register (0x00 -
										 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

// Ned PB0
GPIOB->MODER &= ~(0x00000003 << (pin4 * 2)); // Clear mode register
GPIOB->MODER |= (0x00000000 << (pin4 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
										 	 	//Alternate Function, 0x03 - Analog in/out)
GPIOB->PUPDR &= ~(0x00000003 << (pin4 * 2)); 		// Clear push/pull register
GPIOB->PUPDR |= (0x00000002 << (pin4 * 2)); 		// Set push/pull register (0x00 -
										 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

// Center PB5
GPIOB->MODER &= ~(0x00000003 << (pin5 * 2)); // Clear mode register
GPIOB->MODER |= (0x00000000 << (pin5 * 2)); 		// Set mode register (0x00 – Input, 0x01 - Output, 0x02 -
										 	 	//Alternate Function, 0x03 - Analog in/out)
GPIOB->PUPDR &= ~(0x00000003 << (pin5 * 2)); 		// Clear push/pull register
GPIOB->PUPDR |= (0x00000002 << (pin5 * 2)); 		// Set push/pull register (0x00 -
										 	 	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
}

int16_t PCBreadJoystick(){

	//Joystick definationer

	int16_t h = GPIOC->IDR & (0x0001 << pin1);
	int16_t v = GPIOC->IDR & (0x0001 << pin2);
	int16_t o = GPIOA->IDR & (0x0001 << pin3);
	int16_t n = GPIOB->IDR & (0x0001 << pin4);
	int16_t c = GPIOB->IDR & (0x0001 << pin5);

	int16_t a = 0;


	 if(o){ 			//Op
			a += 0x01;
		} if(n){ 		//Ned
			a += 0x02;
		} if(v){ 		//Venstre
			a += 0x04;
		} if(h){ 	    //Højre
			a += 0x08;
		} if(c){ //Center
			a += 0x10;
		}
		return a;
}

void PCBinfoLED(){

	//Clock initialicering
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C

// Set pin PB4 to output
GPIOB->OSPEEDR &= ~(0x00000003 << (pin6 * 2));		 // Clear speed register
GPIOB->OSPEEDR |= (0x00000002 << (pin6 * 2)); 		// set speed register (0x01 - 10
													//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
GPIOB->OTYPER &= ~(0x0001 << (pin6 * 1));		 	// Clear output type register
GPIOB->OTYPER |= (0x0000 << (pin6)); 				// Set output type register (0x00 -
													//Push pull, 0x01 - Open drain)

GPIOB->MODER &= ~(0x00000003 << (pin6 * 2)); 		// Clear mode register
GPIOB->MODER |= (0x00000001 << (pin6 * 2)); 		// Set mode register (0x00 –
													//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

// Set pin PC7 to output
GPIOC->OSPEEDR &= ~(0x00000003 << (pin7 * 2));		 // Clear speed register
GPIOC->OSPEEDR |= (0x00000002 << (pin7 * 2)); 		// set speed register (0x01 - 10
													//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
GPIOC->OTYPER &= ~(0x0001 << (pin7 * 1));		 	// Clear output type register
GPIOC->OTYPER |= (0x0000 << (pin7)); 				// Set output type register (0x00 -
													//Push pull, 0x01 - Open drain)

GPIOC->MODER &= ~(0x00000003 << (pin7 * 2)); 		// Clear mode register
GPIOC->MODER |= (0x00000001 << (pin7 * 2)); 		// Set mode register (0x00 –
													//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

// Set pin PA9 to output
GPIOA->OSPEEDR &= ~(0x00000003 << (pin8 * 2));		 // Clear speed register
GPIOA->OSPEEDR |= (0x00000002 << (pin8 * 2)); 		// set speed register (0x01 - 10
													//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
GPIOA->OTYPER &= ~(0x0001 << (pin8 * 1));		 	// Clear output type register
GPIOA->OTYPER |= (0x0000 << (pin8)); 				// Set output type register (0x00 -
													//Push pull, 0x01 - Open drain)

GPIOA->MODER &= ~(0x00000003 << (pin8 * 2)); 		// Clear mode register
GPIOA->MODER |= (0x00000001 << (pin8 * 2)); 		// Set mode register (0x00 –
													//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
}

void PCBsetLED(int16_t a){

	if(a == 1){
		GPIOB->ODR |= (0x0001 << pin6); //Set pin PB4 to high Red
		GPIOC->ODR |= (0x0001 << pin7); //Set pin PC7 to high Green
		GPIOA->ODR &= ~(0x0001 << pin8); //Set pin PA9 to high Blue
	} else if (a == 2){
		GPIOB->ODR |= (0x0001 << pin6); //Set pin PB4 to high Red
		GPIOC->ODR &= ~(0x0001 << pin7); //Set pin PC7 to high Green
		GPIOA->ODR |= (0x0001 << pin8); //Set pin PA9 to high Blue
	} else if (a == 4){
		GPIOB->ODR &= ~(0x0001 << pin6); //Set pin PB4 to high Red
		GPIOC->ODR |= (0x0001 << pin7); //Set pin PC7 to high Green
		GPIOA->ODR |= (0x0001 << pin8); //Set pin PA9 to high Blue
	} else if (a == 8){
		GPIOB->ODR &= ~(0x0001 << pin6); //Set pin PB4 to high Red
		GPIOC->ODR |= (0x0001 << pin7); //Set pin PC7 to high Green
		GPIOA->ODR &= ~(0x0001 << pin8); //Set pin PA9 to high Blue
	} else if (a == 16){
		GPIOB->ODR |= (0x0001 << pin6); //Set pin PB4 to high Red
		GPIOC->ODR &= ~(0x0001 << pin7); //Set pin PC7 to high Green
		GPIOA->ODR &= ~(0x0001 << pin8); //Set pin PA9 to high Blue
	} else {
		GPIOB->ODR &= ~(0x0001 << pin6); //Set pin PB4 to high Red
		GPIOC->ODR &= ~(0x0001 << pin7); //Set pin PC7 to high Green
		GPIOA->ODR &= ~(0x0001 << pin8); //Set pin PA9 to high Blue
	}
}



