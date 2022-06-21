#ifndef MISSILE_H_
#define MISSILE_H_

#include "include.h"

void createMissile(boomRod *missile);
void missileShoot(boomRod *missile, goodShip *player);
void missileShift(boomRod *missile);
int32_t missileUpdate(boomRod *missile, badShip a[], bigRock b[], int32_t score);


#endif /* MISSILE_H_ */
