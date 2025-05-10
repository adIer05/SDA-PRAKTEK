#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

typedef ElmtList list;
typedef queue Queue;
typedef stack Stack;

typedef struct {
    char Nama[21];
    int prioritas;
} Anggota;

typedef struct BukuNode *BukuAddress;
typedef struct BukuNode {
    char judul[50];
    int stok;
    Queue antrian;
    BukuAddress next;
    BukuAddress prev;
} BukuNode;

typedef struct {
    BukuAddress head;
    BukuAddress tail;
} ListBuku;


void Create_node(address *newNode);
void Isi_node(address *newNode, infotype data);

void Create_queue(Queue *q);
void Insert_Queue(Queue *q, address P, address before);
void ENQueue(Queue *q, infotype data);
void DEQueue(Queue *q, infotype *data);
int is_Empty_Queue (Queue q);
void Remove_Node(Queue *q, infotype data);

void Create_stack(Stack *s);
void Push(Stack *s, infotype data);
void Pop(Stack *s, infotype *data);
int is_Empty_Stack(Stack s);

void Create_ListBuku(ListBuku *LB);
void Tambah_Buku(ListBuku *LB, char *judul, int stok);
int GetPrioritas(char *status);
void daftarPeminjam(ListBuku *LB, Stack *undoAktivitas, char *nama, char *status, char *judulBuku) ;
void prosesPeminjaman(BukuAddress B);
void prosesPengembalian(BukuAddress B);
void undo(Stack *undoAktivitas, ListBuku *LB);

void runDLLmode();
#endif 
