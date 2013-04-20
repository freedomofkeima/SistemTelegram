/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_String.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_String.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* { *** ADT PENGELOLAAN KARAKTER / STRING *** } */
void InisialisasiString(char X[])
/* { I.S. : X sembarang } */
/* { F.S. : Semua elemen X menjadi '\0' / NULL } */
{
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    for (i=0; i<MAX_CHAR; i++)
        X[i] = '\0';
}

void InisialisasiTanggal(char X[])
/* { I.S. : X sembarang } */
/* { F.S. : Semua elemen X bertipe tanggal menjadi '\0' / NULL } */
{
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    for (i=0; i<13; i++)
        X[i] = '\0';
}

boolean IsStringSama(char X1[], char X2[])
/* { IsStringSame menerima dua buah String dan membandingkan apakah kedua buah string tersebut bernilai sama } */
{
    /* Kamus Lokal */
    boolean IsSama = true;
    int i;
    /* Algoritma */
    for (i=1;i<MAX_CHAR;i++)
    {
        if ((IsSama) && (toupper(X1[i]) == toupper(X2[i])))
        {
            if (X1[i] == '\0')
              break;
        } else IsSama = false;
    }
    return IsSama;
}

void SalinString(char X1[],char X2[])
/* { I.S. : X1 terdefinisi } */
/* { F.S. : X2 merupakan salinan dari X1 } */
{
    /* Kamus Lokal */
    int i = 0;
    /* Algoritma */
    while ((X1[i] != '\0') && (i<MAX_CHAR))
    {
        X2[i] = X1[i];
        i++;
    }
}

void Konkat (char X[], char Y[])
/* I.S. String X dan Y sudah pernah diinisialisasi, string X tidak penuh
   F.S. String Y ditambahkan di belakang string X (maksimal hingga X penuh)
*/
{
	/** Kamus Lokal **/
	int ix=0; //indeks jelajah string X
	int iy=0; //indeks jelajah string Y
	/** Algoritma **/
	while (X[ix]!='\0')
	{
		ix++;
	} //ix merupakan indeks setelah indeks karakter terakhir pada X
	/* Menambahkan karakter-karakter Y ke belakang X */
	while ((Y[iy]!='\0') && (ix<=MAX_CHAR))
	{
		X[ix]=Y[iy];
		ix++;
		iy++;
	}
}

/* All Rights Reserved 2012 */
