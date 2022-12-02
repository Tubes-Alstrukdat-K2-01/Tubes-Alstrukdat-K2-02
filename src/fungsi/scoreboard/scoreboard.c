#include "scoreboard.h"

void PrintScore(Map M){
    printf("| NAMA         | SKOR         |\n");
    printf("|-----------------------------|\n");
    if(MIsEmpty(M)){
        printf("|----- SCOREBOARD KOSONG -----|\n");
    }
    else{
        for (int i = 0 ; i < M.Count ; i++){
            printf("| %-13.13s|%13d |\n", M.Elements[i].Key.Tab, M.Elements[i].Value);
        }
    }
    printf("|-----------------------------|\n\n");
}

void Scoreboard(Map *SC, ArrayDin game){
    int i;
    for(i=0; i<game.Neff; i++){
        printf("**** SCOREBOARD GAME %s ****\n",game.A[i].Tab);
        PrintScore(SC[i]);
    }
}