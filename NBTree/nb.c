#include <stdio.h>
#include "nb.h"

/***************************/
/* S P E S I F I K A S I */
/***************************/

int Root(Isi_Tree P) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_pr == nil) {
            return i;
        }
    }
    return nil;
}

void Create_tree(Isi_Tree X, int Jml_Node){
	for (int i = 1; i <= jml_maks; i++){
		X[i].info ='\0';
		X[i].ps_fs = nil;
		X[i].ps_nb = nil;
		X[i].ps_pr = nil;
	}
	
	for (int i = 1; i <= Jml_Node; i++){
		printf("Masukkan info node ke-%d: ", i);
		scanf(" %c", &X[i].info);
	}
	
	for (int i = 1; i <= Jml_Node; i++) {
        int fs, nb, pr;
        printf("Node %c - indeks first son: ", X[i].info);
        scanf("%d", &fs);
        printf("Node %c - indeks brother: ", X[i].info);
        scanf("%d", &nb);
        printf("Node %c - indeks parent: ", X[i].info);
        scanf("%d", &pr);

        X[i].ps_fs = fs;
        X[i].ps_nb = nb;
        X[i].ps_pr = pr;
    }
}

boolean IsEmpty (Isi_Tree P){
	for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') return false;
    }
    return true;
}

void PreOrderRec(Isi_Tree P, int idx) {
    if (idx != nil) {
    	printf("%c ", P[idx].info);
    	PreOrderRec(P, P[idx].ps_fs);
    	PreOrderRec(P, P[idx].ps_nb);
	}
}

void PreOrder(Isi_Tree P) {
    int root = Root(P);
	PreOrderRec(P, root);
	printf("\n");	
}

void InOrderRec(Isi_Tree P, int idx) {
    if (idx != nil) {
    	int kid = P[idx].ps_fs;
    	if (kid != nil){
    		InOrderRec(P, kid); //anak pertama
		}
    	printf("%c ", P[idx].info);
    	
    	if (kid != nil){
    		kid = P[kid].ps_nb; //anak kedua dan seterusnya
    		while (kid != nil) {
    			InOrderRec(P, kid);
    			kid = P[kid].ps_nb;
			}
		}
    	
	}
}

void InOrder(Isi_Tree P) {
    int root = Root(P);
    if (root != nil){
    	InOrderRec(P, root);
    	printf("\n");
	}
}

void PostOrderRec(Isi_Tree P, int idx) {
    if (idx != nil) {
        // Telusuri semua anak (first son dan brother-brothernya)
        int child = P[idx].ps_fs;
        while (child != nil) {
            PostOrderRec(P, child);
            child = P[child].ps_nb;
        }
        // Setelah semua anak selesai, cetak parent
        printf("%c ", P[idx].info);
    }
}

void PostOrder(Isi_Tree P) {
	int root = Root(P);
	if (root != nil){
    	PostOrderRec(P, root);
    	printf("\n");
	}
}

void Level_order(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0')
            printf("%c ", X[i].info);
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    printf("Seluruh Node pada Non Binary Tree:\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            printf("--> Index  ke %d:\n", i); 
			printf("-----------------------------------------------------\n"); 
			printf("info array ke %d             : %c\n", i, P[i].info); 
			printf("first son array ke %d        : %d\n", i, P[i].ps_fs);
			printf("next brother array ke %d     : %d\n", i, P[i].ps_nb); 
			printf("parent array ke %d           : %d\n", i, P[i].ps_pr); 
			printf("-----------------------------------------------------\n");
        }
    }
}

boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X)
            return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int idx = i;
            while (P[idx].ps_pr != nil) {
                idx = P[idx].ps_pr;
                level++;
            }
            return level;
        }
    }
    return -1;
}

int DepthRec(Isi_Tree P, int idx) {
    if (idx == nil) return -1;
    int maxDepth = -1;
    for (int i = P[idx].ps_fs; i != nil; i = P[i].ps_nb) {
        int d = DepthRec(P, i);
        if (d > maxDepth) maxDepth = d;
    }
    return maxDepth + 1;
}

int Depth(Isi_Tree P) {
    int root = Root(P);
    return DepthRec(P, root);
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

