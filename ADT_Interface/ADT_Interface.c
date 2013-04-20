/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_Interface.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_Interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* *** ADT INTERFACE *** */
void DelayWaktu(long long x)
/* { I.S. : x >= 0 } */
/* { F.S. : Untuk membuat delay waktu selama x milidetik } */
{
    /* Kamus Lokal */
    long long i = 0;
    /* Algoritma */
    while (i < x * 200000)
       i++;
}

void Opening()
/* { F.S. : Mencetak menu pembuka interface } */
{
    /* Kamus Lokal */
    int i;
    /* Algoritma */
	printf ("            ===Welcome to Brain Burst System [Version 6.2.9200]===\n"); DelayWaktu(500);
    printf ("                   Confirming user data, Access Granted.\n"); DelayWaktu(500);
    printf ("             Confirming Statistical Components, Access Granted.\n\n"); DelayWaktu(500);
    printf ("                        Set priority to: IF2030--Tubes\n\n"); DelayWaktu(500);
    printf ("                          WELCOME "); DelayWaktu(100);
    printf("TO "); DelayWaktu(100);
    printf("SISTEM "); DelayWaktu(100);
    printf("TELEGRAM!\n\n"); DelayWaktu(100);
         printf("                              ._                __        \n");
         printf("                            / \\\"-.          ,-\\\",''/  \n");
         printf("                            (   \\ ,\"--.__.--\".,'' /    \n");
         printf("                           =---Y(_i.-''  |-.i_)---=       \n");
         printf("                           f ,  \"..''/\\v/|/|/\\  , l    \n");
         printf("                           l//  ,''|/   V / /||  \\j      \n");
         printf("                           \"--; / db     db|/---\"       \n");
         printf("                              | \\ YY   , YY//            \n");
         printf("                               ''.\\>_   (_),\"'' __      \n");
         printf("                             .-\"    \"-.-.\" I,\"  `.    \n");
         printf("                             \\.-\"\"-. ( , ) ( \\   |    \n");
         printf("                             (     l  `\"''  -''-._j      \n");
         printf("                      __,---_ ''._.\" .  .    \\          \n");
         printf("                     (__.--_-''.  ,  :  ''  \\  ''-.      \n");
         printf("                         ,'' .''  /   |   \\  \\  \\ \"-  \n");
         printf("                          \"--.._____t____.--''-\"\"''    \n");
         printf("                                 /  /  `. \".             \n");
         printf("                                / \":     \\'' ''.        \n");
         printf("                              .''  (       \\   :         \n");
         printf("                              |    l      j    \"-.       \n");
         printf("                              l_;_;I      l____;_I        \n");
    for (i=1;i<=80;i++)
    {
     printf("=");
     DelayWaktu(10);
    }
    printf("\n");
}

void MainMenu()
/* { F.S. : Menampilkan menu utama dari interface } */
{
        printf("root@brainburst-system:IF2030--Tubes:~#\n\n");
        printf("               ------------------------------------------------\n");
	    printf("               |          - TEST DRIVER -                      |\n");
        printf("               |      A - Modus Penulisan                      |\n");
        printf("               |      B - Modus Pengiriman                     |\n");
        printf("               |      C - Modus Penerimaan                     |\n");
        printf("               |      D - Modus Pengaturan                     |\n");
	    printf("               |      E - Burst Link Out                       |\n");
        printf("               ------------------------------------------------\n\n");
	    printf("               Input> ");
}

void ModePenulisan()
/* { F.S. : Menampilkan Mode A - Mode Penulisan } */
{
        printf("root@brainburst-system:IF2030--Tubes-penulisan:~#\n\n");
        printf("               ------------------------------------------------\n");
	    printf("               |          - TEST DRIVER -                      |\n");
        printf("               |      1 - Kirim                                |\n");
        printf("               |      2 - Hitung Harga                         |\n");
        printf("               |      7 - Statistik                            |\n");
        printf("               |      8 - Ubah Modus Penggunaan                |\n");
	    printf("               |      9 - Burst Link Out                       |\n");
        printf("               ------------------------------------------------\n\n");
	    printf("               Input> ");
}

void ModePengiriman()
/* { F.S. : Menampilkan Mode B - Mode Pengiriman } */
{
        printf("root@brainburst-system:IF2030--Tubes-pengiriman:~#\n\n");
        printf("               ------------------------------------------------\n");
	    printf("               |          - TEST DRIVER -                      |\n");
        printf("               |      1 - Transmit Semua Pesan                 |\n");
        printf("               |      7 - Statistik                            |\n");
        printf("               |      8 - Ubah Modus Penggunaan                |\n");
	    printf("               |      9 - Burst Link Out                       |\n");
        printf("               ------------------------------------------------\n\n");
	    printf("               Input> ");
}


void ModePenerimaan()
/* { F.S. : Menampilkan Mode C - Mode Penerimaan } */
{
        printf("root@brainburst-system:IF2030--Tubes-penerimaan:~#\n\n");
        printf("               ------------------------------------------------\n");
	    printf("               |          - TEST DRIVER -                      |\n");
        printf("               |      1 - List Pesan                           |\n");
        printf("               |      2 - Baca Pesan                           |\n");
        printf("               |      3 - Hapus Pesan                          |\n");
        printf("               |      7 - Statistik                            |\n");
        printf("               |      8 - Ubah Modus Penggunaan                |\n");
	    printf("               |      9 - Burst Link Out                       |\n");
        printf("               ------------------------------------------------\n\n");
	    printf("               Input> ");
}

void ModePengaturan()
/* { F.S. : Menampilkan Mode D - Mode Pengaturan } */
{
        printf("root@brainburst-system:IF2030--Tubes-pengaturan:~#\n\n");
        printf("               ------------------------------------------------\n");
	    printf("               |          - TEST DRIVER -                      |\n");
        printf("               |      1 - Daftar Harga                         |\n");
        printf("               |      2 - List Item Kamus                      |\n");
        printf("               |      3 - Penambahan Item Kamus                |\n");
	    printf("               |      4 - Penghapusan Item Kamus               |\n");
        printf("               |      5 - List Pelanggan                       |\n");
        printf("               |      6 - Penambahan Pelanggan                 |\n");
        printf("               |      7 - Penghapusan Pelanggan                |\n");
        printf("               |      8 - Ubah Modus Penggunaan                |\n");
	    printf("               |      9 - Burst Link Out                       |\n");
        printf("               ------------------------------------------------\n\n");
	    printf("               Input> ");
}

void Closing()
/* { F.S. : Mencetak menu penutup interface } */
{
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    printf("\n");
    for (i=1;i<=80;i++)
    {
     printf("=");
     DelayWaktu(10);
    }
    printf("\n");
    printf("\n                             Burst Link Out!\n");
    printf("                                Goodbye!\n");
    DelayWaktu(2000);
}

/* All Rights Reserved 2012 */
