#include "quit.h"
#include <stdio.h>

void QUIT(boolean *running){
    printf("Anda keluar dari game BNMO.\nBye bye ...\n");
    *running = false;
}