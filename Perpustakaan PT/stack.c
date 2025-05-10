#include "stack.h"

void Create_Stack(stack *l) {
    l->top = NULL;
}

void del_Stack(stack *l) {
    infotype temp;
    while (l->top != NULL) {
        Del_Awal(&(l->top), &temp);
    }
}

bool is_Empty(stack l) {
    return l.top == NULL;
}

void push(stack *l, int newL) {
    address PNew;
    Create_Node(&PNew);
    if (PNew != NULL) {
        Isi_Node(&PNew, newL);
        Ins_Awal(&(l->top), PNew);
    } else {
        printf("Gagal menambahkan elemen, memori penuh!\n");
    }
}

void pop(stack *l, int *value) {
    if (l->top != NULL) {
        Del_Awal(&(l->top), value);
    } else {
        printf("Stack kosong, tidak bisa pop!\n");
    }
}

bool peek(stack *l, int *value) {
    if (l->top != NULL) {
        *value = l->top->info;
        return true;
    }
    return false;
}

void Tampil_Stack(stack l) {
    stack temp = l;
    int value;
    
    printf("Angka: ");
    while (!is_Empty(temp)) {
        pop(&temp, &value);
        printf("%d", value);
    }
    printf("\n");
}
