#ifndef ENEMY_H_
#define ENEMY_H_

#include "include.h"


void initArrayEnemy(badShip a[], int8_t length);
void createEnemy(badShip a[]);
void moveEnemy(badShip a[], goodShip *player);
void slideEnemy(badShip a);



#endif /* ENEMY_H_ */
