#include "queue.h"
#include <stdio.h>
int main(){
    Queue Q;
    CreateQueue(&Q);
    printf("Length : %d, isEmpty: %d", lengthQueue(Q), isEmpty(Q));
    enqueue(&Q, StringtoKata("Hello"));
    displayQueue(Q);
}