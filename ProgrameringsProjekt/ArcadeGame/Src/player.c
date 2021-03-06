#include "player.h"

void createPlayer(goodShip *player) {
	playerDraw(65,115);
	player->x = 65;
	player->y = 115;
	player->life = 3;
}


void movePlayer(goodShip *player, int32_t joystick) {
	if(joystick == 1 && player->x>6) { //left
		shiftLeft(player);
		player->x--;
	}
	if(joystick == 2 && player->x<132) {//right
		shiftRight(player);
		player->x++;
	}
}

void shiftRight(goodShip *player) {
	fgcolor(15);
	gotoxy(player->x+1,player->y);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x,player->y);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-2,player->y+1);
	printf("%c", 219);
	gotoxy(player->x+1,player->y+1);
	printf("%c", 219);
	gotoxy(player->x+4,player->y+1);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-3,player->y+1);
	printf("%c", 219);
	gotoxy(player->x,player->y+1);
	printf("%c", 219);
	gotoxy(player->x+3,player->y+1);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-2,player->y+2);
	printf("%c", 219);
	gotoxy(player->x+1,player->y+2);
	printf("%c", 219);
	gotoxy(player->x+2,player->y+2);
	printf("%c", 219);
	gotoxy(player->x+4,player->y+2);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-3,player->y+2);
	printf("%c", 219);
	gotoxy(player->x-1,player->y+2);
	printf("%c", 219);
	gotoxy(player->x+3,player->y+2);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x,player->y+3);
	printf("%c", 219);
	fgcolor(4);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+4,player->y+3);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-3,player->y+3);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-1,player->y+4);
	printf("%c", 219);
	fgcolor(4);
	gotoxy(player->x+2,player->y+4);
	printf("%c", 219);
	fgcolor(15);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-2,player->y+4);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+4, player->y+5);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-3,player->y+5);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-1, player->y+6);
	printf("%c", 219);
	gotoxy(player->x+1, player->y+6);
	printf("%c", 219);
	gotoxy(player->x+5, player->y+6);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-4,player->y+6);
	printf("%c", 219);
	gotoxy(player->x,player->y+6);
	printf("%c", 219);
	gotoxy(player->x+2,player->y+6);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-2,player->y+7);
	printf("%c", 219);
	gotoxy(player->x+5,player->y+7);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-4,player->y+7);
	printf("%c", 219);
	gotoxy(player->x+3,player->y+7);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-3,player->y+8);
	printf("%c", 219);
	gotoxy(player->x+5,player->y+8);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x-4,player->y+8);
	printf("%c", 219);
	gotoxy(player->x+4,player->y+8);
	printf("%c", 219);
}

void shiftLeft(goodShip *player) {
	fgcolor(15);
	gotoxy(player->x-1,player->y);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x,player->y);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+2,player->y+1);
	printf("%c", 219);
	gotoxy(player->x-1,player->y+1);
	printf("%c", 219);
	gotoxy(player->x-4,player->y+1);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+3,player->y+1);
	printf("%c", 219);
	gotoxy(player->x,player->y+1);
	printf("%c", 219);
	gotoxy(player->x-3,player->y+1);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+2,player->y+2);
	printf("%c", 219);
	gotoxy(player->x-1,player->y+2);
	printf("%c", 219);
	gotoxy(player->x-2,player->y+2);
	printf("%c", 219);
	gotoxy(player->x-4,player->y+2);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+3,player->y+2);
	printf("%c", 219);
	gotoxy(player->x+1,player->y+2);
	printf("%c", 219);
	gotoxy(player->x-3,player->y+2);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x,player->y+3);
	printf("%c", 219);
	fgcolor(4);
	gotoxy(player->x-1,player->y+3);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-4,player->y+3);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+3,player->y+3);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+1,player->y+4);
	printf("%c", 219);
	fgcolor(4);
	gotoxy(player->x-2,player->y+4);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-3,player->y+4);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+2,player->y+4);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x-4, player->y+5);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+3,player->y+5);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+1, player->y+6);
	printf("%c", 219);
	gotoxy(player->x-1, player->y+6);
	printf("%c", 219);
	gotoxy(player->x-5, player->y+6);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+4,player->y+6);
	printf("%c", 219);
	gotoxy(player->x,player->y+6);
	printf("%c", 219);
	gotoxy(player->x-2,player->y+6);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+2,player->y+7);
	printf("%c", 219);
	gotoxy(player->x-5,player->y+7);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+4,player->y+7);
	printf("%c", 219);
	gotoxy(player->x-3,player->y+7);
	printf("%c", 219);
	fgcolor(15);
	gotoxy(player->x+3,player->y+8);
	printf("%c", 219);
	gotoxy(player->x-5,player->y+8);
	printf("%c", 219);
	fgcolor(0);
	gotoxy(player->x+4,player->y+8);
	printf("%c", 219);
	gotoxy(player->x-4,player->y+8);
	printf("%c", 219);
}
