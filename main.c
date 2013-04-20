/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : main.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Tubes */
#include "./ADT_String/ADT_String.c" //Use String
#include "./ADT_MesinKarakter/ADT_MesinKarakter.c" //Use Mesin Karakter
#include "./ADT_MesinKata/ADT_MesinKata.c" //Use Mesin Kata
#include "./ADT_PohonBiner/ADT_PohonBiner.c" //Use Pohon Biner
#include "./ADT_ListPengguna/ADT_ListPengguna.c" //Use List Pengguna
#include "./ADT_ListKamus/ADT_ListKamus.c" //Use List Kamus
#include "./ADT_ListStatistik/ADT_ListStatistik.c" //Use List Statistik
#include "./ADT_LoadFile/ADT_LoadFile.c" //Use Load File
#include "./ADT_StatistikPengiriman/ADT_StatistikPengiriman.c" //Use Statistik Pengiriman
#include "./ADT_StatistikPenerimaan/ADT_StatistikPenerimaan.c" //Use Statistik Penerimaan
#include "./ADT_Interface/ADT_Interface.c" //Use Interface
#include "adt_tubes.c" //Use ADT Tubes (Modus)

#include "adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

void LoadFile(DataPengguna *SP, DaftarHarga SH[], KamusKarakter *SK, Statistik *SS, StatKirim *SKirim, StatTerima *STerima)
/* { Prosedur yang digunakan untuk me-load semua file eksternal } */
{
    /* Kamus Lokal */
    boolean IsLoaded;
    /* Algoritma */
     /* Membuat List Kosong */
     UCreateList(SP);
     KCreateList(SK);
     SCreateList(SS);
     SKCreateList(SKirim);
     STCreateList(STerima);
     /* MeLoad kembali data yang sudah ada */
     IsLoaded = LoadDataPengguna(SP);
     IsLoaded = LoadDaftarHarga(SH);
     IsLoaded = LoadKamusKarakter(SK);
     IsLoaded = LoadStatistik(SS);
     IsLoaded = LoadStatKirim(SKirim);
     IsLoaded = LoadStatTerima(STerima);
}

int main(){
    /* Kamus Lokal */
    boolean alnum; /* Variabel yang digunakan untuk menentukan apakah suatu karakter bersifat alfanumerik */
    boolean IsExit; /* Digunakan sebagai penanda berakhirnya program */
    boolean IsSukses; /* Apabila Load / Save file berhasil dilakukan, maka bernilai true */
    char NamaPengguna[MAX_CHAR]; /* Digunakan untuk menerima masukkan NamaPengguna */
    char NamaFile[MAX_CHAR]; /* Digunakan untuk menuliskan nama file */
    char SubMode; /* Mode yang sedang aktif */
    uaddress P; /* Address dari sebuah List Pengguna */
    kaddress Px; /* Address dari sebuah List Kamus Karakter */
    saddress Py; /* Address dari sebuah List Statistik */
    DataPengguna DataList; /* List penyimpanan Data Pengguna */
    DaftarHarga HargaList[5]; /* Tabel penyimpanan Daftar Harga */
    KamusKarakter KamusList; /* List penyimpanan Kamus Karakter */
    Statistik StatistikList;
    StatKirim StatKirimList; /* List penyimpanan Statistik Pengiriman */
    StatTerima StatTerimaList; /* List penyimpanan Statistik Penerimaan */
    char BurstMode; /* Menu pilihan pengguna */
    char SubBurstMode; /* Untuk menerima masukkan pilihan pengguna */
    int i; /* Indeks untuk traversal */
    int Option; /* Variabel untuk pilihan pengguna */
    int NHarga; /* Variabel penyimpan harga sementara */
    /* Algoritma */
    /* Reading Databases - External File */
    LoadFile(&DataList,HargaList,&KamusList,&StatistikList,&StatKirimList,&StatTerimaList);
    /* Inisialisasi Variabel */
    IsExit = false;
    InisialisasiString(NamaPengguna);
    Opening();
	do
	{
	    SubMode = '0';
        MainMenu();
	    scanf("\n%c",&BurstMode);
	    switch(toupper(BurstMode))
	    {
	        case 'A':
                     do
                    {
                     SubMode = 'A';
                     ModePenulisan();
                     scanf("\n%c",&SubBurstMode);
                     //Meng-load kembali data-data pengguna
                     LoadFile(&DataList,HargaList,&KamusList,&StatistikList,&StatKirimList,&StatTerimaList);
                     switch(SubBurstMode)
                     {
                        case '1':
                                        /* Asumsi Pesan berisikan setidaknya 1 buah kata */
                                        Kirim(DataList,KamusList,&StatistikList,HargaList);
                                        break;
                        case '2':
                                        HitungHarga(StatistikList);
                                        break;
                        case '7':
                                        ListStatistikTulis(StatistikList,1);
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'A');
                     break;
            case 'B':
                     do
                    {
                     SubMode = 'B';
                     ModePengiriman();
                     scanf("\n%c",&SubBurstMode);
                     //Meng-load kembali data-data pengguna
                     LoadFile(&DataList,HargaList,&KamusList,&StatistikList,&StatKirimList,&StatTerimaList);
                     switch(SubBurstMode)
                     {
                        case '1':
                                        TransmitPesan(&StatistikList,&StatKirimList);
                                        break;
                        case '7':
                                        ListStatistikKirim(StatKirimList);
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'B');
                     break;
            case 'C':
                     do
                    {
                     SubMode = 'C';
                     ModePenerimaan();
                     scanf("\n%c",&SubBurstMode);
                     //Meng-load kembali data-data pengguna
                     LoadFile(&DataList,HargaList,&KamusList,&StatistikList,&StatKirimList,&StatTerimaList);
                     switch(SubBurstMode)
                     {
                        case '1':
                                        ListPesan(&StatistikList,&StatTerimaList);
                                        break;
                        case '2':
                                        BacaPesan(&StatistikList,KamusList,&StatTerimaList);
                                        break;
                        case '3':
                                        HapusPesan(&StatistikList);
                                        break;
                        case '7':
                                        ListStatistikTerima(StatTerimaList);
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'C');
                     break;
            case 'D':
                     SubMode = 'D';
                     do
                    {
                     ModePengaturan();
                     scanf("\n%c",&SubBurstMode);
                     //Meng-load kembali data-data pengguna
                     LoadFile(&DataList,HargaList,&KamusList,&StatistikList,&StatKirimList,&StatTerimaList);
                     switch(SubBurstMode)
                     {
                         case '1':
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
                                            DelayWaktu(300);
                                            printf("\n--------------------------------------------------------------------------------\n");
                                        /* Akhir Fungsi Cetak Harga - Modus Pengaturan */
                                        break;
                         case '2':
                                         /* Awal Fungsi Cetak Item Kamus - Modus Pengaturan */
                                            printf("\n               List Item Kamus");
                                            /* Cetak List Daftar Harga */
                                            printf("\n               Simbol   - Nama Karakter - Jenis Karakter");
                                            Px = First(KamusList);
                                            while (Px != Nil)
                                                {
                                                    printf("\n                  %c     - ",Simbol(Px));
                                                    for (i=0;i<14;i++)
                                                     printf("%c",KarakterSimbol(Px)[i]);
                                                    printf("-  %s",JenisKataL(Px));
                                                    Px = Next(Px);
                                                }
                                            DelayWaktu(300);
                                            printf("\n--------------------------------------------------------------------------------\n");
                                        /* Akhir Fungsi Cetak Item Kamus - Modus Pengaturan */
                                        break;
                         case '3':
										TambahKamus(&KamusList);
										SaveKamusKarakter(KamusList);
                                        break;
                         case '4':
										HapusKamus(&KamusList);
										SaveKamusKarakter(KamusList);
                                        break;
                         case '5':
                                        /* Awal Fungsi Cetak List Pengguna - Modus Pengaturan */
                                            P = First(DataList);
                                            while (P != Nil)
                                            {
                                                printf("%s",Nama(P));
                                                P = Next(P);
                                            }
                                            DelayWaktu(300);
                                            printf("\n--------------------------------------------------------------------------------\n");
                                        /* Akhir Fungsi Cetak List Pengguna - Modus Pengaturan */
                                            break;
                        case '6':
                                        /* Awal Fungsi Tambahkan List Pengguna - Modus Pengaturan */
											alnum = true;
											printf("\nMasukkan nama pengguna yang ingin ditambahkan(hanya boleh alphanumerik)> ");
                                            scanf("\n");
                                            fgets(NamaPengguna,sizeof(NamaPengguna),stdin);
                                            i = 0;
											while(NamaPengguna[i]!='\n')
												{
												alnum = alnum &&(isalnum(NamaPengguna[i]) || NamaPengguna[i] == ' ');
												i++;
												}
											if(!alnum)
												{
												printf("Nama mengandung simbol, input gagal\n");
												}
											else
												{
												i= 0;
												while (NamaPengguna[i]!='\0')
													{
													NamaPengguna[i] = toupper(NamaPengguna[i]);
													i++;
													}
												/* Silahkan cara membacanya diganti dengan skema mesin karakter */
												if (IsUserValid(DataList,NamaPengguna))
													{
													printf("\n               User berhasil ditambahkan!!!",NamaPengguna);
													UInsVLast(&DataList,NamaPengguna);
													IsSukses = SaveDataPengguna(DataList);
													}
												else
													printf("\n               User sudah terdaftar",NamaPengguna);
												InisialisasiString(NamaPengguna);
												}
                                            DelayWaktu(300);
                                            printf("\n--------------------------------------------------------------------------------\n");
                                        /* Akhir Fungsi Tambahkan List Pengguna - Modus Pengaturan */
                                            break;
                        case '7' :
									/* Awal Fungsi Hapus List Pengguna - Modus Pengaturan */
									/* Asumsikan Pengguna yang dihapus, datanya tetap disimpan persisten dalam file */
                                            printf("\n               Masukkan nama pengguna yang ingin dihapus> ");
                                            scanf("\n");
                                            fgets(NamaPengguna,sizeof(NamaPengguna),stdin);
											i= 0;
											while (NamaPengguna[i]!='\0')
												{
												NamaPengguna[i] = toupper(NamaPengguna[i]);
												i++;
												}
                                            /* Silahkan cara membacanya diganti dengan skema mesin karakter */
                                            UDelX(&DataList,NamaPengguna);
                                            IsSukses = SaveDataPengguna(DataList);
                                            InisialisasiString(NamaPengguna);
                                            printf("\n--------------------------------------------------------------------------------\n");
									/* Akhir Fungsi Hapus List Pengguna - Modus Pengaturan */
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'D');
                     break;
            case 'E':
                     IsExit = true;
                     break;
	        default: printf("                            Masukkan Anda Salah!\n");
                     break;
	    }

	} while (!IsExit);
    Closing();
return 0;
}
/* All Rights Reserved 2012 */
