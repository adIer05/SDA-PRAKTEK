#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "BT.h"
#include "morse_table.h"


int main() {
    Node* root = NULL;
    buildMorseTree(&root);

    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\n\n");

    printf("Konversi:\n");
    stringToMorse("JTK Politeknik Negeri Bandung");

    printf("\nKonversi balik kode morse:\n");
    morseToString(root, ".- -.-. ..- .-..-. -... .. ... .-");

    printf("\nKonversi file input.txt → out.txt\n");
    convertFile(root, "input.txt", "out.txt");

    destroyTree(root);
    return 0;
}

/** MAIN FUNCTION**/
void buildMorseTree(Node** root) {
    for (int i = 0; i < morseTableSize; ++i) {
        insertMorse(root, morseTable[i].letter, morseTable[i].code);
    }
}

void stringToMorse(const char* input) {
    for (int i = 0; input[i]; ++i) {
        char ch = toupper(input[i]);
        for (int j = 0; j < morseTableSize; ++j) {
            if (morseTable[j].letter == ch) {
                printf("%s  ", morseTable[j].code); // dua spasi antar huruf
                break;
            }
        }
    }
    printf("\n");
}

void morseToString(Node* root, const char* morseInput) {
    char code[10];
    int idx = 0;

    for (int i = 0; ; ++i) {
        if (morseInput[i] != ' ' && morseInput[i] != '\0') {
            code[idx++] = morseInput[i];
        } else {
            code[idx] = '\0';
            if (idx > 0) {
                char ch = searchMorse(root, code);
                printf("%c", ch);
                idx = 0;
            }
            if (morseInput[i + 1] == ' ') { // dua spasi = pemisah kata
                printf(" ");
                i++;
            }
        }
        if (morseInput[i] == '\0') break;
    }
    printf("\n");
}

void convertFile(Node* root, const char* inputFile, const char* outputFile) {
    FILE* in = fopen(inputFile, "r");
    FILE* out = fopen(outputFile, "w");
    if (!in || !out) {
        printf("File error.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), in)) {
        for (int i = 0; line[i]; ++i) {
            char ch = toupper(line[i]);
            for (int j = 0; j < morseTableSize; ++j) {
                if (morseTable[j].letter == ch) {
                    fprintf(out, "%s  ", morseTable[j].code);
                    break;
                }
            }
        }
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);
    printf("Output ditulis ke %s\n", outputFile);
}