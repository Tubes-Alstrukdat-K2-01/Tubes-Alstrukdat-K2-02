#include <stdio.h>
#include "matrikssnake.h"

/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return (i <= BrsMax && i >= BrsMin) && (j <= KolMax && j >= KolMin);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
{
    /* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}

indeks GetFirstIdxKol(MATRIKS M)
{
    /* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}
indeks GetLastIdxBrs(MATRIKS M)
{
    /* Mengirimkan indeks baris terbesar M */
    return NBrsEff(M);
}
indeks GetLastIdxKol(MATRIKS M)
{
    /* Mengirimkan indeks kolom terbesar M */
    return NKolEff(M);
}
boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
{
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return (i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal(MATRIKS M, indeks i)
{
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
{
    /* Melakukan assignment MHsl  MIn */
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    *MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
{
    /* I.S. IsIdxValid(NB,NK) */
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 */
    ElType elm;

    MakeMATRIKS(NB, NK, M);
    for (indeks i = GetFirstIdxBrs(*M); i <= NB; i++)
    {
        for (indeks j = GetFirstIdxKol(*M); j <= NK; j++)
        {

            scanf("%d", &elm);
            Elmt(*M, i, j) = elm;
        }
    }
}
void MakeMATRIKS0(MATRIKS *M, int NB, int NK)
{
    /* I.S. IsIdxValid(NB,NK) */
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 */
    MakeMATRIKS(NB, NK, M);
    for (indeks i = GetFirstIdxBrs(*M); i <= NB; i++)
    {
        for (indeks j = GetFirstIdxKol(*M); j <= NK; j++)
        {
            Elmt(*M, i, j) = 0;
        }
    }
}
void TulisMATRIKS(MATRIKS M)
{
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
    dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10*/

    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            printf("%d", Elmt(M, i, j));
            if (j != GetLastIdxKol(M))
            {
                printf(" ");
            }
        }
        if (i != GetLastIdxBrs(M))
        {
            printf("\n");
        }
    }
    printf("\n");
}
void TulisMATRIKSpeta(MATRIKS M)
{
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
    dipisahkan dan membuat peta seperti pada spesifikasi game snake on meteor */
    /* Contoh: menulis matriks (ingat di akhir tiap baris, tidak ada spasi)
    =====================
    |1  |2  |3  |   |   |
    |11 |22 |33 |   |   |
    |1  |2  |3  |   |   |
    |1  |2  |3  |   |   |
    |1  |2  |3  |   |   |
    =====================
                    */
    int last =0;
    boolean huruf = false;
    printf("=====================\n");
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            
            printf("|%d", Elmt(M, i, j));
            if (j != GetLastIdxKol(M)  )
            {
                if (Elmt(M, i, j) >= 0 && Elmt(M, i, j) < 9) {
                    printf("  ");
                } else  printf(" ");
            }
            last = Elmt(M, i, j);
        }
        if (i != GetLastIdxBrs(M))
        {
            if (last >= 0 && last < 9) {
                    printf("  ");
                } else  printf(" ");
            printf("|\n");
        }
    }
    if (last >= 0 && last < 9) {
                    printf("  ");
                } else  printf(" ");
    printf("|\n");
    printf("=====================\n");
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ(MATRIKS M1, MATRIKS M2)
{
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    if (NBElmt(M1) != NBElmt(M2))
        return false;
    for (indeks i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (indeks j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            if (Elmt(M1, i, j) != Elmt(M2, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

boolean NEQ(MATRIKS M1, MATRIKS M2)
{
    /* Mengirimkan true jika M1 tidak sama dengan M2 */
    return (!EQ(M1, M2));
}
boolean EQSize(MATRIKS M1, MATRIKS M2)
{
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt(MATRIKS M)
{
    /* Mengirimkan banyaknya elemen M */
    return NBrsEff(M) * NKolEff(M);
}