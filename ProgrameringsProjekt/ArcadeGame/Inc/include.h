#ifndef INCLUDE_H_
#define INCLUDE_H_

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "stdint.h"
#include "stdio.h"
#include "ansi.h"

typedef struct {
	int16_t x, y;
}vector_t;

typedef struct {
	int16_t x, y, alive;
	vector_t vec;
} bullet;

#include "math.h"
#include "config.h"
#include "sprite.h"
#include "bullets.h"
#include "buzz.h"
#include "gameBoard.h"
#include "enemy.h"
#include "player.h"
#include "timer.h"
#include "lcd.h"





#endif /* INCLUDE_H_ */
