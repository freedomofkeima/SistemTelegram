/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_String.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_String_h
#define adt_String_h

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

#ifndef MAX_CHAR
#define MAX_CHAR 1000
#endif

/* { *** ADT PENGELOLAAN KARAKTER / STRING *** } */
void InisialisasiString(char X[]);
/* { I.S. : X sembarang } */
/* { F.S. : Semua elemen X menjadi '\0' / NULL } */

void InisialisasiTanggal(char X[]);
/* { I.S. : X sembarang } */
/* { F.S. : Semua elemen X bertipe tanggal menjadi '\0' / NULL } */

boolean IsStringSama(char X1[], char X2[]);
/* { IsStringSame menerima dua buah String dan membandingkan apakah kedua buah string tersebut bernilai sama } */

void SalinString(char X1[],char X2[]);
/* { I.S. : X1 terdefinisi } */
/* { F.S. : X2 merupakan salinan dari X1 } */

void Konkat (char X[], char Y[]);
/* I.S. String X dan Y sudah pernah diinisialisasi, string X tidak penuh */
/* F.S. String Y ditambahkan di belakang string X (maksimal hingga X penuh) */



#endif
/* All Rights Reserved 2012 */
