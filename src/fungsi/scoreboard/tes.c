#include "scoreboard.h"

int main(){
    Map game;
    MCreateEmpty(&game);
    MInsert(&game,StringtoKata("Satrio"),98);
    MInsert(&game,StringtoKata("Budi"),99);
    MInsert(&game,StringtoKata("Dilan"),97);
    PrintScore(game);
    return 0;
}