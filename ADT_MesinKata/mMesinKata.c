/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mMesinKata.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "../ADT_String/ADT_String.c"
#include "../ADT_MesinKarakter/ADT_MesinKarakter.c"
#include "ADT_MesinKata.c" //comment this later

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
	/* Kamus */
	int i; //indeks traversal CKata.TabKata

	/* Algoritma */
	STARTKATA("pitakar.txt"); //membuka file
	while (!EndKata)
	{
		for(i=0;i<CKata.Length;i++)
			printf("%c",CKata.TabKata[i]); //mencetak isi kata yang telah diakuisisi
		printf("\n");
		ADVMORSE();
	}
	return 0;
}

/* All Rights Reserved 2012 */
