#include "DLL_perpus.h"


// Membuat node baru
void Create_node(address *newNode) {
    *newNode = (address)malloc(sizeof(ElmtList));
    if (*newNode == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
    (*newNode)->next = NULL;
    (*newNode)->prev = NULL;
}

// Mengisi node dengan data
void Isi_node(address *newNode, infotype data) {
    (*newNode)->info = data;
}

// Membuat antrian kosong
void Create_queue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

// Menambah data ke antrian (enqueue)
void ENQueue(Queue *q, infotype data) {
    address newNode;
    Create_Node(&newNode);
    Isi_Node(&newNode, data);

    if (q->tail == NULL) {  // Antrian kosong
        q->head = q->tail = newNode; // Node pertama
    } else {  // Menambahkan ke akhir antrian
        q->tail->next = newNode;
        newNode->prev = q->tail;
        q->tail = newNode;
    }
}

void Insert_Queue(Queue *q, address P, address before) {
    if (before == NULL) {
        P->next = q->head;
        if (q->head != NULL) q->head->prev = P;
        q->head = P;
        if (q->tail == NULL) q->tail = P;
    } else {
        P->next = before->next;
        P->prev = before;
        if (before->next != NULL)
            before->next->prev = P;
        before->next = P;
        if (q->tail == before) q->tail = P;
    }
}

// Menghapus data dari antrian (dequeue)
void DEQueue(Queue *q, infotype *data) {
    if (is_Empty(*q)) {
        printf("Antrian kosong!\n");
        return;
    }

    address temp = q->head;
    *data = temp->info;

    if (q->head == q->tail) {  // Antrian hanya punya satu elemen
        q->head = q->tail = NULL;
    } else {  // Menangani penghapusan dari depan antrian
        q->head = q->head->next;
        q->head->prev = NULL;
    }

    free(temp);  // Hapus node yang sudah dikeluarkan
}

// Mengecek apakah antrian kosong
int is_Empty_Queue(Queue q) {
    return (q.head == NULL);
}

// Menghapus node dari antrian berdasarkan data
void Remove_Node(Queue *q, infotype data) {
    address curr = q->head;
    while (curr != NULL) {
        if (curr->info == data) {
            if (curr == q->head) {  // Hapus dari awal
                q->head = curr->next;
                if (q->head != NULL) q->head->prev = NULL;
            } else if (curr == q->tail) {  // Hapus dari akhir
                q->tail = curr->prev;
                if (q->tail != NULL) q->tail->next = NULL;
            } else {  // Hapus dari tengah
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            free(curr);  // Hapus node
            return;
        }
        curr = curr->next;
    }
    printf("Node dengan data %d tidak ditemukan.\n", data);
}

// Membuat stack kosong
void Create_stack(Stack *s) {
    s->top = NULL;
}

// Menambah data ke stack (push)
void Push(Stack *s, infotype data) {
    address newNode;
    Create_Node(&newNode);
    Isi_Node(&newNode, data);

    // Menambahkan node baru di atas stack
    if (s->top == NULL) {
        s->top = newNode;
    } else {
        newNode->next = s->top;
        s->top->prev = newNode;
        s->top = newNode;
    }
}

// Menghapus data dari stack (pop)
void Pop(Stack *s, infotype *data) {
    if (is_Empty_Stack(*s)) {
        printf("Stack kosong!\n");
        return;
    }

    address temp = s->top;
    *data = temp->info;
    
    // Memperbarui pointer top ke node berikutnya
    s->top = s->top->next;
    if (s->top != NULL) s->top->prev = NULL;

    free(temp);  // Hapus node
}

// Mengecek apakah stack kosong
int is_Empty_Stack(Stack s) {
    return (s.top == NULL);
}

void Create_ListBuku(ListBuku *LB) {
    LB->head = LB->tail = NULL;
}

BukuAddress Cari_Buku(ListBuku LB, char *judul) {
    BukuAddress p = LB.head;
    while (p != NULL) {
        if (strcmp(p->judul, judul) == 0) return p;
        p = p->next;
    }
    return NULL;
}

void Tambah_Buku(ListBuku *LB, char *judul, int stok) {
    BukuAddress newBuku = (BukuAddress)malloc(sizeof(BukuNode));
    strcpy(newBuku->judul, judul);
    newBuku->stok = stok;
    Create_Queue(&newBuku->antrian);
    newBuku->next = NULL;
    newBuku->prev = LB->tail;

    if (LB->head == NULL) {
        LB->head = LB->tail = newBuku;
    } else {
        LB->tail->next = newBuku;
        LB->tail = newBuku;
    }
}

int GetPrioritas(char *status) {
    if (strcmp(status, "dosen") == 0) return 3;
    if (strcmp(status, "mahasiswa") == 0) return 2;
    return 1;
}

void daftarPeminjam(ListBuku *LB, Stack *undoAktivitas, char *nama, char *status, char *judulBuku) {
    BukuAddress B = Cari_Buku(*LB, judulBuku);
    if (B == NULL) {
        printf("Buku tidak ditemukan.\n");
        return;
    }

    Anggota p;
    strcpy(p.Nama, nama);
    p.prioritas = GetPrioritas(status);
    infotype kode = p.prioritas * 1000 + ((uintptr_t)B % 1000);

    address prev = NULL, curr = B->antrian.head, PNew;
    Create_Node(&PNew);
    Isi_Node(&PNew, kode);

    while (curr != NULL && curr->info / 1000 >= p.prioritas) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        Ins_Awal(&B->antrian.head, PNew);
    } else {
        InsertAfter(&prev, PNew);
    }

    if (B->antrian.tail == NULL || B->antrian.tail == prev) {
        B->antrian.tail = PNew;
    }

    printf("%s (%s) masuk antrian pinjam '%s'\n", nama, status, B->judul);
    push(undoAktivitas, kode);
}

void prosesPeminjaman(BukuAddress B) {
    if (B == NULL || B->stok <= 0 || is_Empty(B->antrian)) {
        printf("Tidak bisa memproses peminjaman.\n");
        return;
    }
    infotype data;
    DeQueue(&B->antrian, &data);
    B->stok--;
    int prior = data / 1000;
    printf("Peminjaman berhasil: prioritas %d mendapat '%s'\n", prior, B->judul);
}

void prosesPengembalian(BukuAddress B) {
    if (B == NULL) return;
    B->stok++;
    printf("Buku '%s' dikembalikan. Stok sekarang: %d\n", B->judul, B->stok);

    if (!is_Empty(B->antrian)) {
        printf("Menunggu berikutnya...\n");
        prosesPeminjaman(B);
    }
}

void undo(Stack *undoAktivitas, ListBuku *LB) {
    if (is_Empty_Stack(*undoAktivitas)) {
        printf("Tidak ada aktivitas untuk dibatalkan.\n");
        return;
    }

    infotype kode;
    pop(undoAktivitas, &kode);
    int prior = kode / 1000;
    int ptr_code = kode % 1000;

    BukuAddress B = LB->head;
    while (B != NULL) {
        if (((uintptr_t)B % 1000) == ptr_code) break;
        B = B->next;
    }

    if (B == NULL) {
        printf("Buku tidak ditemukan untuk undo.\n");
        return;
    }

    address *pp = &B->antrian.head;
    while (*pp != NULL) {
        if ((*pp)->info == kode) {
            address hapus = *pp;
            if (hapus == B->antrian.head) B->antrian.head = hapus->next;
            else if (hapus == B->antrian.tail) B->antrian.tail = hapus->prev;

            if (hapus->prev) hapus->prev->next = hapus->next;
            if (hapus->next) hapus->next->prev = hapus->prev;

            DeAlokasi(&hapus);
            break;
        }
        pp = &(*pp)->next;
    }

    printf("Undo berhasil. Peminjam dengan prioritas %d dihapus dari '%s'\n", prior, B->judul);
}

void runDLLmode(){
	ListBuku perpustakaan;
    stack undoStack;
    Create_ListBuku(&perpustakaan);
    Create_Stack(&undoStack);

    int menu;
    char judul[50], nama[21], status[15];

    do {
        printf("\n[DLL]\n");
        printf("1. Tambah Buku\n");
        printf("2. Daftar Peminjam\n");
        printf("3. Proses Peminjaman\n");
        printf("4. Pengembalian Buku\n");
        printf("5. Undo Aktivitas Terakhir\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &menu);
        getchar(); // konsumsi newline

        switch (menu) {
            case 1:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = '\0';
                int stok;
                printf("Stok: ");
                scanf("%d", &stok);
                Tambah_Buku(&perpustakaan, judul, stok);
                break;
            case 2:
                printf("Nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                printf("Status (dosen/mahasiswa/lain): ");
                fgets(status, sizeof(status), stdin);
                status[strcspn(status, "\n")] = '\0';
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = '\0';
                daftarPeminjam(&perpustakaan, &undoStack, nama, status, judul);
                break;
            case 3:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = '\0';
                prosesPeminjaman(Cari_Buku(perpustakaan, judul));
                break;
            case 4:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = '\0';
                prosesPengembalian(Cari_Buku(perpustakaan, judul));
                break;
            case 5:
                undo(&undoStack, &perpustakaan);
                break;
            case 6:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while ( != 6);
}
