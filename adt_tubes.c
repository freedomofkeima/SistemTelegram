/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : adt_tubes.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "adt_tubes.h"

#include "adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* *** MODUS A *** */

/* ***** AWAL FUNGSI ANTARA MODUS KIRIM ***** */
boolean SearchKamus(KamusKarakter X, char Y)
/* { Fungsi SearchKamus menerima masukkan tabel X dan satu karakter Y kemudian mengembalikan true apabila Y merupakan anggota X } */
{
   /*Kamus Lokal*/
   kaddress pt;
   boolean found=false;

   /*Algoritma*/
   pt=First(X);
   while((pt!=Nil)&& !found)
   {
                 found=(Simbol(pt)==Y);
                 pt=Next(pt);
   } //pt=Nil
   return (found);
}

boolean IsPesanValid(KamusKarakter X, char Y[])
/* { Fungsi IsPesanValid menerima masukkan tabel X dan karakter Y dan mengembalikan true apabila Y merupakan anggota X } */
{
    /*Kamus Lokal*/
    boolean valid = true;
    int i=0;

    /*Algoritma*/
    while((Y[i]!='\0'))
        {
            if(Y[i] != ' ')
            valid = valid && (isalnum(Y[i]) || SearchKamus(X, Y[i]));
            i++;
        }// Y[i]='\0' (akhir dari string)
    return(valid);

}

void uppercase(char c[])
/* { I.S. : Karakter terdefinisi } */
/* { F.S. : Mengembalikan uppercase dari suatu String } */
{
	int i = 0;
	while (c[i]!= '\0')
		{
		c[i] = toupper(c[i]);
		i++;
		}
}

void SalinKarakterSimbol (char c,KamusKarakter ListKamus, char s[],char jk[])
/* { I.S.: karakter c ada dalam kamus karakter } */
/* { F.S. : prosedur SalinKarakterSimbol, menyalin karakter simbol dari c menjadi karaktersimbol } */
{
	/* Kamus Lokal */
	kaddress p;
	int i = 0; //variabel untuk traversal
	/* Algoritma */
	p = First(ListKamus);
	while((Simbol(p) != c) && (p!= Nil))
		{
		  p = Next(p);
		}
	if(Simbol(p) == c)
		{
		 while(KarakterSimbol(p)[i]!= '\n' && KarakterSimbol(p)[i]!= '\0')
			{
		    	s[i] = KarakterSimbol(p)[i];
			    i++;
			}
		   i = 0;
		  while (JenisKataL(p)[i] !='\n' && JenisKataL(p)[i]!= '\0')
			{
			   jk[i] = JenisKataL(p)[i];
			   i++;
			}
		}
}

void PrioIToChar(char i,char s[])
/* { function PrioIToChar mengubah angka prioritas menjadi karakter } */
{
	if (i == '1')
		{
		s[0] = 'S';
		s[1] = 'A';
		s[2] = 'T';
		s[3] = 'U';
		s[4] = '\0';
		}
	else
	if( i == '2')
		{
		s[0] = 'D';
		s[1] = 'U';
		s[2] = 'A';
		s[3] = '\0';
		}
	else
	if(i == '3')
		{
		s[0] = 'T';
		s[1] = 'I';
		s[2] = 'G';
		s[3] = 'A';
		s[4] = '\0';
		}
	else
		{
		s[0] = 'E';
		s[1] = 'M';
		s[2] = 'P';
		s[3] = 'A';
		s[4] = 'T';
		s[5] = '\0';
		}
}

int CetakHarga(InfoStatistik S, DaftarHarga ListHarga[])
/* { Fungsi CetakHarga menerima masukkan data pesan dalam S serta ListHarga dari masing-masing jenis kata, dan mengeluarkan biaya pengiriman suatu pesan } */
{
    return S.jumlahpendek * Harga(ListHarga[0]) + S.jumlahpanjang * Harga(ListHarga[1]) + S.jumlahtandabaca * Harga(ListHarga[2]) + S.jumlahlain * Harga(ListHarga[3]) + S.jumlahenter * Harga(ListHarga[4]);
}

/* ***** AKHIR FUNGSI ANTARA MODUS KIRIM ***** */

boolean Kirim (DataPengguna NamaUser, KamusKarakter k, Statistik *S, DaftarHarga ListHarga[])
/* { Fungsi Kirim mengirimkan pesan pengguna apabila nama pengirim dan penerima telah terdaftar di NamaUserdan seluruh isi pesan terdefinisi di
 kamus X. Pengiriman dilakukan apabila nama pengguna telah terdaftar, isi pesan telah diverifikasi validitasnya. Apabila pengiriman berhasil,
 fungsi Kirim akan mengeluarkan true. } */
{
	/* Kamus Lokal */
	InfoStatistik IS;//penampung statistik
	FILE *fp;
	int i, j; //variabel traversal
	char prioritas;//prioritas pesan
	//Jumlah awal masing-masing kata
	int jumlahpendek = 6;
	int jumlahpanjang = 0;
	int jumlahlain = 1;
	int jumlahtandabaca = 4;
	int jumlahenter = 3;
	int p = 0;
	int q = 0;
	char KS[MAX_CHAR];
	char DD;//Karakter yang sedang diproses
	char pchar[MAX_CHAR];//Karakter yang mensimbolkan Prioritas
	char X[MAX_CHAR];
	char z;//untuk inputan
	char jk[MAX_CHAR];//jumlah karakter
	char pesan[MAX_CHAR];
    char namapengirim[MAX_CHAR];
	char namapenerima[MAX_CHAR];
	char waktukirim[13];

	char dirout[MAX_CHAR] = "./Outbox/"; //direktori file eksternal hasil konversi kode morse
	char waktu[MAX_CHAR];
	time_t now;
	struct tm *ptr;

	boolean IsPesanVal = false;
	boolean namapengirimvalid = false;
	boolean namapenerimavalid = false;
	boolean prioritasvalid = false;
	boolean IsSukses;

    /* Algoritma */
    //Inisialisasi Variabel
	InisialisasiString(namapengirim);
	InisialisasiString(namapenerima);
    InisialisasiString(pesan);
    InisialisasiString(IS.namapengirim);
    InisialisasiString(dirout);

    for(i=0;i<13;i++)
        waktukirim[i] = '\0';
	j= 0;
	do
		{
		printf("Prioritas : ");
		scanf("\n%c",&prioritas);
		j++;
		}while (j<3 && (prioritas < (1 + '0')) || prioritas > (4 + '0'));
	if ((j<=3) && !(prioritas < (1 + '0')) || prioritas > (4 + '0'))
		{
		j=0;
		prioritasvalid = true;
		}

	//memeriksa validitas nama pengirim, salah lebih dari 3 kali akan mengulang
    while((j<3) && (IsUserValid(NamaUser, namapengirim)))//IsUserValid menampilkan true apabila nama tersebut tidak ada di dalam kamus
    {
     j++;
    printf("Nama Pengirim : ");
	scanf("\n");
    fgets(namapengirim,sizeof(namapengirim),stdin);
    }
	i=0;
	if(j<=3 && !IsUserValid(NamaUser,namapengirim))
		{
		namapengirimvalid = true;
		j = 0;
		}
	for(;;)
		{
		while(namapengirim[i]!='\n')
			i++;
		namapengirim[i]='\0';
		break;
		}
	uppercase(namapengirim);

    //memeriksa validitas nama penerima, salah lebih dari 3 kali akan mengulang
    while((j<3) && namapengirimvalid && IsUserValid(NamaUser,namapenerima))//IsUserValid menampilkan true apabila nama tersebut tidak ada di dalam kamus
    {
     j++;
    printf("Nama Penerima : ");
	scanf("\n");
    fgets(namapenerima,sizeof(namapenerima),stdin);
	i=0;
	}
	if(!IsUserValid(NamaUser,namapenerima))
		{
		j=0;
		namapenerimavalid = true;
		}
	for(;;)
		{
		while(namapenerima[i]!='\n' && namapenerima[i]!='\0')
			i++;
		namapenerima[i]='\0';
		break;
		}
	uppercase(namapenerima);
	IsPesanVal = false;
	//memeriksa validitas pesan, salah lebih dari 3 kali akan mengulang
	while ((IsPesanVal == false) && (j < 3) && namapenerimavalid && namapengirimvalid)
		{
		  i = 0;
		  IsPesanVal = true;
		  InisialisasiString(X);
		  printf("Pesan : ");
		  for(;;)
		   {
			  scanf("%c",&z);
				if (z == '\n')
						break;
			  X[i] = z;

			  i++;
		   }
		   X[i] = '\0';
			if(!IsPesanValid(k,X))
			{
						IsPesanVal = false;
						j++;
			}
		}
	if(IsPesanVal)
		{
		//mengkonversi seluruh pesan ke dalam karakter
        /* Memindahkan semua pesan yang valid kedalam txt */
		uppercase(X);
		PrioIToChar(prioritas,pchar);
		printf("\n          Nama Pengirim : %s\n",namapengirim);
		printf("          Nama Penerima : %s\n",namapenerima);
		printf("          Pesan         : %s\n",X);
		printf("          Prioritas     : %c\n",prioritas);

        dirout[0] = '.';
        dirout[1] = '/';
        dirout[2] = 'O';
        dirout[3] = 'u';
        dirout[4] = 't';
        dirout[5] = 'b';
        dirout[6] = 'o';
        dirout[7] = 'x';
        dirout[8] = '/';
        dirout[9] = '\0';

        time(&now);
        ptr=localtime(&now);
        strftime(waktu,MAX_CHAR,"%y%m%d%H%M%S",ptr);

        Konkat(dirout,waktu);
        Konkat(dirout,"-");
        Konkat(dirout,namapengirim);
        Konkat(dirout,".txt");

		fp=fopen(dirout, "wt");
		fprintf(fp,"PRIORITAS TITIKDUA %s ENTER ",pchar);
		fprintf(fp,"NAMA PENGIRIM TITIKDUA %s ENTER ",namapengirim);
		fprintf(fp,"NAMA PENERIMA TITIKDUA %s ENTER PESAN TITIKDUA",namapenerima);
		fprintf(fp," ");
		//Mengecek panjang dari nama penerima dan nama pengirim
		i = 0;
		j = 0;
		for(;;)
		{
			if ((namapengirim[j] != ' ') && (namapengirim[j] != '\0'))
				j++;
			else
			{
			  if (j - i < 11)
				jumlahpendek++;
			 else
				jumlahpanjang++;
			i = j;
			j++;
			if (namapengirim[j] == '\0')
				break;
			}
		}

		i = 0;
		j = 0;
		for(;;)
		{
			if ((namapenerima[j] != ' ') && (namapenerima[j] != '\0'))
				j++;
			else
			{
			  if (j - i < 11)
				jumlahpendek++;
			 else
				jumlahpanjang++;
			i = j;
			j++;
			if (namapenerima[j] == '\0')
				break;
			}
		}

		q = 0;
		for(;;)
			{
				DD = X[p];
				if (isalpha(DD)) //memeriksa apakah karakter pesan ke p merupakan anggota alfa
					{
						fprintf(fp,"%c",DD);
						p++;
						q++;
						DD = X[p];
					}
				else //apabila karakter pesan ke p bukan merupakan anggota alfanumerik
					{
							if ((DD == ' ') || (DD == '\0')) //apabila karakter spasi
								{
										if(q<11)
											jumlahpendek++;
										else
											jumlahpanjang++;
										q = 0;
									if (DD == '\0')
										break;
									fprintf(fp,"%c",DD);
									p++;
								}
							else //apabila karakter bukan spasi
								{
									if (SearchKamus(k,DD))
									{
									InisialisasiString(jk);
									InisialisasiString(KS);
									SalinKarakterSimbol(DD,k,KS,jk);
									if(p == 0)
                                        fprintf(fp,"%s",KS);
                                    else
                                        fprintf(fp," %s",KS);
									p++;
									if(jk[0] == 'L')
										jumlahlain++;
									else
										jumlahtandabaca++;
									}
								}

					}
			}

        /* Memindahkan pesan yang Valid kedalam record Statistik */
        SalinString(namapengirim,IS.namapengirim);
        SalinString(namapenerima,IS.namapenerima);
        IS.prioritas = prioritas - '0';
        SalinString(waktu,IS.waktukirim);
        IS.statuskirim = 1;
        IS.jumlahpendek = jumlahpendek;
        IS.jumlahpanjang = jumlahpanjang;
        IS.jumlahtandabaca = jumlahtandabaca;
        IS.jumlahlain = jumlahlain;
        IS.jumlahenter = jumlahenter;
        IS.biayapesan = CetakHarga(IS,ListHarga);
        /* Mencetak harga ke layar */
		fprintf(fp,"*");
        printf("          Jumlah Total Kata %d kata\n",(jumlahpendek+jumlahpanjang+jumlahtandabaca+jumlahlain+jumlahenter));
		printf("          Jumlah Kata Pendek: %d\n",jumlahpendek);
		printf("          Jumlah Kata Panjang: %d\n",jumlahpanjang);
		printf("          Jumlah Tanda Baca: %d\n",jumlahtandabaca);
		printf("          Jumlah Lain-lain: %d\n",jumlahlain);
		printf("          Jumlah Enter: %d\n",jumlahenter);
		printf("          Biaya Pesan: %d\n",CetakHarga(IS,ListHarga));
		printf("\n                  Pesan berhasil dikirim!\n");
		fclose(fp);
		SInsVLast(S,IS);
		SaveStatistik(*S);
		ListStatistikTulis(*S,0);
		return true;
		}
	else
	{
		printf("                   Masukkan Tidak Valid!!!");
		return false;
	}
    DelayWaktu(300);
    printf("\n--------------------------------------------------------------------------------\n");
}

void HitungHarga(Statistik S)
/* { I.S. : S boleh kosong }
   { F.S. : Mencetak info harga dari pesan terakhir yang dikirimkan jika S tidak kosong. Jika Statistik kosong, cetak ÅgTidak ada pesan yang dikirimkan.Åh } */
{
	/* Kamus Lokal */
	saddress P;
	/* algoritma */
	P = First(S);
	if (P == Nil)
		printf("Tidak ada pesan yang dikirimkan");
	else
		{
		while (Next(P)!= Nil)
			P = Next(P);
            printf("\n            ---INFO HARGA DARI PESAN TERAKHIR---\n\n");
            printf("               Nama Pengirim: %s\n",NamaPengirim(P));
            printf("               Nama Penerima: %s\n",NamaPenerima(P));
            printf("               Harga %d\n",BiayaPesan(P));
            printf("                    Jumlah Total Kata %d\n",(JumlahPendek(P)+JumlahPanjang(P)+JumlahTandaBaca(P)+JumlahLain(P)+JumlahEnter(P)));
            printf("                    Kata Pendek %d\n",JumlahPendek(P));
            printf("                    Kata Panjang %d\n",JumlahPanjang(P));
            printf("                    Tanda Baca %d\n",JumlahTandaBaca(P));
            printf("                    Lain-lain %d\n",JumlahLain(P));
            printf("                    Enter %d\n",JumlahEnter(P));
		}
        DelayWaktu(300);
        printf("\n--------------------------------------------------------------------------------\n");
}


void ListStatistikTulis(Statistik S, int Mode)
/* I.S. S terdefinisi
   F.S  Menampikan List Statistik Penulisan ke layar */
{
    /* Kamus Lokal */
    FILE *pt;
        /* Konstruktor Lokal */
    typedef struct tStatTulis *stladdress;
    typedef struct tStatTulis
    {
        char namaT[MAX_CHAR]; //Variabel untuk menyimpan nama sementara
        int JumlahPesanT; //Variabel untuk menghitung jumlah pesan yang dikirimkan
        int JumlahKataT; //Variabel untuk menghitung jumlah kata yang dikirimkan
        int JumlahBiayaT; //Variabel untuk menghitung biaya total yang dikirimkan
        stladdress next; //Address next elemen
    } StatistikTulisElmt;
    typedef struct
    {
        stladdress First;
    } StatistikTulis;

    /* Selektor Lokal */
    #define NamaT(X) (X)->namaT
    #define JumlahPesanT(X) (X)->JumlahPesanT
    #define JumlahKataT(X) (X)->JumlahKataT
    #define JumlahBiayaT(X) (X)->JumlahBiayaT

    stladdress STLAlokasi(char A[],int B, int C, int D)
    /* Fungsi lokal yang berfungsi untuk melakukan alokasi List Statistik Tulis */
    {
        /* Kamus Lokal */
        stladdress P;
        /* Algoritma */
        P = (stladdress) malloc (sizeof(StatistikTulisElmt));
            if (P != Nil)
            {
                InisialisasiString(NamaT(P));
                SalinString(A,NamaT(P));
                JumlahPesanT(P) = B;
                JumlahKataT(P) = C;
                JumlahBiayaT(P) = D;
                Next(P) = Nil;
            }
        return P;
    }

    boolean IsFound = false; //Untuk menentukan apakah terdapat elemen dalam List
    saddress p; //Address untuk Statistik
    stladdress px, pAlok, pTemp, pTempTwo, pRec; //Address untuk Statistik Penulisan
    StatistikTulis StatistikTList, StatistikTTemp, StatistikTTempTwo, StatistikTTempThree; //List untuk menyimpan Statistik Penulisan
    boolean IsValid = false;
    char PilihanPengguna;
    int i; /* Indeks Traversal */
    /* Algoritma */
        /* Inisialisasi */
        First(StatistikTList) = Nil;
        /* Memindahkan semua data statistik yang diperlukan kedalam list prioritas sementara */
        p = First(S);
        while (p != Nil)
        {
            /* Lakukan iterasi sepanjang List Statistik Tulis */
            if (First(StatistikTList) == Nil)
               {
                    pAlok = STLAlokasi(NamaPengirim(p),1,(JumlahPanjang(p) + JumlahPendek(p) + JumlahTandaBaca(p) + JumlahLain(p) + JumlahEnter(p)),BiayaPesan(p));
                    if(pAlok != Nil)
                    {
                        First(StatistikTList) = pAlok;
                        Next(pAlok) = Nil;
                    }
               } else /*Bukan elemen pertama */
               {
                    pTemp = First(StatistikTList);
                    pRec = Nil;
                    IsFound = false;
                    /* Lakukan pencarian */
                    while((pTemp != Nil) && (!IsFound))
                    {
                        if (IsStringSama(NamaT(pTemp),NamaPengirim(p)))
                        {
                            IsFound = true;
                            JumlahPesanT(pTemp)++;
                            JumlahKataT(pTemp) = JumlahKataT(pTemp) + JumlahPanjang(p) + JumlahPendek(p) + JumlahTandaBaca(p) + JumlahLain(p) + JumlahEnter(p);
                            JumlahBiayaT(pTemp) = JumlahBiayaT(pTemp) + BiayaPesan(p);
                        }
                        if (!IsFound)
                        {
                            pRec = pTemp;
                            pTemp = Next(pTemp);
                        }
                    }
                    /* Jika tidak ditemukan */
                    if (!IsFound)
                    {
                        pAlok = STLAlokasi(NamaPengirim(p),1,(JumlahPanjang(p) + JumlahPendek(p) + JumlahTandaBaca(p) + JumlahLain(p) + JumlahEnter(p)),BiayaPesan(p));
                        if (pAlok != Nil)
                            Next(pRec) = pAlok;
                    }
               }
            p = Next(p);
        }


        /* Mencetak List ke Layar */
        if (Mode == 1)
        {
            /* Mengurutkan sesuai Jumlah Pesan kedalam StatistikTTemp */
                /* Inisialisasi Variabel */
                First(StatistikTTemp) = Nil;
                 px = First(StatistikTList);
                 while (px!=Nil)
                 {
                    pAlok = STLAlokasi(NamaT(px),JumlahPesanT(px),JumlahKataT(px),JumlahBiayaT(px));
                    if (pAlok != Nil)
                    {
                        if (First(StatistikTTemp) == Nil)
                        {
                            First(StatistikTTemp) = pAlok;
                        } else
                        {
                            pTemp = First(StatistikTTemp);
                            pTempTwo = Nil;
                            IsFound = false;
                            while ((pTemp != Nil) && (!IsFound)) {
                                if (JumlahPesanT(pAlok) <= JumlahPesanT(pTemp))
                                {
                                    pTempTwo = pTemp;
                                    pTemp = Next(pTemp);
                                }
                                else
                                    IsFound = true;
                            }
                            if (pTempTwo == Nil)
                            {
                                Next(pAlok) = First(StatistikTTemp);
                                First(StatistikTTemp) = pAlok;
                            } else
                            {
                                Next(pTempTwo) = pAlok;
                                Next(pAlok) = pTemp;
                            }
                        }
                    }
                    px = Next(px);
                 }

            /* Mengurutkan sesuai Jumlah Rata-rata Kata kedalam StatistikTTempTwo */
                /* Inisialisasi Variabel */
                First(StatistikTTempTwo) = Nil;
                 px = First(StatistikTList);
                 while (px!=Nil)
                 {
                    pAlok = STLAlokasi(NamaT(px),JumlahPesanT(px),JumlahKataT(px),JumlahBiayaT(px));
                    if (pAlok != Nil)
                    {
                        if (First(StatistikTTempTwo) == Nil)
                        {
                            First(StatistikTTempTwo) = pAlok;
                        } else
                        {
                            pTemp = First(StatistikTTempTwo);
                            pTempTwo = Nil;
                            IsFound = false;
                            while ((pTemp != Nil) && (!IsFound)) {
                            if ( (JumlahKataT(pAlok) / JumlahPesanT(pAlok))  <=  (JumlahKataT(pTemp) / JumlahPesanT(pTemp)) )
                                {
                                    pTempTwo = pTemp;
                                    pTemp = Next(pTemp);
                                }
                                else
                                    IsFound = true;
                            }
                            if (pTempTwo == Nil)
                            {
                                Next(pAlok) = First(StatistikTTempTwo);
                                First(StatistikTTempTwo) = pAlok;
                            } else
                            {
                                Next(pTempTwo) = pAlok;
                                Next(pAlok) = pTemp;
                            }
                        }
                    }
                    px = Next(px);
                 }
            /* Mengurutkan sesuai Biaya Pesan kedalam StatistikTTempThree */
                /* Inisialisasi Variabel */
                First(StatistikTTempThree) = Nil;
                px = First(StatistikTList);
                 while (px!=Nil)
                 {
                    pAlok = STLAlokasi(NamaT(px),JumlahPesanT(px),JumlahKataT(px),JumlahBiayaT(px));
                    if (pAlok != Nil)
                    {
                        if (First(StatistikTTempThree) == Nil)
                        {
                            First(StatistikTTempThree) = pAlok;
                        } else
                        {
                            pTemp = First(StatistikTTempThree);
                            pTempTwo = Nil;
                            IsFound = false;
                            while ((pTemp != Nil) && (!IsFound)) {
                                if (JumlahBiayaT(pAlok) <= JumlahBiayaT(pTemp))
                                {
                                    pTempTwo = pTemp;
                                    pTemp = Next(pTemp);
                                }
                                else
                                    IsFound = true;
                            }
                            if (pTempTwo == Nil)
                            {
                                Next(pAlok) = First(StatistikTTempThree);
                                First(StatistikTTempThree) = pAlok;
                            } else
                            {
                                Next(pTempTwo) = pAlok;
                                Next(pAlok) = pTemp;
                            }
                        }
                    }
                    px = Next(px);
                 }

            printf("\n                        STATISTIK PENULISAN\n\n");
            do
            {
            printf("Sortir berdasarkan (A. Urutan Masuk / default ; B. Jumlah Pesan (Descending); C. Jumlah Rata-rata Kata (Descending); D. Biaya Pesan (Descending)) \n\n");
            printf("                Pilihan Anda> ");
            scanf("\n%c",&PilihanPengguna);
            switch(toupper(PilihanPengguna))
            {
                case 'A':
                            pTemp = First(StatistikTList);
                            IsValid = true;
                            break;
                case 'B':
                            pTemp = First(StatistikTTemp);
                            IsValid = true;
                            break;
                case 'C':
                            pTemp = First(StatistikTTempTwo);
                            IsValid = true;
                            break;
                case 'D':
                            pTemp = First(StatistikTTempThree);
                            IsValid = true;
                            break;
                default:    printf("                            Masukkan Anda Salah!\n\n");
                            break;
            }
            if (IsValid)
            {
                    while (pTemp != Nil)
                    {
                        printf("           %s   %d Pesan     %d kata/pesan     %d\n",NamaT(pTemp),JumlahPesanT(pTemp),(JumlahKataT(pTemp) / JumlahPesanT(pTemp)),JumlahBiayaT(pTemp));
                        pTemp = Next(pTemp);
                    }
            }

            } while (IsValid == false);
        }
            pt = fopen("./Outbox/stattulis.dat","wt");
            pTemp = First(StatistikTList);
            while (pTemp != Nil)
            {
                fprintf(pt,"\"%s\" %d %d %d\n",NamaT(pTemp),JumlahPesanT(pTemp),(JumlahKataT(pTemp) / JumlahPesanT(pTemp)),JumlahBiayaT(pTemp));
                pTemp = Next(pTemp);
            }
        fprintf(pt,"@end\n");
        fclose(pt);

        DelayWaktu(300);
        printf("\n--------------------------------------------------------------------------------\n");
}

/* *** MODUS B *** */
void KarakterToMorse (char Y[])
/* I.S. File katanya ada, isinya dijamin dapat dikonversi
   F.S. Semua kata dalam pesan masukan terkonversi menjadi morse dan pesan yang terkonversi tersimpan di file eksternal di direktori Sending
*/

{
	/** Kamus **/
	kata tabtemp; //penampung karakter sementara hasil BST
	char hasil[MAX_CHAR]; //penampung karakter hasil konversi
	int count; //jumlah karakter yang telah dikonversi
	int i,j; //indeks traversal
	FILE *fp;
	char waktu[MAX_CHAR]; //waktu ketika tabkarakter disalin ke dalam file eksternal baru
	char dirout[MAX_CHAR]; //direktori file eksternal hasil konversi kode morse
	char filein[MAX_CHAR]; //direktori file eksternal yang akan dikonversi
    BinTreeRev KamusPohon;

	/* Algoritma */
    KamusPohon = MakePohonAlfabet();
    /* Inisialisasi variabel */
    InisialisasiString(tabtemp.TabKata);
    InisialisasiString(hasil);
    /* Konversi Kode Morse dan Menyimpan ke tabkarakter */
	START(Y);
	count = -1;
	while (CC != MARK)
	{
        /* Binary Search Tree Reverse */
        BVSearchRev(KamusPohon,CC,0,0,&tabtemp);
        i = 0;
        while (tabtemp.TabKata[i] != '\0')
        {
           count++;
           hasil[count] = tabtemp.TabKata[i];
           i++;
        }
		ADV();
		if (CC != MARK)
        {
           count++;
		   hasil[count] = ' ';
        }
    InisialisasiString(tabtemp.TabKata);
	} /* seluruh String telah berhasil dikonversi dan disimpan dalam hasil */
	/* menyimpan isi tabkarakter ke dalam file eksternal pada folder Inbox */
	i=9;
	j=0;
	InisialisasiString(filein);
	while (Y[i]!='\0')
	{
		filein[j]=Y[i];
		j++;
		i++;
	}
	InisialisasiString(dirout);
	dirout[0]='.';
	dirout[1]='/';
	dirout[2]='S';
	dirout[3]='e';
	dirout[4]='n';
	dirout[5]='d';
	dirout[6]='i';
	dirout[7]='n';
	dirout[8]='g';
	dirout[9]='/';
	Konkat(dirout,filein); //dirout siap dipakai sebagai direktori file hasil konversi
	remove(Y); //Mengdelete file masukkan / yang berada pada folder Outbox

    //Mencetak hasil konversi
	fp = fopen(dirout, "wt");
	for(i=0;i<=count;i++)
	{
		fprintf(fp,"%c",hasil[i]);
	}
	fprintf(fp,"*");
	fclose(fp);
}

void TransmitPesan(Statistik *S, StatKirim *Sx)
/* { I.S. S terdefinisi, Sx terdefinisi} */
/* { F.S. Mentransmisikan semua pesan dari folder Outbox ke folder Inbox, dengan mensimulasikan
waktu pengiriman sekitar 30 detik serta priority queue } */
{
    /* Kamus Lokal */
    /* Konstruktor Lokal*/
    typedef struct tPriority *address;
    typedef struct tPriority
    {
        char namafile[MAX_CHAR];
        int priority;
        address next;
    } PriorityElmt;
    typedef struct
    {
        address First;
    } PriorityPesan;

    PriorityPesan PesanList; //List untuk menyimpan Pesan
    address PTemp, PTempTwo, PAlok; //address file priority queue
    saddress p;  //address file statistik
    boolean IsFound; //Variabel untuk menentukan apakah prioritas ditemukan dalam List
    char TempFileDir[MAX_CHAR]; //Variabel yang digunakan untuk nama file sementara
    int i,j; //Variabel untuk traversal dan indeks sementara
    int JumlahPesan = 0; //Variabel yang akan menghitung jumlah pesan

    char WaktuLokal[MAX_CHAR];
    time_t now;
	struct tm *ptr;
	skaddress pTemp; //	Untuk memasukkan ke statistik pengiriman

    /* Selektor Lokal */
    #define NamaFile(X) (X)->namafile
    #define Priority(X) (X)->priority
    /* Algoritma */
        //Memindahkan semua data statistik yang diperlukan kedalam list prioritas sementara
        First(PesanList) = Nil;
        p = First(*S);
        while (p != Nil)
        {
            if (StatusKirim(p) == 1) //Jika file masih berada di Outbox
            {
                PAlok = (address) malloc (sizeof(PriorityElmt));
                if (PAlok != Nil)
                {
                    InisialisasiString(TempFileDir);
                    InisialisasiString(NamaFile(PAlok));
                    //Melakukan inisialisasi variabel yang akan digunakan
                    TempFileDir[0] = '.';
                    TempFileDir[1] = '/';
                    TempFileDir[2] = 'O';
                    TempFileDir[3] = 'u';
                    TempFileDir[4] = 't';
                    TempFileDir[5] = 'b';
                    TempFileDir[6] = 'o';
                    TempFileDir[7] = 'x';
                    TempFileDir[8] = '/';
                    Konkat(TempFileDir,WaktuKirim(p));
                    Konkat(TempFileDir,"-");
                    Konkat(TempFileDir,NamaPengirim(p));
                    Konkat(TempFileDir,".txt\0");
                    /* NamaFile diisi dengan nama file yang akan dipindahkan */
                    SalinString(TempFileDir,NamaFile(PAlok));
                    /* Tingkat prioritas file dipindahkan kedalam List */
                    Priority(PAlok) = Prioritas(p);

                    //Sort sesuai priority Queue
                    if (First(PesanList) == Nil)
                        First(PesanList) = PAlok;
                    else
                    {
                        PTemp = First(PesanList);
                        PTempTwo = Nil;
                        IsFound = false;
                        while ((PTemp != Nil)&& (!IsFound))
                        {
                            if(Priority(PTemp) <= Priority(PAlok))
                                {
                                    PTempTwo = PTemp;
                                    PTemp = Next(PTemp);
                                } else IsFound = true; /* Jika angka prioritas sudah lebih besar, maka telah ditemukan tempat yang tepat */
                        }
                        if (PTempTwo == Nil) //Tempat pertama masih kosong
                        {
                            Next(PAlok) = First(PesanList);
                            First(PesanList) = PAlok;
                        } else
                        {
                            Next(PTempTwo) = PAlok;
                            Next(PAlok) = PTemp;
                        }
                     }
                     JumlahPesan++;
                } else /* Alokasi Gagal */
                    PAlok = Nil;
            }
            p = Next(p);
        }
        //Proses, mulai pindahkan pesan
        PTemp = First(PesanList);
        while (PTemp != Nil)
        {
             printf("\n                Jumlah Pesan tersisa yang akan ditransfer: %d\n",JumlahPesan);
             for (i=30;i>=0;i--)
             {
                 DelayWaktu(1000);
                 printf("%d detik tersisa...\n",i);
                 if (i==0)
                 {
                    KarakterToMorse(NamaFile(PTemp));
                    //Membaca waktu lokal
                    time(&now);
                    ptr=localtime(&now);
                    strftime(WaktuLokal,MAX_CHAR,"20%y%m%d%H\0",ptr);

                    //Mencari apakah waktu tersebut telah terdefinisi dalam statistik
                    pTemp = First(*Sx);
                    IsFound = false; //Inisialisasi
                    while ((pTemp != Nil) && (!IsFound))
                    {
                        if (IsStringSama(WaktuLokal,Waktu(pTemp)))
                         {
                             IsFound = true;
                             JumlahPesan(pTemp)++;
                         }
                        pTemp = Next(pTemp);
                    }
                    //Jika tidak ditemukan dalam list
                    if (!IsFound)
                        SKInsVLast(Sx,WaktuLokal,1);
                    SaveStatKirim(*Sx);
                    //Search posisi file di statistik
                    p = First(*S);
                    IsFound = false; //Inisialisasi
                    while (IsFound == false)
                    {
                        InisialisasiString(TempFileDir);
                        //Melakukan inisialisasi variabel yang akan digunakan
                        TempFileDir[0] = '.';
                        TempFileDir[1] = '/';
                        TempFileDir[2] = 'O';
                        TempFileDir[3] = 'u';
                        TempFileDir[4] = 't';
                        TempFileDir[5] = 'b';
                        TempFileDir[6] = 'o';
                        TempFileDir[7] = 'x';
                        TempFileDir[8] = '/';
                        Konkat(TempFileDir,WaktuKirim(p));
                        Konkat(TempFileDir,"-");
                        Konkat(TempFileDir,NamaPengirim(p));
                        Konkat(TempFileDir,".txt\0");
                        //Mengecek apakah kedua string bernilai string
                        IsFound = IsStringSama(TempFileDir,NamaFile(PTemp));
                        if (IsFound == false)
                            p = Next(p);
                    }
                    //Mengubah status statistik
                    StatusKirim(p) = 2;
                    SaveStatistik(*S);
                   // system("clear");
                   JumlahPesan--;
                    printf("\n\n             PESAN %s TERKIRIM!\n",NamaFile(PTemp));
                 }
             }
             PTemp = Next(PTemp);
        }
        //Ubah file statistik, hapus pesan lama
            DelayWaktu(300);
            printf("\n--------------------------------------------------------------------------------\n");
}

void ListStatistikKirim(StatKirim Sx)
/* I.S. Sx terdefinisi
   F.S  Menampikan List Statistik Pengiriman ke layar */
{
    /* Kamus Lokal */
    skaddress px, pAlok, pTemp, pTempTwo;
    StatKirim StatKirimTemp;
    char PilihanPengguna;
    boolean IsValid = false;
    boolean IsFound = false;
    int i; /* Indeks untuk traversal */
    /* Algoritma */
     /* Inisialisasi List Temporary */
     SKCreateList(&StatKirimTemp);
     /* Menyalin Sx kedalam StatKirimTemp dengan posisi terurut */
     px = First(Sx);
     while (px!=Nil)
     {
        pAlok = SKAlokasi(Waktu(px),JumlahPesan(px));
    if (pAlok != Nil)
    {
        if (SKIsListEmpty(StatKirimTemp))
        {
            First(StatKirimTemp) = pAlok;
        } else
        {
            pTemp = First(StatKirimTemp);
            pTempTwo = Nil;
            IsFound = false;
			while ((pTemp != Nil) && (!IsFound)) {
				if (JumlahPesan(pAlok) <= JumlahPesan(pTemp))
				{
					pTempTwo = pTemp;
					pTemp = Next(pTemp);
				}
				else
					IsFound = true;
			}
			if (pTempTwo == Nil)
			{
				Next(pAlok) = First(StatKirimTemp);
				First(StatKirimTemp) = pAlok;
			} else
			{
				Next(pTempTwo) = pAlok;
				Next(pAlok) = pTemp;
			}
        }
    }
        px = Next(px);
     }

    printf("                List Statistik Pengiriman: \n");
   do
    {
        printf("Sortir berdasarkan (A. Urutan Masuk / default ; B. Jumlah Pesan Masuk (Descending)) \n\n");
        printf("                Pilihan Anda> ");
        scanf("\n%c",&PilihanPengguna);
        switch(toupper(PilihanPengguna))
        {
            case 'A':
                        px = First(Sx);
                        IsValid = true;
                        break;
            case 'B':
                        px = First(StatKirimTemp);
                        IsValid = true;
                        break;
            default:    printf("                            Masukkan Anda Salah!\n\n");
                        break;
        }
        if (IsValid)
        {
                while (px!=Nil)
                {
                    printf("                ");
                    for (i=0;i<=3;i++)
                        printf("%c",Waktu(px)[i]);
                    printf("-");
                    for (i=4;i<=5;i++)
                        printf("%c",Waktu(px)[i]);
                    printf("-");
                    for (i=6;i<=7;i++)
                        printf("%c",Waktu(px)[i]);
                    printf(" ");
                    for (i=8;i<=9;i++)
                        printf("%c",Waktu(px)[i]);
                    printf("  %d pesan\n",JumlahPesan(px));
                    px = Next(px);
                }
        }

    } while (IsValid == false);

    DelayWaktu(300);
    printf("\n--------------------------------------------------------------------------------\n");

}

/* *** MODUS C *** */
void MorseToKarakter (char Y[])
/* I.S. File Kode Morse ada, isinya dijamin dapat dikonversi, Nama File Kode Morse Y ada
   F.S. Semua kode morse masukan terkonversi menjadi karakter dan pesan yang terkonversi tersimpan di file eksternal di direktori Inbox
*/
{
	/** Kamus **/
	char tabkarakter[MAX_CHAR]; //penampung karakter yang sudah dikonversi
	int count; //jumlah karakter yang telah dikonversi
	int i,j; //indeks traversal
	FILE *fp;
	char waktu[MAX_CHAR]; //waktu ketika tabkarakter disalin ke dalam file eksternal baru
	char dirout[MAX_CHAR]; //direktori file eksternal hasil konversi kode morse
	char filein[MAX_CHAR]; //untuk menampung nama file yang akan dikonversi
	time_t now;
	struct tm *ptr;
	BinTree KamusPohon;

	/** Algoritma **/
	/* Morse dalam Pohon Biner */
    KamusPohon = MakePohonMorse();
	/* Konversi Kode Morse dan Menyimpan ke tabkarakter */
	STARTKATA(Y);
	InisialisasiString(tabkarakter);
	count=0;
	while (!EndKata)
	{
		if (count > 1)
		{
			if ((tabkarakter[count-2] != ' ') && (tabkarakter[count-1] == ' ') && (CKata.TabKata[0] != ' '))
				count--;
		}
		if (count > 2)
		{
			if ((tabkarakter[count-3] == ' ') && (tabkarakter[count-2] == ' ') && (tabkarakter[count-1] == ' '))
				count = count - 2;
		}
		BVSearch(KamusPohon,CKata,&tabkarakter[count],0);
		count++;
	    ADVMORSE();
	} /* seluruh kode morse telah berhasil dikonversi dan disimpan dalam tabkarakter */
	/* Mengambil nama file yang akan dikonversi dari nama file Y */
	i=10;
	j=0;
	InisialisasiString(filein);
	while (Y[i]!='\0')
	{
		filein[j]=Y[i];
		j++;
		i++;
	} //nama file yang akan dikonversi sudah tersimpan pada variabel filein
	/* menyimpan isi tabkarakter ke dalam file eksternal pada folder Inbox */
	InisialisasiString(dirout);
	dirout[0]='.';
	dirout[1]='/';
	dirout[2]='I';
	dirout[3]='n';
	dirout[4]='b';
	dirout[5]='o';
	dirout[6]='x';
	dirout[7]='/';
	Konkat(dirout,filein); //dirout siap dipakai sebagai direktori file hasil konversi
	fp = fopen(dirout, "wt");
	for(i=0;i<count;i++)
	{
		fprintf(fp,"%c",tabkarakter[i]);
	}
	fprintf(fp,"*");
	fclose(fp);
}

/*** FUNGSI ANTARA KarakterToPesan ***/
kaddress AddressSimbol(KamusKarakter X, char Y[])
/* Mengembalikan address simbol bila kata Y ada di dalam kamus karakter X (kata merupakan representasi alfabet dari suatu simbol) */
/* Mengembalikan Nil bila tidak ada */
{
	kaddress pt; //address jelajah kamus karakter
	kaddress a; //address untuk menampung nilai sementara dari fungsi AddressSimbol
	boolean found=false; //FALSE bila kata yang dicari tidak ada dalam kamus, TRUE bila ada
	pt=First(X);
	a=Nil;
	/* Traversal dari awal list Kamus Karakter hingga akhir */
	while((pt!=Nil) && (!found))
	{
		if (IsStringSama(KarakterSimbol(pt),Y)) //Kata yang dicari ada di dalam Kamus Karakter
		{
			a=pt;
			found=true;
		}
		pt = Next(pt);
	}//pt==Nil (sudah mencapai akhir list) atau found==true (kata yang dicari ada di Kamus Karakter
	return a;
}
/*** END OF FUNGSI ANTARA KarakterToPesan ***/

void KarakterToPesan (KamusKarakter X, char Y[])
/* I.S. Karakter dalam pesan terdefinisi, kamus karakter X terdefinisi, nama file Y ada
   F.S. Karakter terkonversi menjadi pesan sesuai dengan kamus karakter X dan menampilkannya ke layar
*/
{
	/** Kamus Lokal **/
	int i; //untuk traversal tiap karakter pada CKata
	kaddress sim; //untuk menampung hasil fungsi KarakterToSimbol
	/** Algoritma **/
	STARTKATA(Y);
	while(!EndKata)
	{
		/* Mencari apakah kata yang telah diakuisisi ada dalam Kamus Karakter */
		sim=AddressSimbol(X,CKata.TabKata);
		/* Mencetak pesan ke layar */
		if(sim!=Nil) //kata pada CKata merupakan representasi alfabet dari suatu simbol
		{
			printf("%c",Simbol(sim)); //mencetak simbol ke layar
		}
		else //kata pada CKata bukan merupakan representasi alfabet dari suatu simbol
		{
			/* Mencetak kata ke layar */
			if ((CKata.TabKata[0] == 'E') && (CKata.TabKata[1] == 'N') && (CKata.TabKata[2] == 'T') && (CKata.TabKata[3] == 'E') && (CKata.TabKata[4] == 'R') && (CKata.TabKata[5] == '\0'))
			{
              printf("\n");
              ADVMORSE();
			}
              else
            {
                 for(i=0;i<CKata.Length;i++)
                 {
                     printf("%c",CKata.TabKata[i]);
                 }
            }
		}
		InisialisasiString(CKata.TabKata);
		ADVMORSE();
	}// Seluruh kata sudah terkonversi dan tercetak ke layar
}


void ListPesan (Statistik *S, StatTerima *Sx)
/* I.S. S terdefinisi, Sx terdefinisi
   F.S. Konversi pesan dari kode morse ke dalam karakter tersimpan ke dalam suatu file eksternal
   pada direktori Inbox (dari direktori Sending). Kemudian, menampilkan ke layar nama file dari pesan-
   pesan tersebut
*/
{
	/** Kamus Lokal **/
	int i=0; //indeks jelajah
	boolean IsFound; //Variabel yang digunakan untuk mencari elemen dalam Lists
	saddress p; //indeks jelajah kamus
	staddress px;
	char dirin[MAX_CHAR]; //direktori file kode morse yang akan dikonversi
	char tampung[MAX_CHAR];
	char ext[MAX_CHAR]; //ekstensi file Kode Morse
	char strip[MAX_CHAR];
	/** Algoritma **/

	/* Inisialisasi semua variabel string */
    printf("               List nama pesan di folder Inbox (Sorted by Date): \n");
	InisialisasiString(dirin);
	InisialisasiString(ext);
	InisialisasiString(tampung);
	InisialisasiString(strip);
	/* Mengisi dirin dengan direktori folder Sending */
	dirin[0]='.';
	dirin[1]='/';
	dirin[2]='S';
	dirin[3]='e';
	dirin[4]='n';
	dirin[5]='d';
	dirin[6]='i';
	dirin[7]='n';
	dirin[8]='g';
	dirin[9]='/';
	dirin[10]='\0';

	/* Mengisi strip dengan '-' */
	strip[0]='-';
	strip[1]='\0';

	/* Mengisi ext dengan ekstensi file Kode Morse */
	ext[0]='.';
	ext[1]='t';
	ext[2]='x';
	ext[3]='t';
	ext[4]='\0';

	/* Traversal Statistik */
	p=First(*S);
	while (p!=Nil)
	{
    	if (StatusKirim(p)==2) //posisi file sekarang berada pada folder Sending
		{
			/* Mengisi tampung dengan direktori Kode Morse yang akan dikonversi */
			SalinString(dirin,tampung); //tampung berisi direktori folder Sending
			Konkat(tampung,WaktuKirim(p));
			Konkat(tampung,strip);
			Konkat(tampung,NamaPengirim(p));
			Konkat(tampung,ext);//tampung berisi direktori Kode Morse yang akan dikonversi
			/* Konversi Kode Morse */
            MorseToKarakter(tampung);
			StatusKirim(p)=3; //pesan sekarang berada di folder Inbox

			/* Menghapus file pada folder Sending */
			remove(tampung);
            /* Masukkan status file ke statistik */
            px = First(*Sx);
            IsFound = false;
            while ((px!=Nil) && (!IsFound))
             {
                if(IsStringSama(Penerima(px),NamaPenerima(p)))
                {
                    IsFound = true;
                    TotalTerima(px)++;
                }
                px = Next(px);
             }
            //Jika nama penerima tidak ditemukan dalam statistik
            if (!IsFound)
            {
                STInsVLast(Sx,NamaPenerima(p),0,1);
            }
            //Menyimpan kembali file ke statistik
            SaveStatTerima(*Sx);

			InisialisasiString(tampung);

		}
		if ((StatusKirim(p)== 3) || (StatusKirim(p) == 4))
		{
            i++;
			/* Mencetak list pesan yang sudah terkonversi */
			printf("               %d. %s-%s.txt\n",i,WaktuKirim(p),NamaPengirim(p));
		}
		p = Next(p);
	}
	SaveStatistik(*S);
    DelayWaktu(300);
    printf("\n--------------------------------------------------------------------------------\n");
}

void BacaPesan (Statistik *S, KamusKarakter X, StatTerima *Sx)
/* I.S. S terdefinisi, Kamus Karakter X terdefinisi, Sx terdefinisi
   F.S. Membaca ID pesan, kemudian membuka pesan yang dimaksud jika ID pesan terdefinisi. Mengubah Status(S)
   dari belum dibaca menjadi sudah dibaca
*/
{
    /** Kamus Lokal **/
	int id; //ID pesan yang akan dibaca
	saddress p; //address traversal statistik
	staddress px; //address traversal statistik terima
	boolean IsFound;
	char dirin[MAX_CHAR]; //direktori file pesan yang akan dibaca
	int i; //traversal id

	/** Algoritma **/
	/*Input ID pesan yang akan dibaca */
	printf("\n               Masukkan ID Pesan> ");
    scanf("%d",&id);

	/* Traversal Statistik */
    p = First(*S);
    i = 0;
    IsFound = false;
    while ((p != Nil) && (!IsFound))
    {
        if ((StatusKirim(p) == 3) || (StatusKirim(p) == 4))
            i++;
        if (i == id)
                IsFound = true;
        if (!IsFound)
             p = Next(p);
    }

    if (IsFound == true) //jika ID pesan valid
    {
        InisialisasiString(dirin);
        Konkat(dirin,"./Inbox/");
        Konkat(dirin,WaktuKirim(p));
        Konkat(dirin,"-");
        Konkat(dirin,NamaPengirim(p));
        Konkat(dirin,".txt\0");
        printf("\n\n");
        SaveStatistik(*S);
        //Menyimpan kedalam statistik pada direktori Inbox
        if (StatusKirim(p) == 3)
        {
        px = First(*Sx);
        while (px!=Nil)
        {
                if(IsStringSama(Penerima(px),NamaPenerima(p)))
                {
                    SudahBaca(px)++;
                    break;
                }
                px = Next(px);
        }
            SaveStatTerima(*Sx);
            StatusKirim(p) = 4;
        }
        KarakterToPesan(X,dirin);
    }
    else
        printf("\n               Pesan tidak ditemukan!\n");
        DelayWaktu(300);
        printf("\n--------------------------------------------------------------------------------\n");
}

void HapusPesan (Statistik *S)
/* I.S. S terdefinisi
   F.S. Masukan ID pesan yang ingin dihapus pengguna terbaca, jika terdefinisi maka pesan dihapus dari direktori Inbox
   dan status pesan diubah menjadi "deleted"
*/
{
	/** Kamus Lokal **/
	saddress p; //address traversal statistik
	int id; //id pesan yang akan dihapus
	int i=1; //untuk traversal ID pesan
	char dirin[MAX_CHAR]; //direktori pesan yang akan dihapus
	char ext[MAX_CHAR]; //ekstensi file pesan yang akan dihapus
	char strip[MAX_CHAR];
	boolean IsFound;

	/** Algoritma **/
	InisialisasiString(dirin);
	InisialisasiString(ext);
	InisialisasiString(strip);

	/* Mengisi dirin dengan direktori folder Inbox */
	dirin[0]='.';
	dirin[1]='/';
	dirin[2]='I';
	dirin[3]='n';
	dirin[4]='b';
	dirin[5]='o';
	dirin[6]='x';
	dirin[7]='/';

	/* Mengisi strip dengan '-' */
	strip[0]='-';

	/* Mengisi ext dengan ekstensi file Kode Morse */
	ext[0]='.';
	ext[1]='t';
	ext[2]='x';
	ext[3]='t';

	/* Input ID pesan yang akan dihapus */
	printf("\n               Masukkan Id Pesan> ");
	scanf("%d",&id);

	/* Traversal statistik */
	p = First(*S);
	i=0;
    IsFound = false;
    while ((p != Nil) && (!IsFound))
    {
        if ((StatusKirim(p) == 3) || (StatusKirim(p) == 4))
            i++;
        if (i == id)
            IsFound = true;
        if (!IsFound)
             p = Next(p);
    }
    if (IsFound == true) /* Jika ID pesan valid */
    {
        Konkat(dirin,WaktuKirim(p));
        Konkat(dirin,strip);
		Konkat(dirin,NamaPengirim(p));
		Konkat(dirin,ext);
        remove(dirin);//pesan telah terhapus dari sistem
        StatusKirim(p) = 5;
		printf("\nPesan %s-%s.txt telah terhapus dari sistem",WaktuKirim(p),NamaPengirim(p));
        SaveStatistik(*S);
    }
    else
        printf("\n               Pesan tidak ditemukan!\n");
    DelayWaktu(300);
    printf("\n--------------------------------------------------------------------------------\n");
}

void ListStatistikTerima(StatTerima Sx)
/* I.S. Sx terdefinisi
   F.S  Menampikan List Statistik Penerimaan ke layar */
{
    /* Kamus Lokal */
    staddress px, pAlok, pTemp, pTempTwo;
    StatTerima StatTerimaTemp, StatTerimaTempTwo;
    char PilihanPengguna;
    boolean IsValid = false;
    boolean IsFound = false;
    int i; /* indeks traversal */
    /* Algoritma */
     /* Inisialisasi List Temporary */
     STCreateList(&StatTerimaTemp);
     STCreateList(&StatTerimaTempTwo);
     /* Menyalin Sx kedalam StatTerimaTemp dengan posisi terurut */
     px = First(Sx);
     while (px!=Nil)
     {
        pAlok = STAlokasi(Penerima(px),SudahBaca(px),TotalTerima(px));
    if (pAlok != Nil)
    {
        if (STIsListEmpty(StatTerimaTemp))
        {
            First(StatTerimaTemp) = pAlok;
        } else
        {
            pTemp = First(StatTerimaTemp);
            pTempTwo = Nil;
            IsFound = false;
			while ((pTemp != Nil) && (!IsFound)) {
				if (TotalTerima(pAlok) <= TotalTerima(pTemp))
				{
					pTempTwo = pTemp;
					pTemp = Next(pTemp);
				}
				else
					IsFound = true;
			}
			if (pTempTwo == Nil)
			{
				Next(pAlok) = First(StatTerimaTemp);
				First(StatTerimaTemp) = pAlok;
			} else
			{
				Next(pTempTwo) = pAlok;
				Next(pAlok) = pTemp;
			}
        }
    }
        px = Next(px);
     }
     /* Menyalin Sx kedalam StatTerimaTempTwo dengan posisi terurut */
     px = First(Sx);
     while (px!=Nil)
     {
        pAlok = STAlokasi(Penerima(px),SudahBaca(px),TotalTerima(px));
    if (pAlok != Nil)
    {
        if (STIsListEmpty(StatTerimaTempTwo))
        {
            First(StatTerimaTempTwo) = pAlok;
        } else
        {
            pTemp = First(StatTerimaTempTwo);
            pTempTwo = Nil;
            IsFound = false;
			while ((pTemp != Nil) && (!IsFound)) {
				if (SudahBaca(pAlok) <= SudahBaca(pTemp))
				{
					pTempTwo = pTemp;
					pTemp = Next(pTemp);
				}
				else
					IsFound = true;
			}
			if (pTempTwo == Nil)
			{
				Next(pAlok) = First(StatTerimaTempTwo);
				First(StatTerimaTempTwo) = pAlok;
			} else
			{
				Next(pTempTwo) = pAlok;
				Next(pAlok) = pTemp;
			}
        }
    }
        px = Next(px);
     }
    printf("                List Statistik Penerimaan: \n");
    do
    {
        printf("Sortir berdasarkan (A. Urutan Masuk / default ; B. Jumlah Pesan Masuk (Descending); C. Jumlah Pesan Dibaca (Descending)) \n\n");
        printf("                Pilihan Anda> ");
        scanf("\n%c",&PilihanPengguna);
        switch(toupper(PilihanPengguna))
        {
            case 'A':
                        px = First(Sx);
                        IsValid = true;
                        break;
            case 'B':
                        px = First(StatTerimaTemp);
                        IsValid = true;
                        break;
            case 'C':
                        px = First(StatTerimaTempTwo);
                        IsValid = true;
                        break;
            default:    printf("                            Masukkan Anda Salah!\n\n");
                        break;
        }
        if (IsValid)
        {
                while (px!=Nil)
                {
                    printf("               %s   %d / %d Pesan\n",Penerima(px),SudahBaca(px),TotalTerima(px));
                    px = Next(px);
                }
        }

    } while (IsValid == false);
    DelayWaktu(300);
    printf("\n--------------------------------------------------------------------------------\n");
}

/* *** MODUS D *** */
boolean SearchKarakterSimbol(KamusKarakter X, char Y[])
/* Fungsi SearchKamus menerima masukkan tabel X dan satu karakter Y kemudian mengembalikan true apabila Y merupakan anggota X) */
	{
	/*kamus*/
	kaddress pt;
	boolean found=false;
	/*algoritmaa*/
	pt=First(X);
	while((pt!=Nil)&& !found)
	{
				 found=(IsStringSama(KarakterSimbol(pt),Y));
				 pt=Next(pt);
	}
	return (found);
	}


boolean IsUserValid (DataPengguna user,char nama[])
/* Mengembalikan true bila user tidak terdaftar) */
/* Mengembalikan false bila user sudah terdaftar */
	{
	//kamus lokal
	uaddress P = First(user);
	//algoritma
	while ((P!= Nil) && (!IsStringSama(nama,Nama(P))))
		P = Next(P);
	if (P == Nil)
		return true;
	else
		return false;
	}

void TambahKamus(KamusKarakter *X)
// { I.S. : X terdefinisi, X mungkin kosong,tidak dilakukan pengecekan }
// { F.S. : Menambahkan karakter baru kedalam X (Karakter beserta representasinya dalam mesin kata) }
	{
	//kamus lokal
	char c;
	char ks[MAX_CHAR];
	char js[MAX_CHAR];
	int i;
	boolean alnum = true;
	//algoritma
	printf("Masukkan kamus yang ingin ditambahkan : ");
	scanf("\n%c",&c);
	if (SearchKamus(*X,c))
		{
		printf("Kamus sudah ada\n");
		}
	else
			{
			printf("Karakter Simbol untuk %c: ",c);
			scanf("%s",&ks);
			i=0;
			while(ks[i]!='\0')
				{
				alnum = alnum && isalnum(ks[i]);
				i++;
				}
			if(!alnum)
				{
				printf("Kamus Karakter mengandung simbol, input gagal\n");
				}
			else
			{
			i = 0;//pembuatan case insensitive
			while (ks[i]!= '\0')
				{
				ks[i] = toupper(ks[i]);
				i++;
				}
			if (!SearchKarakterSimbol(*X,ks))
				{
				printf("Jenis Simbol untuk %c [1 Tanda Baca,2 Lain-Lain]: ",c);
				scanf("%i",&i);
				while(i != 1 && i != 2)
					{
					printf("Masukan salah, input ulang : ");
					scanf("%i",&i);
					}
				if(i== 1)
					{
					js[0] = 'T';js[1] = 'a';js[2] = 'n';js[3] = 'd';js[4] = 'a';js[5]=' ';js[6]='B';js[7]='a';js[8]='c';js[9]='a';js[10] ='\0';
					}
				else
					{
					js[0] = 'L';js[1] = 'a';js[2] = 'i';js[3] = 'n';js[4] = '-';js[5]='L';js[6]='a';js[7]='i';js[8]='n';js[9]='\0';
					}
				KInsVLast(X,c,ks,js);
				printf("Kamus berhasil ditambahkan!!!\n");
				}
			else
				printf("Representasi Karakter %s sudah ada\n",ks);
			}
		}
	DelayWaktu(300);
	}

void KDelX(KamusKarakter *L, char X)
/* { I.S. list tidak kosong } */
/* { F.S. elemen X di list dihapus }
{ dan alamat elemen tersebut di-dealokasi } */
	{
		/* Kamus Lokal */
		kaddress P;
		kaddress Prec;
		/* Algoritma */
		P = First(*L);
		while ((P!= Nil) && (X!=Simbol(P)))
		{
			Prec = P;
			P=Next(P);
		}
		if ((P!= Nil) && (P!=First(*L)))
		{
			Next(Prec) = Next(P);
			Next(P) = Nil;
			KDealokasi(&P);
		}
		else
		if (P == First(*L))
			{
			First(*L) = Next(P);
			KDealokasi(&P);
			}
		printf("Penghapusan Berhasil!!\n");
	}

void HapusKamus(KamusKarakter *X)
// { I.S. : X terdefinisi, X mungkin kosong }
// { F.S. : Menghapus karakter yang sudah terdefinisi dalam X. Jika X kosong, cetak ÅgTidak ada karakter dalam kamus.Åh}
	{
	//kamus lokal
	char c;
	//algoritma
	printf("Karakter yang ingin dihapus: ");
	scanf("\n%c",&c);
	if (!SearchKamus(*X,c))
		{
		printf("%c tidak ada dalam kamus\n",c);
		}
	else
		{
		KDelX(X,c);
		printf("Kamus berhasil dihapus!!!\n");
		}
	DelayWaktu(300);
	}

/* All Rights Reserved 2012 */
