#include "scoreboard.h"

void PrintScore(Map M){
    printf("| NAMA        | SKOR       |\n");
    printf("|--------------------------|\n");
    if(MIsEmpty(M)){
        printf("---- SCOREBOARD KOSONG ----\n");
    }
    else{
        for (int i = 0 ; i < M.Count ; i++){
            printf("|%-13s|%12d|\n", M.Elements[i].Key.Tab, M.Elements[i].Value);
        }
    }
    printf("|--------------------------|\n");
}