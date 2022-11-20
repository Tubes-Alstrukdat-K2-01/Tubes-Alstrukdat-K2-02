
// Header
#include "queue.h"
#include <stdio.h>
// /* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

// #ifndef QUEUE_H
// #define QUEUE_H

// #include "boolean.h"

// #define IDX_UNDEF -1
// #define CAP 100

// /* Definisi elemen dan address */
// typedef int Kata;
// typedef struct {
// 	Kata buffer[CAP]; 
// 	int idxHead;
// 	int idxTail;
// } Queue;


// /* ********* AKSES (Selektor) ********* */
// /* Jika q adalah Queue, maka akses elemen : */
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).buffer[(q).idxHead]
// #define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q){
    return ((CAP+IDX_TAIL(q)-IDX_HEAD(q))%CAP == CAP-1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQueue(Queue q){
    if (isEmpty(q)){
        return 0;
    }
    else {
        return (((CAP+IDX_TAIL(q)-IDX_HEAD(q))%CAP)+1) ;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Kata val){
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q)+1)%CAP;
    }
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, Kata *val){
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1)%CAP;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    if (isEmpty(q)){
        printf("[]\n");
    }
    else {
        int i;
        if (IDX_TAIL(q) >= IDX_HEAD(q)){
            int j;
            printf("[");
            for(i=IDX_HEAD(q) ; i < IDX_TAIL(q) ; i++){
                for(j=0; j < q.buffer[i].Length; j++){    
                    printf("%c,",q.buffer[i].Tab[j]);
                }
            }
            for(j=0; j < q.buffer[i].Length; j++){    
                printf("%c,",TAIL(q).Tab[j]);
            }
            printf("]\n");
        }
        else {
            int j;
            printf("[");
            for(i=IDX_HEAD(q) ; i < CAP ; i++){
                for(j=0; j < q.buffer[i].Length; j++){    
                    printf("%c,",q.buffer[i].Tab[j]);
                }
            }
            for(i=0; i < IDX_TAIL(q); i++){
                for(j=0; j < q.buffer[i].Length; j++){    
                    printf("%c,",q.buffer[i].Tab[j]);
                }
            }
            for(j=0; j < q.buffer[i].Length; j++){    
                printf("%c,",TAIL(q).Tab[j]);
            }
            printf("]\n");
        }
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

