/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mLoadFile.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "../ADT_String/ADT_String.c"
#include "../ADT_ListPengguna/ADT_ListPengguna.c"
#include "../ADT_ListKamus/ADT_ListKamus.c"
#include "../ADT_ListStatistik/ADT_ListStatistik.c"
#include "ADT_LoadFile.c" //comment this later

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>


int main(){
    /* Kamus Lokal */
    boolean IsSukses; /* Apabila Load / Save file berhasil dilakukan, maka bernilai true */
    uaddress P; /* Address dari sebuah List Pengguna */
    kaddress Px; /* Address dari sebuah List Kamus Karakter */
    saddress Py; /* Address dari sebuah List Statistik */
    DataPengguna DataList; /* List penyimpanan Data Pengguna */
    DaftarHarga HargaList[5]; /* Tabel penyimpanan Daftar Harga */
    KamusKarakter KamusList; /* List penyimpanan Kamus Karakter */
    Statistik StatistikList;
	int i;//variabel option
	char SubBurstMode;
	char X;//karakter inputan
	char Y[255];//Karakter simbol, dkk untuk inputan
	char Z[255];//Jenis Karakter
	int Option;
	int NHarga;

    /* Algoritma */
    /* Reading Databases - External File */
    UCreateList(&DataList);
    KCreateList(&KamusList);
    SCreateList(&StatistikList);
    IsSukses = LoadDataPengguna(&DataList);
    IsSukses = LoadDaftarHarga(HargaList);
    IsSukses = LoadKamusKarakter(&KamusList);
    IsSukses = LoadStatistik(&StatistikList);
	do
		{
		printf("1 Print Statistik\n2 insert elemen baru list Kamus\n3 print pengguna\n4 tambah pengguna\n5 cetak harga\n6 Statistik\n7 keluar>input ");
		scanf("%d",&i);
		switch (i)
			{
			case 1:
				PrintInfoLK(KamusList);
				break;
			case 2:
				printf("karakter :");
				scanf("\n%c",&X);
				printf("Karakter Simbol:");
				scanf("%s[255]",&Y);
				printf("Jenis Karakter:");
				scanf("%s",&Z);
				KInsVLast(&KamusList,X,Y,Z);
				printf("elemen List:\n");
				IsSukses = SaveKamusKarakter(KamusList);
				break;
			case 3:
				PrintInfoLP(DataList);
				break;
			case 4:
				printf("Nama Pengguna :\n");
				scanf("\n");
				fgets(Y,sizeof Y,stdin);
				UInsVLast(&DataList,Y);
				printf("Elemen List:\n");
				PrintInfoLP(DataList);
				IsSukses = SaveDataPengguna(DataList);
				break;
			case 5:
			/* Awal Fungsi Cetak Harga - Modus Pengaturan */
				printf("\n               List Daftar Harga");
				/* Cetak List Daftar Harga */
				printf("\n               Jenis Kata   - Harga");
				for (i=0;i<=4;i++)
					{
						printf("\n               %d. %s - %d",i+1,JenisKata(HargaList[i]),Harga(HargaList[i]));
					}

				do
				{
					printf("\n                Apakah anda ingin mengganti daftar Harga (Y/N)?> ");
					scanf("\n%c",&SubBurstMode);
					if (toupper(SubBurstMode) == 'Y')
					{
						/* Tanyakan bagian yang ingin diubah - Modus Pengaturan */
						printf("Bagian apa yang ingin diubah?\n(1:Pendek,2:Panjang,3:Tanda Baca,4:Lain-Lain,5:Enter/Baris Baru)> ");
						scanf("%d",&Option);
						while ((Option!=1) && (Option!=2) && (Option!=3) && (Option!=4) && (Option!= 5))
						{
							printf("Masukan salah\nBagian yang ingin diubah> ");
							scanf("%d",&Option);
						};
						NHarga = 0; /* Inisialisasi variabel sementara */
						do
						{
							printf("Harga Baru :");
							scanf("%d",&NHarga);
							if (NHarga < 0)
							 printf("\n                Masukkan harga tidak valid!\n");
						}
						while (NHarga < 0);
						Harga(HargaList[Option-1]) = NHarga;
						printf("\n                Penggantian harga berhasil!\n");
						IsSukses = SaveDaftarHarga(HargaList);
						break;
					} else
						{
						if (toupper(SubBurstMode) == 'N')
							break;
							else
							{
								printf("\n                Masukkan anda salah!\n");
							}
						}
				} while ((SubBurstMode != 'Y') || (SubBurstMode != 'N'));
				printf("\n--------------------------------------------------------------------------------\n");
				/* Akhir Fungsi Cetak Harga - Modus Pengaturan */
				break;
			case 6:
				LPrintInfo(StatistikList);
				break;
			}
		}while (i!= 7);
return 0;
}
/* All Rights Reserved 2012 */
