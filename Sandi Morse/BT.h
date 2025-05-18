#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node {
    char data; 
    struct Node *left;  // (O)
    struct Node *right; // (X)
} Node;

Node* createNode(char data);
void insertMorse(Node** root, char letter, const char* code);
void inorderTraversal(Node* root);
char searchMorse(Node* root, const char* code);
void destroyTree(Node* root);

#endif
