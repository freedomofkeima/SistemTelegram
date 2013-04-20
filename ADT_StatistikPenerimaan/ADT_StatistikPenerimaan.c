/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_StatistikPenerimaan.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Statistik Penerimaan */
#include "ADT_StatistikPenerimaan.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
/* ********* ADT STATISTIK PENERIMAAN ********* */

/* { *** MANAJEMEN LIST STATISTIK TERIMA*** } */
boolean STIsListEmpty(StatTerima S)
/* { Mengirimkan true jika list StatTerima kosong } */
{
	return (First(S)==Nil);
}

/* { ***************** PEMBUATAN LIST KOSONG ***************** } */
void STCreateList(StatTerima *S)
/* { I.S. sembarang     } */
/* { F.S Terbentuk list kosong } */
{
    First(*S) = Nil;
}

/* { ***************** Manajemen Memori ***************** } */
staddress STAlokasi(char X[], int Y, int Z)
/* { Mengirimkan address hasil alokasi sebuah elemen } */
/* { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil. } */
 /* { Jika alokasi gagal, mengirimkan Nil } */
{
	/** Kamus Lokal **/
	staddress p;
	int i;

	/** Algoritma **/
	p = (staddress) malloc (sizeof(ElmtStatTerima));
	if (p!=Nil)
	{
		InisialisasiString(Penerima(p));
		for(i=0;i<MAX_CHAR;i++)
		{
			Penerima(p)[i] = X[i];
			if (X[i]=='\0')
				break;
		}
		SudahBaca(p)=Y;
		TotalTerima(p)=Z;
		Next(p) = Nil;
	}
	else //Alokasi gagal
		p = Nil;
	return p;
}

void STDealokasi(staddress *P)
/* { I.S. P terdefinisi } */
/* { F.S. P dikembalikan ke sistem } */
/* { Melakukan dealokasi/pengembalian address P } */
{
    free(*P);
}

/* { ***************** PRIMITIF BERDASARKAN NILAI ***************** } */
/* { *** PENAMBAHAN ELEMEN *** } */
void STInsVFirst(StatTerima *S, char X[], int Y, int Z)
/* { I.S. S mungkin kosong } */
/* { F.S. X , Y, Z ditambahkan sebagai elemen pertama L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
	/** Kamus Lokal **/
    staddress P, Pt;

    /** Algoritma **/
    Pt = STAlokasi(X,Y,Z);
    if (Pt != Nil)
    {
        P = First(*S);
        Next(Pt) = P;
        First(*S) = Pt;
    }
}

void STInsVLast(StatTerima *L, char X[], int Y, int Z)
/* { I.S. L mungkin kosong } */
/* { F.S. X ditambahkan sebagai elemen terakhir L } */
/* { Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. } */
{
	/** Kamus Lokal **/
    staddress P, Psec;
    /** Algoritma **/
    if (STIsListEmpty(*L))
        STInsVFirst(L,X,Y,Z);
    else
    {
        Psec = STAlokasi(X,Y,Z);
        P = First(*L);
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = Psec;
    }
}

 /* { ***************** LOAD DAN SAVE ***************** } */
boolean LoadStatTerima(StatTerima *S)
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe StatTerima) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */
{
    /** Kamus Lokal **/
    boolean IsLoaded = false;
	char Temp[MAX_CHAR];
    char TempPenerima[MAX_CHAR];
	int TempRead;
	int TempTotal;
    FILE *st;
	int idx,i;

    /** Algoritma **/
    st = fopen("./Inbox/statterima.dat","r");
    if (st != Nil)
    {
        IsLoaded = true;
        InisialisasiString(Temp);
        while (fgets(Temp,sizeof(Temp),st) != NULL)
        {
            if((Temp[0] != '@') && (Temp[1]!='e'))
            {
				/* Pemrosesan Masukan */
				/* Memroses Nama Pengirim */
				idx=1;
				while (Temp[idx]!='"')
					idx++;
				//i merupakan indeks '"' kedua
				InisialisasiString(TempPenerima);
				for (i=1;i<idx;i++)
					TempPenerima[i-1] = Temp[i];
				//Nama Penerima sudah dimasukkan ke Temp

				/* Memroses jumlah pesan yang belum dibaca */
				idx+=2;
				TempRead = 0;
				while (Temp[idx]!=' ')
				{
					TempRead = TempRead*10 + Temp[idx] - '0';
					idx++;
				} //indeks sekarang berada pada ' '

				/* Memroses jumlah pesan total yang telah diterima */
				idx++;
				TempTotal = 0;
				while (Temp[idx]!='#')
				{
					TempTotal = TempTotal*10 + Temp[idx] - '0';
					idx++;
				} //indeks sekarang berada pada '#'
            STInsVLast(S,TempPenerima,TempRead,TempTotal);
            }
		}
    }
    fclose(st);
    return IsLoaded;
}

boolean SaveStatTerima(StatTerima S)
/* { I.S. DataPengguna tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */
{
	/** Kamus Lokal **/
	boolean IsSaved = false;
	FILE *st;
	staddress p;

	/** Algoritma **/
	st = fopen("./Inbox/statterima.dat","wt");
	p = First(S);
	while (p!=Nil)
	{
		IsSaved = true;
		fprintf(st,"\"%s\" %d %d#\n",Penerima(p),SudahBaca(p),TotalTerima(p));
		p = Next(p);
	}
	fprintf(st,"@end\n");
	fclose(st);
	return IsSaved;
}
