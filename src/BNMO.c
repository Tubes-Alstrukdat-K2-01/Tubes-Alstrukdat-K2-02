/*
    file ini adalah drive main program dari program BNMO
*/

#include "fungsi/creategame/creategame.h"
#include "fungsi/deletegame/deletegame.h"
#include "fungsi/help/help.h"
#include "fungsi/listgame/listgame.h"
#include "fungsi/load/load.h"
#include "fungsi/playgame/playgame.h"
#include "fungsi/queuegame/queuegame.h"
#include "fungsi/quit/quit.h"
#include "fungsi/save/save.h"
#include "fungsi/skipgame/skipgame.h"
#include "fungsi/start/start.h"
#include "fungsi/scoreboard/scoreboard.h"
#include "ADT/queue/queuediner.h"
#include "ADT/set&map/map.h"
#define NGame 5
int main(){
    ArrayDin TabGame = MakeArrayDin();
    boolean start = false, running = true;
    Queue QGame;
    char * Games [NGame] = {"RNG", "DinerDash", "Hangman", "Tower Of Hanoi", "Snake"};
    Map Scoreboards[NGame];
    Map scRNG;
    Map scDiner;
    Map scHangman;
    Map scTOH;
    Map scSnake;
    MCreateEmpty(&scRNG);
    MCreateEmpty(&scDiner);
    MCreateEmpty(&scHangman);
    MCreateEmpty(&scTOH);
    MCreateEmpty(&scSnake);
    Scoreboards[0] = scRNG;
    Scoreboards[1] = scDiner;
    Scoreboards[2] = scHangman;
    Scoreboards[3] = scTOH;
    Scoreboards[4] = scSnake;
    CreateQueue(&QGame);
    printf("\n\n");       
    printf("               .:^^^^^~~~~~~~~~!!!!!!!!777777777!!~^^:..                                        \n");
    printf("            .7????77777777777777777777!!!!!!!!!!!777?????77!~^:.                                \n");
    printf("           :PJ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777777777???JJYYJJ?7!:                          \n");
    printf("           !BJJJJ????7777!!!!7JYY55YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY5P?                         \n");
    printf("           !GJJJJJPYJJYJJJJ?JG5YJJJJJJJJJJJJYYYYYYYYYYYY55555555555JJYB:                        \n");
    printf("           !GJJJYYYJJYPYJJJJPGJJJJ55555YYYYYYJJJJJ???7777!!!!!~~~~JGJJB^                        \n");
    printf("           !GJJJPYJYPJJYYJJJPPJJJG?^^^^^^:::::::::::::::::::::::::^BYJB:                        \n");
    printf("           !GJJJJJYJJJJ5YJJJPPJJYB^:::::^^::^^^^^^^^^^^^^^^:^^:^^:^GYJB:                        \n");
    printf("           !GJJJJYPJJP5JJJJJPPJJYG^:^^^^:^!!^:^^^^^^^^^^^^:!BG~:^:^GYJB:                        \n");
    printf("           !GJJ5P5YYYYJJJJJJPPJJYG^:^^^^:!&&!:^:^^^^^^^^:::!G5^:^:^GYJG:                        \n");
    printf("           !GJJB&#B##BBGGPJJPPJJYG^:^^^^:^JJ^^^^::::::::!~:::::^^:^GYJG:                        \n");
    printf("           7GJJB&PY##BYG&BJJPPJJYG^:^^^^^:::^^:?J77!!7?JY~:^:^^^^:^GYJG:                        \n");
    printf("           7GJJ5######GB&BJJPPJJYG^:^^^^^^^^^^^:^!!!!!~^::^^^^^^^:^GYJG:                        \n");
    printf("           7GJJJ5GG5YGB#BYJJPPJJYG^:^^^^^^^^^^^^::::::::^^^^^^^^^:^GYYG:                        \n");
    printf("           7GJJ5BBGGP555YJJJPPJJYG^:^^^^^^^^^^^^^^^^^^^^^^^^^^::::^BJYG:                        \n");
    printf("           7GJJJY5PGB####5JJPPJJYG^::::::::::::::::::::::::::^^^^^7GJYG:                        \n");
    printf("           7GJJYGBBBBGGP5YJJPGJJYG^::^^^^^^~~~~!!!777??JJJYYYY55555YJYG:                        \n");
    printf("           7GJJYGBB##BBGPJJJPGJJJ55YYYYYY555555555555555YYYJYPPPPJJJJYG:                        \n");
    printf("           7GJJ5GGPPPPPGGYJJ5GJJJJY555PPPPGGGGGBBBBBB##GJJJJYGPPGYJJJYG.                        \n");
    printf("           7GJJYPGBBBBBBG5JJ5GJJJJP##BBBBBBBGGGGPPPP555YJJJJJY55YJJJJYG.                        \n");
    printf("           7GJJJJJJ5G####5JJ5GJJJJYYYYYYYYYJJJJJJJJJJJJJJJJJJJJJJJJJJYG.                        \n");
    printf("           7GJJY5YYP###GYJJJ5GJJJJJJJJ55P??PYJJJJJJJJJJJYYYJJJJJJJJJJYP.                        \n");
    printf("           ?GJJYB##BB###BYJJ5BJJJJJY55PJJ~^JJJPJJJJJJJJ5P5J5YJJJJJJJJYP.                        \n");
    printf("           JPJJJJYY5PPGGBYJJYBJJJJJ5Y57!!~^!77PJJJJJJJ5P5!~7Y5JY5PP5YYP                         \n");
    printf("           JPJJJ5GBBBBGPYJJJYBJJJJJY55PY5!^Y5YYJJJJJJ5PPYJYJY5JGBY?JPPP                         \n");
    printf("           JPJJG###PPB&#BYJJYBJJJJJJJJY55YY5YJJJJJJJJJJJJYY5YYJPG5YYP5P:                        \n");
    printf("           JPJJB##P!!7G#&PJJYBJJJJJJJJJJJJJJJJJJJJJJJJJ5PGGGGGPYY55YJ5G??|.                     \n");
    printf("           JPJJ5##B?!77G#YJJYBJJJJJJJJJJJJJJJJJJJJJJJJ5GGP55555G5JJJJ5G77?J7^                   \n");
    printf("           ~BJJJYPGGJ7!7Y5JJYBJJJJJJJJJJJJJJJJJYYYYYJJ5GG555555PPJJJJ5P?J7!7J?~.                \n");
    printf("            7P5YJJJJ55?!!?Y5YBJJJJJY5PPPPGGYPGGBBBBGJJJ5GGGPPPP5JJJJJPY ^7JJ?7?J!.              \n");
    printf("             :7JY55YYY5Y?!!?YGYJJJJYGGGGPPPY55555YYYJJJJYY555YJJJJJJJG?  ^P55P7?YY~             \n");
    printf("                .:^!?JY5GPJ7!7JY5YJJJJJJJJJJJJJJJJJJJJ5P5PYYYYY5555PGJ. .P5YYGYYPP?             \n");
    printf("                      .:^!?JJ?777JYYYYYYYY5555PP5YYYJ5PYY5G5PPPPP5555YYYYPYYYP:^~:              \n");
    printf("                            .~7J?77J5PGPGPPP55PP5YJ?!55YY5J .:~!?JYY55555555P!                  \n");
    printf("                               .^7?YPP~:~!7JYY55555555YY5P^        .:^~!7777^                   \n");
    printf("                                   .^.      ..:~!7?JYYYYJ^                                      \n");
    printf("                                                    ...                                         \n");
    printf("\n\n");                                                                                                  
    printf(" BBBBBBBBBBBBBBBBB    NNNNNNNN        NNNNNNNN MMMMMMMM               MMMMMMMM      OOOOOOOOO      \n");
    printf(" B::::::::::::::::B   N:::::::N       N::::::N M:::::::M             M:::::::M    OO:::::::::OO    \n");
    printf(" B::::::BBBBBB:::::B  N::::::::N      N::::::N M::::::::M           M::::::::M  OO:::::::::::::OO  \n");
    printf(" BB:::::B     B:::::B N:::::::::N     N::::::N M:::::::::M         M:::::::::M O:::::::OOO:::::::O \n");
    printf("   B::::B     B:::::B N::::::::::N    N::::::N M::::::::::M       M::::::::::M O::::::O   O::::::O \n");
    printf("   B::::B     B:::::B N:::::::::::N   N::::::N M:::::::::::M     M:::::::::::M O:::::O     O:::::O \n");
    printf("   B::::BBBBBB:::::B  N:::::::N::::N  N::::::N M:::::::M::::M   M::::M:::::::M O:::::O     O:::::O \n");
    printf("   B:::::::::::::BB   N::::::N N::::N N::::::N M::::::M M::::M M::::M M::::::M O:::::O     O:::::O \n");
    printf("   B::::BBBBBB:::::B  N::::::N  N::::N:::::::N M::::::M  M::::M::::M  M::::::M O:::::O     O:::::O \n");
    printf("   B::::B     B:::::B N::::::N   N:::::::::::N M::::::M   M:::::::M   M::::::M O:::::O     O:::::O \n");
    printf("   B::::B     B:::::B N::::::N    N::::::::::N M::::::M    M:::::M    M::::::M O:::::O     O:::::O \n");
    printf("   B::::B     B:::::B N::::::N     N:::::::::N M::::::M     MMMMM     M::::::M O::::::O   O::::::O \n");
    printf(" BB:::::BBBBBB::::::B N::::::N      N::::::::N M::::::M               M::::::M O:::::::OOO:::::::O \n");
    printf(" B:::::::::::::::::B  N::::::N       N:::::::N M::::::M               M::::::M  OO:::::::::::::OO  \n");
    printf(" B::::::::::::::::B   N::::::N        N::::::N M::::::M               M::::::M    OO:::::::::OO    \n");
    printf(" BBBBBBBBBBBBBBBBB    NNNNNNNN         NNNNNNN MMMMMMMM               MMMMMMMM      OOOOOOOOO      \n\n\n");
    printf("Welcome To BNMO Machine !(^.^)!.\n");
    HELP(start);
    printf("\n");
    while(running){
        Kata command;
        printf("ENTER COMMAND: ");
        STARTWORD();
        MakeKata(&command);
        CopyWordtoKata(&command,currentWord);
        if(IsKataEqual(command,StringtoKata("START"))){
            ADVWORD();
            if(isEndWord()){
                STARTPROGRAM(&TabGame,&start);
            }
            else{
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                while(!isEndWord()){
                    ADVWORD();
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("LOAD"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata filename; MakeKata(&filename);
                CopyWordtoKata(&filename,currentWord);
                ADVWORD();
                if(isEndWord()){
                    LOAD(&TabGame, &start, filename.Tab);
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    while(!isEndWord()){
                        ADVWORD();
                    }
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("SAVE"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata filename; MakeKata(&filename);
                CopyWordtoKata(&filename,currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(start){
                        SAVE(TabGame,filename.Tab);
                    }
                    else{
                        printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    while(!isEndWord()){
                        ADVWORD();
                    }
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("CREATE"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata command2; MakeKata(&command2);
                CopyWordtoKata(&command2, currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(IsKataEqual(command2,StringtoKata("GAME"))){
                        if(start){    
                            CREATEGAME(&TabGame);
                        }
                        else{
                            printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                        }
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("LIST"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata command2; MakeKata(&command2);
                CopyWordtoKata(&command2,currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(IsKataEqual(command2,StringtoKata("GAME"))){
                        if(start){    
                            LISTGAME(TabGame);
                        }
                        else{
                            printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                        }
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("DELETE"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata command2; MakeKata(&command2);
                CopyWordtoKata(&command2,currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(IsKataEqual(command2,StringtoKata("GAME"))){
                        if(start){
                            DELETEGAME(&TabGame);
                        }
                        else{
                            printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                        }
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("QUEUE"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata command2; MakeKata(&command2);
                CopyWordtoKata(&command2,currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(IsKataEqual(command2,StringtoKata("GAME"))){
                        if(start){    
                            menuQueueGame(&QGame, TabGame);
                        }
                        else{
                            printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                        }
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("PLAY"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata command2; MakeKata(&command2);
                CopyWordtoKata(&command2,currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(IsKataEqual(command2,StringtoKata("GAME"))){
                        if(start){    
                            menuPlayGame(&QGame, Scoreboards);
                        }
                        else{
                            printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                        }
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("SKIP"))){
            ADVWORD();
            if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                if(IsKataEqual(command,StringtoKata("GAME"))){
                    int skip, i;
                    boolean integer = true;
                    for(i=0; i<currentWord.Length; i++){
                        if(currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9'){
                            skip *= 10;
                            skip += (int)(currentWord.TabWord[i]-48);
                        }
                        else{
                            integer = false;   
                        }
                    }
                    ADVWORD();
                    if(isEndWord() && integer){
                        if(start){
                            menuSkipGame(&QGame, skip);
                        }
                        else{
                            printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                        }
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                        while(!isEndWord()){
                            ADVWORD();
                        }
                    }
                }
                else{
                    printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("QUIT"))){
            ADVWORD();
            if(isEndWord()){
                if(start){
                    QUIT(&running);
                }
                else{
                    printf("\nProgram BNMO belum dijalankan silahkan pilih command START atau LOAD terlebih dahulu!\n");
                }
            }
            else{
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                while(!isEndWord()){
                    ADVWORD();
                }
            }
        } else if (IsKataEqual(command, StringtoKata("SCOREBOARD"))){
            ADVWORD();
            if (isEndWord())
             for (int i = 0; i < NGame; i++){
                printf("\nSCORE GAME %s\n", Games[i]);
                PrintScore(Scoreboards[i]);
            }
            else{
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                while(!isEndWord()){
                    ADVWORD();
                }
            }
        } else if (IsKataEqual(command, StringtoKata("RESET"))){
            ADVWORD();
             if(isEndWord()){
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else{
                Kata command2; MakeKata(&command2);
                CopyWordtoKata(&command2,currentWord);
                ADVWORD();
                if(isEndWord()){
                    if(IsKataEqual(command2,StringtoKata("SCOREBOARD"))){
                        printf("Pilih game yang ingin direset: \n");
                        printf("0. All\n");
                        for (int i = 0; i < NGame; i++){
                            printf("%d. %s\n", i+1, Games[i]);
                        }
                        int game;
                        printf("Pilihan (0-%d): ", NGame);
                        scanf("%d", &game);
                        if (game == 0){
                            for (int i = 0; i < NGame; i++){
                                MCreateEmpty(&Scoreboards[i]);
                            }
                        } else {
                            MCreateEmpty(&Scoreboards[game-1]);
                        }
                        printf("Scoreboard berhasil direset!\n");
                    }
                    else{
                        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                        while(!isEndWord()){
                            ADVWORD();
                        }
                    }
                }
                else{
                    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                    while(!isEndWord()){
                        ADVWORD();
                    }
                }
            }
        }
        else if(IsKataEqual(command,StringtoKata("HELP"))){
            ADVWORD();
            if(isEndWord()){
                HELP(start);
            }
            else{
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
                while(!isEndWord()){
                    ADVWORD();
                }
            }
        }
        else{
            printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            while(!isEndWord()){
                ADVWORD();
            }
        }
        while(!isEndWord()){
            ADVWORD();
        }
        printf("\n");
    }
}