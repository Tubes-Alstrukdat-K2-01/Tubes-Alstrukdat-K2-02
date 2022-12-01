#ifndef __PLAY_GAME__
#define __PLAY_GAME__

#include "../../ADT/normalqueue/queue.h"
#include "../rng/RNG.h"
#include "../dinerdash/dinerdash.h"
#include "../../ADT/array/arraydin.h"
#include "../hangman/hangman.h"
#include "../queuegame/queuegame.h"
#include "../../ADT/set&map/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NGame 5
void menuPlayGame(Queue *Q, Map M [NGame]);

void Play(Kata W, Map M [NGame]);

#endif // !__PLAY_GAME__