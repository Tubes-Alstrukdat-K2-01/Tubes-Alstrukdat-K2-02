#include "arraydin.h"
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin p;
    p.A = (Kata*) malloc (InitialSize*sizeof(Kata));
    p.Capacity = InitialSize;
    p.Neff = 0;
    return p;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free((*array).A);
    (*array).Capacity = 0;
    (*array).Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Kata Get(ArrayDin array, IdxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, Kata el, IdxType i){
    if ((*array).Neff == (*array).Capacity){
        Kata *list = (Kata*) malloc (((*array).Capacity*2)*sizeof(Kata));
        IdxType p=0;
        for (p; p<(*array).Neff; p++){
            list[p] = Get(*array , p);
        }
        free((*array).A);
        (*array).A = list;
        (*array).Capacity *= 2;
    }
    IdxType j=(*array).Neff;
    for (j;j>i;j--){
        CopyKata(&(*array).A[j-1] , &(*array).A[j]);
    }
    (*array).A[i]=el;
    (*array).Neff+=1;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DeleteAt(ArrayDin *array, IdxType i){
    IdxType j = i;
    while (j < (*array).Neff-1){
        (*array).A[j] = (*array).A[j+1];
        j++;
    }
    (*array).Neff--;
}

void InsertLast(ArrayDin *TabGame, Kata game){
    InsertAt(TabGame,game,(*TabGame).Neff);
}