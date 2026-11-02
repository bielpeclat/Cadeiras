#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    printf("Programa iniciado...\n");

    int N = atoi();


    setbuf(stdout, NULL);

    for (int i = 0; i < 5; i++) {
        printf("*\n");
        sleep(1);
    }
}