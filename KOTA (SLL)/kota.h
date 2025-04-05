#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

typedef ElmtList list;

typedef struct Kota *anKota;
typedef struct Kota{
	char kota[15];
	address orang;
	anKota next;
} Kota;

void insLastKota (anKota *K, char nama[]);
void insLast (address *K, char name[]);
void tampiList (anKota K);

#endif