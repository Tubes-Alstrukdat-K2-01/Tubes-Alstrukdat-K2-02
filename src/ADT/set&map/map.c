#include "map.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
// #define Nil 0
// #define MaxEl 10
// #define Undefined -999

// // typedef int bool;
// typedef int keytype;
// typedef int valuetype;
// typedef int address;

// typedef struct {
// 	keytype Key;
// 	valuetype Value;
// } infotype;

// typedef struct {
// 	infotype Elements[MaxEl];
// 	address Count;
// } Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
    int i;
    for(i=0; i<MaxEl; i++){
        (*M).Elements[(*M).Count].ctr = 0;
    }
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M){
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M){
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype* Value(Map M, keytype k){
    if (IsMember(M,k)){
        int i = 0;
        valuetype* v;
        for (i ; i < M.Count ; i++){
            if (M.Elements[i].Key == k){
                v = (valuetype*) malloc (M.Elements[i].ctr*sizeof(valuetype));
                v = M.Elements[i].Value;
                return v;
            }
        }
    }
    else{
        return Nil;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Nil */

void Insert(Map *M, keytype k, valuetype v){
    boolean found = false;
    int i = 0, index;
    while( (i < (*M).Count) && (!found) ){
        if((*M).Elements[i].Key == k){
            found = true;
            index = i;
        }
        i++;
    }
    if(!found){
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value[0] = v;
        (*M).Elements[(*M).Count].ctr = 1;
        (*M).Count++;
    }
    else{
        (*M).Elements[index].Value[(*M).Elements[index].ctr] = v;
        (*M).Elements[index].ctr++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi penambahan valuetype */

void Delete(Map *M, keytype k){
    if (IsMember(*M,k) && (*M).Count == 1){
        (*M).Count = Nil;
    }
    if (IsMember(*M,k)){
        int i = 0, j , count = 0;
        while (i < (*M).Elements[i].Key != k && count < MaxEl){
            i = (i+1)% MaxEl;
            count++;
        } 
        for (i ; i < (*M).Count; i++){
            (*M).Elements[i].Key = (*M).Elements[i+1].Key;
            for(j = 0; j < (*M).Elements[i+1].ctr; j++){
                (*M).Elements[i].Value[j] = (*M).Elements[i+1].Value[j];
            }
            (*M).Elements[i].ctr = (*M).Elements[i+1].ctr;
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k){
    int i = 0;
    boolean found = false;
    while((i < M.Count) && (!found)){
        if(M.Elements[i].Key == k){
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */