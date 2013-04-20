/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_ListStatistik.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_ListStatistik.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* { *** ADT MANAJEMEN LIST STATISTIK *** } */
boolean SIsListEmpty(Statistik L)
/* { Mengirimkan true jika list kosong } */
{
    return (First(L) == Nil);
}

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void SCreateList(Statistik *L)
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */
{
    First(*L) = Nil;
}

/* { ***************** Manajemen Memori ***************** } */
saddress SAlokasi(InfoStatistik X)
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */
 {
     /* Kamus Lokal */
     saddress P;
     int i;
     /* Algoritma */
     P = (saddress) malloc (sizeof(ElmtStatistik));
     if (P != Nil)
     {
         InisialisasiString(NamaPengirim(P));
         for (i=0;i<MAX_CHAR;i++)
         {
           NamaPengirim(P)[i] = X.namapengirim[i];
           if (X.namapengirim[i] == '\0')
             break;
         }
        InisialisasiString(NamaPenerima(P));
        for (i=0;i<MAX_CHAR;i++)
        {
            NamaPenerima(P)[i] = X.namapenerima[i];
            if (X.namapenerima[i] == '\0')
              break;
        }
        Prioritas(P) = X.prioritas;
        InisialisasiTanggal(WaktuKirim(P));
        for (i=0;i<12;i++)
            WaktuKirim(P)[i] = X.waktukirim[i];
        StatusKirim(P) = X.statuskirim;
        JumlahPanjang(P) = X.jumlahpanjang;
        JumlahPendek(P) = X.jumlahpendek;
        JumlahTandaBaca(P) = X.jumlahtandabaca;
        JumlahLain(P) = X.jumlahlain;
        JumlahEnter(P) = X.jumlahenter;
        BiayaPesan(P) = X.biayapesan;
        Next(P) = Nil;
     } else
     { /* Alokasi Gagal */
         P = Nil;
     }
     return P;
 }

 void SDealokasi(saddress *P)
 /* { I.S. P terdefinisi } */
 /* { F.S. P dikembalikan ke sistem } */
 /* { Melakukan dealokasi/pengembalian address P } */
 {
     free(*P);
 }

/* { ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** } */
/* Pencarian yang dilakukan sesuai dengan keyword yang dibutuhkan, realisasikan */

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void SInsVFirst(Statistik *L, InfoStatistik X)
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
    /* Kamus Lokal */
    saddress P, Pt;
    /* Algoritma */
    Pt = SAlokasi(X);
    if (Pt != Nil)
    {
        P = First(*L);
        Next(Pt) = P;
        First(*L) = Pt;
    }
}

void SInsVLast(Statistik *L, InfoStatistik X)
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
    /* Kamus Lokal */
    saddress P, Psec;
    /* Algoritma */
    if (SIsListEmpty(*L))
        SInsVFirst(L, X);
    else
    {
        Psec = SAlokasi(X);
        P = First(*L);
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = Psec;
    }
}
/* All Rights Reserved 2012 */
void LPrintInfo(Statistik L)
//LPRintInfo Memprint Info dari statistik
	{
	//kamus lokal
	saddress P;
	//algoritma
	P = First(L);
	while (Next(P)!=Nil && NamaPengirim(P)!= Nil)
		{
		printf("statistik");
		P = Next(P);
		printf("Nama Pengirim: %s \n",NamaPengirim(P));
		printf("NamaPenerima : %s \n",NamaPenerima(P));
		printf("Prioritas: %d \n",Prioritas(P));
		printf("Waktu Kirim: %s \n",WaktuKirim(P));
		printf("StatusKirim: %d \n",StatusKirim(P));
		printf("Jumlah Pendek: %d \n",JumlahPendek(P));
		printf("Jumlah Panjang: %d \n",JumlahPanjang(P));
		printf("Jumlah Tanda Baca: %d \n",JumlahTandaBaca(P));
		printf("Jumlah Lain - Lain : %d \n",JumlahLain(P));
		printf("Jumlah Enter : %d \n",JumlahEnter(P));
		printf("Biaya Pesan : %d \n\n",BiayaPesan(P));
		}
	}