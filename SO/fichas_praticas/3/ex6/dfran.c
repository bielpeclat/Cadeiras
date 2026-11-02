#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char *pt[5] = {"mesa", "gato", "casa", "livro", "ola"};
    char *en[5] = {"table", "chat", "maison", "livre", "bonjour"};

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
        printf("traducao (fr): %s\n", traducao);

    return 0;
    
}