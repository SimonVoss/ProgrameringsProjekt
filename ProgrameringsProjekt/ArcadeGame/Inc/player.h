#ifndef PLAYER_H_
#define PLAYER_H_

#include "include.h"



void createPlayer(goodShip *player);
void movePlayer(goodShip *player, int32_t joystick);

void shiftRight(goodShip *player);
void shiftLeft(goodShip *player);

#endif /* PLAYER_H_ */
