#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {

    int fd_s = open("sucesso.log", O_WRONLY);
    int fd_e = open("erro.log", O_WRONLY);

    dup2(fd_s, 1);
    dup2(fd_e, 2);

    close(fd_s);
    close(fd_e);

    printf("essa msg deve ir para o stdout :D");
    fprintf(stderr, "essa msg deve ir para o stderr :(");
    
    return 0;
}