/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mMesinKarakter.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "ADT_MesinKarakter.h" //comment this later

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
/* Kamus global */
extern char CC;
extern boolean eop;

int main()
{
    /* Kamus Lokal */

/* Algoritma  : menuliskan isi pita */
    printf("awal pita \n");
    START("pitakar.txt");
    while (!eop){
        printf("%c",CC);
        ADV();
    }
    printf("\n... akhir, Bye \n");
    return 0;
}

/* All Rights Reserved 2012 */
