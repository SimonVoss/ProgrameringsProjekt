
#ifndef BULLETS_H_
#define BULLETS_H_
#include "include.h"
#include "math.h"


void initArrayBullets(bullet a[], int8_t lenght);
void bulletSpaceship(int16_t x, int16_t y, bullet a[]);
void bulletEnemy(int16_t x, int16_t y, bullet a[]);
void updateBulletFriendly(bullet a[]);
void updateBulletEnemy(bullet a[]);
void bulletHitEnemy(bullet a[], badShip b[]);

#endif /* BULLETS_H_ */
