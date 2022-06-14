
#ifndef BULLETS_H_
#define BULLETS_H_
#include "stdio.h"
#include "stdint.h"
#include "math.h"

typedef struct {
	int32_t x,y, alive;
	vector_t vec;
} bulletPos;

void bulletSpaceship(int32_t x, int32_t y, bulletPos *a, vector_t *vec)
void bulletEnemy(int32_t x, int32_t y, bulletPos *a);
void updateBullet(bulletPos *a, vector_t *vec);

#endif /* BULLETS_H_ */
