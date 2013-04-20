/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_MesinKata.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_MesinKata.h"
#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* ***************ADT MESIN KATA*************** */
/* Deklarasi Variabel */
boolean EndKata;
kata CKata;

/* { *** Primitif-Primitif Mesin Kata *** } */
void Ignore_Blank()
/* { Mengabaikan satu atau beberapa BLANK } */
/* { I.S. : CC sembarang } */
/* { F.S. : CC != BLANK atau CC = MARK } */
{
	while((CC == blank)&&(CC != MARK))
	{
		ADV();
	}
}

void SalinKata()
/* { Mengakuisisi kata, menyimpan dalam CKata } */
/* {I.S. : CC adalah karakter pertama dari kata } */
/* {F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
            NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
            karakter sesudah karakter terakhir yang diakuisisi } */
{
	int i = 0;
	InisialisasiString(CKata.TabKata);
	while ((CC != MARK)&&(CC != blank))
	{
		CKata.TabKata[i] = CC;
		ADV();
		i++;
	}
	CKata.Length = i;
}

void STARTKATA(char X[])
/* { I.S. : CC sembarang } */
/* { F.S. : EndKata = true, dan CC = Mark; }
{           atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
            CC karakter pertama sesudah karakter terakhir kata } */
{
	START(X);
	Ignore_Blank();
	if(CC == MARK)
	{
		EndKata=true;
	}
	else
	{
		EndKata=false;
		SalinKata();
	}
}

void ADVMORSE()
/* { I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
            dari kata yg sudah diakuisisi } */
/* { F.S. : Jika CC = MARK, maka EndKata = true
            atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
            CC karakter pertama sesudah karakter terakhir kata } */
{
	if(CC == MARK)
	{
		EndKata=true;
	}
	else if(CC == blank)
	{
		CKata.Length=1;
		CKata.TabKata[0]=' ';
		ADV();
	}
	else
	{
		SalinKata();
	}
}

/* All Rights Reserved 2012 */
