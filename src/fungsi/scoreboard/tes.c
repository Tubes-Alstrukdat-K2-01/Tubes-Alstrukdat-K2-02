#include "scoreboard.h"

int main(){
    Map M[5];
    int i;
    for(i=0; i<5; i++){
        MCreateEmpty(&M[i]);
    }
    ArrayDin game = MakeArrayDin();
    InsertLast(&game,StringtoKata("RNG"));
    InsertLast(&game,StringtoKata("DINER DASH"));
    InsertLast(&game,StringtoKata("HANGMAN"));
    InsertLast(&game,StringtoKata("TOWER OF HANOI"));
    InsertLast(&game,StringtoKata("SNAKE ON METEOR"));
    Scoreboard(M,game);
    return 0;
}