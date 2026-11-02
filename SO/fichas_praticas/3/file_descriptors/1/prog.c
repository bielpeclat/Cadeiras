#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {

    int fd = open("senha.txt", O_RDONLY);
    char buffer[128];

    dup2(fd, 0);

    scanf("%s", buffer);

    printf("senha: %s\n", buffer);

    return 0;
}