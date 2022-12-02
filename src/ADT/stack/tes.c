#include "stack.h"
#include <stdio.h>

int main(){
    Stack2 s;
    CreateEmpty2(&s);
    Push2(&s, "Hallo,guys!");
    infotype2 x;
    Pop2(&s,&x);
    printf("%s\n",x);
    return 0;
}