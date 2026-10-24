#include <stdio.h>

int main () {

    char buffer[128];

    printf("texto: ");
    scanf("%s", buffer);

    printf("%s\n", buffer);

    return 0;
}