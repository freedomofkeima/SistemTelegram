/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mListKamus.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

// Driver File ADT List Kamus
#include "../ADT_String/ADT_String.c"
#include "ADT_ListKamus.h" //comment this later
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
//kamus lokal
KamusKarakter K;
int i;
//algoritma
char X;
char Y[255];
char Z[255];
KCreateList(&K);
do
	{
	printf("1 insert elemen baru list di awal\n2 insert elemen baru list di akhir\n3 keluar\n>input ");
	scanf("%d",&i);
	switch (i)
		{
		case 1:
			printf("karakter :");
			scanf("\n%c",&X);
			printf("Karakter Simbol:");
			scanf("%s",&Y);
			printf("Jenis Karakter:");
			scanf("%s",&Z);
			KInsVFirst(&K,X,Y,Z);
			printf("elemen List:\n");
			PrintInfoLK(K);
			break;
		case 2:
			printf("karakter :");
			scanf("\n%c",&X);
			printf("Karakter Simbol:");
			scanf("%s",&Y);
			printf("Jenis Karakter:");
			scanf("%s",&Z);
			KInsVLast(&K,X,Y,Z);
			printf("elemen List:\n");
			PrintInfoLK(K);
			break;
		}
	}while (i!= 3);
return 0;
}
/* All Rights Reserved 2012 */
