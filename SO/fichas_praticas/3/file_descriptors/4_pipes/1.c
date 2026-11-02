#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main () {

    int fd[2] = { 0 };
    char buffer[256];
    char buffer2[256] = { 0 };

    pipe(fd);

    printf("texto a enviar: ");
    fgets(buffer, 256, stdin);

    int id = fork();
    if (id > 0) {
        close(fd[0]);
        write(fd[1], buffer, strlen(buffer) + 1);    
        close(fd[1]);
        wait(NULL);
    } else if (id == 0) {
        close(fd[1]);
        read(fd[0], buffer2, sizeof(buffer2));    
        close(fd[0]);
        printf("texto recebido: %s", buffer2);
        return 1;
    }

    return 0;
}