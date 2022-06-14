
#ifndef MATH_H_
#define MATH_H_
#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"
#include "sinlut.h"
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( (a)*(b) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )

typedef struct {
	int32_t x, y;
} vector_t;



#endif /* MATH_H_ */
