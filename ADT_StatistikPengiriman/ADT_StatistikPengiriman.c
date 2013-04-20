/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_StatistikPengiriman.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Statistik Pengiriman */
#include "ADT_StatistikPengiriman.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
/* ********* ADT STATISTIK PENGIRIMAN ********* */

/* { *** MANAJEMEN LIST STATISTIK KIRIM*** } */
boolean SKIsListEmpty(StatKirim S)
/* { Mengirimkan true jika list StatKirim kosong } */
{
	return (First(S)==Nil);
}

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void SKCreateList(StatKirim *S)
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */
{
    First(*S) = Nil;
}

/* { ***************** Manajemen Memori ***************** } */
skaddress SKAlokasi(char X[], int Y)
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */
{
	/** Kamus Lokal **/
	skaddress p;
	int i;

	/** Algoritma **/
	p = (skaddress) malloc (sizeof(ElmtStatKirim));
	if (p!=Nil)
	{
		for (i=0;i<11;i++)
            Waktu(p)[i] = '\0';
		for(i=0;i<MAX_CHAR;i++)
		{
            if (X[i]=='\0')
				break;
			Waktu(p)[i] = X[i];
		}
		JumlahPesan(p)=Y;
		Next(p) = Nil;
	}
	else //Alokasi gagal
		p = Nil;
	return p;
}

void SKDealokasi(skaddress *P)
/* { I.S. P terdefinisi } */
/* { F.S. P dikembalikan ke sistem } */
/* { Melakukan dealokasi/pengembalian address P } */
{
    free(*P);
}

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void SKInsVFirst(StatKirim *S, char X[], int Y)
/* { I.S. S mungkin kosong } */
/* { F.S. X dan Y ditambahkan sebagai elemen pertama List } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
	/** Kamus Lokal **/
    skaddress P, Pt;

    /** Algoritma **/
    Pt = SKAlokasi(X,Y);
    if (Pt != Nil)
    {
        P = First(*S);
        Next(Pt) = P;
        First(*S) = Pt;
    }
}

void SKInsVLast(StatKirim *S, char X[], int Y)
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir List } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
	/** Kamus Lokal **/
    skaddress P, Psec;
    /** Algoritma **/
    if (SKIsListEmpty(*S))
        SKInsVFirst(S,X,Y);
    else
    {
        Psec = SKAlokasi(X,Y);
        P = First(*S);
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = Psec;
    }
}

 /* { ***************** LOAD DAN SAVE ***************** } */
boolean LoadStatKirim(StatKirim *S)
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DataPengguna) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */
{
    /** Kamus Lokal **/
    boolean IsLoaded = false;
    char Temp[MAX_CHAR]; //Variabel pembacaan sementara
    char TempWaktu[MAX_CHAR]; //Variabel untuk menyimpan waktu dari setiap jam pengiriman
    int TempPesan; //Variabel untuk menyimpan jumlah pesan sementara
    FILE *sk;
	int i; //Indeks untuk traversal

    /** Algoritma **/
    sk = fopen("./Sending/statkirim.dat","r");
    if (sk != Nil)
    {
        IsLoaded = true;
        InisialisasiString(Temp);
        while (fgets(Temp,sizeof(Temp),sk) != NULL)
        {
            if((Temp[0] != '@') && (Temp[1]!='e'))
            {
				/* Pemrosesan Masukan */
				/* Memroses Waktu Pengiriman */
                InisialisasiString(TempWaktu);
                for(i=0;i<=9;i++)
                {
                        TempWaktu[i] = Temp[i];
                }
				/* Memroses jumlah pesan yang ditransfer setiap jamnya */
				 i = 11;
				 TempPesan = 0;
				 while (Temp[i]!='#')
				 {
			     		TempPesan= TempPesan*10 + Temp[i] - '0';
			    		i++;
				 } //indeks sekarang berada pada '#'
            SKInsVLast(S,TempWaktu,TempPesan);
            InisialisasiString(Temp);
            }
		}
    }
    fclose(sk);
    return IsLoaded;
}

boolean SaveStatKirim(StatKirim S)
/* { I.S. DataPengguna tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */
{
	/** Kamus Lokal **/
	boolean IsSaved = false;
	FILE *sk;
	skaddress p;

	/** Algoritma **/
	sk = fopen("./Sending/statkirim.dat","wt");
	p = First(S);
	while (p!=Nil)
	{
		IsSaved = true;
		fprintf(sk,"%s %d#\n",Waktu(p),JumlahPesan(p));
		p = Next(p);
	}
	fprintf(sk,"@end\n");
	fclose(sk);
	return IsSaved;
}
