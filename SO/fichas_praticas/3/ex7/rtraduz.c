#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main () {


    
    int fd[2];
    char *prog, letra;
    char buffer[100];

    printf("idioma: ");
    scanf(" %c", &letra);

    printf("texto: ");
    scanf(" %s", buffer);

    if (letra == 'i') {
        prog = "./rding";
    } else if (letra == 'f') {
        prog = "./rdfran";
    } else {
        return 1;
    }

    pipe(fd);

    fflush(stdout);
    
    int flag = fork();

    if (flag == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        execl(prog, prog, NULL);
    } else if (flag > 0) {
        close(fd[0]);
        write(fd[1], buffer, strlen(buffer));
        write(fd[1], "\n", 1);
        close(fd[1]);
        wait(NULL);
    }




    return 0;
}