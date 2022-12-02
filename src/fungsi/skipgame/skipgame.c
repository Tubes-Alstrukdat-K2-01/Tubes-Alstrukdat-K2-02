#include "skipgame.h"


void menuSkipGame(Queue *Q, int skip){
    displayQueueGame(*Q);
    if (skip > lengthQueue(*Q)){
        Kata x;
        while(!isEmpty(*Q)){
            dequeue(Q, &x);
        }
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    else{
        Kata x;
        for (int i = 0; i < skip; i++){
            dequeue(Q, &x);
        }
    }
    Kata Head;
    dequeue(Q, &Head);
    /* nunggu list game buat nge run permainan yang di head */
    Play(Head); // PLACEHOLDER
};
