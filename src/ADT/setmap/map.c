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
int strcomp(char *s1, char *s2){
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] != s2[i]){
            return 0;
        }
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0'){
        return 1;
    }
    return 0;
}
/* *** Konstruktor/Kreator *** */
void MCreateEmpty(Map *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean MIsEmpty(Map M){
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean MIsFull(Map M){
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype MValue(Map M, keytype k){
    if (MIsMember(M,k)){
        int i = 0;
        for (i ; i < M.Count ; i++){
            if(IsKataEqual(M.Elements[i].Key,k)){
                return M.Elements[i].Value;
            }
        }
    }
    else{
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Nil */

void MInsert(Map *M, keytype k, valuetype v){
    if(!MIsMember(*M,k)) {
        int index = 0;
        while(((*M).Elements[index].Value >= v) && (index < (*M).Count)){
            index++;
        }
        (*M).Count++;
        int i = (*M).Count;
        for(i; i > index; i--){
            (*M).Elements[i].Value = (*M).Elements[i-1].Value;
            for(int j=0; j < 50; j++){
                (*M).Elements[i].Key.Tab[j] = (*M).Elements[i-1].Key.Tab[j];
            }
            (*M).Elements[i].Key.Length = (*M).Elements[i-1].Key.Length;
        }
        (*M).Elements[index].Value = v;
        for(int j=0; j < 50; j++){
                (*M).Elements[index].Key.Tab[j] = k.Tab[j];
        }
        (*M).Elements[index].Key.Length = k.Length;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi penambahan valuetype */

void MDelete(Map *M, keytype k){
    if (MIsMember(*M,k) && (*M).Count == 1){
        (*M).Count = Nil;
    }
    if (MIsMember(*M,k)){
        int i = 0, j , count = 0;
        //nyari indeks key
        while (!IsKataEqual((*M).Elements[i].Key,k)){
            i++;
        } 
        for (i ; i < (*M).Count; i++){
            //geser
            (*M).Elements[i].Value = (*M).Elements[i+1].Value;
            //copy string
            for(int j=0; j < 50; j++){
                (*M).Elements[i].Key.Tab[j] = (*M).Elements[i+1].Key.Tab[j];
            }
            (*M).Elements[i].Key.Length = (*M).Elements[i+1].Key.Length;
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean MIsMember(Map M, keytype k){
    int i = 0;
    boolean found = false;
    while((i < M.Count) && (!found)){
        if(IsKataEqual(M.Elements[i].Key,k)){
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */