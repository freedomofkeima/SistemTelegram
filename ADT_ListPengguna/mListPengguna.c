/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mListPengguna.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT List Pengguna */
#include "../ADT_String/ADT_String.c"
#include "ADT_ListPengguna.h" //comment this later

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
DataPengguna u;
int i;
//algoritma
char X[255];
UCreateList(&u);
do
	{
	printf("1 insert elemen baru list di awal\n2 insert elemen baru list di akhir\n3 menghapus elemen \n4 keluar\n>input ");
	scanf("%d",&i);
	switch (i)
		{
		case 1:
			printf("Nama Pengguna :\n");
			scanf("\n%s",&X);
			UInsVFirst(&u,X);
			printf("Elemen List:\n");
			PrintInfoLP(u);
			break;
		case 2:
			printf("Nama Pengguna :");
			scanf("\n%s",&X);
			UInsVLast(&u,X);
			printf("elemen List:\n");
			PrintInfoLP(u);
			break;
		case 3:
			printf("Nama Pengguna :");
			scanf("\n%s",&X);
			UDelX(&u,X);
			printf("elemen List:\n");
			PrintInfoLP(u);
			break;
		}
	}while (i!= 4);
return 0;
}
/* All Rights Reserved 2012 */
