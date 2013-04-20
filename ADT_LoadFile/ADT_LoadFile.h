/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_LoadFile.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_LoadFile_h
#define adt_LoadFile_h

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

/* *** KONSTRUKTOR *** */
typedef struct {
	char jeniskata[MAX_CHAR];
    int harga;
} DaftarHarga;


/* *** SELEKTOR *** */
#define JenisKata(X) (X).jeniskata
#define Harga(X) (X).harga


/* *** LOAD FILE *** */
boolean LoadDataPengguna(DataPengguna *L);
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DataPengguna) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */

boolean SaveDataPengguna(DataPengguna L);
/* { I.S. DataPengguna tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */

boolean LoadDaftarHarga(DaftarHarga X[]);
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DaftarHarga) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */

boolean SaveDaftarHarga(DaftarHarga X[]);
/* { I.S. DaftarHarga tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Daftar Harga disimpan dalam NamaFile - file eksternal } */

boolean LoadKamusKarakter(KamusKarakter *L);
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe KamusKarakter) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */

boolean SaveKamusKarakter(KamusKarakter L);
/* { I.S. KamusKarakter tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */

boolean LoadStatistik(Statistik *L);
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe Statistik) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */

boolean SaveStatistik(Statistik L);
/* { I.S. Statistik tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */

#endif
/* All Rights Reserved 2012 */
