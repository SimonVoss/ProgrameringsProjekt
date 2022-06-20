#ifndef INCLUDE_H_
#define INCLUDE_H_

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"


//structs

typedef struct {
	int16_t x, y;
}vector_t;

typedef struct {
	int32_t x, y;
	int8_t alive, enemy;
	vector_t vec;
} bullet;

typedef struct {
	int32_t x,y;
	int8_t alive;
} badShip;

typedef struct {
	int32_t x,y;
	int8_t life;
} goodShip;

typedef struct {
	int32_t x,y;
	int8_t alive;
} bigRock;

typedef struct {
	int32_t x,y;
	int8_t alive;
	vector_t vec;
} boomRod;



//more includes

#include "ansi.h"
#include "math.h"
#include "config.h"
#include "analog.h"
#include "sprite.h"
#include "bullets.h"
#include "missile.h"
#include "buzz.h"
#include "gameBoard.h"
#include "enemy.h"
#include "player.h"
#include "timer.h"
#include "astroid.h"
#include "collision.h"



#endif /* INCLUDE_H_ */
