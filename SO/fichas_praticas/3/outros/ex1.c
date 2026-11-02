#include <stdio.h>

int main(void) {
    char texto[100];

    setbuf(stdout, NULL);

    printf("Escreva uma cadeia de caracteres: ");
    if (fgets(texto, sizeof(texto), stdin) == NULL) {
        printf("\nNao foi lido nada.\n");
        return 1;
    }

    printf("Escreveu: %s", texto);
    return 0;
} 
