#include "start.h"
#include <stdio.h>

void STARTPROGRAM(ArrayDin *TabGame, boolean *start)
{
    if (*start)
    {
        printf("Proses Start tidak berhasil dilakukan karena BNMO telah dijalankan!\n");
    }
    else
    {
        *start = true;
        *TabGame = MakeArrayDin();
        int i;
        for (i = 0; i < 6; i++)
        {
            Kata k;
            MakeKata(&k);
            if (i == 0)
            {
                char p[25] = "RNG";
                CopyStringtoKata(&k, p);
            }
            else if (i == 1)
            {
                char p[25] = "DINER DASH";
                CopyStringtoKata(&k, p);
            }
            else if (i == 2)
            {
                char p[25] = "DINOSAUR IN EARTH";
                CopyStringtoKata(&k, p);
            }
            else if (i == 3)
            {
                char p[25] = "RISEWOMAN";
                CopyStringtoKata(&k, p);
            }
            else if (i == 4)
            {
                char p[25] = "EIFFEL TOWER";
                CopyStringtoKata(&k, p);
            }
            else
            {
                char p[25] = "HANGMAN";
                CopyStringtoKata(&k, p);
            }
            InsertLast(TabGame, k);
        }
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}
/*
    I.S : Sembarang
    F.S : Jika start false maka TabGame diisikan game dengan configurasi awal, dan boolean start menjadi true.
        boolean start merupakan penanda bahwa BNMO telah dijalankan.
        Jika start true maka, tampilkan bahwa BNMO telah berjalan.
*/