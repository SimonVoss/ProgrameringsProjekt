#include <analog.h>


int8_t adcRead1(void){

	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	uint32_t joystickWay = ADC_GetConversionValue(ADC1); // Read the ADC value

	if(joystickWay<=1000) {
		return 1; //venstre
	}else if(joystickWay>=3000) {
		return 2; //højre
	}else {
		return 0;
	}
}

int8_t adcRead2(void) {

	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	uint32_t joystickWay = ADC_GetConversionValue(ADC1); // Read the ADC value
	if(joystickWay>=3000) {
		return 1; //op
	}else if(joystickWay<=1000) {
		return 2; //ned
	}else {
		return 0;
	}
}


int8_t buttonRead(void) {
	int16_t a = 0;
	int16_t b1 = GPIOC->IDR & (0x0001 << 0);
	int16_t b2 = GPIOC->IDR & (0x0001 << 1);

	if(b1) {
		a += 1;
	}
	if(b2) {
		a += 2;
	}
	return a;
}



void buzz(int32_t lyd, int32_t *c, int32_t *flag){

	//sound effects
	//0 - no sound
	//1 - player shoots a bullet
	//2 - Play gets hit
	//4 - player hits an enemy / astoroid
	//16 - new level
	//8 - menu sound

	int32_t i, j, k;


	if(lyd == 0){
		TIM2->CR1 = 0x0000; // Disable timer
	}



//	if(lyd == 1){
//		if(fork() == 0){
//			TIM2->CR1 = 0x0001; // enable timer
//			for (i=1; i<3; i++){
//				int32_t freq = 500/i;
//				int32_t PRESCALER_VALUE = 9;
//				uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
//				TIM2->ARR = reload; // Set auto reload value
//				TIM2->CCR3 = reload/2; // Set compare register
//				TIM2->EGR |= 0x01;
//				printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
//				for(j=0;j<=tid0;j++){}
//			}
//		}
//
//	}




	if(lyd == 16){
		TIM2->CR1 = 0x0001; // enable timer
		for (i=1; i<3; i++){
			int32_t freq = 500/i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
//			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(j=0;j<=tid0;j++){}
		}

	}

	if(lyd == 8){
		TIM2->CR1 = 0x0001; // enable timer
		for (i=50; i>=3; i--){
			int32_t freq = 2*i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
//			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(j=0;j<=tid1;j++){}
		}

	}

	if(lyd == 4){
		TIM2->CR1 = 0x0001; // enable timer
		for (i=1; i<=3; i++){
			for (j=1;j<=2;j++){
			int32_t freq = 200/j;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
//			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(k=0;k<=tid2;k++){}
			}

		}

	}

	if(lyd == 2){
		TIM2->CR1 = 0x0001; // enable timer
		for (i=1; i<=5; i++){
			int32_t freq = 500*i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
//			printf("freq = %d , i = %d , lyd = %d\n",freq,i,lyd);
			for(j=0;j<=tid3;j++){}
		}

	}

	if(lyd == 1){
		TIM2->CR1 = 0x0001; // enable timer
			int32_t freq = 300;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			for(j=0;j<=tid3;j++){}
		for (i=1; i<=5; i++){
			int32_t freq = 300*i;
			int32_t PRESCALER_VALUE = 9;
			uint32_t reload = 64e6 / freq / (PRESCALER_VALUE + 1) - 1;
			TIM2->ARR = reload; // Set auto reload value
			TIM2->CCR3 = reload/2; // Set compare register
			TIM2->EGR |= 0x01;
			for(j=0;j<=tid2;j++){}
		}

	}

}
