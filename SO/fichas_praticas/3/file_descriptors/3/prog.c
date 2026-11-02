#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {

    int fd_w = open("lista_arquivos.txt", O_WRONLY | O_CREAT);
    // int fd_e = open("erro.log", O_WRONLY);

    dup2(fd_w, 1);
    // dup2(fd_e, 2);

    close(fd_w);
    // close(fd_e);

    execlp("ls", "ls", "-l", NULL);
    
    return 1; // se chegou aqui é pq o execlp falhou!!
}