#include "kota.h"

void makeNode(address *nama){
	Create_Node(nama);
}

void addName(kota *k, char *nama){
	address PNew;
	Create_Node(&PNew);
	Isi_Node(&PNew, nama);
	
	if (k->head == NULL){
		k->head = PNew;
	} else {
		Ins_Akhir(&k->head, PNew);
	}
}

void printData(kota *listKota, int jumlahKota){
	for (int i = 0; i < jumlahKota; i++) {
        printf("=== %s ===\n ", listKota[i].kota);
        printf("- Daftar Nama -\n");
        Tampil_List(listKota[i].head);
    }
}

void delNamaInKota(kota *k){
	while (k->head != NULL) {
        infotype temp;
        Del_Awal(&k->head, &temp);
    }
}

void delKota(kota *listKota, int *jmlKota, char *namaKota){
	for (int i = 0; i < *jmlKota; i++) {
        if (strcmp(listKota[i].kota, namaKota) == 0) {
            delNamaInKota(&listKota[i]);

            for (int j = i; j < *jmlKota - 1; j++) {
                listKota[j] = listKota[j + 1]; // Geser elemen ke kiri
            }
            (*jmlKota)--; // Kurangi jumlah kota
            break;
        }
    }
}