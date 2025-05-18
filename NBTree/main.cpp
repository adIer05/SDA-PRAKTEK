#include <stdio.h>
#include "nb.h"

int main() {
    Isi_Tree T;
    int pilihan, jmlNode;
    char cari, node1, node2;

    printf("Masukkan jumlah node: ");
    scanf("%d", &jmlNode);
    Create_tree(T, jmlNode);

    do {
        printf("\n============================\n");
        printf("  Menu Operasi Non Binary Tree\n");
        printf("============================\n");
        printf("1.  Traversal PreOrder\n");
        printf("2.  Traversal InOrder\n");
        printf("3.  Traversal PostOrder\n");
        printf("4.  Traversal Level Order\n");
        printf("5.  Print Tree\n");
        printf("6.  Search Node Tree\n");
        printf("7.  Jumlah Daun/Leaf\n");
        printf("8.  Mencari Level Node Tree\n");
        printf("9.  Kedalaman Tree\n");
        printf("10. Membandingkan 2 Node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("PreOrder:\n");
                PreOrder(T);
                break;
            case 2:
                printf("InOrder:\n");
                InOrder(T);
                break;
            case 3:
                printf("PostOrder:\n");
                PostOrder(T);
                break;
            case 4:
                printf("Level Order:\n");
                Level_order(T, jmlNode);
                break;
            case 5:
                PrintTree(T);
                break;
            case 6:
                printf("Masukkan node yang ingin dicari: ");
                scanf(" %c", &cari);
                if (Search(T, cari))
                    printf("Node ditemukan.\n");
                else
                    printf("Node tidak ditemukan.\n");
                break;
            case 7:
                printf("Jumlah daun: %d\n", nbDaun(T));
                break;
            case 8:
                printf("Masukkan node yang ingin diketahui levelnya: ");
                scanf(" %c", &cari);
                printf("Level dari node %c adalah %d\n", cari, Level(T, cari));
                break;
            case 9:
                printf("Kedalaman/Depth Tree adalah: %d\n", Depth(T));
                break;
            case 10: {
    			printf("Masukkan dua node untuk dibandingkan levelnya:\n");
    			scanf(" %c %c", &node1, &node2);
    			int level1 = Level(T, node1);
    			int level2 = Level(T, node2);
    
    			if (level1 == level2) {
        			printf("Kedua node berada di level yang sama.\n");
    			} else if (level1 < level2) {
       				printf("%c berada di level yang lebih tinggi dari %c.\n", node1, node2);
    			} else {
        			printf("%c berada di level yang lebih tinggi dari %c.\n", node2, node1);
    			}
    			break;
				}
            case 11:
                printf("Terima kasih!\n");
                break;
            default:
            	
                printf("Menu tidak tersedia.\n");
                break;
        }

        if (pilihan != 11) {
            printf("Klik apapun untuk melanjutkan...\n");
            getchar(); getchar(); // pause
        }
    } while (pilihan != 11);

    return 0;
}
