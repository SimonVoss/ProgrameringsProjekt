#include "math.h"

int32_t sinus(int32_t graderMen512) {
	int32_t a = graderMen512;
	while(a > 511) {
		a -= 512;
	}
	while(a < 0) {
		a += 512;
	}
	a =  SIN[a];
	return a;
}

int32_t cosinus(int32_t graderMen512) {
	int32_t a = graderMen512 + 128;
	while(a > 511) {
			a -= 512;
		}
	while(a < 0) {
		a += 512;
	}
	a =  SIN[a];
	return a;
}

void rotateVector(vector_t *vec, int32_t graderMen512Igen) {
	int32_t a = vec->x;
	int32_t b = vec->y;
	int32_t x = FIX8_MULT(a,cosinus(graderMen512Igen)) - FIX8_MULT(b,sinus(graderMen512Igen));
	int32_t y = FIX8_MULT(a,sinus(graderMen512Igen)) + FIX8_MULT(b,cosinus(graderMen512Igen));
	vec->x = x;
	vec->y = y;
}


