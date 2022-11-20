#include "mesinkata.h"
#include <stdio.h>
int main(){
    STARTWORD();
    while(!isEndWord()){
        printf("%s\n", currentWord.TabWord);
        ADVWORD();
    }
}