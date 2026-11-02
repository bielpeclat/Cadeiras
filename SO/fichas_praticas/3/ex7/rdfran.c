#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char *pt[5] = {"mesa", "gato", "casa", "livro", "ola"};
    char *fr[5] = {"table", "chat", "maison", "livre", "bonjour"};

    char traducao[15] = "", palavra[30];
    int i;
    
    scanf("%s", palavra);

    
    for (i = 0; i < 5; i++) {
        if (strcmp(palavra, pt[i]) == 0) {
                strcpy(traducao, fr[i]);
            }
    }

    if (strcmp(traducao, "") == 0) {
        printf("tradução não encontrada!\n");
    } else 
        printf("traducao (fr): %s\n", traducao);

    return 0;
    
}