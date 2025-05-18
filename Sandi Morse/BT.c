#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BT.h"

Node* createNode(char data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insertMorse(Node** root, char letter, const char* code){
	if (*root == NULL){
		*root = createNode(' '); //inisialisasi jika root belum ada
	}
	
	Node* curr = *root;
	for (int i = 0; code[i]; i++){
		if (code[i] == 'O'){
			if (curr->left == NULL){
				curr->left = createNode(' ');
				curr = curr->left;
			}else if (code[i] == 'X'){
				if (curr->right == NULL){
					curr->right = createNode(' ');
					curr = curr->right;
				}
			}
		}
	}
	curr->data = letter;
}

void inorderTraversal(Node* root){
	if (root != NULL){
		inorderTraversal(root->left);
		if (root->data != ' '){
			printf("%c ", root->data);
			inorderTraversal(root->right);
		}
	}
}

char searchMorse(Node* root, const char* code){
	Node* curr = root;
	for (int i = 0; code[i]; i++){
		if (curr == NULL)return '?';
		if (code[i] == 'O'){
			curr = curr->left;
		}else if (code[i] == 'X'){
			curr = curr->right;
		}
	}
}

void destroyTree(Node* root){
	if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

