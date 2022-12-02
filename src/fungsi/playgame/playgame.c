#include "playgame.h"
#include "../../ADT/setmap/map.h"
void menuPlayGame(Queue *Q){
    displayQueueGame(*Q);
    if (!isEmpty(*Q)){
        Kata Head;
        dequeue(Q, &Head);
        printf("%s\n",Head.Tab);
        /* nunggu list game buat nge run permainan yang di head */
        Play(Head); // PLACEHOLDER
    }
    else{
        printf("Antrian Game yang akan dimainkan kosong!\n");
    }
}
void Play(Kata W){
    if  (IsKataEqual(W, StringtoKata("RNG"))){
        printf("Loading game RNG...\n");
        RNG();
    } else if (IsKataEqual(W, StringtoKata("DINER DASH"))){
        printf("Loading game Dinner Dash...\n");
        dinerdash();
    } else if (IsKataEqual(W, StringtoKata("HANGMAN"))){
        printf("Loading game HANGMAN...\n");
        hangman();
    } else if (IsKataEqual(W, StringtoKata("TOWER OF HANOI"))){
        printf("Loading game TOWER OF HANOI...\n");
        towerofhanoi();
    } else if (IsKataEqual(W, StringtoKata("SNAKE ON METEOR"))){
        printf("Loading game TOWER OF HANOI...\n");
        //
    } else {
        printf("Loading game %s...\n",W.Tab);
        srand(time(0));
        int skor = (rand()*3)%100 + 1;
        printf("Skor Akhir dari game %s adalah %d\n",W.Tab,skor);
    }
    Push2(&History,W.Tab);
}
// int main(){
//     Queue Q;
//     CreateQueue(&Q);
//     enqueue(&Q, StringtoKata("RNG"));
//     enqueue(&Q, StringtoKata("DINNERDASH"));
//     ArrayDin A = MakeArrayDin();
//     InsertAt(&A, StringtoKata("RNG"),0);
//     InsertAt(&A, StringtoKata("DiNNERDASH"),0);

//     menuPlayGame(&Q);

//     return 0;
// }