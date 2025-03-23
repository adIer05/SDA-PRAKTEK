#ifndef COMBO_H
#define COMBO_H

#include "linked.h"
#include "queue.h"
#include "stack.h"

typedef struct {
    ElmtList *head;  // Head untuk SLL
} SLL;

typedef stack Stack;
typedef queue Queue;  

//Fungsi SLL
void Create_List(SLL *L);
address search(SLL L, infotype X);
void isi_List(SLL *L, infotype X);
void ins_Last(SLL *L, infotype X);
void ins_First(SLL *L, infotype X);
void ins_After(SLL *L, infotype X);
void del_First(SLL *L);
void print_List(SLL L);

//Fungsi Stack
void Create_Stack(Stack *S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void print_Stack(Stack S);

//Fungsi Queue
void Create_queue(Queue *Q);
void Enqueue(Queue *Q, infotype X);
void Dequeue(Queue *Q, infotype *X);
void print_Queue(Queue Q);

//MENU
void mainMenu();
void menu_SLL();
void menu_Stack();
void menu_Queue();
void menu_TambahData(SLL *L);  //SUBSUBMENU SLL

#endif