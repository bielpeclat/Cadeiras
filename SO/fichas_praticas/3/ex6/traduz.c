#include <stdio.h>
#include <unistd.h>

int main () {

    char letra = 'x';

    printf("letra: ");
    scanf("%c", &letra);

    while (letra != 'x') {

        if (letra == 'i') { // ingles
            if (fork() == 0) {
                execlp("ls", "ls", NULL);
            }


        } else if (letra == 'f') { // frances
            if (fork() == 0) {
                printf("sou o filho (fr)\n");
            }

        }
        
        
    }

    printf("escolheu X, fim do programa\n");

    return 0;
}