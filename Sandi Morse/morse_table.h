#ifndef MORSE_TABLE_H
#define MORSE_TABLE_H

#include "BT.h"

typedef struct {
    char letter;
    const char* code;
} MorseMap;

extern MorseMap morseTable[];
extern int morseTableSize;

/*** MAIN FUNCTION ***/
void buildMorseTree(Node** root);
void stringToMorse(const char* input);
void morseToString(Node* root, const char* morseInput);
void convertFile(Node* root, const char* inputFile, const char* outputFile);


#endif
