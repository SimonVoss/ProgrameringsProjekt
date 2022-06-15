
#ifndef BULLETS_H_
#define BULLETS_H_
#include "include.h"
#include "math.h"


void initArrayBullets(bullet a[], int8_t lenght);
void bulletSpaceship(int8_t x, int8_t y, bullet a[]);
void bulletEnemy(int8_t x, int8_t y, bullet a[]);
void updateBulletFriendly(bullet a[]);
void updateBulletEnemy(bullet a[]);

#endif /* BULLETS_H_ */
