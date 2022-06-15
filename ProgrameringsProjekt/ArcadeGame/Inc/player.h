#ifndef PLAYER_H_
#define PLAYER_H_

#include "include.h"

typedef struct {
	uint32_t x,y,life;
} goodShip;

void createPlayer(goodShip *player);
void movePlayer(goodShip *player, int32_t joystick);

void shiftRightMake(goodShip *player);
void shiftRightRemove(goodShip *player);
void shiftRight(goodShip *player);
void shiftLeftMake(goodShip *player);
void shiftLeftRemove(goodShip *player);
void shiftLeft(goodShip *player);

#endif /* PLAYER_H_ */
