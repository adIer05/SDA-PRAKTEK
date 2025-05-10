#ifndef STACK_H
#define STACK_H

#include<string.h>
#include "linked.h"

typedef struct {
    address top;
} stack;

void Create_Stack(stack *l);
// Inisialisasi stack kosong

void del_Stack(stack *l);
// Menghapus semua elemen dalam stack

bool is_Empty(stack l);
// Mengecek apakah stack kosong

void push(stack *l, int newL);
// Menambahkan elemen ke stack

void pop(stack *l, int* value);
// Menghapus elemen dari stack dan mengembalikan nilainya

bool peek(stack *l, int* value);
// Mengambil nilai elemen teratas tanpa menghapusnya

void Tampil_Stack(stack l);
// Menampilkan isi stack (bilangan biner)

#endif