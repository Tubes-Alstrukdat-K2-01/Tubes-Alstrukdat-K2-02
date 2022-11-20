#include "hangman.h"
#include "../../ADT/word/word.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char toLower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + 32;
    }
    else{
        return c;
    }
}
ArrayDin initKatalist(){
    ArrayDin A = MakeArrayDin();
    int i;

    InsertAt(&A, StringtoKata("Lapar"),0);
    InsertAt(&A, StringtoKata("Kenyang"),1);
    InsertAt(&A, StringtoKata("Makan"),2);
    return A;
}
ArrayDin initDescList(){
    ArrayDin A = MakeArrayDin();
    int i;
    InsertAt(&A, StringtoKata("berasa ingin makan (karena perut kosong)"),0);
    InsertAt(&A, StringtoKata("sudah puas makan"),1);
    InsertAt(&A, StringtoKata("bikin kenyang"),2);
    return A;
}

void hangman(){
    srand(time(0));
    ArrayDin Katalist = initKatalist();
    ArrayDin descList = initDescList();

    int i;
    int random = rand() % Katalist.Neff;
    // printf("%d\n", random);
    Kata kata = Katalist.A[random];
    Kata desc = descList.A[random];
    int KataLength = kata.Length;
    int wrongGuess = 0;
    int correctGuess = 0;
    char guess;
    char KataGuess[50];
    for(i=0; i<KataLength; i++){
        KataGuess[i] = '_';
    }
    KataGuess[KataLength] = '\0';
    printf("Selamat datang di game Hangman!\n");
    printf("Game ini akan mengacak sebuah kata dan memberikan deskripsi dari kata tersebut.\n");
    printf("Kamu harus menebak kata tersebut dengan menebak satu huruf per satu huruf.\n");
    printf("Jika salah menebak, kamu akan diberikan kesempatan untuk menebak lagi.\n");
    printf("Jika salah menebak 6 kali, kamu akan kalah.\n");
    printf("Jika berhasil menebak, kamu akan menang.\n");
    printf("Selamat bermain!\n");
    printf("Deskripsi: %s\n", desc.Tab);
    printf("Kata: %s\n", KataGuess);
    while(wrongGuess < 6 && correctGuess < KataLength){
        printf("Masukkan huruf: ");
        scanf(" %c", &guess);
        boolean found = false;
        for(i=0; i<KataLength; i++){
            if(toLower(kata.Tab[i]) == guess){
                KataGuess[i] = kata.Tab[i];
                correctGuess++;
                found = true;
            }
        }
        if(correctGuess == KataLength){
            printf("Selamat, kamu berhasil menebak kata tersebut!\n");
            printf("Kata: %s\n", KataGuess);
            break;
        }
        if(!found){
            wrongGuess++;
            printf("Kamu salah menebak!\n");
            printf("Kesempatan salah menebak: %d\n", 6-wrongGuess);
        }
        printf("Kata: %s\n", KataGuess);
    }
    if(wrongGuess == 6){
        printf("Kamu kalah!\n");
        printf("Kata yang harus ditebak: %s\n", kata.Tab);
    }
}