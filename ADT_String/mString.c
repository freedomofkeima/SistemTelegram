/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mString.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "ADT_String.h" //comment this later

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
    char string1[MAX_CHAR];
	char string2[MAX_CHAR];
	char string3[MAX_CHAR];
	
    /* Algoritma */
	printf("Inisialisasi string1, string2, string3\n");
	InisialisasiString(string1);
	InisialisasiString(string2);
	InisialisasiString(string3);
	/* Mencetak string1 */
	printf("Isi dari string1 adalah : %s\n\n",string1);
	/* Mengisi string1 */
	printf("string1 diisi dengan \"tes tes\"\n");
	Konkat(string1,"tes tes\0");
	printf("Isi dari string1 sekarang adalah : %s\n\n",string1);
	/* Menyalin string1 ke string2 */
	printf("Menyalin string1 ke string2\n");
	SalinString(string1,string2);
	printf("Isi dari string2 adalah : %s\n\n",string2);
	/* Memeriksa kesamaan string1 dan string2 */
	printf("Apakah string1 dan string2 sama? %d\n\n",IsStringSama(string1,string2));
	/* Mengisi string 3 */
	printf("string3 diisi dengan \"bukan tes\"\n");
	Konkat(string3,"bukan tes\0");
	printf("Isi dari string3 adalah : %s\n\n",string3);
	/* Memeriksa kesamaan string1 dan string3 */
	printf("Apakah string1 dan string3 sama? %d\n",IsStringSama(string1,string3));
	

return 0;
}
/* All Rights Reserved 2012 */
