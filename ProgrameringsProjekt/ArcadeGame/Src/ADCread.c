#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"


int ADCread(){

	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	uint16_t JoystickWay = ADC_GetConversionValue(ADC1); // Read the ADC value

	if(JoystickWay > 2048){
		return 1;
	}
	if(JoystickWay < 2048){
		return 0;
	}
}
