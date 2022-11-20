#ifndef __QUEUEGAME_H__
#define __QUEUEGAME_H__
#include "../../ADT/normalqueue/queue.h"
#include "../../ADT/array/arraydin.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/array/arraydin.h"
#include "../listgame/listgame.h"
#include <stdio.h>

void displayQueueGame(Queue q);
/* display isi queue */
void menuQueueGame(Queue *q, ArrayDin arrayGames);
/* memperlihatkan menu game */

#endif