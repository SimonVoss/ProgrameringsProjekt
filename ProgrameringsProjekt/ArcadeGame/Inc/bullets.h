
#ifndef BULLETS_H_
#define BULLETS_H_
#include "include.h"
#include "math.h"


void initArrayBullets(bullet a[], int8_t lenght);
void bulletSpaceship(int16_t x, int16_t y, bullet a[]);
void bulletEnemy(badShip b[], bullet a[]);
void updateBulletFriendly(bullet a[]);
void updateBulletEnemy(bullet a[]);
int32_t bulletHitEnemy(bullet a[], badShip b[], int32_t score);
void bulletHitPlayer(bullet a[], goodShip *b);
void bulletHitAstroid(bullet a[], bigRock b[]);
void bulletGravity(bullet a[], bigRock b[]);

#endif /* BULLETS_H_ */
