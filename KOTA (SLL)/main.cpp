#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kota.h"

int main(){
	anKota K = NULL;
	char kota[15], nama[15], lanjut;
 
	do {	
		printf("Masukkan nama kota: ");
    	scanf("%[^\n]", kota);
    	getchar();
    	
    	insLastKota(&K, kota);
    	
    	//cari pointer kota yang baru ditambah
    	anKota current = K;
    	while (current->next != NULL){
    		current = current->next;
		}
    	
    	do{
    		printf("Masukkan nama orang di kota %s: ", current->kota);
    		scanf("%[^\n]", nama);
    		getchar();
    		
    		insLast(&current->orang, nama); 
    		printf("Nama '%s' berhasil ditambahkan ke kota '%s'\n", nama, current->kota);
    		
    		printf("Tambah orang lagi di kota %s? (y/n): ", current->kota);
    		scanf("%c", &lanjut);
    		getchar();
		} while (lanjut == 'y' || lanjut == 'Y');
		
		//Tambah kota
		printf("Tambah kota lagi? (y/n): ");
		scanf("%c", &lanjut);
    	getchar();
	} while (lanjut == 'y' || lanjut == 'Y');

	puts("=== Daftar Kota dan Orang ===");
	tampiList(K);

}