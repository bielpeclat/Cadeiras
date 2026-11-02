#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int num = atoi(argv[1]);
    int seg = atoi(argv[2]);

    for (int i = 0; i < num; i++) {
        printf("*\n");
        sleep(seg);
    }

    return 0;
}