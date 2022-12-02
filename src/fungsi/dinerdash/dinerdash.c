#include "dinerdash.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

boolean gameover(Queuediner q, int pelayanan){
    return ((lengthDiner(q) > 7) || pelayanan == 15);
}
/*
    I.S : q dan pelanggaran sembarang
    F.S : True jika panjang antrian queueDiner lebih dari 7 atau pelayanan mencapai 15
          False jika belum termasuk katergori di atas
*/

void displayPesanan(Queuediner q){
    printf("Daftar Pesanan\n");
    printf("Memasak | Durasi memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    if(isEmptyDiner(q)){
        printf("        |                |           |      \n");
    }
    else{
        int i;
        if (IDX_TAIL(q) >= IDX_HEAD(q)){
            for(i=IDX_HEAD(q) ; i <= IDX_TAIL(q) ; i++){
                printf("M%d     | %d             | %d        | %d\n",q.buffer[i].makanan, q.buffer[i].durasi, q.buffer[i].ketahanan, q.buffer[i].harga);
            }
        }
        else {
            for(i=IDX_HEAD(q) ; i <= CAPACITY+IDX_TAIL(q) ; i++){
                printf("M%d     | %d             | %d        | %d\n",q.buffer[i%CAPACITY].makanan, q.buffer[i%CAPACITY].durasi, q.buffer[i%CAPACITY].ketahanan, q.buffer[i%CAPACITY].harga);
            }
        }
    }
}
/*
    I.S : q sembarang
    F.S : Menampilkan Pesanan yang terdiri dari Makanan, Durasi, Ketahanan, dan Harga
*/

void displayMemasak(Queuediner q){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Memasak | Sisa durasi memasak \n");
    printf("------------------------------\n");
    if(isEmptyDiner(q)){
        printf("        |                \n");
    }
    else{
        int i;
        if (IDX_TAIL(q) >= IDX_HEAD(q)){
            for(i=IDX_HEAD(q) ; i <= IDX_TAIL(q) ; i++){
                if(q.buffer[i].durasi != 0){
                    printf("M%d     | %d                \n",q.buffer[i].makanan, q.buffer[i].durasi);
                }
            }
        }
        else {
            for(i=IDX_HEAD(q) ; i <= CAPACITY+IDX_TAIL(q) ; i++){
                if(q.buffer[i%CAPACITY].durasi != 0){
                    printf("M%d     | %d                \n",q.buffer[i%CAPACITY].makanan, q.buffer[i%CAPACITY].durasi);
                }
            }
        }
    }
}
/*
    I.S : q sembarang
    F.S : Menampilkan Daftar Pesanan yang sedang dimasak yang terdiri dari Makanan dan Durasi
*/

void displayDisajikan(Queuediner q){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Memasak | Sisa ketahanan memasak \n");
    printf("------------------------------\n");
    if(isEmptyDiner(q)){
        printf("        |                \n");
    }
    else{
        int i;
        if (IDX_TAIL(q) >= IDX_HEAD(q)){
            for(i=IDX_HEAD(q) ; i <= IDX_TAIL(q) ; i++){
                if(q.buffer[i].durasi == 0){
                    printf("M%d     | %d                \n",q.buffer[i].makanan, q.buffer[i].ketahanan);
                }
            }
        }
        else {
            for(i=IDX_HEAD(q) ; i <= CAPACITY+IDX_TAIL(q) ; i++){
                if(q.buffer[i%CAPACITY].durasi == 0){
                    printf("M%d     | %d                \n",q.buffer[i%CAPACITY].makanan, q.buffer[i%CAPACITY].ketahanan);
                }
            }
        }
    }
}
/*
    I.S : q sembarang
    F.S : Menampilkan Daftar Masakan yang sudah bisa disajikan yang sedang dimasak yang terdiri dari Makanan dan Ketahanan
*/
void cook(Queuediner qpesan, Queuediner *qmasak, int makanan){
    if(isMember(qpesan,makanan)){
        if(isMember(*qmasak,makanan)){
            printf("Makanan sedang atau sudah dimasak!\n");
        }
        else{
            if(availablecook(*qmasak)){
                printf("Berhasil memasak M%d\n",makanan);
                turn(qmasak);
                int durasi,ketahaan,harga;
                dequeueMember(&qpesan, &makanan, &durasi, &ketahaan, &harga);
                enqueueDiner(qmasak,makanan,durasi,ketahaan,harga);
            }
            else{
                printf("Kapasitas memasak telah mencapai batas!\n");
            }
        }
    }
    else{
        printf("Makanan tidak ada dalam antrian pesanan!\n");
    }
}
/*
    I.S : Input bebas
    F.S : Memasukkan makanan kedalam qmasak selama masih availablecook
*/

void serve(Queuediner *qpesan, Queuediner *qmasak, int makanan, int *pelayanan, int *saldo, int *m){
    if(isMember(*qmasak,makanan)){
        int idx;
        boolean found = false;
        if (IDX_TAIL(*qmasak) >= IDX_HEAD(*qmasak)){
            idx = IDX_HEAD(*qmasak);
            while((idx <= IDX_TAIL(*qmasak)) && (!found)){
                if((*qmasak).buffer[idx].makanan == makanan){
                    found = true;
                }
                else{
                    idx = (idx+1)%CAPACITY;
                }
            }
        }
        else {
            int i = IDX_HEAD(*qmasak);
            while((i < CAPACITY) && (!found)){
                if((*qmasak).buffer[i].makanan == makanan){
                    found = true;
                    idx = i;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
            i = 0;
            while((i <= IDX_TAIL(*qmasak)) && (!found)){
                if((*qmasak).buffer[i].makanan == makanan){
                    found = true;
                    idx = i;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
        }
        if((*qmasak).buffer[idx].durasi == 0){
            if(HEAD_makanan(*qpesan) == makanan){
                printf("M%d berhasil diantar\n",makanan);
                int durasi, ketahanan, harga;
                dequeueDiner(qpesan,&makanan,&durasi,&ketahanan,&harga);
                *saldo += harga;
                dequeueMember(qmasak,&makanan,&durasi,&ketahanan,&harga);
                *pelayanan++;
                turn(qmasak);
                durasi = rand()%5 + 1;
                ketahanan = rand()%5 + 1;
                harga = (rand()%41 + 10)*1000;
                enqueueDiner(qpesan,*m,durasi,ketahanan,harga);
                *m += 1;
            }
            else{
                printf("M%d belum dapat disajikan karena M%d belum selesai\n",makanan,HEAD_makanan(*qpesan));
            }
        }
        else{
            printf("Makanan belum selesai dimasak!\n");
        }
    }
}
/*
    I.S : Input bebas
    F.S : Jika makanan adalah head qpesan maka makanan akan dihapus dari qmasak dan pelayanan diincrement 1
          Jika tidak maka output "makanan" belum dapat disajikan karena "head qpesan" belum selesai
*/

void turn(Queuediner *q){
    int i;
    if (IDX_TAIL(*q) >= IDX_HEAD(*q)){
        for(i=IDX_HEAD(*q) ; i <= IDX_TAIL(*q) ; i++){
            if((*q).buffer[i].durasi == 0){
                (*q).buffer[i].ketahanan--;
                if((*q).buffer[i].ketahanan == 0){
                    printf("Makanan M%d telah basi!\n",(*q).buffer[i].makanan);
                    int makanan = (*q).buffer[i].makanan;
                    int durasi, ketahanan, harga;
                    dequeueMember(q,&makanan,&durasi,&ketahanan,&harga);
                }
            }
            else{
                (*q).buffer[i].durasi--;
                if((*q).buffer[i].durasi == 0){
                    printf("Masakan M%d telah selesai dimasak\n",(*q).buffer[i].makanan);
                }
            }
        }
    }
    else {
        for(i=IDX_HEAD(*q) ; i <= CAPACITY+IDX_TAIL(*q) ; i++){
            if((*q).buffer[i%CAPACITY].durasi == 0){
                (*q).buffer[i%CAPACITY].ketahanan--;
                if((*q).buffer[i%CAPACITY].ketahanan == 0){
                    printf("Makanan M%d telah basi!\n", (*q).buffer[i%CAPACITY].makanan);
                    int makanan = (*q).buffer[i%CAPACITY].makanan;
                    int durasi, ketahanan, harga;
                    dequeueMember(q,&makanan,&durasi,&ketahanan,&harga);
                }
            }
            else{
                (*q).buffer[i%CAPACITY].durasi--;
                if((*q).buffer[i%CAPACITY].durasi == 0){
                    printf("Masakan M%d telah selesai dimasak\n",(*q).buffer[i%CAPACITY].makanan);
                }
            }
        }
    }
}
/*
    I.S : qmasak sembarang
    F.S : Melakukan decrement pada durasi yang tidak 0 dan melakukan decrement pada ketahanan jika durasi == 0
*/

boolean availablecook(Queuediner q){
    int i;
    int count = 0;
    if (IDX_TAIL(q) >= IDX_HEAD(q)){
        for(i=IDX_HEAD(q) ; i <= IDX_TAIL(q) ; i++){
            if((q).buffer[i].durasi == 0){
                count++;
            }
        }
    }
    else {
        for(i=IDX_HEAD(q) ; i <= CAPACITY+IDX_TAIL(q) ; i++){
            if((q).buffer[i%CAPACITY].durasi == 0){
                count++;
            }
        }
    }
    return (count <= 5);
}
/*
    I.S : q sembarang
    F.S : True jika sumpah yang sedang dimasak tidak lebih dari 5, tanda bahwa sedang dimasak adalah durasi != 0
*/

void dinerdash(){
    Queuediner qpesan, qmasak;
    CreateQueueDiner(&qpesan); CreateQueueDiner(&qmasak);
    int makanan=0, durasi, ketahanan, harga;
    srand(time(0));
    for(makanan; makanan < 3; makanan++){
        durasi = rand()%5 + 1;
        ketahanan = rand()%5 + 1;
        harga = (rand()%41 + 10)*1000;
        enqueueDiner(&qpesan, makanan, durasi, ketahanan, harga);
    }
    int pelayanan = 0, saldo = 0;
    printf("Selamat Datang di Diner Dash!\n\n");
    while(!gameover(qpesan,pelayanan)){
        printf("SALDO: %d\n\n",saldo);
        displayPesanan(qpesan);
        printf("\n");
        displayMemasak(qmasak);
        printf("\n");
        displayDisajikan(qmasak);
        printf("\n");
        char command[50];
        int m = 0;
        printf("MASUKKAN COMMAND: ");
        STARTWORD();
        int i;
        for (i=0; i<currentWord.Length; i++){
            command[i] = currentWord.TabWord[i];
        }
        ADVWORD();
        boolean invalid = false;
        if(!isEndWord()){
            for (i=1; i<currentWord.Length; i++){
                if(currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9'){
                    m *= 10;
                    m += (int)(currentWord.TabWord[i]-48);
                }
                else{
                    invalid = true;
                }
            }
            ADVWORD();
        }
        if(isEndWord() && (!invalid)){
            if((command[0] == 'S' || command[0] == 's') && (command[1] == 'E' || command[1] == 'e') && (command[2] == 'R' || command[2] == 'r') && (command[3] == 'V' || command[3] == 'v') && (command[4] == 'E' || command[4] == 'e')){
                serve(&qpesan, &qmasak, m, &pelayanan, &saldo, &makanan);
            }
            else if((command[0] == 'C' || command[0] == 'c') && (command[1] == 'O' || command[1] == 'o') && (command[2] == 'O' || command[2] == 'o') && (command[3] == 'K' || command[3] == 'k')){
                if((isMember(qpesan,m)) && (!isMember(qmasak,m)) && (availablecook(qmasak))){
                    cook(qpesan,&qmasak,m);
                    durasi = rand()%5 + 1;
                    ketahanan = rand()%5 + 1;
                    harga = (rand()%41 + 10)*1000;
                    enqueueDiner(&qpesan, makanan, durasi, ketahanan, harga);
                    makanan++;
                }
                if(!isMember(qpesan,m)){
                    printf("Makanan belum dimasak atau tidak ada dalam pesanan\n");
                }
            }
            else if((command[0] == 'S' || command[0] == 's') && (command[1] == 'K' || command[1] == 'k') && (command[2] == 'I' || command[2] == 'i') && (command[3] == 'P' || command[3] == 'p')){
                printf("Berhasil Melakukan SKIP\n");
                turn(&qmasak);
                durasi = rand()%5 + 1;
                ketahanan = rand()%5 + 1;
                harga = (rand()%41 + 10)*1000;
                enqueueDiner(&qpesan, makanan, durasi, ketahanan, harga);
                makanan++;
            }
            else{
                printf("INVALID COMMAND!\n");
            }
        }
        else{
            printf("INVALID COMMAND!\n");
        }
        printf("==========================================================\n\n");
        saldo = (saldo+1)/1000;
        saldo = saldo*1000;
    }
    saldo = (saldo+1)/1000;
    saldo = saldo*1000;
    printf("Game Over!, SALDO ANDA: %d\n",saldo);
    InsertScore(1,saldo);
}