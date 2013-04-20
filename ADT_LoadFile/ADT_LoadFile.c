/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_LoadFile.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_LoadFile.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* *** LOAD FILE *** */
boolean LoadDataPengguna(DataPengguna *L)
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DataPengguna) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */
{
    /* Kamus Lokal */
    boolean IsLoaded = false;
    char NamaTemp[MAX_CHAR];  /* variabel penyimpanan karakter masukkan sementara */
    FILE *penggunafile;
    /* Algoritma */
    penggunafile = fopen("pengguna.dat","r");
    if (penggunafile != Nil)
    {
        IsLoaded = true;
        InisialisasiString(NamaTemp);
        while (fgets(NamaTemp,sizeof(NamaTemp),penggunafile) != NULL)
        {
              if((NamaTemp[0] != '@'))
              {
                UInsVLast(L,NamaTemp);
                InisialisasiString(NamaTemp);
              }
       }
    }
    fclose(penggunafile);
    return IsLoaded;
}

boolean SaveDataPengguna(DataPengguna L)
/* { I.S. DataPengguna tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */
{
    /* Kamus Lokal */
    boolean IsSaved = false;
    FILE *penggunafile;
    uaddress P;
    /* Algoritma */
    penggunafile = fopen("pengguna.dat","wt");
    P = First(L);
    while (P!=Nil)
        {
            IsSaved = true;
            fprintf(penggunafile,"%s",Nama(P));
            P = Next(P);
        }
    fprintf(penggunafile,"@end\n");
    fclose(penggunafile);
    return IsSaved;
}

boolean LoadDaftarHarga(DaftarHarga X[])
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe DaftarHarga) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */
{
    /* Kamus Lokal */
    boolean IsLoaded = false;
    FILE *hargafile;
    char NamaTemp[MAX_CHAR]; /* variabel penyimpanan karakter masukkan sementara */
    int idx = 0;
    int i,j; /* indeks untuk traversal */
    /* Algoritma */
    hargafile = fopen("harga.dat","r");
    InisialisasiString(NamaTemp);
        while (fgets(NamaTemp,sizeof(NamaTemp),hargafile) != NULL)
        {
              IsLoaded = true;
              if((NamaTemp[0] != '@'))
              {
                i = 1;
                while (NamaTemp[i] != '"')
                 i++;
                 InisialisasiString(JenisKata(X[idx]));
                //Indeks ke 1 sampai i-1 adalah JenisKata
                for (j=1;j<i;j++)
                 JenisKata(X[idx])[j-1] = NamaTemp[j];
                //Indeks ke i+2 sampai habis adalah hargafile
                Harga(X[idx]) = 0; /* Inisialisasi awal */
                for (j=i+2;j<MAX_CHAR;j++)
                {
                    if (NamaTemp[j] == '#') /* Karakter ke-j adalah '\n' */
                      break;
                    else
                      Harga(X[idx]) = Harga(X[idx]) * 10 + (NamaTemp[j] - 48);
                }
                idx++;
                InisialisasiString(NamaTemp);
              }
       }
    fclose(hargafile);
    return IsLoaded;
}

boolean SaveDaftarHarga(DaftarHarga X[])
/* { I.S. DaftarHarga tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Daftar Harga disimpan dalam NamaFile - file eksternal } */
{
    /* Kamus Lokal */
    boolean IsSaved = false;
    FILE *hargafile;
    int i; /* Indeks untuk traversal */
    /* Algoritma */
    hargafile = fopen("harga.dat","wt");
      /* Proses */
    for (i=0;i<=4;i++)
    {
        fprintf(hargafile,"\"%s\" %d#\n",JenisKata(X[i]),Harga(X[i]));
    }
    fprintf(hargafile,"@end\n");
    fclose(hargafile);
    return IsSaved;
}

boolean LoadKamusKarakter(KamusKarakter *L)
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe KamusKarakter) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */
{
    /* Kamus Lokal */
    boolean IsLoaded = false;
    char NamaTemp[MAX_CHAR]; /* variabel penyimpanan karakter masukkan sementara */
    char KarakterTemp[MAX_CHAR], JenisTemp[MAX_CHAR];
    FILE *kamusfile;
    int IdxBatas;
    int i, counter; /* Indeks Traversal */
    /* Algoritma */
    kamusfile = fopen("kamus.dat","r");

    if (kamusfile != Nil)
    {
        IsLoaded = true;
        InisialisasiString(NamaTemp);
        InisialisasiString(KarakterTemp);
        InisialisasiString(JenisTemp);
        while (fgets(NamaTemp,sizeof(NamaTemp),kamusfile) != NULL)
        {
            IdxBatas = 2; /* Inisialisasi */
              if((NamaTemp[0] != '@') && (NamaTemp[1] != 'e'))
              {
                /* Pemrosesan Masukkan */
                while (NamaTemp[IdxBatas] != ' ' )
                  IdxBatas++;
                //Salin
                for (i=2;i<IdxBatas;i++)
                   KarakterTemp[i-2] = NamaTemp[i];
                IdxBatas = IdxBatas + 2;
                counter = 0;
                while (NamaTemp[IdxBatas] != '"')
                   {
                       JenisTemp[counter] = NamaTemp[IdxBatas];
                       counter++;
                       IdxBatas++;
                   }
                KInsVLast(L,NamaTemp[0],KarakterTemp,JenisTemp);
                InisialisasiString(NamaTemp);
                InisialisasiString(KarakterTemp);
                InisialisasiString(JenisTemp);
              }
       }
    }

    fclose(kamusfile);
    return IsLoaded;
}

boolean SaveKamusKarakter(KamusKarakter L)
/* { I.S. KamusKarakter tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */
{
    /* Kamus Lokal */
    boolean IsSaved = false;
    FILE *kamusfile;
    kaddress P;
    /* Algoritma */
    kamusfile = fopen("kamus.dat","wt");
    P = First(L);
    while (P!=Nil)
        {
            IsSaved = true;
            fprintf(kamusfile,"%c %s \"%s\"\n",Simbol(P),KarakterSimbol(P),JenisKataL(P));
            P = Next(P);
        }
    fprintf(kamusfile,"@end\n");
    fclose(kamusfile);
    return IsSaved;
}

boolean LoadStatistik(Statistik *L)
/* { I.S. File Sembarang } */
/* { F.S. File dengan NamaFile (bertipe Statistik) di Load } */
/* { Jika File tersebut telah diload sebelumnya, maka data lama terhapus } */
{
    /* Kamus Lokal */
    boolean IsLoaded = false;
    char NamaTemp[MAX_CHAR]; /* variabel penyimpanan karakter masukkan sementara */
    FILE *statistikfile;
    InfoStatistik Temp;
    int i, idx, counter; /* Indeks Traversal */
    /* Algoritma */
    statistikfile = fopen("statistik.dat","r");

    if (statistikfile != Nil)
    {
        IsLoaded = true;
        InisialisasiString(NamaTemp);
        while (fgets(NamaTemp,sizeof(NamaTemp),statistikfile) != NULL)
        {
              if((NamaTemp[0] != '@') && (NamaTemp[1] != 'e'))
              {
                /* Pemrosesan Masukkan */
                idx = 1;
                while(NamaTemp[idx] != '"')
                 idx++;
                InisialisasiString(Temp.namapengirim);
                for (i=1;i<idx;i++)
                  Temp.namapengirim[i-1] = NamaTemp[i]; //Nama Pengirim dari file

                InisialisasiString(Temp.namapenerima);
                idx = idx + 3;
                counter = 0;
                while(NamaTemp[idx] != '"')
                {
                    Temp.namapenerima[counter] = NamaTemp[idx];//Nama Penerima dari file
                    counter++;
                    idx++;
                }

                Temp.prioritas = NamaTemp[idx+2] - '0' ; //Prioritas dari file

                InisialisasiTanggal(Temp.waktukirim);
                for(i=idx+4;i<=idx+15;i++)
                    Temp.waktukirim[i-idx-4] = NamaTemp[i]; //Waktu kirim dari file

                Temp.statuskirim = NamaTemp[idx+17] - '0'; //Status kirim dari file

                idx = idx + 19;
                Temp.jumlahpendek = 0;
                while(NamaTemp[idx] != ' ')
                {
                   Temp.jumlahpendek = Temp.jumlahpendek * 10 + NamaTemp[idx] - '0'; //Jumlah kata pendek dari file
                   idx++;
                }

                idx = idx + 1;
                Temp.jumlahpanjang = 0;
                while(NamaTemp[idx] != ' ')
                {
                    Temp.jumlahpanjang = Temp.jumlahpanjang * 10 + NamaTemp[idx] - '0'; //Jumlah kata panjang dari file
                    idx++;
                }

                idx = idx + 1;
                Temp.jumlahtandabaca = 0;
                while(NamaTemp[idx] != ' ')
                {
                    Temp.jumlahtandabaca = Temp.jumlahtandabaca * 10 + NamaTemp[idx] - '0'; //Jumlah tanda baca dari file
                    idx++;
                }

                idx = idx + 1;
                Temp.jumlahlain = 0;
                while(NamaTemp[idx] != ' ')
                {
                    Temp.jumlahlain = Temp.jumlahlain * 10 + NamaTemp[idx] - '0'; //Jumlah tanda baca dari file
                    idx++;
                }

                idx = idx + 1;
                Temp.jumlahenter = 0;
                while(NamaTemp[idx] != ' ')
                {
                    Temp.jumlahenter = Temp.jumlahenter * 10 + NamaTemp[idx] - '0'; //Jumlah enter / baris baru dari file
                    idx++;
                }

                idx = idx + 1;
                Temp.biayapesan = 0;
                while(NamaTemp[idx] != '#')
                {
                    Temp.biayapesan = Temp.biayapesan * 10 + NamaTemp[idx] - '0'; //Biaya pesan dari file
                    idx++;
                }

                SInsVLast(L,Temp);
                InisialisasiString(NamaTemp);
              }
       }
    }
    fclose(statistikfile);
    return IsLoaded;
}

boolean SaveStatistik(Statistik L)
/* { I.S. Statistik tidak kosong, NamaFile sembarang } */
/* { F.S. Seluruh Data List disimpan dalam NamaFile - file eksternal } */
{
    /* Kamus Lokal */
    boolean IsSaved = false;
    FILE *statistikfile;
    saddress P;
    /* Algoritma */
    statistikfile = fopen("statistik.dat","wt");
    P = First(L);
    while (P!=Nil)
        {
            IsSaved = true;
            fprintf(statistikfile,"\"%s\" \"%s\" %d %s %d %d %d %d %d %d %d#\n",NamaPengirim(P),NamaPenerima(P),Prioritas(P),WaktuKirim(P),StatusKirim(P),JumlahPendek(P),JumlahPanjang(P),JumlahTandaBaca(P),JumlahLain(P),JumlahEnter(P),BiayaPesan(P));
            P = Next(P);
        }
    fprintf(statistikfile,"@end\n");
    fclose(statistikfile);
    return IsSaved;
}

/* All Rights Reserved 2012 */
