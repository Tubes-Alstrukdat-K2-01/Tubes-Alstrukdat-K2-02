#ifndef __SCOREBOARD_H__
#define __SOCREBOARD_H__

#include "../../ADT/setmap/map.h"
#include "../../ADT/array/arraydin.h"
#include "../../ADT/global.h"
#include <stdio.h>

void PrintScore(Map M);

void Scoreboard(Map *SC, ArrayDin game);

void InserScore(Map M, int score);

void ResetScore(ArrayDin game);

#endif // !__SCORE_BOARD__