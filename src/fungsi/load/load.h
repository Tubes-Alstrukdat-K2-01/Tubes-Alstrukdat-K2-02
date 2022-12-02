#ifndef __LOAD__
#define __LOAD__

#include "../../ADT/array/arraydin.h"
#include "../../ADT/word/word.h"
#include "../../ADT/global.h"
#include <stdio.h>
#include <stdlib.h>

void LOAD(ArrayDin *TabGame, boolean *start, char *filename);
/*
   I.S : Sembarang
   F.S : Jika start false maka write semua value yang ada di filename.txt kedalam TabGame sesuai dengan format konfigurasi
        Jika start true maka menampilkan LOAD gagal karena BNMO sudah dijalankan
*/

#endif // !__LOAD__