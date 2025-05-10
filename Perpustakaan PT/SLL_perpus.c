#include <stdio.h>

#include "SLL_perpus.h"
#include "stack.h"

Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;
stack undoAktivitas;


//yang akan menentukan urutan dari peminjam berdasarkan identitasnya
int getPrioritas(char * status){
	if (strcmp(status, "dosen") == 0) return 3;
	if (strcmp(status, "mahasiswa") == 0) return 2;
	return 1;
}

//mencari indeks buku
int cariBuku(char * judul){
	for (int i = 0; i <jumlahBuku; i++){
		if (strcmp(daftarBuku[i].judul, judul) == 0) return i;
	}
	return -1;
}

//untuk menambahkan daftar buku
void tambahBuku(char * judul, int stok){
	strcpy (daftarBuku[jumlahBuku].judul, judul);
	daftarBuku[jumlahBuku].stok = stok;
	Create_Queue(&daftarBuku[jumlahBuku].antrian);
	jumlahBuku++;
}

//untuk menambahkan daftar peminjam secara enqueue berdasarkan prioritas
void daftarPeminjam(char * nama, char * status, char * judulBuku){
	int idx = cariBuku(judulBuku);
	if (idx == -1){
		printf("Buku tidak ditemukan. \n");
		return;
	}
	
	Anggota p;
	strcpy (p.Nama, nama);
	p.prioritas = getPrioritas(status);
	infotype kodeAnggota = p.prioritas * 10 + idx; //contoh encode prioritas
	
	// Masukin peminjam ke queue berdasarkan prioritas
	address prev = NULL, curr = daftarBuku[idx].antrian.head;
	address PNew;
	Create_Node(&PNew);
	Isi_Node(&PNew, kodeAnggota);
	
	while (curr != NULL && curr->info / 10 >= p.prioritas){
		prev = curr;
		curr = curr->next;
	}
	
	if (prev == NULL){
		Ins_Awal(&daftarBuku[idx].antrian.head, PNew);
	} else {
		InsertAfter(&prev, PNew);
	}
	
	if (daftarBuku[idx].antrian.tail == NULL || daftarBuku[idx].antrian.tail == prev) {
		daftarBuku[idx].antrian.tail = PNew;
	}
	
	printf("%s (%s) masuk antrian pinjam '%s'\n", nama, status, judulBuku);
	push(&undoAktivitas, kodeAnggota);
}

//proses peminjaman
void prosesPeminjaman(char * judulBuku){
	int idx = cariBuku(judulBuku);
    if (idx == -1 || daftarBuku[idx].stok <= 0 || is_Empty(daftarBuku[idx].antrian)) {
        printf("Tidak bisa memproses peminjaman.\n");
        return;
    }

    infotype data;
    DeQueue(&daftarBuku[idx].antrian, &data);
    daftarBuku[idx].stok--;

    int prior = data / 10;
    printf("Peminjaman berhasil: prioritas %d mendapat '%s'\n", prior, judulBuku);
}

//proses pengembalian
void prosesPengembalian(char * judulBuku){
	 int idx = cariBuku(judulBuku);
    if (idx == -1) return;

    daftarBuku[idx].stok++;
    printf("Buku '%s' dikembalikan. Stok sekarang: %d\n", judulBuku, daftarBuku[idx].stok);

    if (!is_Empty(daftarBuku[idx].antrian)) {
        printf("Menunggu berikutnya...\n");
        prosesPeminjaman(judulBuku);
    }
}

// Undo aktivitas terakhir
void undo() {
    if (is_Empty(undoAktivitas)) {
        printf("Tidak ada aktivitas untuk dibatalkan.\n");
        return;
    }

    int kode;
    pop(&undoAktivitas, &kode);
    int prior = kode / 10;
    int idx = kode % 10;

    // Hapus dari queue berdasarkan info
    address *pp = &daftarBuku[idx].antrian.head, prev = NULL;
    while (*pp != NULL) {
        if ((*pp)->info == kode) {
            address hapus = *pp;
            *pp = (*pp)->next;
            DeAlokasi(&hapus);
            break;
        }
        pp = &(*pp)->next;
    }

    printf("Undo berhasil. Peminjam dengan prioritas %d dihapus dari '%s'\n", prior, daftarBuku[idx].judul);
}

void runSLLMode() {
    Create_Stack(&undoAktivitas);
    int menu;
    char nama[50], status[20], judul[50];
    int stok;

    do {
        printf("\n[SLL  & Array]\n");
        printf("1. Tambah Buku\n");
        printf("2. Daftar Pinjam\n");
        printf("3. Proses Peminjaman\n");
        printf("4. Proses Pengembalian\n");
        printf("5. Undo Aktivitas\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &menu);
        getchar(); // Bersihkan newline

        switch (menu) {
            case 1:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                printf("Stok: ");
                scanf("%d", &stok);
                getchar();
                tambahBuku(judul, stok);
                break;
            case 2:
                printf("Nama Peminjam: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Status (dosen/mahasiswa/umum): ");
                fgets(status, sizeof(status), stdin);
                status[strcspn(status, "\n")] = 0;
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                daftarPeminjam(nama, status, judul);
                break;
            case 3:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                prosesPeminjaman(judul);
                break;
            case 4:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                prosesPengembalian(judul);
                break;
            case 5:
                undo();
                break;
        }
    } while (menu != 0);
}

    