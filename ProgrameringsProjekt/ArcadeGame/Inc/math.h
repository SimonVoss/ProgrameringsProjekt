
#ifndef MATH_H_
#define MATH_H_

#include "include.h"
#include "sinlut.h"

#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( (a)*(b) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b)
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b)


int32_t sinus(int32_t graderMen512);
int32_t cosinus(int32_t graderMen512);
void rotateVector(vector_t *vec, int32_t graderMen512Igen);



#endif /* MATH_H_ */
