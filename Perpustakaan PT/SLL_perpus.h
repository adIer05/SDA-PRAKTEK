#ifndef PT_H
#define PT_H

#include "linked.h"
#include "queue.h"
#include "stack.h"

typedef ElmtList list;

typedef struct {
	char judul[50];
	int stok;
	queue antrian;
} Buku;

typedef struct {
	char Nama[21];
	int prioritas; // 3 = dosen, 2 = mahasiswa, 1 = umum
} Anggota;

#define MAX_BUKU 10
extern Buku daftarBuku[MAX_BUKU];
extern int jumlahBuku;
extern stack undoAktivitas;

 
//yang akan menentukan urutan dari peminjam berdasarkan identitasnya
int getPrioritas(char * status);

//mencari indeks buku
int cariBuku(char * judul);

//untuk menambahkan daftar buku
void tambahBuku(char * judul, int stok);

//untuk menambahkan daftar peminjam secara enqueue berdasarkan prioritas
void daftarPeminjam(char * nama, char * status, char * judulBuku);

//proses peminjaman
void prosesPeminjaman(char * judulBuku);

//proses pengembalian
void prosesPengembalian(char * judulBuku);

// Undo aktivitas terakhir
void undo();

void runSLLMode();

#endif