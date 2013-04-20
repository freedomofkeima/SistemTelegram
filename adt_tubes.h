/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : adt_tubes.h */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

#ifndef adt_tubes_h
#define adt_tubes_h

#include "adt_boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

/* Header File ADT Tubes */
/* *** MODUS A *** */
/* ***** AWAL FUNGSI ANTARA MODUS KIRIM ***** */
boolean SearchKamus(KamusKarakter X, char Y);
/* { Fungsi SearchKamus menerima masukkan tabel X dan satu karakter Y kemudian mengembalikan true apabila Y merupakan anggota X } */

boolean IsPesanValid(KamusKarakter X, char Y[]);
/* { Fungsi IsPesanValid menerima masukkan tabel X dan karakter Y dan mengembalikan true apabila Y merupakan anggota X } */

void uppercase(char c[]);
/* { I.S. : Karakter terdefinisi } */
/* { F.S. : Mengembalikan uppercase dari suatu String } */

void SalinKarakterSimbol (char c,KamusKarakter ListKamus, char s[],char jk[]);
/* { I.S.: karakter c ada dalam kamus karakter } */
/* { F.S. : prosedur SalinKarakterSimbol, menyalin karakter simbol dari c menjadi karaktersimbol } */

void PrioIToChar(char i,char s[]);
/* { function PrioIToChar mengubah angka prioritas menjadi karakter } */

int CetakHarga(InfoStatistik S, DaftarHarga ListHarga[]);
/* { Fungsi CetakHarga menerima masukkan data pesan dalam S serta ListHarga dari masing-masing jenis kata, dan mengeluarkan biaya pengiriman suatu pesan } */

/* ***** AKHIR FUNGSI ANTARA MODUS KIRIM ***** */

boolean Kirim (DataPengguna NamaUser, KamusKarakter k, Statistik *S, DaftarHarga ListHarga[]);
/* { Fungsi Kirim mengirimkan pesan pengguna apabila nama pengirim dan penerima telah terdaftar di NamaUserdan seluruh isi pesan terdefinisi di
 kamus X. Pengiriman dilakukan apabila nama pengguna telah terdaftar, isi pesan telah diverifikasi validitasnya. Apabila pengiriman berhasil,
 fungsi Kirim akan mengeluarkan true. } */

void ListStatistikTulis(Statistik S, int Mode);
/* I.S. S terdefinisi
   F.S  Menampikan List Statistik Penulisan ke layar */

void HitungHarga(Statistik S);
/* { I.S. : S boleh kosong }
   { F.S. : Mencetak info harga dari pesan terakhir yang dikirimkan jika S tidak kosong. Jika Statistik kosong, cetak ÅgTidak ada pesan yang dikirimkan.Åh } */

/* *** MODUS B *** */
void KarakterToMorse (char Y[]);
/* I.S. File katanya ada, isinya dijamin dapat dikonversi
   F.S. Semua kata dalam pesan masukan terkonversi menjadi morse dan pesan yang terkonversi tersimpan di file eksternal di direktori Sending
*/

void TransmitPesan(Statistik *S, StatKirim *Sx);
/* { I.S. S terdefinisi, Sx terdefinisi} */
/* { F.S. Mentransmisikan semua pesan dari folder Outbox ke folder Inbox, dengan mensimulasikan
waktu pengiriman sekitar 30 detik serta priority queue } */

void ListStatistikKirim(StatKirim Sx);
/* I.S. Sx terdefinisi
   F.S  Menampikan List Statistik Pengiriman ke layar */

/* *** MODUS C *** */

void MorseToKarakter ();
/* I.S. File Kode Morse ada, isinya dijamin dapat dikonversi
   F.S. Semua kode morse masukan terkonversi menjadi karakter dan pesan yang terkonversi tersimpan di file eksternal di direktori Inbox
*/

/* *** FUNGSI ANTARA KarakterToPesan *** */
kaddress AddressSimbol(KamusKarakter X, char Y[]);
/* Mengembalikan address simbol bila kata Y ada di dalam kamus karakter X (kata merupakan representasi alfabet dari suatu simbol) */
/* Mengembalikan '\0' bila tidak ada */

void KarakterToPesan (KamusKarakter X, char Y[]);
/* I.S. Karakter dalam pesan terdefinisi, kamus karakter X terdefinisi
   F.S. Karakter terkonversi menjadi pesan sesuai dengan kamus karakter X dan menampilkannya ke layar
*/

void ListPesan (Statistik *S, StatTerima *Sx);
/* I.S. S terdefinisi, Sx terdefinisi
   F.S. Konversi pesan dari kode morse ke dalam karakter tersimpan ke dalam suatu file eksternal
   pada direktori Inbox (dari direktori Sending). Kemudian, menampilkan ke layar nama file dari pesan-
   pesan tersebut
*/

void BacaPesan (Statistik *S, KamusKarakter X, StatTerima *Sx);
/* I.S. S terdefinisi, Kamus Karakter X terdefinisi, Sx terdefinisi
   F.S. Membaca ID pesan, kemudian membuka pesan yang dimaksud jika ID pesan terdefinisi. Mengubah Status(S)
   dari belum dibaca menjadi sudah dibaca
*/

void HapusPesan (Statistik *S);
/* I.S. S terdefinisi
   F.S. Masukan ID pesan yang ingin dihapus pengguna terbaca, jika terdefinisi maka pesan dihapus dari direktori Inbox
   dan status pesan diubah menjadi "deleted"
*/

void ListStatistikTerima(StatTerima Sx);
/* I.S. Sx terdefinisi
   F.S  Menampikan List Statistik Penerimaan ke layar */

/* *** MODUS D *** */
boolean SearchKarakterSimbol(KamusKarakter X, char Y[]);
/* Fungsi SearchKamus menerima masukkan tabel X dan KamusKarakter Y kemudian mengembalikan true apabila Y merupakan anggota X) */

boolean IsUserValid (DataPengguna user,char nama[]);
/* Mengembalikan true bila user tidak terdaftar) */
/* Mengembalikan false bila user sudah terdaftar */

void CetakDaftarHarga(DaftarHarga *ListHarga);
// { I.S. : ListHarga terdefinisi }
// { F.S. : Mencetak daftar harga dari masing-masing jenis kata ke layar, kemudian mengubah bila diinginkan }

void TambahKamus(KamusKarakter *X);
// { I.S. : X terdefinisi, X mungkin kosong,tidak dilakukan pengecekan }
// { F.S. : Menambahkan karakter baru kedalam X (Karakter beserta representasinya dalam mesin kata) }

void HapusKamus(KamusKarakter *X);
// { I.S. : X terdefinisi, X mungkin kosong }
// { F.S. : Menghapus karakter yang sudah terdefinisi dalam X. Jika X kosong, cetak ÅgTidak ada karakter dalam kamus.Åh}

void KDelX(KamusKarakter *L, char X);
/* { I.S. list tidak kosong } */
/* { F.S. elemen X di list dihapus }
{ dan alamat elemen tersebut di-dealokasi } */

#endif
/* All Rights Reserved 2012 */
