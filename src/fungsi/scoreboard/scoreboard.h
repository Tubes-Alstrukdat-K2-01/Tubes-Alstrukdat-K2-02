#ifndef __SCORE_BOARD__
#define __SOCRE_BOARD__

#include "../../ADT/set&map/map.h"
void PrintScore(Map M){
    printf("| NAMA        | SKOR       |\n");
    printf("|--------------------------|\n");
    if(IsEmpty(M)){
        printf("—--- SCOREBOARD KOSONG —----\n");
    }
    else{
    int i,j,k;
    for(i=100; i>=0; i--){
        if(M.Elements[i].score.Neff > 0){
            for(j=0; j < M.Elements[i].score.Neff; j++){
                printf("| %s",M.Elements[i].score.A[j].Tab);
                for(k=0; k < 12 - M.Elements[i].score.A[j].Length; k++){
                    printf(" ");
                }
                printf("| %d");
                
            }
        }
    }
    }
}

#endif // !__SCORE_BOARD__