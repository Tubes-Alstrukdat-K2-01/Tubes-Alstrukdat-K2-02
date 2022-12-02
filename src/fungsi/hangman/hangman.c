#include "hangman.h"
#include "../../ADT/word/word.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/setmap/set.h"
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
//semua game ngasilin score (int)
void hangman(){
    ArrayDin Katalist = initKatalist();
    ArrayDin descList = initDescList();

    // printf("%d\n", random);
    int score = 0;
    printf("Selamat datang di game Hangman!\n");
    printf("Game ini akan mengacak sebuah kata dan memberikan deskripsi dari kata tersebut.\n");
    printf("Kamu harus menebak kata tersebut dengan menebak satu huruf per satu huruf.\n");
    printf("Jika salah menebak, kamu akan diberikan kesempatan untuk menebak lagi.\n");
    printf("Jika salah menebak 6 kali, kamu akan kalah.\n");
    printf("Jika berhasil menebak, kamu akan menang.\n");
    printf("Selamat bermain!\n");
    int wrongGuess = 0; //kempatan
    boolean lose = false;
    Set guessedChar;
    SCreateEmpty(&guessedChar);
    while (!lose){
        int i;
        srand(time(0));
        int random = rand() % Katalist.Neff;
        Kata kata = Katalist.A[random];
        Kata desc = descList.A[random];
        int KataLength = kata.Length;
        int correctGuess = 0;
        char guess;
        char KataGuess[50];
        for(i=0; i<KataLength; i++){
            KataGuess[i] = '_';
        }
        KataGuess[KataLength] = '\0';
        while(wrongGuess < 10 && correctGuess < KataLength){
            printf("\nKata: %s\n", KataGuess);
            printf("Deskripsi: %s\n", desc.Tab);
            printf("Kesempatan : %d\n", 10-wrongGuess);
            printf("Huruf yang sudah ditebak: %s\n", guessedChar.Elmt);
            printf("Masukkan huruf: ");
            scanf(" %c", &guess);
            boolean found = false;
            if (SIsMember(guessedChar, toLower(guess))){
                printf("Kamu sudah pernah menebak huruf %c\n", guess);
                continue;
            }
            for(i=0; i<KataLength; i++){
                if(toLower(kata.Tab[i]) == guess && KataGuess[i] == '_'){
                    KataGuess[i] = kata.Tab[i];
                    correctGuess++;
                    found = true;
                }
            }
            if(correctGuess == KataLength){
                printf("Selamat, kamu berhasil menebak kata tersebut!\n");
                printf("Kata: %s\n", KataGuess);
                score += KataLength;
                break;
            }
            if(!found){
                wrongGuess++;
                printf("Kamu salah menebak!\n");
                printf("Kesempatan salah menebak: %d\n", 10-wrongGuess);
            }
            printf("Kata: %s\n", KataGuess);
            SInsert(&guessedChar, guess);
        }
        if(wrongGuess == 10){
            printf("Kamu kalah!\n");
            printf("Kata yang harus ditebak: %s\n", kata.Tab);
            lose = true;
        }
    }
    printf("Score yang kamu dapatkan: %d\n", score);
}