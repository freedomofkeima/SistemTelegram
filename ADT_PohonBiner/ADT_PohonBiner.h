/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_PohonBiner.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_PohonBiner_h
#define adt_PohonBiner_h

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

#ifndef MAX_CHAR
#define MAX_CHAR 1000
#endif

/* ***************ADT POHON BINER*************** */
typedef char infotype;
/* Konstruktor */
typedef struct tNode *Pohonaddress;
typedef struct tNode {
infotype value;
Pohonaddress left;
Pohonaddress right;
} Node;
typedef Pohonaddress BinTree;

/* Konstruktor */
typedef struct tNodeRev *PohonaddressRev;
typedef struct tNodeRev {
char value[5];
int length;
PohonaddressRev left;
PohonaddressRev right;
} NodeRev;
typedef PohonaddressRev BinTreeRev;
/* Selektor */
#define Akar(P) (P)->value
#define Length(P) (P)->length
#define Left(P) (P)->left
#define Right(P) (P)->right

/* Pengelolaan Memori */
void Allocate (Pohonaddress *Pohon);
/* Melakukan alokasi terhadap Pohon Biner */

void AllocateRev (PohonaddressRev *Pohon);
/* Melakukan alokasi terhadap Pohon Biner Rev */

void BVSearch(BinTree Pohon,kata X,char *Hasil,int Level);
/* I.S. : Menerima masukkan Binary Search Tree, sandi morse dalam Kata */
/* F.S. : Dengan metode Dichotomic Search, melakukan pencarian dalam Pohon Biner, dan mengembalikan karakter Key yang sama dalam Hasil */

void BVSearchRev(BinTreeRev Pohon, char X, int Nilai, int Level, kata *Hasil);
/* I.S. : Menerima masukkan Binary Search Tree dan alfabet yang akan dikonversikan menjadi sandi morse */
/* F.S. : Dengan metode Dichotomic Search, melakukan pencarian dalam Pohon Biner, dan mengembalikan sandi morse yang sama dalam Hasil */


BinTree MakePohonMorse();
/* Menghasilkan Pohon Morse */

BinTreeRev MakePohonAlfabet();
/* Menghasilkan Pohon Alfabet */

#endif
/* All Rights Reserved 2012 */
