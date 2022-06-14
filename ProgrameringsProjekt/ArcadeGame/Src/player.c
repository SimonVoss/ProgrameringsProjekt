#include "player.h"

void createPlayer(goodShip *player) {
	playerDraw(65,115);
	player->x = 65;
	player->y = 115;
	player->life = 3;
}


void playerMove(goodShip *player, int32_t joystick) {
	if(joystick == 1) { //left
		playerRemove(player->x,player->y);
		player->x--;
		playerDraw(player->x,player->y);
	}
	if(joystick == 2) {//right
		playerRemove(player->x,player->y);
		player->x++;
		playerDraw(player->x,player->y);
	}
}
