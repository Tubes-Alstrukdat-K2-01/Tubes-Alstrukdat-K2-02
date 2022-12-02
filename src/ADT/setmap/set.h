#ifndef __SET_H__
#define __SET_H__
#include "../boolean.h"
#define SMaxEl 50

typedef struct {
    char Elmt[SMaxEl];
    int Count;
} Set;

void SCreateEmpty(Set *S);

boolean SIsEmpty(Set S);

boolean SIsFull(Set S);

void SInsert(Set *S, char X);

void SDelete(Set *S, char X);

boolean SIsMember(Set S, char X);

#endif
