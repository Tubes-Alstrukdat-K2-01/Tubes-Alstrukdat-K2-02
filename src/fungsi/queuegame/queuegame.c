#include "queuegame.h"
void displayQueueGame(Queue q){
    if (isEmpty(q)){
        printf("Queue Kosong\n");
    }
    else{
        printf("Berikut adalah daftar antrian game-mu: \n");
        for (int i = IDX_HEAD(q); i < IDX_TAIL(q)+1; i++){
            printf("%d. %s\n", (i - IDX_HEAD(q) + 1), q.buffer[i].Tab);
        }
    }
}
void menuQueueGame(Queue *q, ArrayDin arrayGames){
    displayQueueGame(*q);
    printf("\n");
    LISTGAME(arrayGames);
    /* asumsi listgame pake adt List, sesuaian */
    printf("\n");
    int pil, i;
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    boolean valid = false;
    while(!valid){
        STARTWORD();
        pil = 0;
        if(!isEndWord()){
            boolean integer = true;
            for(i=0; i<currentWord.Length; i++){
                if(currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9'){
                    pil *= 10;
                    pil += (int)(currentWord.TabWord[i]-48);
                }
                else{
                    integer = false;   
                }
            }
            ADVWORD();
            if(isEndWord() && integer){
                valid = true;
            }
            else{
                while(!isEndWord()){
                    ADVWORD();
                }
            }
        }
        if(!valid){
            printf("Masukkan Invalid! Silahkan Masukkan Nomor Game Kembali : ");
        }
    }
    // Kata namaGame = Get(arrayGames, pil - 1);
    /* minta buat fungsi getnama game dari index */
    if(pil <= arrayGames.Neff && pil > 0){
        enqueue(q, arrayGames.A[pil-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
    }
    else{
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}