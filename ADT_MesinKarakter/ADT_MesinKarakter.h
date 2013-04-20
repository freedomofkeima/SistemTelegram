/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_MesinKarakter.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_MesinKarakter_h
#define adt_MesinKarakter_h

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

#ifndef MARK
#define MARK '*'
#endif

#ifndef MAX_CHAR
#define MAX_CHAR 1000
#endif

/* ***************ADT MESIN KARAKTER*************** */
void ADV();
/* I.S. CC != MARK */
/* F.S. CC adalah karakter berikutnya dari CC pada I.S. */
/*      Jika CC==MARK, EOP menyala (true) */


void START(char X[]);
/* I.S. sembarang */
/* F.S. CC adalah karakter pertama pita */
/*      Jika CC==MARK, eop menyala (true) */
/*      Jika CC != MARK, eop padam (false) */

#endif
/* All Rights Reserved 2012 */
