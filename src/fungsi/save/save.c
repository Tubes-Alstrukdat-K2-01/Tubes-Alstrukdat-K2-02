#include "save.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *file;
char* IntToString(int n){
    int p,k;
    char* s;
    if(n < 0){
        n *= -1;
    }
    if(n == 0){
        s = (char*) malloc (1*sizeof(char));
        s[0] = 48;
        s[1] = '\0';
    }
    else{
        p = n;
        k = 0;
        while( p != 0 ){
            p = (p - p%10)/10;
            k++;
        }
        s = (char*) malloc (k*sizeof(char));
        s[k] = '\0';
        k--;
        while (n != 0){
            s[k] = (n%10)+48;
            n = (n - n%10)/10;
            k--;
        }
    }
    return s;
}

void SAVE(ArrayDin TabGame, char *filename){
    char* loc = concat("../data/",filename);
    file = fopen(loc,"w");
    // printf("%d\n",file == NULL);
    char* ngame = IntToString(TabGame.Neff);
    fputs(ngame,file);
    fputs("\n",file);
    int i;
    for(i=0; i<TabGame.Neff; i++){
        fputs(TabGame.A[i].Tab,file);
        fputs("\n",file);
    }
    printf("Save file berhasil disimpan.\n");
}