#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNT 10000

int main(){
    FILE* file = fopen("victim-file.txt", "w");

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "FORK FAILED");
    } 
    else if (pid == 0) {
        int i;
        for(i=0; i< COUNT; i++) {
            fprintf(file, "Child writing: %d\n", i);
        }

    }
    else{
        int i;
        for(i=0; i< COUNT; i++) {
            fprintf(file, "Parent writing: %d\n", i);
        }
    }

}
