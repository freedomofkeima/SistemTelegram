/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_StatistikPengiriman.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */


/* ********* ADT STATISTIK PENGIIRIMAN  ********* */
#ifndef adt_statistikpengiriman_h
#define adt_statistikpengiriman_h

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
typedef struct tStatKirim *skaddress;
typedef struct tStatKirim
{
    char waktu[11]; //Untuk menyimpan waktu dari pengiriman pada statistik
    int jumlahpesan; //Untuk menyimpan jumlah pesan
    skaddress next;
} ElmtStatKirim;
typedef struct
{
	skaddress First;
} StatKirim;

/* *** SELEKTOR *** */
#define Next(P) (P)->next
#define First(L) (L).First
#define Waktu(K) (K)->waktu
#define JumlahPesan(K) (K)->jumlahpesan

/* Header File ADT Statistik Pengiriman */

/* { *** MANAJEMEN LIST STATISTIK KIRIM*** } */
boolean SKIsListEmpty(StatKirim S);
/* { Mengirimkan true jika list StatKirim kosong } */

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void SKCreateList (StatKirim *S);
/* I.S. sembarang
   F.S. terbentuk list StatKirim kosong
*/

/* { ***************** Manajemen Memori ***************** } */
skaddress SKAlokasi(char X[], int Y);
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */

void SKDealokasi(skaddress *P);
/* { I.S. P terdefinisi } */
/* { F.S. P dikembalikan ke sistem } */
/* { Melakukan dealokasi/pengembalian address P } */

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void SKInsVFirst(StatKirim *S, char X[], int Y);
/* { I.S. S mungkin kosong } */
/* { F.S. X dan Y ditambahkan sebagai elemen pertama List } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

void SKInsVLast(StatKirim *S, char X[], int Y);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir List } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

 /* { ***************** LOAD DAN SAVE ***************** } */
boolean LoadStatKirim(StatKirim *S);
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DataPengguna) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */

boolean SaveStatKirim(StatKirim S);
/* { I.S. DataPengguna tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */

#endif
