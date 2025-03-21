#include <stdio.h>
#include "stack.h"

int main() {
    int decimal;
    
    printf("bilangan desimal: ");
    scanf("%d", &decimal);
    
    if (decimal < 0) {
        printf("Bilangan harus positif!\n");
        return 1;
    }
    
    DectoBiner(decimal);
    return 0;
}
