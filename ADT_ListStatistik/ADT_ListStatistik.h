/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_ListStatistik.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_ListStatistik_h
#define adt_ListStatistik_h

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
typedef struct {
	char namapengirim[MAX_CHAR];
	char namapenerima[MAX_CHAR];
	int prioritas; //Sehingga prioritas tertinggi diberi rank 1, dst
	char waktukirim[13]; //waktu kirim terdiri dari 12 karakter, format (YYMMDDHHMMSS)
	int statuskirim; //Sehingga ketika pesan di outbox = 1, sending = 2, dst
	int jumlahpendek;
	int jumlahpanjang;
	int jumlahtandabaca;
	int jumlahlain;
	int jumlahenter;
	int biayapesan;
} InfoStatistik;
typedef struct tStatistik *saddress;
typedef struct tStatistik {
    InfoStatistik info;
	saddress next;
} ElmtStatistik;
typedef struct {
	saddress First;
} Statistik;

/* *** SELEKTOR *** */
#define Next(P) (P)->next
#define First(L) (L).First
#define NamaPengirim(T) (T)->info.namapengirim
#define NamaPenerima(T) (T)->info.namapenerima
#define Prioritas(T) (T)->info.prioritas
#define WaktuKirim(T) (T)->info.waktukirim
#define StatusKirim(T) (T)->info.statuskirim
#define JumlahPendek(T) (T)->info.jumlahpendek
#define JumlahPanjang(T) (T)->info.jumlahpanjang
#define JumlahTandaBaca(T) (T)->info.jumlahtandabaca
#define JumlahLain(T) (T)->info.jumlahlain
#define JumlahEnter(T) (T)->info.jumlahenter
#define BiayaPesan(T) (T)->info.biayapesan

/* { *** MANAJEMEN LIST STATISTIK *** } */
boolean SIsListEmpty(Statistik L);
/* { Mengirimkan true jika list kosong } */

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void SCreateList(Statistik *L);
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */

/* { ***************** Manajemen Memori ***************** } */
saddress SAlokasi(InfoStatistik X);
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */

 void SDealokasi(saddress *P);
 /* { I.S. P terdefinisi } */
 /* { F.S. P dikembalikan ke sistem } */
 /* { Melakukan dealokasi/pengembalian address P } */

/* { ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** } */
/* Pencarian yang dilakukan sesuai dengan keyword yang dibutuhkan, realisasikan */

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void SInsVFirst(Statistik *L, InfoStatistik X);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

void SInsVLast(Statistik *L, InfoStatistik X);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
void LPrintInfo(Statistik L);
//LPRintInfo Memprint Info dari statistik


#endif
/* All Rights Reserved 2012 */
