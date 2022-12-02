#include "history.h"
#include <stdio.h>

int main(){
    Stack2 history;
    CreateEmpty2(&history);
    Push2(&history,"Diner Dash");
    Push2(&history,"Tower of Hanoi");
    Push2(&history,"RNG");
    Push2(&history,"Snake On Meteor");
    Push2(&history,"Diner Dash");
    ResetHistory(&history);
    HISTORY(history,2);
    return 0;
}