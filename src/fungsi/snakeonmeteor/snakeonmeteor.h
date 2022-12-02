#ifndef __SNAKE_ON_METEOR__
#define __SNAKE_ON_METEOR__

#include <stdio.h>
#include "../../ADT/boolean.h"
#include "../scoreboard/scoreboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/matrixsnake/matrikssnake.c"
#include "../../ADT/listlinier/listular.c"

ular makeUlar();

void setupPeta (MATRIKS* peta);

infotype newbuah();

void buahTOpeta(MATRIKS* peta,infotype buah);

void UlarTOpeta(MATRIKS* peta,ular* Ularmain);

void playsnake();

#endif // !__SNAKE_ON_METEOR__