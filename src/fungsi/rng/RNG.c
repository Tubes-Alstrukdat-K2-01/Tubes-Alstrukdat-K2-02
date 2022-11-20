#include "RNG.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../../ADT/mesinkata/mesinkata.h"

void RNG() {
    int giliran,skor,angka,max,count;
    boolean main = true,menang = false;
    int tebakan;
    srand(time(0));
    giliran = 20;
    skor = 0;
    max = 0;
    count = 1;
    int digitmax = 0;
    for (int i = 0;i < 8;i++) {
        max = max + rand()%((int)pow(2,i));
    }

    angka = rand()%max;
    max--;
    /* debugging variabel

    angka = 10;
    max = 15;
    printf("%d %d %d %d",giliran,skor,angka,max);

    */
    
    printf("===========GAME RNG TELAH DIMULAI==========\n");
    printf("==========PERSIAPKAN TEBAKAN ANDA==========\n");
    printf("=========ANGKA MAKSIMAL ADALAH %d=======",max);
    int temp = max;
    do {
    temp /= 10;
    ++digitmax;
    } while (temp != 0);
    for (int i = 0;i < 5-digitmax;i++) {
    printf("=");
    } 
    printf("\n");
    while (main) {
        if (count == 1) {
            printf("            TEBAKAN PERTAMA: ");
        }
        else {
            printf("            SILAKAN COBA LAGI\n");
            printf("               TEBAKAN: ");
        }
        //STARTWORD();
        STARTWORD();
        while(isEndWord()){
            STARTWORD();
        }
        tebakan = 0;
        int i;
        for(i=0; i<currentWord.Length; i++){
            if(currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9'){
                tebakan *= 10;
                tebakan += (int)(currentWord.TabWord[i]-48);
            }
        }
        //int tebakan = atoi(currentWord.TabWord);
        //ADVWORD();
        if (tebakan > angka) {
            printf("===========KAYAKNYA KEBESARAN DEH===========\n");
        }
        if (tebakan < angka) {
            printf("===========KAYAKNYA KEKECILAN DEH===========\n");
        }

        if ( tebakan == angka ) {
            main = false;
            menang = true;
        }
        else if (count == giliran) {
            main = false;
            menang = false;
        }
        count++;
    }
    printf("\n");
    if ( menang ) {
        skor = (21-count)*5;
        printf("HEBAT,KAMU BERHASIL MENEBAK\n");
        printf("SKOR YANG KAMU DAPAT ADALAH %d\n",skor);
    } else {
        printf("SAYANG SEKALI KAMU BELUM BERHASIL\n");
        printf("SKOR YANG KAMU DAPAT ADALAH %d\n",1);
    }
}

