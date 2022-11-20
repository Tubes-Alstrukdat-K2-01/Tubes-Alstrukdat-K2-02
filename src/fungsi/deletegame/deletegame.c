#include "deletegame.h"
#include <stdio.h>

void DELETEGAME (ArrayDin *arrayGames){
    int del, i;

    LISTGAME(*arrayGames);
    printf("Masukkan nomor game yang akan dihapus: ");
    boolean valid = false;
    while(!valid){
        STARTWORD();
        del = 0;
        if(!isEndWord()){
            boolean integer = true;
            for(i=0; i<currentWord.Length; i++){
                if(currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9'){
                    del *= 10;
                    del += (int)(currentWord.TabWord[i]-48);
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
    if ((del>=1) && (del<=6)){
        printf("Game gagal dihapus \n");
    }

    else if (del>6){
        if(del <= (*arrayGames).Neff){    
            i = del-1;
            DeleteAt(arrayGames, i);
            printf("Game berhasil dihapus \n");
        }
        else{
            printf("Tidak ada game dengan nomor tersebut.\n");
        }
    }
}