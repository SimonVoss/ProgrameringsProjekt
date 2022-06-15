
#ifndef BULLETS_H_
#define BULLETS_H_
#include "include.h"

typedef struct {
	int32_t x,y;
} bulletPos;

void bulletSpaceship(int32_t x, int32_t y, bulletPos *a);
void bulletEnemy(int32_t x, int32_t y, bulletPos *a);
void updateBulletFriendly(bulletPos *a);
void updateBulletEnemy(bulletPos *a);

#endif /* BULLETS_H_ */
