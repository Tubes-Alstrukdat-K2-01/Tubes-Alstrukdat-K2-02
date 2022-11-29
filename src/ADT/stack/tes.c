#include "stack.h"
#include <stdio.h>

int main(){
    Stack2 s;
    CreateEmpty2(&s);
    Push2(&s, "Hallo,guys!");
    printf("%s\n",InfoTop(s));
    return 0;
}