#include "creategame.h"
#include <stdio.h>

static FILE *pita;

boolean isSame(Kata k1, Kata k2){
    if(k1.Length != k2.Length){
        return false;
    }
    else{
        boolean same = true;
        int i;
        for(i=0; i<k1.Length; i++){
            if(k1.Tab[i] != k2.Tab[i]){
                same = false;
            }
        }
        return same;
    }
}

void CREATEGAME (ArrayDin *arrayGames){
    int i;
    char name[255];
    boolean found = false;
    printf("Masukkan nama game yang akan ditambahkan: "); 
    pita = stdin;
    while(pita == NULL){
        printf("Masukkan INVALID! Silahkan Masukkan kembali :");
        pita = stdin;
    }
    fgets(name,255,pita);
    Kata game;
    MakeKata(&game);
    CopyStringtoKata(&game, name);
    // Megecek apakah nama game sudah terdaftar atau belum
    for (i=0; i < (*arrayGames).Neff; i++){
        if (isSame((*arrayGames).A[i],game)){
            found = true;
        }
    }
    if (!found) // Kondisi ketika game belum terdaftar
    {
        InsertLast(arrayGames,game);
        printf("Game berhasil ditambahkan\n");
    } 
    else // Kondisi ketika game telah terdaftar
    {
        printf("Game telah terdaftar\n");
    }
}