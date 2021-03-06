/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mPohonBiner.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "../ADT_String/ADT_String.c"
#include "../ADT_MesinKarakter/ADT_MesinKarakter.c"
#include "../ADT_MesinKata/ADT_MesinKata.c"
#include "ADT_PohonBiner.c"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

int main()
{
	/** Kamus **/
	BinTree PohonMorse; //untuk menampung hasil fungsi MakePohonMorse()
	BinTreeRev PohonAlfabet; //untuk menampung hasil fungsi MakePohonAlfabet()
	kata tes1;
	kata tes2;
	char tampung1;
	char tes3;
	char tes4;
	kata tampung2;

	/** Algoritma **/
	/* Tes Pohon Morse */
	PohonMorse = MakePohonMorse(); //membuat pohon morse
	InisialisasiString(tes1.TabKata);
	InisialisasiString(tes2.TabKata);
	Konkat(tes1.TabKata,"--.\0");
	tes1.Length=3;
	Konkat(tes2.TabKata,".-\0");
	tes2.Length=2;
	BVSearch(PohonMorse,tes1,&tampung1,0);
	printf("Hasil konversi morse %s ke alfabet adalah %c\n",tes1.TabKata,tampung1);
	BVSearch(PohonMorse,tes2,&tampung1,0);
	printf("Hasil konversi morse %s ke alfabet adalah %c\n",tes2.TabKata,tampung1);
	/* Tes Pohon Alfabet */
	PohonAlfabet = MakePohonAlfabet(); //membuat pohon alfabet
	tes3 = 'A';
	tes4 = 'E';
	InisialisasiString(tampung2.TabKata);
	BVSearchRev(PohonAlfabet,tes3,0,0,&tampung2);
	printf("Hasil konversi alfabet %c ke morse adalah %s\n",tes3,tampung2.TabKata);
	InisialisasiString(tampung2.TabKata);
	BVSearchRev(PohonAlfabet,tes4,0,0,&tampung2);
	printf("Hasil konversi alfabet %c ke morse adalah %s\n",tes4,tampung2.TabKata);

	return 0;
}
/* All Rights Reserved 2012 */
