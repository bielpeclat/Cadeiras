#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char *pt[5] = {"bola", "gato", "casa", "azul", "estrela"};
    char *en[5] = {"ball", "cat", "house", "blue", "star"};

    char traducao[15] = "";
    int i;
    
    for (i = 0; i < 5; i++) {
        if (strcmp(argv[1], pt[i]) == 0) {
                strcpy(traducao, en[i]);
            }
    }

    if (strcmp(traducao, "") == 0) {
        printf("tradução não encontrada!\n");
    } else 
        printf("traducao (en): %s\n", traducao);

    return 0;
    
}