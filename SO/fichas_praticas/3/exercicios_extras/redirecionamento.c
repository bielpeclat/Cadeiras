#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {b

    printf("programa iniciado\n");

    int fd = open("texto.txt", O_WRONLY);
    dup2(fd, 1);

    for (int i = 10; i < 15; i++) {
        printf("Ola %d\n", i);
    }

    printf("finalizando...\n");

    return 0;
}