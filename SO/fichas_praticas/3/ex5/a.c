#include <stdio.h>
#include <unistd.h>

int main () {

    int a = 10;
    if (fork() == 0) {
        printf("filho: oi (PID = 0)\n");
        a++;
        printf("filho: tchau (PID = 0)\n");
    }
        
    else {
        printf("pai: oi\n");
        a--;
        printf("pai: tchau\n");
    }
        
    printf("a = %d\n", a);
    return 0;
}