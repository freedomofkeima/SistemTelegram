/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : ADT_PohonBiner.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Realisasi Header File ADT Tubes */
#include "ADT_PohonBiner.h"

#include "../adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* ***************ADT POHON BINER*************** */
/* Pengelolaan Memori */
void Allocate (Pohonaddress *Pohon)
/* Melakukan alokasi terhadap Pohon Biner */
{
	*Pohon =(Pohonaddress) malloc(sizeof(Node));
}

void AllocateRev (PohonaddressRev *Pohon)
/* Melakukan alokasi terhadap Pohon Biner Rev */
{
    *Pohon = (PohonaddressRev) malloc(sizeof(NodeRev));
}

void BVSearch(BinTree Pohon,kata X,char *Hasil,int Level)
/* I.S. : Menerima masukkan Binary Search Tree, sandi morse dalam Kata */
/* F.S. : Dengan metode Dichotomic Search, melakukan pencarian dalam Pohon Biner, dan mengembalikan karakter Key yang sama dalam Hasil */
{
    if ((X.Length == 1) && (X.TabKata[0] == ' '))
		(*Hasil) = ' ';
    else
    {
        /* Searching, O( log2(N) ) complexity sebagai worst case */
        if (X.Length == Level)
        {
            (*Hasil) = Akar(Pohon);
        }
        else
        {
            //Jika dot maka kearah kiri
            if (X.TabKata[Level] == '.')
                BVSearch(Left(Pohon),X,Hasil,Level+1);
            else //Jika dash maka kearah kanan
                BVSearch(Right(Pohon),X,Hasil,Level+1);
        }
    }
}

void BVSearchRev(BinTreeRev Pohon, char X, int Nilai, int Level, kata *Hasil)
/* I.S. : Menerima masukkan Binary Search Tree dan alfabet yang akan dikonversikan menjadi sandi morse */
/* F.S. : Dengan metode Dichotomic Search, melakukan pencarian dalam Pohon Biner, dan mengembalikan sandi morse yang sama dalam Hasil */
{
    /* Kamus Lokal */
    int NilaiKarakter; /* Untuk menampung nilai ASCII karakter */
    int i; /* indeks untuk traversal */
    int kanan; /* nilai batas kanan */
    /* Algoritma */
    if (X == ' ')
    {
     (*Hasil).TabKata[0] = ' ';
     (*Hasil).Length = 1;
    }
    else
    {
        NilaiKarakter = X - 'A' + 1;
         //Jika sama dengan posisi, maka keluar
        if (NilaiKarakter == Nilai)
          {
              for (i=0;i<Length(Pohon);i++)
                (*Hasil).TabKata[i] = Akar(Pohon)[i];
              (*Hasil).Length = Length(Pohon);
          } else
          {
              kanan = 1;
              for (i=0;i<(4-Level);i++)
                kanan = kanan * 2;
              kanan = kanan + Nilai;
              if (NilaiKarakter >= kanan)
                BVSearchRev(Right(Pohon),X,kanan,Level+1,Hasil);  //Jika lebih samadengan dari kanan, maka kearah kanan
              else             //Jika kurang dari kanan, maka kearah kiri
                BVSearchRev(Left(Pohon),X,Nilai+1,Level+1,Hasil);
          }
    }
}

BinTree MakePohonMorse()
/* Menghasilkan Pohon Morse */
{
    /* Kamus Lokal */
    BinTree Pohon;
    Pohonaddress A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;

    /* Algoritma */
    Allocate(&Pohon);
    //Inisialisasi Pohon
    Akar(Pohon) = '\0';

    /* Membangun Pohon secara Manual, dengan Mengalokasikan setiap Address dengan elemen */
    Allocate(&E);
    Akar(E) = 'E';
    Left(Pohon) = E;

    Allocate(&T);
    Akar(T) = 'T';
    Right(Pohon) = T;

    Allocate(&I);
    Akar(I) = 'I';
    Left(E) = I;

    Allocate(&A);
    Akar(A) = 'A';
    Right(E) = A;

    Allocate(&N);
    Akar(N) = 'N';
    Left(T) = N;

    Allocate(&M);
    Akar(M) = 'M';
    Right(T) = M;

    Allocate(&S);
    Akar(S) = 'S';
    Left(I) = S;

    Allocate(&U);
    Akar(U) = 'U';
    Right(I) = U;

    Allocate(&R);
    Akar(R) = 'R';
    Left(A) = R;

    Allocate(&W);
    Akar(W) = 'W';
    Right(A) = W;

    Allocate(&D);
    Akar(D) = 'D';
    Left(N) = D;

    Allocate(&K);
    Akar(K) = 'K';
    Right(N) = K;

    Allocate(&G);
    Akar(G) = 'G';
    Left(M) = G;

    Allocate(&O);
    Akar(O) = 'O';
    Right(M) = O;

    Allocate(&H);
    Akar(H) = 'H';
    Left(S) = H;

    Allocate(&V);
    Akar(V) = 'V';
    Right(S) = V;

    Allocate(&F);
    Akar(F) = 'F';
    Left(U) = F;

    Allocate(&L);
    Akar(L) = 'L';
    Left(R) = L;

    Allocate(&P);
    Akar(P) = 'P';
    Left(W) = P;

    Allocate(&J);
    Akar(J) = 'J';
    Right(W) = J;

    Allocate(&B);
    Akar(B) = 'B';
    Left(D) = B;

    Allocate(&X);
    Akar(X) = 'X';
    Right(D) = X;

    Allocate(&C);
    Akar(C) = 'C';
    Left(K) = C;

    Allocate(&Y);
    Akar(Y) = 'Y';
    Right(K) = Y;

    Allocate(&Z);
    Akar(Z) = 'Z';
    Left(G) = Z;

    Allocate(&Q);
    Akar(Q) = 'Q';
    Right(G) = Q;

    return Pohon;
}

BinTreeRev MakePohonAlfabet()
/* Menghasilkan Pohon Alfabet */
{
    /* Kamus Lokal */
    BinTreeRev Pohon;
    PohonaddressRev A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    AllocateRev(&Pohon);
    //Inisialisasi Pohon
    Akar(Pohon)[0] = '\0';
    Length(Pohon) = 1;

    /* Membangun Pohon secara Manual, dengan Mengalokasikan setiap Address dengan elemen */
    AllocateRev(&A);
    Akar(A)[0] = '.';
    Akar(A)[1] = '-';
    Akar(A)[2] = '\0';
    Length(A) = 2;
    Left(Pohon) = A;

    AllocateRev(&B);
    Akar(B)[0] =  '-';
    Akar(B)[1] = '.';
    Akar(B)[2] = '.';
    Akar(B)[3] = '.';
    Akar(B)[4] = '\0';
    Length(B) = 4;
    Left(A) = B;

    AllocateRev(&C);
    Akar(C)[0] = '-';
    Akar(C)[1] = '.';
    Akar(C)[2] = '-';
    Akar(C)[3] = '.';
    Akar(C)[4] = '\0';
    Length(C) = 4;
    Left(B) = C;

    AllocateRev(&D);
    Akar(D)[0] = '-';
    Akar(D)[1] = '.';
    Akar(D)[2] = '.';
    Akar(D)[3] = '\0';
    Length(D) = 3;
    Left(C) = D;

    AllocateRev(&E);
    Akar(E)[0] = '.';
    Akar(E)[1] = '\0';
    Length(E) = 1;
    Right(C) = E;

    AllocateRev(&F);
    Akar(F)[0] = '.';
    Akar(F)[1] = '.';
    Akar(F)[2] = '-';
    Akar(F)[3] = '.';
    Akar(F)[4] = '\0';
    Length(F) = 4;
    Right(B) = F;

    AllocateRev(&G);
    Akar(G)[0] = '-';
    Akar(G)[1] = '-';
    Akar(G)[2] = '.';
    Akar(G)[3] = '\0';
    Length(G) = 3;
    Left(F) = G;

    AllocateRev(&H);
    Akar(H)[0] = '.';
    Akar(H)[1] = '.';
    Akar(H)[2] = '.';
    Akar(H)[3] = '.';
    Akar(H)[4] = '\0';
    Length(H) = 4;
    Right(F) = H;

    AllocateRev(&I);
    Akar(I)[0] = '.';
    Akar(I)[1] = '.';
    Akar(I)[2] = '\0';
    Length(I) = 2;
    Right(A) = I;

    AllocateRev(&J);
    Akar(J)[0] = '.';
    Akar(J)[1] = '-';
    Akar(J)[2] = '-';
    Akar(J)[3] = '-';
    Akar(J)[4] = '\0';
    Length(J) = 4;
    Left(I) = J;

    AllocateRev(&K);
    Akar(K)[0] = '-';
    Akar(K)[1] = '.';
    Akar(K)[2] = '-';
    Akar(K)[3] = '\0';
    Length(K) = 3;
    Left(J) = K;

    AllocateRev(&L);
    Akar(L)[0] = '.';
    Akar(L)[1] = '-';
    Akar(L)[2] = '.';
    Akar(L)[3] = '.';
    Akar(L)[4] = '\0';
    Length(L) = 4;
    Right(J) = L;

    AllocateRev(&M);
    Akar(M)[0] = '-';
    Akar(M)[1] = '-';
    Akar(M)[3] = '\0';
    Length(M) = 2;
    Right(I) = M;

    AllocateRev(&N);
    Akar(N)[0] = '-';
    Akar(N)[1] = '.';
    Akar(N)[2] = '\0';
    Length(N) = 2;
    Left(M) = N;

    AllocateRev(&O);
    Akar(O)[0] = '-';
    Akar(O)[1] = '-';
    Akar(O)[2] = '-';
    Akar(O)[3] = '\0';
    Length(O) = 3;
    Right(M) = O;

    AllocateRev(&P);
    Akar(P)[0] = '.';
    Akar(P)[1] = '-';
    Akar(P)[2] = '-';
    Akar(P)[3] = '.';
    Akar(P)[4] = '\0';
    Length(P) = 4;
    Right(Pohon) = P;

    AllocateRev(&Q);
    Akar(Q)[0] = '-';
    Akar(Q)[1] = '-';
    Akar(Q)[2] = '.';
    Akar(Q)[3] = '-';
    Akar(Q)[4] = '\0';
    Length(Q) = 4;
    Left(P) = Q;

    AllocateRev(&R);
    Akar(R)[0] = '.';
    Akar(R)[1] = '-';
    Akar(R)[2] = '.';
    Akar(R)[3] = '\0';
    Length(R) = 3;
    Left(Q) = R;

    AllocateRev(&S);
    Akar(S)[0] = '.';
    Akar(S)[1] = '.';
    Akar(S)[2] = '.';
    Akar(S)[3] = '\0';
    Length(S) = 3;
    Left(R) = S;

    AllocateRev(&T);
    Akar(T)[0] = '-';
    Akar(T)[1] = '\0';
    Length(T) = 1;
    Right(R) = T;

    AllocateRev(&U);
    Akar(U)[0] = '.';
    Akar(U)[1] = '.';
    Akar(U)[2] = '-';
    Akar(U)[3] = '\0';
    Length(U) = 3;
    Right(Q) = U;

    AllocateRev(&V);
    Akar(V)[0] = '.';
    Akar(V)[1] = '.';
    Akar(V)[2] = '.';
    Akar(V)[3] = '-';
    Akar(V)[4] = '\0';
    Length(V) = 4;
    Left(U) = V;

    AllocateRev(&W);
    Akar(W)[0] = '.';
    Akar(W)[1] = '-';
    Akar(W)[2] = '-';
    Akar(W)[3] = '\0';
    Length(W) = 3;
    Right(U) = W;

    AllocateRev(&X);
    Akar(X)[0] = '-';
    Akar(X)[1] = '.';
    Akar(X)[2] = '.';
    Akar(X)[3] = '-';
    Akar(X)[4] = '\0';
    Length(X) = 4;
    Right(P) = X;

    AllocateRev(&Y);
    Akar(Y)[0] = '-';
    Akar(Y)[1] = '.';
    Akar(Y)[2] = '-';
    Akar(Y)[3] = '-';
    Akar(Y)[4] = '\0';
    Length(Y) = 4;
    Left(X) = Y;

    AllocateRev(&Z);
    Akar(Z)[0] = '-';
    Akar(Z)[1] = '-';
    Akar(Z)[2] = '.';
    Akar(Z)[3] = '.';
    Akar(Z)[4] = '\0';
    Length(Z) = 4;
    Left(Y) = Z;
    return Pohon;
}

/* All Rights Reserved 2012 */
