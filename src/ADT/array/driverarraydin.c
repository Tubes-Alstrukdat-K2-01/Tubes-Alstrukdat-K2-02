#include <stdlib.h>
#include <stdio.h>
#include "arraydin.h"
#include "../word/word.h"

int main() {
    ArrayDin list;
    list = MakeArrayDin();
    printf("Panjang list adalah %d\n",Length(list));
    if (IsEmpty(list)) {
        printf("list Kosong\n");
    }
    Kata game;
    CopyStringtoKata(&game,"GENSHIN IMPACT");
    InsertLast(&list,game);
    CopyStringtoKata(&game,"POKEMON");
    InsertLast(&list,game);
    CopyStringtoKata(&game,"DINER DASH");
    InsertLast(&list,game);
    printf("Panjang list sekarang adalah %d\n",Length(list));
    int i;
    for (i = 0;i < Length(list);i++) {
        printf("Elemen ke %d adalah %s\n",i+1,Get(list,i));
    }
    printf("Kapasistas maksimum list adalah %d\n",GetCapacity(list));
    //printf("Akan dimasukkan elemen pada urutan kedua\n");
    //CopyStringtoKata(&game,"ANGRY BIRD");
    //InsertAt(&list,game,1);
    for (i = 0;i < Length(list);i++) {
        printf("Elemen ke %d adalah %s\n",i+1,Get(list,i));
    }
    printf("Akan dihapus elemen pada urutan ketiga\n");
    DeleteAt(&list,2);
    for (i = 0;i < Length(list);i++) {
        printf("Elemen ke %d adalah %s\n",i+1,Get(list,i));
    }
    DeallocateArrayDin(&list);
    return 0;
}