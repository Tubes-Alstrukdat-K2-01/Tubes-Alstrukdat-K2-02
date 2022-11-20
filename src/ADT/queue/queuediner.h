/* File : queue.h */
/* Definisi ADT QueueDiner dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __QUEUE_DINER__
#define __QUEUE_DINER__

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 10

/* Definisi elemen dan address */
typedef struct {
        int makanan;
        int durasi; //dari 1-5
        int ketahanan; //dari 1-5
        int harga; //dari 10000-50000 dengan kelipatan 1000
} ElTypeDiner;

/* Definisi elemen, tail dan head */
typedef struct {
        ElTypeDiner buffer[CAPACITY];
        int idxTail;
        int idxHead;
} Queuediner ;



/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueDiner, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD_makanan(q) (q).buffer[(q).idxHead].makanan
#define     HEAD_durasi(q) (q).buffer[(q).idxHead].durasi
#define     HEAD_ketahanan(q) (q).buffer[(q).idxHead].ketahanan
#define     HEAD_harga(q) (q).buffer[(q).idxHead].harga
#define     TAIL_makanan(q) (q).buffer[(q).idxTail].makanan
#define     TAIL_durasi(q) (q).buffer[(q).idxTail].durasi
#define     TAIL_ketahanan(q) (q).buffer[(q).idxTail].ketahanan
#define     TAIL_harga(q) (q).buffer[(q).idxTail].harga

/* *** Kreator *** */
void CreateQueueDiner(Queuediner *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDiner(Queuediner q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullDiner(Queuediner q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthDiner(Queuediner q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueDiner(Queuediner *q, int makanan,int durasi ,int ketahanan, int harga);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueDiner(Queuediner *q, int *makanan,int *durasi, int *ketahanan, int *harga);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

boolean isMember(Queuediner q, int makanan);
/*
   I.S : q dan makanan sembarangan
   F.S : True jika makanan ada di dalam queue
*/

void dequeueMember(Queuediner *q, int *makanan, int *durasi, int *ketahanan, int *harga);
/*
   I.S : q dan makanan sembarangan, makanan bisa bukan anggota dari q
   F.S : q dengan makanan telah dihapus
*/

#endif