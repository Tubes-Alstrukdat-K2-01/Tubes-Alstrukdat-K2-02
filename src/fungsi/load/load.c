#include "load.h"

Stack2 History;
Map SC[100];

void LOAD(ArrayDin *TabGame, boolean *start, char *filename)
{
    if (*start)
    {
        printf("Proses LOAD gagal karena BNMO telah dijalankan.");
    }
    else{
        CreateEmpty2(&History);
        for(int j=0; j<100; j++){
            MCreateEmpty(&SC[j]);
        }
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
            for (i = 0; i < n; i++)
            {
                int game = i;
                fgets(data, 255, file);
                int j = 0, k = 0;
                while(data[k] != '\0'){
                    if(data[k] >= '0' && data[k] <= '9'){
                        j *= 10;
                        j += (int)(data[k]-48);
                    }
                    k++;
                }
                for(int a = 0; a < j; a++){
                    fgets(data, 255, file);
                    Kata nama;
                    MakeKata(&nama);
                    k = 0;
                    while(data[k] != '\0' && data[k] != ' '){
                        nama.Tab[k] = data[k];
                        k++;
                    }
                    nama.Tab[k] = '\0';
                    while(data[k] == ' '){
                        k++;
                    }
                    int skor = 0;
                    while(data[k] != '\0'){
                        if(data[k] >= '0' && data[k] <= '9'){
                            skor *= 10;
                            skor += (int)(data[k]-48);
                        }
                        k++;
                    }
                    MInsert(&SC[game], nama, skor);
                }
            }
        }
    }
}
/*
I.S : Sembarang
F.S : Jika start false maka write semua value yang ada di filename.txt kedalam TabGame sesuai dengan format konfigurasi
        Jika start true maka menampilkan LOAD gagal karena BNMO sudah dijalankan
*/