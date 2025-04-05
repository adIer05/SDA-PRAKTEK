#include "kota.h"

void insLast (address *C, char name[]){
	address K = (address) malloc(sizeof(ElmtList));
	
	if (K != NULL){
		strcpy(K->nama, name);
		K->next = NULL;
	}
	
	if (*C == NULL){
		*C = K;
	} else {
		Ins_Akhir(C, K);	
	}
}

void insLastKota (anKota *C, char nama[]){
	anKota K = (anKota) malloc(sizeof(Kota));
	if (K != NULL){
		strcpy(K->kota, nama);
		K->orang = NULL;
		K->next = NULL;
		
		if (*C == NULL){
			*C = K;
		} else {
			anKota last = *C;
			while (last->next != NULL){
				last = last->next;
			}
			last->next = K;
		}
	}
}

void tampiList (anKota C){
	anKota K = C;
	while (K != NULL){
		printf("%s -", K->kota);
		
		address O = K->orang;
		while (O != NULL){
			printf(" -> %s", O->nama);
			O = O->next;
		}
		
		K = K->next;
		printf("\n");
	}
}
