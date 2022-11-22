#ifndef __TOWER_OF_HANOI__
#define __TOWER_OF_HANOI__

#include <stdio.h>
#include "../../ADT/stack/stack.h"
#include "../../ADT/mesinkata/mesinkata.h"

void printnchar(char c, int n);
// Menampilkan char c sebanyak n kali dalam satu baris

void displayTOH(Stack A, Stack B, Stack C, int n);
// Menampilkan piringan yang berada pada stack

void insertTOH(Stack *S1, Stack *S2, int *step);
// Memindahkan pirngan dari Top S1 ke Top S2 dengan aturan TOH

char commandTOH();
// Mendapatkan inputan dari user

void towerofhanoi();
// Main fungsi game tower of hanoi

#endif // !__TOWER_OF_HANOI__