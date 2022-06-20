

#ifndef PCBJOYSTICK_H_
#define PCBJOYSTICK_H_

#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"

void PCBinfoJoystick();
int32_t PCBreadJoystick();
void PCBinfoLED();
void PCBsetLED();

#endif /* PCBJOYSTICK_H_ */
