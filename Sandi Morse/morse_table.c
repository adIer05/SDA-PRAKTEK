#include "morse_table.h"

MorseMap morseTable[] = {
    {'A', "O"},    {'B', "X"},  {'I', "OO"},  {'T', "OX"},   {'E', "XO"},
    {'M', "XX"},  {'N', "OOO"},   {'D', "OOX"},  {'G', "OXO"},    {'K', "OXX"},
    {'O', "XOO"},  {'R', "XOX"},    {'S', "XXO"},    {'U', "XXX"}, {'W', "OOOO"},
    {'C', "OOOX"},  {'F', "OOXO"},  {'H', "OOXX"},   {'J', "OXOO"},   {'L', "OXOX"},
    {'P', "OXXO"},   {'Q', "OXXX"},  {'V', "XOOO"},   {'X', "XOOX"},  {'Y', "XOXO"},
    {'Z', "XOXX"}, {'1', "XXOO"}, {'2', "XXOX"}, {'3', "XXXO"},{'4', "XXXX"}, 
	{'5', "OOOXX"}, {'6', "OXOOO"}, {'7', "OXXOX"}, {'8', "OXXXO"},
    {'9', "XOOOO"}, {'0', "XOXOO"}, {' ', "XXXXX"}
};

int morseTableSize = sizeof(morseTable) / sizeof(morseTable[0]);

