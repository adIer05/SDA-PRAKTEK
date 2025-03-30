#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kota.h"

#define MAX_KOTA 20

int main() {
	kota listKota[MAX_KOTA]; 
	int jmlKota = 0;
	char kota[15], nama[15], lanjut;
	
	do {
		// Tambah Kota
    	printf("Masukkan nama kota: ");
    	scanf("%[^\n]", listKota[jmlKota].kota);
    	getchar();
    	listKota[jmlKota].head = NULL; 
    	jmlKota++;
    
		printf("Tambah Kota? (y/n): ");
		scanf(" %c", &lanjut);
		getchar();
	}while (lanjut == 'y' || lanjut == 'Y');
	
	
    do {
        printf("\nMasukkan nama kota: "); //untuk menambahkan orang
        scanf(" %[^\n]", kota);
        getchar();

        printf("Masukkan nama orang: ");
        scanf(" %[^\n]", nama);
        getchar();

        // Cari kota yang sesuai
        int ditemukan = 0;
        for (int i = 0; i < jmlKota; i++) {
            if (strcmp(listKota[i].kota, kota) == 0) {
                addName(&listKota[i], nama);
                ditemukan = 1;
                printf("Nama '%s' berhasil ditambahkan ke kota '%s'!\n", nama, kota);
                break;
            }
        }
        
		if (!ditemukan) {
            printf("Kota tidak ditemukan!\n");
    	}
    	
        printf("Tambah nama? (y/n): ");
        scanf(" %c", &lanjut);
        getchar();
    } while (lanjut == 'y' || lanjut == 'Y');

    // Tampilkan Data
    printData(listKota, jmlKota);
    
	puts("Daftar Setelah di Hapus");
	// Hapus semua nama dalam kota
    for (int i = 0; i < jmlKota; i++) {
        delNamaInKota(&listKota[i]); 
    }
    
    printData(listKota, jmlKota);

    return 0;
}