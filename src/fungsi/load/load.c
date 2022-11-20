#include "load.h"

void LOAD(ArrayDin *TabGame, boolean *start, char *filename)
{
    if (*start)
    {
        printf("Proses LOAD gagal karena BNMO telah dijalankan.");
    }
    else{
        MakeArrayDin(TabGame);
        FILE *file;
        char *loc = concat("../data/",filename);
        if((file = fopen(loc,"r")) == NULL){
            printf("File Konfigurasi tidak ditemukan\n");
        }
        else{
            *start = true;
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
            char data[255];
            fgets(data, 255, file);
            int n = 0, i = 0;
            while (data[i] != '\0')
            {
                if (data[i] >= '0' && data[i] <= '9')
                {
                    n *= 10;
                    n += (int)(data[i] - 48);
                }
                i++;
            }
            for (i = 0; i < n; i++)
            {
                fgets(data, 255, file);
                Kata w;
                MakeKata(&w);
                CopyStringtoKata(&w, data);
                InsertAt(TabGame, w, i);
            }
        }
        fclose(file);
    }
}
/*
I.S : Sembarang
F.S : Jika start false maka write semua value yang ada di filename.txt kedalam TabGame sesuai dengan format konfigurasi
        Jika start true maka menampilkan LOAD gagal karena BNMO sudah dijalankan
*/