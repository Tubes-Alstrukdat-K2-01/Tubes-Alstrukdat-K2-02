#include "history.h"

void HISTORY(Stack stackhistory, int n){
  printf("Berikut adalah daftar Game yang telah dimainkan\n");
  for (int j = 0; j < n; j++) {
    printf("%d. ", j+1); PrintKata(InfoTop(stackhistory)); printf("\n");
    Pop(&stackhistory, &InfoTop(stackhistory)); 
  }
}
