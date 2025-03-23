#include<stdlib.h>
#include "combo.h"

//Fungsi SLL
void Create_List(SLL *L){
	L->head = NULL;
}

address search(SLL L, infotype X){
	address PNew;
	
	Create_Node(&PNew);
	if (PNew != NULL){
		PNew->info= X;
		PNew->next = NULL;
	}
	
	Search(L.head, X);
}

void isi_List(SLL *L, infotype X){
	address PNew;
	
	Create_Node(&PNew);
	if (PNew != NULL){
		PNew->info= X;
		PNew->next = NULL;
	}
	
	Isi_Node(&L->head, X);
}

void ins_Last(SLL *L, infotype X){
	address PNew;
	
	Create_Node(&PNew);
	if (PNew != NULL){
		PNew->info= X;
		PNew->next = NULL;
	}
	
	Ins_Akhir(&L->head, PNew);
}

void ins_First(SLL *L, infotype X){
	address PNew;
	
	Create_Node(&PNew);
	if (PNew != NULL){
		PNew->info= X;
		PNew->next = NULL;
	}
	
	Ins_Awal(&L->head, PNew);
}

void ins_After(SLL *L, infotype X){
	address PNew;
	
	Create_Node(&PNew);
	if (PNew != NULL){
		PNew->info= X;
		PNew->next = NULL;
	}
	InsertAfter(&L->head, PNew);
}

void del_First(SLL *L){
	infotype X;
	
	if(L->head != NULL){
		Del_Awal (&L->head, &X);
	}
}

void print_List(SLL L){
	Tampil_List(L.head);
}

//Fungsi Stack
void Create_stack(stack *S){
    Create_Stack(S);  
}

void Push(Stack *S, infotype X){
	push(S, X);
}

void Pop(Stack *S, infotype *X){
	pop(S,X);
}

void print_Stack(Stack S){
	Tampil_Stack(S);
}

//Fungsi Queue
void Create_queue(Queue *Q){
	Create_Queue(Q);
}

void Enqueue(Queue *Q, infotype X){
	EnQueue(Q, X);
}

void Dequeue(Queue *Q, infotype *X){
	DeQueue(Q, X);
}

void print_Queue(Queue Q){
	Tampil_Queue(Q);
}

// MAIN MENU
void mainMenu() {
    int pilihan;
    do {
        system("cls");
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Single Linked List\n");
        printf("2. Stack\n");
        printf("3. Queue\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: menu_SLL(); break;
            case 2: menu_Stack(); break;
            case 3: menu_Queue(); break;
            case 4: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);
}

// LINKED LIST MENU
void menu_SLL() {
    static SLL L;  // Tetap menyimpan data di antara panggilan
    int pilihan, X;

    Create_List(&L);  // Pastikan list hanya dibuat sekali

    do {
        system("cls");
        printf("\n=== Menu Linked List ===\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampilkan List\n");
        printf("4. Kembali ke Menu Utama\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                menu_TambahData(&L); // Kirim pointer agar perubahan tersimpan
                break;
            
            case 2:
                if (L.head != NULL) {
                    printf("Menghapus elemen pertama...\n");
                    del_First(&L);
                } else {
                    printf("List kosong, tidak bisa dihapus!\n");
                }
                break;

            case 3:
                puts("Isi List:");
                print_List(L);
                break;

            case 4:
                return;  // Langsung kembali ke main menu tanpa tumpukan rekursi

            default:
                printf("Pilihan tidak valid!\n");
        }
        printf("\nTekan Enter untuk kembali ke menu...");
        getchar(); getchar();
    } while (pilihan != 4);
}

// STACK MENU
void menu_Stack() {
    static Stack s;  // Stack tetap menyimpan data di antara panggilan
    int pilihan, X;

    Create_Stack(&s);

    do {
        system("cls");
        printf("\n=== Menu Stack ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Kembali ke Menu Utama\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Nilai: ");
                scanf("%d", &X);
                Push(&s, X);
                break;

            case 2:
                if (!is_Empty(s)) {
                    Pop(&s, &X);
                    printf("Elemen yang di-pop: %d\n", X);
                } else {
                    printf("Stack kosong!\n");
                }
                break;

            case 3:
                print_Stack(s);
                break;

            case 4:
                return;  // Langsung kembali ke main menu

            default:
                printf("Pilihan tidak valid!\n");
        }
        printf("\nTekan Enter untuk kembali ke menu...");
        getchar(); getchar();
    } while (pilihan != 4);
}

// QUEUE MENU
void menu_Queue() {
    static queue antrian[MAX_LOKET];  // Antrian tetap menyimpan data
    int X, QueueNumber = 0, pilihan, loket;

    for (int i = 0; i < MAX_LOKET; i++) {
        Create_Queue(&antrian[i]);
    }

    do {
        system("cls");
        printf("\n=== MENU ANTRIAN ===\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Kembali Ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                QueueNumber++;
                printf("Pilih loket (1 - %d): ", MAX_LOKET);
                scanf("%d", &loket);
                if (loket >= 1 && loket <= MAX_LOKET) {
                    EnQueue(&antrian[loket - 1], QueueNumber);
                    printf("Nomor antrian %d masuk ke loket %d\n", QueueNumber, loket);
                } else {
                    printf("Loket tidak valid!\n");
                }
                break;

            case 2:
                printf("Pilih loket yang akan memproses antrian (1 - %d): ", MAX_LOKET);
                scanf("%d", &loket);
                if (loket >= 1 && loket <= MAX_LOKET) {
                    if (!is_Empty(antrian[loket - 1])) {
                        DeQueue(&antrian[loket - 1], &X);
                        printf("Nomor antrian %d telah diproses di loket %d.\n", X, loket);
                    } else {
                        printf("Antrian di loket %d kosong!\n", loket);
                    }
                } else {
                    printf("Loket tidak valid!\n");
                }
                break;

            case 3:
                for (int i = 0; i < MAX_LOKET; i++) {
                    printf("Antrian di Loket %d: ", i + 1);
                    Tampil_Queue(antrian[i]);
                }
                break;

            case 4:
                return;  // Kembali ke main menu

            default:
                printf("Pilihan tidak valid! Coba lagi.\n");
        }
        printf("\nTekan Enter untuk kembali ke menu...");
        getchar(); getchar();
    } while (pilihan != 4);
}

// TAMBAH DATA MENU
void menu_TambahData(SLL *L) {
    address pBef;
    int pilihan, X;

    do {
        system("cls");
        printf("\n=== Menu Tambah Data ===\n");
        printf("1. Tambah Awal\n");
        printf("2. Tambah Akhir\n");
        printf("3. Tambah di X\n");
        printf("4. Kembali ke Menu SLL\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Nilai: ");
                scanf("%d", &X);
                ins_First(L, X);
                break;

            case 2:
                printf("Nilai: ");
                scanf("%d", &X);
                ins_Last(L, X);
                break;

            case 3:
                printf("Target: ");
                scanf("%d", &X);
                pBef = Search(L->head, X);
                if (pBef != NULL) {
                    int newx;
                    printf("Input nomor: ");
                    scanf("%d", &newx);
                    ins_After(L, newx);
                } else {
                    printf("Target tidak ditemukan!\n");
                }
                break;

            case 4:
                return;  // Kembali ke menu_SLL

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);
}