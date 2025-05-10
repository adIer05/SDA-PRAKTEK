/* File        : linked.c */
/* Deskripsi   : Unit untuk keperluan ADT LINKED */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include "linked.h"

boolean isEmpty(address p){
	return (p == NULL);
}

void Create_Node (address *p){
	*p = (address) malloc(sizeof (ElmtList));
	
	if(*p != NULL){
		(*p)->next = NULL;
	}
}

void Isi_Node (address *p , infotype nilai){
	if(*p != NULL){
		(*p)->info = nilai;
		(*p)->next = NULL;
	}
}

void Tampil_List (address p){
	address head = p;
	while(p != NULL){
		printf("%d -> ", p->info);
		p = p->next;
	}
	printf("NULL \n");
}

void Ins_Awal (address *p, address PNew){
	PNew->next = *p;
	*p = PNew;
}

void Ins_Akhir (address *p, address PNew){
	address last = *p;
	while(last->next != NULL){
		last = last->next;
	}
	last->next = PNew;
}

address Search (address p, infotype nilai){
	while(p != NULL){
		if(p->info == nilai){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void InsertAfter (address * pBef, address PNew){
	PNew->next = (*pBef)->next;
	(*pBef)->next = PNew;
}

void Del_Awal (address * p, infotype * X){
	*X = (*p)->info;
	address temp = *p;
	*p = (*p)->next;
	free(temp);
}

void Del_Akhir (address * p, infotype * X){
	address last = *p;
	address prevLast = NULL;
	while(last->next != NULL){
		prevLast = last;
		last = last->next;
	}
	*X = last->info;
	if(prevLast == NULL){
		*p = NULL;
	}else{
		prevLast->next = NULL;
	}
	free(last);
}

void Del_After (address * pBef, infotype * X){
	address temp = (*pBef)->next;
    *X = temp->info;
    (*pBef)->next = temp->next;
    free(temp);
}

void DeAlokasi (address * p){
	free(*p);
}