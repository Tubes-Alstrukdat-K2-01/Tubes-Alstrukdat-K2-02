#ifndef __HISTORY_H
#define __HISTORY_H
#include "../../ADT/stack/stack.h"
#include"../../ADT/word/word.h"
#include "../../ADT/mesinkata/mesinkata.h"

void HISTORY(Stack2 stackhistory, int n);
// HISTORY <n> menampilkan history permainan yang dimainkan
// n adalah jumlah permainan yang telah dimankan yang ingin ditampilkan

void ResetHistory(Stack2 *stackhistory);
// Reset History akan meminta user untuk konfirmasi apakah akan dilakukan reset history atau tidak

#endif
