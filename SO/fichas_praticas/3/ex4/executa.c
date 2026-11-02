#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main () {

    char buffer[1024];

    printf("texto: ");
    scanf("%s", buffer);

    if (strcmp(buffer, "port") == 0) {
        execl("port", "port", NULL);
    } else if (strcmp(buffer, "ing") == 0) {
        execl("ing", "ing", NULL);
    } else if (strcmp(buffer, "ls") == 0) {
        execlp("ls", "ls", NULL);
    }

    printf("missão cumprida\n");

    return 0;
}