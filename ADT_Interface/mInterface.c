/* NIM/Nama :   1. Antonius Perdana Renardy / 13211143
                2. Daniel / 13511068
                3. Dicky Cahyadi / 13211110
                4. Iskandar Setiadi / 13511073
                5. Michael Aditya Mursalim / 13211066   */
/* Nama file : mInterface.c */
/* Topik : ADT Sistem Telegram */
/* Tanggal : November 2012 */
/* Deskripsi : Membuat Tugas Besar IF2030 - Sistem Telegram */

/* Driver File ADT Load File */
#include "ADT_Interface.h"
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
	boolean IsExit = false;
	char BurstMode;
	char SubMode;
	char SubBurstMode;
    /* Algoritma */
    Opening();
	do
	{
	    SubMode = '0';
        MainMenu();
	    scanf("\n%c",&BurstMode);
       // system("clear");
	    switch(toupper(BurstMode))
	    {
	        case 'A':
                     do
                    {
                     SubMode = 'A';
                     ModePenulisan();
                     scanf("\n%c",&SubBurstMode);
                   //  system("clear");
                     switch(SubBurstMode)
                     {
                        case '1':
                                        /* Asumsi Pesan berisikan setidaknya 1 buah kata */
                                        break;
                        case '2':
                                        break;
                        case '7':
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'A');
                     break;
            case 'B':
                     do
                    {
                     SubMode = 'B';
                     ModePengiriman();
                     scanf("\n%c",&SubBurstMode);
                    // system("clear");
                     switch(SubBurstMode)
                     {
                        case '1':
                                        break;
                        case '7':
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'B');
                     break;
            case 'C':
                     do
                    {
                     SubMode = 'C';
                     ModePenerimaan();
                     scanf("\n%c",&SubBurstMode);
                    // system("clear");
                     switch(SubBurstMode)
                     {
                        case '1':
                                        break;
                        case '2':
                                        break;
                        case '3':
                                        break;
                        case '7':
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'C');
                     break;
            case 'D':
                     SubMode = 'D';
                     do
                    {
                     ModePengaturan();
                     scanf("\n%c",&SubBurstMode);
                    // system("clear");
                     switch(SubBurstMode)
                     {
                         case '1':
                                        break;
                         case '2':
                                        break;
                         case '3':
                                        break;
                         case '4':
                                        break;
                         case '5':
                                            break;
                        case '6':
                                            break;
                        case '7' :
                                        break;
                        case '8':       SubMode = '0';
                                        break;
                        case '9':       SubMode = '0';
                                        IsExit = true;
                                        break;
                        default: printf("                            Masukkan Anda Salah!\n");
                                            break;
                     }
                    } while (SubMode == 'D');
                     break;
            case 'E':
                     IsExit = true;
                     break;
	        default: printf("                            Masukkan Anda Salah!\n");
                     break;
	    }

	} while (!IsExit);
    Closing();


return 0;
}
/* All Rights Reserved 2012 */
