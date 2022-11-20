// Header
#include "queuediner.h"
#include <stdio.h>
// /* Definisi ADT QueueDiner dengan representasi array secara eksplisit dan alokasi statik */

// #ifndef QUEUE_H
// #define QUEUE_H

// #include "boolean.h"

// #define IDX_UNDEF -1
// #define CAPACITY 100

// /* Definisi elemen dan address */
// typedef int ElType;
// typedef struct {
// 	ElType buffer[CAPACITY]; 
// 	int idxHead;
// 	int idxTail;
// } QueueDiner;


// /* ********* AKSES (Selektor) ********* */
// /* Jika q adalah QueueDiner, maka akses elemen : */
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).buffer[(q).idxHead]
// #define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueueDiner(Queuediner *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDiner(Queuediner q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullDiner(Queuediner q){
    return ((CAPACITY+IDX_TAIL(q)-IDX_HEAD(q))%CAPACITY == CAPACITY-1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthDiner(Queuediner q){
    if (isEmptyDiner(q)){
        return 0;
    }
    else {
        return (((CAPACITY+IDX_TAIL(q)-IDX_HEAD(q))%CAPACITY)+1) ;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueDiner(Queuediner *q, int makanan, int durasi, int ketahanan, int harga){
    if (isEmptyDiner(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q)+1)%CAPACITY;
    }
    TAIL_makanan(*q) = makanan;
    TAIL_durasi(*q) = durasi;
    TAIL_ketahanan(*q) = ketahanan;
    TAIL_harga(*q) = harga;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueDiner(Queuediner *q, int *makanan, int *durasi, int *ketahanan, int *harga){
    *makanan = HEAD_makanan(*q);
    *durasi = HEAD_durasi(*q);
    *ketahanan = HEAD_ketahanan(*q);
    *harga = HEAD_harga(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1)%CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

boolean isMember(Queuediner q, int makanan){
    if(isEmptyDiner(q)){
        return false;
    }
    else{
        int i;
        boolean found = false;
        if (IDX_TAIL(q) >= IDX_HEAD(q)){
            i = IDX_HEAD(q);
            while((i <= IDX_TAIL(q)) && (!found)){
                if(q.buffer[i].makanan == makanan){
                    found = true;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
        }
        else {
            i = IDX_HEAD(q);
            while((i < CAPACITY) && (!found)){
                if(q.buffer[i].makanan == makanan){
                    found = true;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
            i = 0;
            while((i <= IDX_TAIL(q)) && (!found)){
                if(q.buffer[i].makanan == makanan){
                    found = true;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
        }
        return found;
    }
}
/*
   I.S : q dan makanan sembarangan
   F.S : True jika makanan ada di dalam queue
*/

void dequeueMember(Queuediner *q, int *makanan, int *durasi, int *ketahanan, int *harga){
    if(isMember(*q,*makanan)){
        int idx;
        boolean found = false;
        if (IDX_TAIL(*q) >= IDX_HEAD(*q)){
            idx = IDX_HEAD(*q);
            while((idx <= IDX_TAIL(*q)) && (!found)){
                if((*q).buffer[idx].makanan == *makanan){
                    found = true;
                }
                else{
                    idx = (idx+1)%CAPACITY;
                }
            }
            *durasi = (*q).buffer[idx].durasi;
            *ketahanan = (*q).buffer[idx].ketahanan;
            *harga = (*q).buffer[idx].harga;
            if(IDX_HEAD(*q) == IDX_TAIL(*q)){
                IDX_HEAD(*q) = IDX_UNDEF;
                IDX_TAIL(*q) = IDX_UNDEF;
            }
            else{
                for(idx; idx < IDX_TAIL(*q); idx++){
                    (*q).buffer[idx].makanan = (*q).buffer[idx+1].makanan;
                    (*q).buffer[idx].durasi = (*q).buffer[idx+1].durasi;
                    (*q).buffer[idx].ketahanan = (*q).buffer[idx+1].ketahanan;
                    (*q).buffer[idx].harga = (*q).buffer[idx+1].harga;
                }
                IDX_TAIL(*q) -= 1;
            }
        }
        else {
            int i = IDX_HEAD(*q);
            while((i < CAPACITY) && (!found)){
                if((*q).buffer[i].makanan == *makanan){
                    found = true;
                    idx = i;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
            i = 0;
            while((i <= IDX_TAIL(*q)) && (!found)){
                if((*q).buffer[i].makanan == *makanan){
                    found = true;
                    idx = i;
                }
                else{
                    i = (i+1)%CAPACITY;
                }
            }
            *durasi = (*q).buffer[idx].durasi;
            *ketahanan = (*q).buffer[idx].ketahanan;
            *harga = (*q).buffer[idx].harga;
            if(idx > IDX_HEAD(*q)){
                for(i=idx; i<CAPACITY+IDX_TAIL(*q); i++){
                    (*q).buffer[i%CAPACITY].makanan = (*q).buffer[(i+1)%CAPACITY].makanan;
                    (*q).buffer[i%CAPACITY].durasi = (*q).buffer[(i+1)%CAPACITY].durasi;
                    (*q).buffer[i%CAPACITY].ketahanan = (*q).buffer[(i+1)%CAPACITY].ketahanan;
                    (*q).buffer[i%CAPACITY].harga = (*q).buffer[(i+1)%CAPACITY].harga;
                }
            }
            else{
                for(i=idx; i<IDX_TAIL(*q); i++){
                    (*q).buffer[i%CAPACITY].makanan = (*q).buffer[(i+1)%CAPACITY].makanan;
                    (*q).buffer[i%CAPACITY].durasi = (*q).buffer[(i+1)%CAPACITY].durasi;
                    (*q).buffer[i%CAPACITY].ketahanan = (*q).buffer[(i+1)%CAPACITY].ketahanan;
                    (*q).buffer[i%CAPACITY].harga = (*q).buffer[(i+1)%CAPACITY].harga;
                }
            }
            IDX_TAIL(*q) -= 1;
        }
    }
}
/*
   I.S : q dan makanan sembarangan, makanan bisa bukan anggota dari q
   F.S : q dengan makanan telah dihapus
*/
