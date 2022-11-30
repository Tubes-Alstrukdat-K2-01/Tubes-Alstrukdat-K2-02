#include "word.h"
#include <stdlib.h>

void CopyKata(Kata *Win, Kata *Wout){
    (*Wout).Length = (*Win).Length;
    int i;
    for(i=0; i < (*Win).Length; i++){
        (*Wout).Tab[i] = (*Win).Tab[i];
    }
    (*Wout).Tab[i] = '\0';
    for(i; i<50; i++){
        (*Wout).Tab[i] = '\0';
    } //jadiin null biar ga  overflow
}

void MakeKata(Kata *W){
    (*W).Length = 0;
}

void CopyStringtoKata(Kata *W, char *s){
    MakeKata(W);
    int i=0;
    while( s[i] != '\0' && s[i] != '\n' ){
        (*W).Tab[i] = s[i];
        (*W).Length++; 
        i++;
    }
    (*W).Tab[i] = '\0';
    for(i; i<50; i++){
        (*W).Tab[i] = '\0';
    } //jadiin null biar ga  overflow
}

void CopyWordtoKata(Kata *K, Word W){
    MakeKata(K);
    int i;
    (*K).Length = W.Length;
    for(i=0; i<W.Length; i++){
        (*K).Tab[i] = W.TabWord[i];
    }
    (*K).Tab[i] = '\0';
    for(i; i<50; i++){
        (*K).Tab[i] = '\0';
    } //jadiin null biar ga  overflow
}

boolean IsKataEqual(Kata W1, Kata W2){
    if(W1.Length != W2.Length){
        return false;
    }
    else{
        int i;
        for(i=0; i<W1.Length; i++){
            if(W1.Tab[i] != W2.Tab[i]){
                return false;
            }
        }
        return true;
    }
}
Kata StringtoKata(char *s){
    Kata W;
    CopyStringtoKata(&W, s);
    return W;
}

int panjang(char *string){
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}

char* concat(char *s1, char *s2){
    int n = panjang(s1) + panjang(s2);
    char* result;
    result = (char*) malloc (n*sizeof(char));
    int i=0;
    while(s1[i] != '\0' && s1[i] != '\n'){
        result[i] = s1[i];
        i++;
    }
    int j=0;
    while(s2[j] != '\0' && s2[j] != '\n'){
        result[i] = s2[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return result;
}

void PrintKata(Word Kata){
    for (int i = 0; i<Kata.Length; i++){
        printf("%c", Kata.TabWord[i]);
    }
}
