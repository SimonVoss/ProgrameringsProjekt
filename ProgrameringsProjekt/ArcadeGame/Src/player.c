#include "player.h"

void createPlayer(goodShip *player) {
	playerDraw(65,115);
	player->x = 65;
	player->y = 115;
	player->life = 3;
}
