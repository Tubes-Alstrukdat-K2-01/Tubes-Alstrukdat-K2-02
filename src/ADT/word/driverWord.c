#include "word.h"
#include <stdio.h>

int main(){
    Kata W;
    Kata K;
    CopyStringtoKata(&W, "Hello");
    printf("Masukkan Kata: ");
    CopyKata(&W, &K);
    printf("%s\n", W.Tab);
    printf("%s\n", K.Tab);
    printf("%d\n", K.Length);
    printf("%d\n", W.Length);
    printf("%d\n", IsKataEqual(K, W));
    return 0;
}