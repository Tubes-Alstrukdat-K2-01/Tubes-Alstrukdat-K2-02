#include <stdio.h>
#include <stdlib.h>
#include "..\boolean.h"
#include "listular.h"

boolean IsEmpty(List L)
{
    return First(L) == Nil;
}

void CreateEmpty(List *L)
{
    First(*L) = Nil;
}

address Alokasi(infotype X)
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P)
{
    free(*P);
}

address Search(List L, infotype X)
{
    address P = First(L);
    boolean isFound = false;
    while (P != Nil && !isFound)
    {
        if (Info(P).koorx == X.koorx && Info(P).koory == X.koory && Info(P).bagian == X.bagian)
            isFound = true;
        else
            P = Next(P);
    }
    return P;
}

void InsVFirst(List *L, infotype X)
{
    address P = Alokasi(X);
    if (P != Nil)
        InsertFirst(L, P);
}

void InsVLast(List *L, infotype X)
{
    address P = Alokasi(X);
    if (P != Nil)
        InsertLast(L, P);
}

void DelVFirst(List *L, infotype *X)
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void InsertFirst(List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address P)
{

    if (IsEmpty(*L))
        InsertFirst(L, P);
    else
    {
        address last = First(*L);
        while (Next(last) != Nil)
            last = Next(last);
        InsertAfter(L, P, last);
    }
}

void DelFirst(List *L, address *P)
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP(List *L, infotype X)
{
    address P = Search(*L, X);
    if (P != Nil)
    {
        if (P == First(*L))
            DelFirst(L, &P);
        else
        {
            address Prec = First(*L);
            while (Next(Prec) != P)
                Prec = Next(Prec);
            DelAfter(L, &P, Prec);
        }
    }
}

void DelLast(List *L, address *P)
{
    address last = First(*L);
    address Prec = Nil;
    while (Next(last) != Nil)
    {
        Prec = last;
        last = Next(last);
    }

    *P = last;
    if (Prec == Nil)
        First(*L) = Nil;
    else
        Next(Prec) = Nil;
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    *Pdel = Next(Prec);
    if (Next(Prec) != Nil)
    {
        Next(Prec) = Next(Next(Prec));
        Next(*Pdel) = Nil;
    }
}

int NbElmt(List L)
{
    int count = 0;
    address P = First(L);
    while (P != Nil)
    {
        P = Next(P);
        count++;
    }
    return count;
}

void Konkat1(List *L1, List *L2, List *L3)
{
    address lastL1 = First(*L1);
    CreateEmpty(L3);
    if (IsEmpty(*L1))
        First(*L3) = First(*L2);
    else
    {
        First(*L3) = First(*L1);
        while (Next(lastL1) != Nil)
            lastL1 = Next(lastL1);
        Next(lastL1) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}

infotype MakebUlar(int x,int y,int bagian) {
    bagianular test;
    test.koorx = x;
    test.koory = y;
    test.bagian = bagian;
    return test;
}
/* 
int main() {
    ular Ularmain;
    CreateEmpty(&Ularmain);
    bagianular test = MakebUlar(8,8,8);
    printf("%d",test.koorx);
    address P = Alokasi(test);
    InsertFirst(&Ularmain,P);
}
*/