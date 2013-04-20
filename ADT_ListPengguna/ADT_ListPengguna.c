/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_ListPengguna.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_ListPengguna.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* *** ADT MANAJEMEN LIST PENGGUNA *** */
boolean UIsListEmpty(DataPengguna L)
/* { Mengirimkan true jika list kosong } */
{
    return (First(L) == Nil);
}

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void UCreateList(DataPengguna *L)
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */
{
    First(*L) = Nil;
}

/* { ***************** Manajemen Memori ***************** } */
uaddress UAlokasi(char X[])
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */
  {
     /* Kamus Lokal */
     uaddress P;
     int i;
     /* Algoritma */
     P = (uaddress) malloc (sizeof(Pengguna));
     if (P != Nil)
     {
         InisialisasiString(Nama(P));
         for (i=0;i<MAX_CHAR;i++)
         {
            Nama(P)[i] = X[i];
            if (Nama(P)[i] == '\0')
             break;
         }
        Next(P) = Nil;
     } else
     { /* Alokasi Gagal */
        P = Nil;
     }
    return(P);
 }

 void UDealokasi(uaddress *P)
 /* { I.S. P terdefinisi } */
 /* { F.S. P dikembalikan ke sistem } */
 /* { Melakukan dealokasi/pengembalian address P } */
 {
     free(*P);
 }

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void UInsVFirst(DataPengguna *L, char X[])
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
    /* Kamus Lokal */
    uaddress P, Pt;
    /* Algoritma */
    Pt = UAlokasi(X);
    if (Pt != Nil)
    {
        P = First(*L);
        Next(Pt) = P;
        First(*L) = Pt;
    }
}

void UInsVLast(DataPengguna *L, char X[])
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
    /* Kamus Lokal */
    uaddress P, Psec;
    /* Algoritma */
    if (UIsListEmpty(*L))
        UInsVFirst(L, X);
    else
    {
        Psec = UAlokasi(X);
        if (Psec != Nil)
        {
        P = First(*L);
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = Psec;
        }
    }
}

/* { *** PENGHAPUSAN ELEMEN *** } */
void UDelX(DataPengguna *L, char X[])
/* { I.S. list tidak kosong } */
/* { F.S. elemen X di list dihapus }
{ dan alamat elemen tersebut di-dealokasi } */
{
	/* Kamus Lokal */
	uaddress P;
	uaddress Prec;
	/* Algoritma */
	P = First(*L);
	while ((P!= Nil) && (!IsStringSama(X,Nama(P))))
	{
		Prec = P;
		P=Next(P);
	}
	if ((P!= Nil) && (P!=First(*L)))
	{
		Next(Prec) = Next(P);
		Next(P) = Nil;
		UDealokasi(&P);
		printf("\n               Penghapusan Berhasil!!\n");
	}
	else
	if (P == First(*L))
		{
		First(*L) = Next(P);
		UDealokasi(&P);
		printf("\n               Penghapusan Berhasil!!\n");
		}
	else
		printf("\n               Penghapusan Gagal, user tidak terdaftar\n");
}

void PrintInfoLP(DataPengguna L)
//PrintInfo Mencetak info di dalam kamuskarakter
	{
	uaddress P;
	P = First(L);
	while(P!= Nil)
		{
		printf("%s\n",Nama(P));
		P=Next(P);
		}
	}

/* All Rights Reserved 2012 */
