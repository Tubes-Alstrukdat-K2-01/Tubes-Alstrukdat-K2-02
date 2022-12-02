#include "towerofhanoi.h"

void printnchar(char c, int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%c",c);
    }
}
// Menampilkan char c sebanyak n kali dalam satu baris

void displayTOH(Stack A, Stack B, Stack C, int n){
    infotype1 x;
    int temp = n, space;
    while(!(IsEmptyStack(A)) || !(IsEmptyStack(B)) || !(IsEmptyStack(C))){
        if(Count(A) == temp){
            Pop(&A,&x);
            space = ((2*n-1) - x)/2;
            printnchar(' ',space); printnchar('*',x); printnchar(' ',space);
            printf("  ");
        }
        else{
            space = ((2*n-1) - 1)/2;
            printnchar(' ',space); printf("|"); printnchar(' ',space);
            printf("  ");
        }
        if(Count(B) == temp){
            Pop(&B,&x);
            space = ((2*n-1) - x)/2;
            printnchar(' ',space); printnchar('*',x); printnchar(' ',space);
            printf("  ");
        }
        else{
            space = ((2*n-1) - 1)/2;
            printnchar(' ',space); printf("|"); printnchar(' ',space);
            printf("  ");
        }
        if(Count(C) == temp){
            Pop(&C,&x);
            space = ((2*n-1) - x)/2;
            printnchar(' ',space); printnchar('*',x); printnchar(' ',space);
            printf("\n");
        }
        else{
            space = ((2*n-1) - 1)/2;
            printnchar(' ',space); printf("|"); printnchar(' ',space);
            printf("\n");
        }
        temp--;
    }
    printnchar('-',(2*n-1)); printf("  "); printnchar('-',(2*n-1)); printf("  "); printnchar('-',(2*n-1)); printf("\n");
    printnchar(' ',(2*n-1)/2); printf("A"); printnchar(' ',(2*n-1)/2); printf("  ");
    printnchar(' ',(2*n-1)/2); printf("B"); printnchar(' ',(2*n-1)/2); printf("  ");
    printnchar(' ',(2*n-1)/2); printf("C"); printnchar(' ',(2*n-1)/2); printf("\n\n");
}
// Menampilkan piringan yang berada pada stack

void insertTOH(Stack *S1, Stack *S2, int *step){
    infotype1 x;
    if(IsEmptyStack(*S1)){
        printf("Tidak ada piringan pada tower asal!\n\n");
    }
    else{
        if(!IsEmptyStack(*S2) && (InfoTop(*S2) < InfoTop(*S1))){
            printf("Piringan dari tower asal lebih besar dari piringan tower tujuan!\n\n");
        }
        else{
            printf("Sedang memindahkan piringan ke tower tujuan...\n\n");
            *step += 1;
            Pop(S1, &x);
            Push(S2, x);
        }
    }
}
// Memindahkan pirngan dari Top S1 ke Top S2 dengan aturan TOH

char commandTOH(){
    char result;
    START();
    if(!IsEOP()){
        if(currentChar == 'A' || currentChar == 'a' || currentChar == 'B' || currentChar == 'b' || currentChar == 'C' || currentChar == 'c'){
            result = currentChar;
        } 
        else{
            return '1';
        }
        ADV();
        if(IsEOP()){
            return result;
        }
        else{
            while(!IsEOP()){
                ADV();
            }
            return '1';
        }
    }
    else{
        return '1';
    }
}
// Mendapatkan inputan dari user

void towerofhanoi(){
    Stack A, B, C;
    int step = 0, skor;
    CreateEmpty(&A); CreateEmpty(&B); CreateEmpty(&C);
    int n, i; 
    boolean invalid = true;
    printf("Masukkan jumlah piringan yang ingin dimainkan: ");
    while(invalid){
        n = 0;
        invalid = false;
        STARTWORD();
        if(!isEndWord()){
            for (i=0; i<currentWord.Length; i++){
                if(currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9'){
                    n *= 10;
                    n += (int)(currentWord.TabWord[i]-48);
                }
                else{
                    invalid = true;
                }
            }
            ADVWORD();
            if(!isEndWord()){
                invalid = true;
                while(!isEndWord()){
                    ADVWORD();
                }
            }
        }
        else{
            invalid = true;
        }
        if(invalid){
            printf("Masukkan Invalid! Silahkan masukkan kembali banyak piringan yang ingin dimainkan: ");
        }
    }
    // Create STACK
    for(i=n; i>0; i--){
        Push(&A, (2*i-1));
    }
    // Command
    displayTOH(A,B,C,n);
    char asal, tujuan;
    boolean valid1, valid2;
    while(Count(C) != n){
        valid1 = true; valid2 = true;
        printf("TIANG ASAL : ");
        asal = commandTOH();
        printf("TIANG TUJUAN : ");
        tujuan = commandTOH();
        if(asal == '1'){
            valid1 = false;
        }
        if(tujuan == '1'){
            valid2 = false;
        }
        while(!valid1 || !valid2){
            printf("\nMasukkan Invalid! Silahkan Input Kembali!\n");
            printf("TIANG ASAL : ");
            asal = commandTOH();
            printf("TIANG TUJUAN : ");
            tujuan = commandTOH();
            if(asal == '1'){
                valid1 = false;
            }
            else{
                valid1 = true;
            }
            if(tujuan == '1'){
                valid2 = false;
            }
            else{
                valid2 = true;
            }
        }
        printf("\n");
        if(asal == 'A' || asal == 'a'){
            if(tujuan == 'A' || tujuan == 'a'){
                printf("Tidak Bisa Memindahkan Piringan dari Asal dan Tujuan yang Sama!\n\n");
            }
            else if(tujuan == 'B' || tujuan == 'b'){
                insertTOH(&A, &B, &step);
            }
            else{
                insertTOH(&A, &C, &step);
            }
        }
        else if(asal == 'B' || asal == 'b'){
            if(tujuan == 'A' || tujuan == 'a'){
                insertTOH(&B, &A, &step);
            }
            else if(tujuan == 'B' || tujuan == 'b'){
                printf("Tidak Bisa Memindahkan Piringan dari Asal dan Tujuan yang Sama!\n\n");
            }
            else{
                insertTOH(&B, &C, &step);
            }
        }
        else{
            if(tujuan == 'A' || tujuan == 'a'){
                insertTOH(&C, &A, &step);
            }
            else if(tujuan == 'B' || tujuan == 'b'){
                insertTOH(&C, &B, &step);
            }
            else{
                printf("Tidak Bisa Memindahkan Piringan dari Asal dan Tujuan yang Sama!\n\n");
            }
        }
        displayTOH(A,B,C,n);
    }
    printf("Permainan Berakhir! Banyak Steps yang dilakukan adalah %d\n",step);
    int scale = 1;
    for(i = 0; i < n; i++){
        scale *= 2;
    }
    skor = 99 + scale - step;
    if(skor < 0){
        skor = 0;
    }
    printf("Skor Akhir : %d\n",skor);
}
// Main fungsi game tower of hanoi