#ifndef __PLAY_GAME__
#define __PLAY_GAME__

#include "../../ADT/normalqueue/queue.h"
#include "../rng/RNG.h"
#include "../dinerdash/dinerdash.h"
#include "../../ADT/array/arraydin.h"
#include "../hangman/hangman.h"
#include "../queuegame/queuegame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuPlayGame(Queue *Q);

void Play(Kata W);

#endif // !__PLAY_GAME__