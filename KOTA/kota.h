#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

typedef ElmtList list;
 
 typedef struct{
 	char kota[15];
 	address head;
 }kota;

void makeNode(address *nama); 
//Untuk membuat node baru ke dalam linked list

void addName(kota *k, char *nama);
//Untuk menambahkan nama ke dalam linked list kota tertentu

void printData(kota *listKota, int jumlahKota);
//Untuk menampilkan kota dan nama yang ada di dalamnya

void delNamaInKota(kota *k);
//Untuk menghapus semua nama dalam kota

void delKota(kota *listKota, int *jmlKota, char *namaKota);
//Untuk menghapus kota beserta semua nama yang ada di dalamnya

#endif