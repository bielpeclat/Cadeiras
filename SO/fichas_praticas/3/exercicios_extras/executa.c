#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main () {

    char buffer[1024];

    setbuf(stdout, NULL);

    printf("texto: ");
    scanf("%s", buffer);

    if (strcmp(buffer, "port") == 0) {
        execl(buffer, buffer, NULL);

    } else if (strcmp(buffer, "ing") == 0) {
        execlp(buffer, buffer, NULL);
    }

    printf("missão cumprida\n");
    return 0;
}