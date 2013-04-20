/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mListStatistik.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "../ADT_String/ADT_String.c"
#include "../ADT_ListKamus/ADT_ListKamus.c"
#include "../ADT_ListPengguna/ADT_ListPengguna.c"
#include "ADT_ListStatistik.h" //comment this later
#include "../adt_boolean.h"
#include "../ADT_LoadFile/ADT_LoadFile.c"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
int i;
int main(){
	Statistik StatistikList;
	LoadStatistik(&StatistikList);
	int i;
	while (i!=2)
		{
		printf("1 Info Statistik\n2 Keluar\nInput>");
		scanf("%d",&i);
		switch (i)
				{
				case 1:
					LPrintInfo(StatistikList);
					break;
				default:
					break;
				}
		}
return 0;
}
/* All Rights Reserved 2012 */
