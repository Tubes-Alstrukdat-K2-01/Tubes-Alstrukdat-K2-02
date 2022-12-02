#include "start.h"
#include <stdio.h>

Stack2 History;
Map SC[100];

void STARTPROGRAM(ArrayDin *TabGame, boolean *start)
{
    if (*start)
    {
        printf("Proses Start tidak berhasil dilakukan karena BNMO telah dijalankan!\n");
    }
    else
    {
        CreateEmpty2(&History);
        for(int j=0; j<100; j++){
            MCreateEmpty(&SC[j]);
        }
        *start = true;
        *TabGame = MakeArrayDin();
        int i;
        for (i = 0; i < 5; i++)
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
                char p[25] = "HANGMAN";
                CopyStringtoKata(&k, p);
            }
            else if (i == 3)
            {
                char p[25] = "TOWER OF HANOI";
                CopyStringtoKata(&k, p);
            }
            else if (i == 4)
            {
                char p[25] = "SNAKE ON METEOR";
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