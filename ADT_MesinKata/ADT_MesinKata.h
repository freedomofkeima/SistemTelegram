/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_MesinKata.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_MesinKata_h
#define adt_MesinKata_h

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* ***************ADT MESIN KATA*************** */
#define blank ' '
#define dot '.'
#define dash '-'
#define MAX_CHAR 1000

/* { *** Definisi Type Kata *** } */
typedef struct
{
	char TabKata[MAX_CHAR];
	int Length;
} kata;

/* { *** Primitif-Primitif Mesin Kata *** } */
void Ignore_Blank();
/* { Mengabaikan satu atau beberapa BLANK } */
/* { I.S. : CC sembarang } */
/* { F.S. : CC != BLANK atau CC = MARK } */

void SalinKata();
/* { Mengakuisisi kata, menyimpan dalam CKata } */
/* {I.S. : CC adalah karakter pertama dari kata } */
/* {F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
            NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
            karakter sesudah karakter terakhir yang diakuisisi } */

void STARTKATA(char X[]);
/* { I.S. : CC sembarang } */
/* { F.S. : EndKata = true, dan CC = Mark; }
{           atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
            CC karakter pertama sesudah karakter terakhir kata } */

void ADVMORSE();
/* { I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
            dari kata yg sudah diakuisisi } */
/* { F.S. : Jika CC = MARK, maka EndKata = true
            atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
            CC karakter pertama sesudah karakter terakhir kata } */


#endif
/* All Rights Reserved 2012 */
