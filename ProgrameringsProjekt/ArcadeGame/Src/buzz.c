#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "buzz.h"

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
int32_t i;
	//sound effects
	//0 - player losses a life 		27sec
	//1 - Play shoots a bullet		23sec
	//2 - player hits an enemy
	//3 - Player hits an storoid
	//4 - new level
	if(lyd == 0){
		TIM2->CR1 = 0x0000; // Disable timer
		for (i=1; i<=20; i++){

			printf("bob , %d\n",i);
		}
			int32_t freq = 500/i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("%d , %d\n",freq,i);
//			//wait 10ms
		printf("test , %d \n",lyd);

		TIM2->CR1 = 0x0000; // Disable timer

	}
	if(lyd == 1){
		for (i=1000; i<=1200; i++){
			int freq = i;
			int PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("%d\n",freq);
			//wait 1ms
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}
	if(lyd == 2){
		for (i=1; i<=10; i++){
			int freq = 1000/i;
			int PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("%d\n",freq);
			//wait 20ms
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}
	if(lyd == 3){
		for (i=50; i<=100; i++){
			int freq = i;
			int PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("%d\n",freq);
			//wait 10ms
		}
		for (i=100; i<=50; i++){
			int freq = i;
			int PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("%d\n",freq);
			//wait 5ms
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}
	if(lyd == 4){
		for (i=1; i<=10; i++){
			int freq = 1000/i;
			int PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			printf("%d\n",freq);
			//wait 20ms
		}
		TIM2->CR1 = 0x0000; // Disable timer
	}
			


}
