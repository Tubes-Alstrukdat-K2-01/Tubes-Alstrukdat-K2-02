#ifndef __WORD__
#define __WORD__

#include "../boolean.h"
#include "../mesinkata/mesinkata.h"

typedef struct {
    char Tab[50];
    int Length;
} Kata;
/*
  Fungsi untuk menyalin semua yang ada di Win ke Wout
*/
void CopyKata(Kata *Win, Kata *Wout);

/*
  Fungsi untuk membuat MakeKata dengan Kata kosong
  Kata Kosong ditandai dengan Kata.Length = 0;
*/
void MakeKata(Kata *W);

/*
  I.S : W kosong dan s berisi
  Fungsi untuk mengkopi semua yang ada di string ke Kata
*/
void CopyStringtoKata(Kata *W, char *s);

void CopyWordtoKata(Kata *K, Word W);

Kata StringtoKata(char *s);

boolean IsKataEqual(Kata W1, Kata W2);

int length(char *string);

char* concat(char *s1, char *s2);

#endif // !__WORD__