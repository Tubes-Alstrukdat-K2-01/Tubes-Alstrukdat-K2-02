#include "set.h"
#include "../boolean.h"

void SCreateEmpty(Set *S){
    int i;
    for(i=0; i<50; i++){
        (*S).Elmt[i] = '\0';
    }
    (*S).Count = 0;
};

boolean SIsEmpty(Set S){
    return (S.Count == 0);
};

boolean SIsFull(Set S){
    return (S.Count == SMaxEl);
};

void SInsert(Set *S, char X){
    if(SIsMember(*S, X) || SIsFull(*S)){
        return;
    }
    (*S).Elmt[(*S).Count] = X;
    (*S).Count++;
};

void SDelete(Set *S, char X){
    if (!SIsMember(*S, X)){
        return;
    }
    int i;
    //nyari indeks
    for(i=0; i<(*S).Count; i++){
        if((*S).Elmt[i] == X){
            break; 
        }
    }
    //geser
    for(; i<(*S).Count-1; i++){
        (*S).Elmt[i] = (*S).Elmt[i+1];
    }
    (*S).Count--;
};

boolean SIsMember(Set S, char X){
    int i;
    for(i=0; i<S.Count; i++){
        if(S.Elmt[i] == X){
            return true;
        }
    }
    return false;
};