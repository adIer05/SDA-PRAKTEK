#ifndef QUEUE_H
#define QUEUE_H
#define MAX_LOKET 2

#include "linked.h"

typedef struct {
    address tail;
    address head;
} queue;

void Create_Queue (queue *q);  //membuat queue
bool is_Empty (queue q); //mengecek apakah queue kosong
void DeQueue (queue *q, infotype *X); //menghapus queue paling depan
void EnQueue (queue *q, infotype X); //menambahkan queue dari belakang
void Tampil_Queue (queue q); //menampilkan queue


#endif