#include "snakeonmeteor.h"

ular makeUlar() {
    int x1 = rand() %5;
    int y1 = rand() %5;
    //int x1,y1=0;
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
    infotype Head =  MakebUlar(x1,y1,99);
    InsVFirst(&Ularmain,Head);
    //printf("%d\n",Ularmain.First->info.koorx);
    //printf("%d\n",Ularmain.First->info.koory);
    //printf("%d\n",Ularmain.First->info.bagian);
    infotype ular2 = MakebUlar(x2,y2,1);
    InsVLast(&Ularmain,ular2);
    infotype ular3 = MakebUlar(x3,y3,2);
    InsVLast(&Ularmain,ular3);

    //printf("%d",Ularmain.First->info.koorx);
    return Ularmain;
}
void setupPeta (MATRIKS* peta) {
    MakeMATRIKS0(peta,5,5);
    //TulisMATRIKS(*peta);
    //TulisMATRIKSpeta(*peta);
    
}
infotype newbuah() {
    int x,y;
    x = rand() %5 ;
    y = rand() %5 ;
    infotype Buah = MakebUlar(x,y,-1);
    return Buah;
}

void buahTOpeta(MATRIKS* peta,infotype buah) {
    int x = buah.koorx;
    int y = buah.koory;
    int val = Elmt(*peta,y+1,x+1);
    //printf("%d %d\n",x,y);
    boolean sukses = false;
    while ( !sukses) {
        if (Elmt(*peta,y+1,x+1) == 0) {
            Elmt(*peta,y+1,x+1) = -1;
            sukses = true;
        }
        buah = newbuah();
    }
    //TulisMATRIKSpeta(*peta);    
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
    MATRIKS peta;
    boolean makan = false;
    boolean play = true;
    char cc;
    ular Ularmain  = makeUlar();
    setupPeta(&peta);
    UlarTOpeta(&peta,&Ularmain);
    buahTOpeta(&peta,newbuah());
    TulisMATRIKSpeta(peta);
    address P = First(Ularmain);
    int i = 0;
    int x ;
    int y ;
    x = P->info.koorx;
    y = P->info.koory;
    printf("%d %d\n",x,y);
    while (i < 3) {
        printf("Masukkan input anda: \n");
        scanf(" %c",&cc);
        if ( cc == 'a') {
            
        }
        i++;
    }
}


/* -1 untuk buah */
/* -2 untuk meteor */
/* -3 untuk obstacle */