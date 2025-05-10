#include <stdio.h>

#include "SLL_perpus.h"
#include "DLL_perpus.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    int menu;

    do {
        printf("\n[Menu Utama]\n");
    	printf("1. SLL & ARRAY\n");
    	printf("2. DLL\n");
    	printf("0. Keluar\n");
    	printf("Pilih mode: ");
        scanf("%d", &menu);  // Membaca pilihan dari pengguna
        getchar();  // Menghapus newline yang tertinggal

        switch (menu) {
            case 1:
                // Mengarah ke mode Single Linked List
                printf("\nMasuk ke Mode Single Linked List & Array\n");
                runSLLMode();  // Menjalankan fungsi mode SLL
                break;
            
            case 2:
                // Mengarah ke mode Double Linked List
                printf("\nMasuk ke Mode Double Linked List (Queue)\n");
                runDLLmode();  // Menjalankan fungsi mode DLL
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (menu != 0); 
    return 0;
}