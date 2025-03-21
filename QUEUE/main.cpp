#include <stdio.h>
#include "queue.h"

#define MAX_LOKET 2

int main() {
    queue antrian[MAX_LOKET];
    int X, QueueNumber = 0, pilihan, loket;

    for (int i = 0; i < MAX_LOKET; i++) {
        Create_Queue(&antrian[i]);
    }
   
    do {
        // Menampilkan menu
        printf("\n=== MENU ANTRIAN ===\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. EXIT\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                QueueNumber++; // Menambah nomor antrian
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
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid! Coba lagi.\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}
