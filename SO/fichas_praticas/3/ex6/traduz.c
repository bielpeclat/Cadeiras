#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {

    char letra = 'x';
    char palavra[20];

    printf("letra: ");
    scanf(" %c", &letra);

    printf("palavra: ");
    scanf(" %s", palavra);

    while (letra != 'x') {

        if (letra == 'i') { // ingles
            if (fork() == 0) {
                execl("./ding", "ding", palavra, NULL);
                _exit(1);
            }
            wait(NULL);

        } else if (letra == 'f') { // frances
            if (fork() == 0) {
                execl("./dfran", "dfran", palavra, NULL);
                _exit(1);
            }
            wait(NULL);
        }
        
        printf("letra: ");
        scanf(" %c", &letra);
        if (letra == 'x') 
            break;

        printf("palavra: ");
        scanf(" %s", palavra);
    }

    printf("escolheu X, fim do programa\n");

    return 0;
}