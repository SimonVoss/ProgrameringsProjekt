#ifndef PLAYER_H_
#define PLAYER_H_

#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"
#include "sprite.h"

typedef struct {
	uint32_t x,y,life;
} goodShip;

void createPlayer(goodShip *player);

#endif /* PLAYER_H_ */
