#include "help.h"

void HELP(boolean start){
    if(!start){
        printf("1. START                - Command untuk membaca konfigurasi default dari BNMO.\n");
        printf("2. LOAD <filename>      - Command untuk membaca konfigurasi filename.txt untuk menjalankan program BNMO.\n");
        printf("3. HELP                 - Command untuk menampilkan command-command yang dapat digunakan.\n");
    }
    else{
        printf("1. SAVE <filename>      - Command untuk menyimpan konfigurasi dari BNMO kedalam filename.txt sesuai dengan format konfigurasi.\n");
        printf("2. CREATE GAME          - Command untuk menambahkan game baru pada list game.\n");
        printf("3. LIST GAME            - Command untuk menampilkan list game yang ada pada program BNMO.\n");
        printf("4. DELETE GAME          - Command untuk menghapus game dari list game sesuai dengan aturan DELETE GAME.\n");
        printf("5. QUEUE GAME           - Command untuk menambahkan game yang ada di list game ke dalam queue game.\n");
        printf("6. PLAY GAME            - Command untuk menjalankan game yang ada pada antrian terdepan dari queue game.\n");
        printf("7. SKIP GAME <n>        - Command untuk meng-skip atau menghapus game pada antrian terdepan queue game sebanyak n kali.\n");
        printf("8. SCOREBOARD           - Command untuk menampilkan scoreboard berdasarkan game yang ada pada list game.\n");
        printf("9. RESET SCOREBOARD     - Command untuk melakukan reset scoreboard pada suatu atau semua game.\n");
        printf("10. HISTORY <n>         - Command untuk menampilkan history game yang terakhir kali dimainkan sebanyak <n> history.\n");
        printf("11. RESET HISTORY       - Command untuk melakukan konfirmasi kepada user untuk me-reset history atau tidak.\n");
        printf("12. QUIT                - Command untuk keluar dari program BNMO.\n");
        printf("13. HELP                - Command untuk menampilkan command-command yang dapat digunakan.\n");
    }
}