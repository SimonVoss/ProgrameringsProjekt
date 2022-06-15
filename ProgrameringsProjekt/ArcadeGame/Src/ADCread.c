#include "adcRead.h"


int32_t ADCread(){

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
