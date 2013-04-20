/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_StatistikPenerimaan.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */


/* ********* ADT STATISTIK PENERIMAAN ********* */
#ifndef adt_statistikpenerimaan_h
#define adt_statistikpenerimaan_h

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
typedef struct tStatTerima *staddress;
typedef struct tStatTerima
{
	char penerima[MAX_CHAR]; //nama penerima
	int sudahbaca; //jumlah pesan yang belum terbaca
	int totalterima; //jumlah pesan yang sudah terbaca
	staddress next;
} ElmtStatTerima;
typedef struct
{
	staddress First;
} StatTerima;

/* *** SELEKTOR *** */
#define Next(P) (P)->next
#define First(L) (L).First
#define Penerima(K) (K)->penerima
#define SudahBaca(K) (K)->sudahbaca
#define TotalTerima(K) (K)->totalterima

/* Header File ADT Statistik Penerimaan */

/* { *** MANAJEMEN LIST STATISTIK TERIMA*** } */
boolean STIsListEmpty(StatTerima S);
/* { Mengirimkan true jika list StatTerima kosong } */

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void STCreateList (StatTerima *S);
/* I.S. sembarang
   F.S. terbentuk list StatTerima kosong
*/

/* { ***************** Manajemen Memori ***************** } */
staddress STAlokasi(char X[], int Y, int Z);
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */

void STDealokasi(staddress *P);
/* { I.S. P terdefinisi } */
/* { F.S. P dikembalikan ke sistem } */
/* { Melakukan dealokasi/pengembalian address P } */

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void STInsVFirst(StatTerima *S, char X[], int Y, int Z);
/* { I.S. S mungkin kosong } */
/* { F.S. X , Y, Z ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

void STInsVLast(StatTerima *S, char X[], int Y, int Z);
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */

 /* { ***************** LOAD DAN SAVE ***************** } */
boolean LoadStatTerima(StatTerima *S);
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DataPengguna) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */

boolean SaveStatTerima(StatTerima S);
/* { I.S. DataPengguna tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */

#endif
