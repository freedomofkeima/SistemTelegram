/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_ListKamus.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_ListKamus_h
#define adt_ListKamus_h

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

#define Nil NULL
#define MARK_RECORD '#'

#ifndef MAX_CHAR
#define MAX_CHAR 1000
#endif

/* *** KONSTRUKTOR *** */
typedef struct tKamus *kaddress;
typedef struct tKamus {
	char simbol;
	char karaktersimbol[MAX_CHAR];
	char jeniskata[MAX_CHAR];
	kaddress next;
} Kamus;
typedef struct {
	kaddress First;
} KamusKarakter;

/* *** SELEKTOR *** */
#define Next(P) (P)->next
#define First(L) (L).First
#define Simbol(K) (K)->simbol
#define JenisKataL(X) (X)->jeniskata
#define KarakterSimbol(K) (K)->karaktersimbol

/* { *** MANAJEMEN LIST KAMUS KARAKTER *** } */
boolean KIsListEmpty(KamusKarakter L);
/* { Mengirimkan true jika list kosong } */

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void KCreateUList(KamusKarakter *L);
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */

/* { ***************** Manajemen Memori ***************** } */
kaddress KAlokasi(char X,char Y[],char Z[]);
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */

 void KDealokasi(kaddress *P);
 /* { I.S. P terdefinisi } */
 /* { F.S. P dikembalikan ke sistem } */
 /* { Melakukan dealokasi/pengembalian address P } */


/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void KInsVFirst(KamusKarakter *L, char X, char Y[], char Z[]);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

void KInsVLast(KamusKarakter *L, char X, char Y[], char Z[]);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

void PrintInfoLK(KamusKarakter L);
//PrintInfo Mencetak info di dalam kamuskarakter


#endif
/* All Rights Reserved 2012 */
