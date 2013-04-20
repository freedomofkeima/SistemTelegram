/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_String.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_ListPengguna_h
#define adt_ListPengguna_h

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
typedef struct tPengguna *uaddress;
typedef struct tPengguna {
	char nama[MAX_CHAR];
	uaddress next;
} Pengguna;
typedef struct {
	uaddress First;
} DataPengguna;

/* *** SELEKTOR *** */
#define Next(P) (P)->next
#define First(L) (L).First
#define Nama(U) (U)->nama

/* { *** MANAJEMEN LIST PENGGUNA *** } */
boolean UIsListEmpty(DataPengguna L);
/* { Mengirimkan true jika list kosong } */

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void UCreateUList(DataPengguna *L);
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */

/* { ***************** Manajemen Memori ***************** } */
uaddress UAlokasi(char X[]);
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */

 void UDealokasi(uaddress *P);
 /* { I.S. P terdefinisi } */
 /* { F.S. P dikembalikan ke sistem } */
 /* { Melakukan dealokasi/pengembalian address P } */


/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void UInsVFirst(DataPengguna *L, char X[]);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

void UInsVLast(DataPengguna *L, char X[]);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

/* { *** PENGHAPUSAN ELEMEN *** } */
void UDelX(DataPengguna *L, char X[]);
/* { I.S. list tidak kosong } */
/* { F.S. elemen X di list dihapus }
{ dan alamat elemen tersebut di-dealokasi } */

void PrintInfoLP(DataPengguna L);
//PrintInfo Mencetak info di dalam kamuskarakter
#endif
/* All Rights Reserved 2012 */
