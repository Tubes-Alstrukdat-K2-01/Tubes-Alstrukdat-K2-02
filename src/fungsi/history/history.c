#include "history.h"
#include <stdio.h>

void HISTORY(Stack2 stackhistory, int n){
  if(n <= Count(stackhistory)){
    printf("Berikut adalah daftar Game yang telah dimainkan\n");
    infotype2 value;
    for (int j = 0; j < n; j++) {
      Pop2(&stackhistory, &value); 
      printf("%d. %s\n", j+1, value);
    }
  }
  else{
    printf("History Game yang Dimiliki Tidak Mencapai %d History\n",n);
  }
}

void ResetHistory(Stack2 *stackhistory){
  printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
  STARTWORD();
  Kata cmd;
  boolean valid = true;
  if(!isEndWord()){
    CopyWordtoKata(&cmd,currentWord);
    ADVWORD();
    if(!isEndWord()){
      valid = false;
      while(!isEndWord()){
        ADVWORD();
      }
    }
    else{
      if(IsKataEqual(cmd,StringtoKata("YA"))){
        infotype2 value;
        while(!IsEmptyStack2(*stackhistory)){
          Pop2(stackhistory,&value);
        }
        printf("History berhasil di-reset.\n");
      }
      else if(IsKataEqual(cmd,StringtoKata("TIDAK"))){
        printf("History tidak jadi di-reset. ");
        HISTORY(*stackhistory,Count(*stackhistory));
      }
      else{
        valid = false;
      }
    }
  }
  else{
    valid = false;
  }
  while(!valid){
    printf("COMMAND RESET INVALID! SILAHKAN INPUT (YA/TIDAK): ");
    STARTWORD();
    if(!isEndWord()){
      CopyWordtoKata(&cmd,currentWord);
      ADVWORD();
      if(!isEndWord()){
        while(!isEndWord()){
          ADVWORD();
        }
      }
      else{
        if(IsKataEqual(cmd,StringtoKata("YA"))){
          valid = true;
          infotype2 value;
          while(!IsEmptyStack2(*stackhistory)){
            Pop2(stackhistory,&value);
          }
          printf("History berhasil di-reset.\n");
        }
        else if(IsKataEqual(cmd,StringtoKata("TIDAK"))){
          valid = true;
          printf("History tidak jadi di-reset. ");
          HISTORY(*stackhistory,Count(*stackhistory));
        }
      }
    }
  }
}
