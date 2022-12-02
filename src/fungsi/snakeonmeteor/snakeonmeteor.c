#include "snakeonmeteor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/matrixsnake/matrikssnake.c"
#include "../../ADT/listlinier/listular.c"

ular makeUlar() {
    //int x1 = rand() %5;
    //int y1 = rand() %5;
    int x1,y1=1;
    int x2,y2,x3,y3;
    printf("%d %d\n",x1,y1);
    ular Ularmain;
    CreateEmpty(&Ularmain);
    if (x1 == 0) {
        if (y1==0) {
            x2 = 0; y2 = 1;
            x3 = 0; y3 = 2;
        }
        else if (y1 ==1) {
            x2 = 0; y2 = 0;
            x3 = 1; y3 = 0;
        }
        else if (y1 >= 2) {
            x2 = 0;
            y2 = y1-1;
            x3 = 0;
            y3 = y2-1;
        }
    } else if (x1 == 1) {
        if (y1==0) {
            x2 = 0; y2 = 0;
            x3 = 0; y3 = 1;
        }
        else {
            x2 = x1-1;
            y2 = y1;
            x3 = x2;
            y3 = y2-1;
        }
    } else if (x1 >= 2) {
        x2 = x1-1;
        y2 = y1;
        x3 = x2-1;
        y3 = y2;
    }
    infotype3 Head =  MakebUlar(x1,y1,(-9));
    InsVFirst(&Ularmain,Head);
    //printf("%d\n",Ularmain.First->info.koorx);
    //printf("%d\n",Ularmain.First->info.koory);
    //printf("%d\n",Ularmain.First->info.bagian);
    infotype3 ular2 = MakebUlar(x2,y2,1);
    InsVLast(&Ularmain,ular2);
    infotype3 ular3 = MakebUlar(x3,y3,2);
    InsVLast(&Ularmain,ular3);

    //printf("%d",Ularmain.First->info.koorx);
    return Ularmain;
}
void setupPeta (MATRIKS* peta) {
    MakeMATRIKS0(peta,5,5);
    //TulisMATRIKS(*peta);
    //TulisMATRIKSpeta(*peta);
    
}

void buahTOpeta(MATRIKS* peta) {
    boolean sukses;
    int x,y;
    //x = rand() %5 ;
    //y = rand() %5 ;
    x = 0;
    y = 3;
    sukses = false;
    while (!sukses) {
        if (Elmt(*peta,y+1,x+1) == 0) {
            Elmt(*peta,y+1,x+1) = -1;
            sukses = true;
        }
        x = rand() %5 ;
        y = rand() %5 ;
    }
}

void UlarTOpeta(MATRIKS* peta,ular* Ularmain) {
    address P = First(*Ularmain);
    // Elmt(*peta,4,4) = 55;
    int x ;
    int y ;
    x = P->info.koorx;
    y = P->info.koory;
    //printf("%d %d\n",x,y);
    //Elmt(*peta,y+1,x+1) = 66;
    int i = 0;
    //printf("%d\n",NbElmt(*Ularmain));
    while(i < NbElmt(*Ularmain)) {
        x = P->info.koorx;
        y = P->info.koory;
        //printf("%d %d\n",x,y);
        Elmt(*peta,y+1,x+1) = P->info.bagian;
        P = Next(P);
        i++;
    }

    //TulisMATRIKSpeta(*peta);
}

void playsnake() {
    infotype3 trash;
    MATRIKS peta;
    boolean makan = false;
    boolean play = true;
    char cc;
    ular Ularmain  = makeUlar();
    setupPeta(&peta);
    printf("yes1\n");
    UlarTOpeta(&peta,&Ularmain);
    printf("yes1\n");
    buahTOpeta(&peta);
    printf("yes1\n");
    TulisMATRIKSpeta(peta);
    address P = First(Ularmain);
    int i = 0;
    int x ;
    int y ;
    x = P->info.koorx;
    y = P->info.koory;
    printf("%d %d\n",x,y);
    while (play) {
        printf("Masukkan input anda: \n");
        scanf(" %c",&cc);
        //case s
        if ( cc = 's') {
            //printf("%d %d\n",x,y);
            //printf("%d\n",Elmt(peta,y+2,x+1));
            if (Elmt(peta,y+2,x+1) == -1) {
                InsVFirst(&Ularmain,MakebUlar(x,(y+5)%4,(-9)));
                printf("yes\n");
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                }
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            } 
            else {
                InsVFirst(&Ularmain,MakebUlar(x,(y+5)%4,(-9)));
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                
                }
                DelVLast(&Ularmain,&trash);
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            }
        }
        if ( cc = 'w') {
            //printf("%d %d\n",x,y);
            //printf("%d\n",Elmt(peta,y,x+1));
            if (Elmt(peta,y,x+1) == -1) {
                InsVFirst(&Ularmain,MakebUlar(x,(y+3)%4,(-9)));
                printf("yes\n");
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                }
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            } 
            else {
                InsVFirst(&Ularmain,MakebUlar(x,(y+3)%4,(-9)));
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                
                }
                DelVLast(&Ularmain,&trash);
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            }
        }
        if ( cc = 'a') {
            //printf("%d %d\n",x,y);
            //printf("%d\n",Elmt(peta,y+1,x));
            if (Elmt(peta,y+1,x) == -1) {
                InsVFirst(&Ularmain,MakebUlar((x+3)%4,y,(-9)));
                printf("yes\n");
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                }
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            } 
            else {
                InsVFirst(&Ularmain,MakebUlar((x+3)%4,y,(-9)));
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                
                }
                DelVLast(&Ularmain,&trash);
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            }
        if ( cc = 'd') {
            //printf("%d %d\n",x,y);
            //printf("%d\n",Elmt(peta,y+1,x));
            if (Elmt(peta,y+1,x+2) == -1) {
                InsVFirst(&Ularmain,MakebUlar((x+5)%4,y,(-9)));
                printf("yes\n");
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                }
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            } 
            else {
                InsVFirst(&Ularmain,MakebUlar((x+5)%4,y,(-9)));
                P = First(Ularmain);
                P->info.bagian = (-9);
                P = Next(P);
                i = 1;
                while ( P != Nil) {
                P->info.bagian = i;
                P = Next(P);
                i++;
                
                }
                DelVLast(&Ularmain,&trash);
                UlarTOpeta(&peta,&Ularmain);
                TulisMATRIKSpeta(peta);
            }
        }
        }
        if (NbElmt(Ularmain) == 24) {
            play = false;
        }
    }
}


int main() {
    srand(time(0));
    playsnake();
    
    return 0;
}

/* -1 untuk buah */
/* -2 untuk meteor */
/* -3 untuk obstacle */