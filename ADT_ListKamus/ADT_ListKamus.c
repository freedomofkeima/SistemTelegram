/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_ListKamus.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_ListKamus.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* *** ADT MANAJEMEN LIST KAMUS KARAKTER *** */
boolean KIsListEmpty(KamusKarakter L)
/* { Mengirimkan true jika list kosong } */
{
    return (First(L) == Nil);
}

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void KCreateList(KamusKarakter *L)
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */
{
    First(*L) = Nil;
}

/* { ***************** Manajemen Memori ***************** } */
kaddress KAlokasi(char X, char Y[], char Z[])
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */
  {
     /* Kamus Lokal */
     kaddress P;
     int i;
     /* Algoritma */
     P = (kaddress) malloc (sizeof(Kamus));
     if (P != Nil)
     {
         InisialisasiString(KarakterSimbol(P));
         InisialisasiString(JenisKataL(P));
         Simbol(P) = X;

         for (i=0;i<MAX_CHAR;i++)
         {
            KarakterSimbol(P)[i] = Y[i];
            if (KarakterSimbol(P)[i] == '\0')
             break;
         }

          for (i=0;i<MAX_CHAR;i++)
         {
            JenisKataL(P)[i] = Z[i];
            if (JenisKataL(P)[i] == '\0')
             break;
         }

        Next(P) = Nil;
     } else
     { /* Alokasi Gagal */
        P = Nil;
     }
    return(P);
 }

 void KDealokasi(kaddress *P)
 /* { I.S. P terdefinisi } */
 /* { F.S. P dikembalikan ke sistem } */
 /* { Melakukan dealokasi/pengembalian address P } */
 {
     free(*P);
 }

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void KInsVFirst(KamusKarakter *L, char X,char Y[],char Z[])
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
    /* Kamus Lokal */
    kaddress P, Pt;
    /* Algoritma */
    Pt = KAlokasi(X,Y,Z);
    if (Pt != Nil)
    {
        P = First(*L);
        Next(Pt) = P;
        First(*L) = Pt;
    }
}

void KInsVLast(KamusKarakter *L, char X, char Y[], char Z[])
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
    /* Kamus Lokal */
    kaddress P, Psec;
    /* Algoritma */
    if (KIsListEmpty(*L))
        KInsVFirst(L, X, Y, Z);
    else
    {
        Psec = KAlokasi(X,Y,Z);
        if (Psec != Nil)
        {
        P = First(*L);
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = Psec;
        }
    }
}

void PrintInfoLK(KamusKarakter L)
//PrintInfo Mencetak info di dalam kamuskarakter
	{
	kaddress P;
	P = First(L);
	while(P!= Nil)
		{
		printf("%c %s %s\n",Simbol(P),JenisKataL(P),KarakterSimbol(P));
		P=Next(P);
		}
	}
/* All Rights Reserved 2012 */
