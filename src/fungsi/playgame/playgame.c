#include "playgame.h"
#include "../../ADT/set&map/map.h"
void menuPlayGame(Queue *Q, Map M [NGame]){
    displayQueueGame(*Q);
    if (!isEmpty(*Q)){
        Kata Head;
        dequeue(Q, &Head);
        printf("%s\n",Head.Tab);
        /* nunggu list game buat nge run permainan yang di head */
        Play(Head, M); // PLACEHOLDER
    }
    else{
        printf("Antrian Game yang akan dimainkan kosong!\n");
    }
}
void Play(Kata W, Map M [NGame]){
    if  (IsKataEqual(W, StringtoKata("RNG"))){
        printf("Loading game RNG...\n");
        RNG();
    } else if (IsKataEqual(W, StringtoKata("DINER DASH"))){
        printf("Loading game Dinner Dash...\n");
        dinerdash();
    } else if (IsKataEqual(W, StringtoKata("HANGMAN"))){
        printf("Loading game HANGMAN...\n");
        char nama[50];
        printf("Masukkan nama: ");
        scanf("%s", nama);
        int skor = hangman();
        MInsert(&M[2], nama, skor);
    } else if (IsKataEqual(W, StringtoKata("DINOSAUR IN EARTH"))){
        printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
    } else if (IsKataEqual(W, StringtoKata("RISEWOMAN"))){
        printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
    } else if (IsKataEqual(W, StringtoKata("EIFFEL TOWER"))){
        printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
    } else {
        srand(time(0));
        int skor = (rand()*3)%100 + 1;
        printf("Skor Akhir dari game %s adalah %d\n",W.Tab,skor);
    }
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