#ifndef ENEMY_H_
#define ENEMY_H_

#include "include.h"

typedef struct {
	uint32_t x,y,exist;
} badShip;

void createEnemy(badShip *enemy);
void moveEnemy(badShip *enemy);
void slideEnemy(badShip *enemy);



#endif /* ENEMY_H_ */
