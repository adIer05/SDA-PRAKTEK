#include "queue.h"

void Create_Queue (queue *q){
	q->head = NULL;
	q->tail = NULL;
} 

bool is_Empty (queue q){
	return (q.head == NULL);
}

void DeQueue (queue *q, infotype *X){
	Del_Awal (&q->head, X);
}

void EnQueue (queue *q, infotype X){
	address PNew;
    Create_Node(&PNew);
    if (PNew != NULL) {
        Isi_Node(&PNew, X);
        if (is_Empty(*q)) {
            q->head = PNew;
            q->tail = PNew;
        } else {
            Ins_Akhir(&q->tail, PNew);
            q->tail = PNew;
        }
    }
}

void Tampil_Queue (queue q){
	Tampil_List(q.head);
}