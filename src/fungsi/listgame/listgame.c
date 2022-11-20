#include "listgame.h"
#include <stdio.h>

void LISTGAME (ArrayDin arrayGames){
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia\n");  
    for (i; i < arrayGames.Neff; i++){
        printf("%d. %s\n", i + 1, arrayGames.A[i].Tab);
    }
}