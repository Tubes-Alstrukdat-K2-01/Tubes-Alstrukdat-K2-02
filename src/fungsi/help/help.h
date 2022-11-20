#ifndef __HELP__
#define __HELP__

#include "../../ADT/boolean.h"
#include <stdio.h>

void HELP(boolean start);
/*
   I.S : Sembarang
   F.S : Menampilkan command-command yang sesuai dengan kondisi dari start
        Jika start false, maka menampilkan command START dan LOAD
        Jika start true, maka menampilkan command LOAD, SAVE, LISTGAME, DELETEGAME, PLAYGAME, SKIPGAME, QUIT.
*/

#endif // !__HELP__