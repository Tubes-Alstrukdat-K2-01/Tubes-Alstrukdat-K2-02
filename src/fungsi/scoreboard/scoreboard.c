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

void InsertScore(int game, int score){
    printf("Nama: ");
    STARTWORD();
    Kata nama; MakeKata(&nama);
    CopyWordtoKata(&nama,currentWord);
    if(!MIsMember(SC[game],nama)){
        MInsert(&SC[game], nama, score);
    }
    else{
        printf("Nama yang digunakan sudah ada di dalam scoreboard!\n");
    }
    while(!isEndWord()){
        ADVWORD();
    }
}

void ResetScore(ArrayDin TabGame){
    printf("Pilih game yang ingin direset: \n");
    printf("0. All\n");
    for (int i = 0; i < TabGame.Neff; i++){
        printf("%d. %s\n", i+1, TabGame.A[i].Tab);
    }
    int n;
    printf("Pilihan (0-%d): ", TabGame.Neff);
    int pil, i;
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
            printf("Masukkan Invalid! Silahkan Masukkan Pilihan Kembali : ");
        }
    }
    if (pil == 0){
        for (int i = 0; i < TabGame.Neff; i++){
            MCreateEmpty(&SC[i]);
        }
        printf("Scoreboard berhasil direset!\n");
    }
    else if(pil > TabGame.Neff){
        printf("Tidak Ada Scoreboard untuk Pilihan Tersebut\n");
    } 
    else{
        MCreateEmpty(&SC[pil-1]);
        printf("Scoreboard berhasil direset!\n");
    }
}