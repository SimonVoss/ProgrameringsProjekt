#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "buzz.h"


#define tid0 10000
#define tid1 50000
#define tid2 70000
#define tid3 180000

static int PRESCALER_VALUE = 9;
void BuzzConfig(void){
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



}
void buzz(int32_t lyd, int32_t *c, int32_t *flag){

	//sound effects
	//0 - no sound
	//1 - player shoots a bullet
	//2 - Play gets hit
	//3 - player hits an enemy / astoroid
	//4 - new level

	int32_t i, j, k;


	if(lyd == 0){
		TIM2->CR1 = 0x0000; // Disable timer
	}

	if(lyd == 1){

		for (i=1; i<3; i++){
			int32_t freq = 500/i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(j=0;j<=tid0;j++){}
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}

	if(lyd == 2){

		for (i=50; i>=3; i--){
			int32_t freq = 2*i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(j=0;j<=tid1;j++){}
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}

	if(lyd == 4){

		for (i=1; i<=3; i++){
			for (j=1;j<=2;j++){
			int32_t freq = 200/j;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(k=0;k<=tid2;k++){}
			}

		}
		TIM2->CR1 = 0x0000; // Disable timer
	}

	if(lyd == 8){

		for (i=1; i<=5; i++){
			int32_t freq = 250*i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(j=0;j<=tid3;j++){}
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}


}
