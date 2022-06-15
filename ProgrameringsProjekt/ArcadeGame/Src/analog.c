#include <analog.h>


int8_t adcRead(void){

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
