#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int num = atoi(argv[1]);
    int seg = atoi(argv[2]);
    
    for (int i = 0; i < 5; i++) {
        printf("%d\n", num);
        sleep(seg);
    }
    
}