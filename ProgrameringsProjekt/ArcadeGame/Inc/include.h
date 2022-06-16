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
	int32_t x, y, alive, enemy;
	vector_t vec;
} bullet;

typedef struct {
	uint32_t x,y,alive;
} badShip;

//more includes

#include "ansi.h"
#include "math.h"
#include "config.h"
#include "analog.h"
#include "sprite.h"
#include "bullets.h"
#include "buzz.h"
#include "gameBoard.h"
#include "enemy.h"
#include "player.h"
#include "timer.h"




#endif /* INCLUDE_H_ */
